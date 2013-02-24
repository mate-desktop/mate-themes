#include <cairo/cairo.h>
#include <gio/gio.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk/gdk.h>
#include <glib.h>
#include <string.h>
#include <math.h>

GFile *gnome_dir = NULL;
GFile *hc_dir = NULL;

static const gint icon_sizes[] = {
  16, 22, 24, 32, 48, 256
};

static char *
replace_str (char *str,
             const char *substr,
             const char *new_substr)
{
  static char buf[4096];
  char *ptr;

  /* if we didn't find the substring, return */
  if (!(ptr = (char*)strstr (str, substr)))
    return str;

  /* copy up to the substring */
  strncpy (buf, str, ptr - str);
  buf[ptr - str] = '\0';

  if (strlen (substr) >=strlen (new_substr))
    {
      sprintf (buf + (ptr - str), "%s%s", new_substr, ptr + strlen (substr));
    }
  else
    {
      static char buf2[4096];

      strncpy (buf2, str, ptr - str + strlen (substr));
      buf2[ptr - str + strlen (substr)] = '\0';

      sprintf (buf2 + (ptr - str), "%s%s", new_substr, ptr + strlen (substr));
      strncpy (buf, buf2, strlen (buf));
    }

  return buf;
}

static gchar *
ensure_dest_path (GFile *file,
                  gint icon_size)
{
  gchar *str, *str2, *size_string, *dest_path;
  GFile *dest_file, *dest_dir, *tmp;

  str = g_file_get_relative_path (gnome_dir, file);
  tmp = g_file_resolve_relative_path (hc_dir, str);
  g_free (str);

  str = g_file_get_path (tmp);
  size_string = g_strdup_printf ("%dx%d", icon_size, icon_size);
  str2 = replace_str (str, "-symbolic.svg", ".png");
  dest_path = replace_str (str2, "scalable", size_string);

  dest_file = g_file_new_for_path (dest_path);
  dest_dir = g_file_get_parent (dest_file);

  g_file_make_directory_with_parents (dest_dir, NULL, NULL);

  g_object_unref (dest_file);
  g_object_unref (dest_dir);
  g_object_unref (tmp);
  g_free (str);
  g_free (size_string);

  return dest_path;
}

static void
optimize_png (const gchar *png_path)
{
  gchar *cmd = g_strconcat ("optipng -quiet", " ", png_path, NULL);
  g_spawn_command_line_async (cmd, NULL);
  g_free (cmd);
}

static GdkPixbuf *
get_recolored_svg (GFile *file,
                   gint icon_size)
{
  gchar *data, *str;
  GdkPixbuf *pixbuf;
  GInputStream *stream;

  str = g_file_get_path (file);
  data = g_strconcat ("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n"
                      "<svg version=\"1.1\"\n"
                      "     xmlns=\"http://www.w3.org/2000/svg\"\n"
                      "     xmlns:xi=\"http://www.w3.org/2001/XInclude\"\n"
                      "     width=\"16\"\n"
                      "     height=\"16\">\n"
                      "  <style type=\"text/css\">\n"
                      "    rect,path {\n"
                      "      fill: black !important;\n"
                      "    }\n"
                      "    .warning {\n"
                      "      fill: #f57900 !important;\n"
                      "    }\n"
                      "    .error {\n"
                      "      fill: #cc0000 !important;\n"
                      "    }\n"
                      "    .success {\n"
                      "      fill: #4e9a06 !important;\n"
                      "    }\n"
                      "  </style>\n"
                      "  <xi:include href=\"", str, "\"/>\n"
                      "</svg>",
                      NULL);

  stream = g_memory_input_stream_new_from_data (data, -1, g_free);
  pixbuf = gdk_pixbuf_new_from_stream_at_scale (stream,
                                                icon_size, icon_size,
                                                TRUE, NULL, NULL);
  g_object_unref (stream);
  g_free (str);

  return pixbuf;
}

/* taken from gdkcairo.c */
static gboolean
_gdk_cairo_surface_extents (cairo_surface_t *surface,
                            GdkRectangle    *extents)
{
  double x1, x2, y1, y2;
  cairo_t *cr;

  g_return_val_if_fail (surface != NULL, FALSE);
  g_return_val_if_fail (extents != NULL, FALSE);

  cr = cairo_create (surface);
  cairo_clip_extents (cr, &x1, &y1, &x2, &y2);
  cairo_destroy (cr);

  x1 = floor (x1);
  y1 = floor (y1);
  x2 = ceil (x2);
  y2 = ceil (y2);
  x2 -= x1;
  y2 -= y1;

  if (x1 < G_MININT || x1 > G_MAXINT ||
      y1 < G_MININT || y1 > G_MAXINT ||
      x2 > G_MAXINT || y2 > G_MAXINT)
    {
      extents->x = extents->y = extents->width = extents->height = 0;
      return FALSE;
    }

  extents->x = x1;
  extents->y = y1;
  extents->width = x2;
  extents->height = y2;

  return TRUE;
}

/* This function originally from Jean-Edouard Lachand-Robert, and
 * available at www.codeguru.com. Simplified for our needs, not sure
 * how much of the original code left any longer. Now handles just
 * one-bit deep bitmaps (in Window parlance, ie those that GDK calls
 * bitmaps (and not pixmaps), with zero pixels being transparent.
 *
 * Changed again here from the GDK version to use an 8-bit surface instead
 * of a 1-bit bitmap.
 */
static cairo_region_t *
_gdk_cairo_region_create_from_surface (cairo_surface_t *surface)
{
  cairo_region_t *region;
  GdkRectangle extents, rect;
  cairo_surface_t *image;
  cairo_t *cr;
  gint x, y, stride;
  guchar *data;

  _gdk_cairo_surface_extents (surface, &extents);

  if (cairo_surface_get_content (surface) == CAIRO_CONTENT_COLOR)
    return cairo_region_create_rectangle (&extents);

  if (cairo_surface_get_type (surface) != CAIRO_SURFACE_TYPE_IMAGE ||
      cairo_image_surface_get_format (surface) != CAIRO_FORMAT_A8)
    {
      /* coerce to an A8 image */
      image = cairo_image_surface_create (CAIRO_FORMAT_A8,
                                          extents.width, extents.height);
      cr = cairo_create (image);
      cairo_set_source_surface (cr, surface, -extents.x, -extents.y);
      cairo_paint (cr);
      cairo_destroy (cr);
    }
  else
    image = cairo_surface_reference (surface);

  data = cairo_image_surface_get_data (image);
  stride = cairo_image_surface_get_stride (image);

  region = cairo_region_create ();

  for (y = 0; y < extents.height; y++)
    {
      for (x = 0; x < extents.width; x++)
        {
          /* Search for a continuous range of "non transparent pixels"*/
          gint x0 = x;
          while (x < extents.width)
            {
              guint8 alpha = data[x];
              if (alpha < 24)
                /* This pixel is "transparent"*/
                break;
              x++;
            }

          if (x > x0)
            {
              /* Add the pixels (x0, y) to (x, y+1) as a new rectangle
               * in the region
               */
              rect.x = x0;
              rect.width = x - x0;
              rect.y = y;
              rect.height = 1;

              cairo_region_union_rectangle (region, &rect);
            }
        }
      data += stride;
    }

  cairo_surface_destroy (image);

  cairo_region_translate (region, extents.x, extents.y);

  return region;
}

static void
write_png_theme (GList *svg_files,
                 gint icon_size)
{
  GList *l;

  g_print ("Writing size: %dx%d\n", icon_size, icon_size);

  for (l = svg_files; l != NULL; l = l->next)
    {
      GFile *file;
      gchar *dest_path;
      GdkPixbuf *pixbuf;
      gint border_offset;
      cairo_surface_t *surface;
      cairo_region_t *region;
      cairo_t *cr;

      file = l->data;
      border_offset = (gint) floor (icon_size / 16);
      pixbuf = get_recolored_svg (file, icon_size - 2.0 * border_offset);

      surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32,
                                            icon_size, icon_size);
      cr = cairo_create (surface);

      gdk_cairo_set_source_pixbuf (cr, pixbuf,
                                   border_offset, border_offset);
      cairo_paint (cr);
      cairo_destroy (cr);

      region = _gdk_cairo_region_create_from_surface (surface);
      cairo_surface_destroy (surface);

      surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32,
                                            icon_size, icon_size);
      cr = cairo_create (surface);

      cairo_save (cr);
      gdk_cairo_region (cr, region);

      cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 1.0);
      cairo_set_line_width (cr, 2.0 * border_offset);
      cairo_set_line_cap (cr, CAIRO_LINE_CAP_ROUND);
      cairo_set_line_join (cr, CAIRO_LINE_JOIN_ROUND);

      cairo_stroke (cr);
      cairo_restore (cr);

      gdk_cairo_set_source_pixbuf (cr, pixbuf,
                                   border_offset, border_offset);
      cairo_paint (cr);

      dest_path = ensure_dest_path (file, icon_size);
      cairo_surface_write_to_png (surface, dest_path);

      cairo_destroy (cr);
      cairo_surface_destroy (surface);
      cairo_region_destroy (region);
      g_object_unref (pixbuf);

      optimize_png (dest_path);
    }
}

static void
process (int argc,
         char **argv)
{
  GList *svg_files = NULL;
  GQueue *descend_into_files;
  GFile *current_dir, *symbolic_theme, *file;
  gchar *str;
  gint idx;

  str = g_get_current_dir ();
  current_dir = g_file_new_for_path (str);
  g_free (str);

  symbolic_theme = g_file_new_for_commandline_arg (argv[1]);
  gnome_dir = g_file_resolve_relative_path (symbolic_theme, "gnome");
  hc_dir = g_file_resolve_relative_path (current_dir, "icons");
  g_object_unref (symbolic_theme);

  descend_into_files = g_queue_new ();
  g_queue_push_tail (descend_into_files, g_object_ref (gnome_dir));
  while ((file = g_queue_pop_head (descend_into_files)) != NULL)
    {
      GFileInfo *child_info;
      GFileEnumerator *enumerator = 
        g_file_enumerate_children (file, "standard::name,standard::type,standard::content-type", 
                                   G_FILE_QUERY_INFO_NONE, NULL, NULL);

      while ((child_info = g_file_enumerator_next_file (enumerator, NULL, NULL)) != NULL)
        {
          if (g_file_info_get_file_type (child_info) == G_FILE_TYPE_DIRECTORY)
            g_queue_push_tail (descend_into_files, g_file_resolve_relative_path (file, g_file_info_get_name (child_info)));
          else if (g_content_type_is_a (g_file_info_get_content_type (child_info), "image/svg+xml"))
            svg_files = g_list_prepend (svg_files, g_file_resolve_relative_path (file, g_file_info_get_name (child_info)));

          g_object_unref (child_info);
        }

      g_object_unref (enumerator);
      g_object_unref (file);
    }

  for (idx = 0; idx < G_N_ELEMENTS (icon_sizes); idx++)
    write_png_theme (svg_files, icon_sizes[idx]);

  g_list_free_full (svg_files, g_object_unref);
  g_queue_free (descend_into_files);
  g_clear_object (&gnome_dir);
  g_clear_object (&hc_dir);
}

int
main (int argc,
      char **argv)
{
  if (argc == 1)
    {
      g_critical ("Location of gnome-icon-theme-symbolic repo must be given");
      return 0;
    }

  g_type_init ();
  process (argc, argv);
  g_spawn_command_line_async ("./create-makefiles.sh", NULL);

  return 0;
}
