AC_PREREQ(2.53)

AC_INIT([mate-themes], [1.9.3], [https://github.com/mate-desktop/mate-themes/issues], [mate-themes-gtk3.8], [http://www.mate-desktop.org])
AC_CONFIG_SRCDIR([icon-themes])

AM_INIT_AUTOMAKE([1.9 tar-ustar dist-xz no-dist-gzip check-news])

# Enable silent build rules by default, requires at least
# Automake-1.11. Disable by either passing --disable-silent-rules to
# configure or passing V=1 to make
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

IT_PROG_INTLTOOL([0.35.0])
PKG_PROG_PKG_CONFIG([0.19])

AM_GLIB_GNU_GETTEXT
GETTEXT_PACKAGE=AC_PACKAGE_NAME
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", [Gettext package.])

# Workaround to make aclocal get the right flags
AC_SUBST(ACLOCAL_AMFLAGS, "\${ACLOCAL_FLAGS}")

# Check GTK+ theme engines
PKG_CHECK_MODULES(THEME_ENGINE,
 [gtk+-2.0 >= 2.0.0 dnl
  gdk-pixbuf-2.0 >= 2.0.0 ])

GTK_VERSION=`$PKG_CONFIG --variable=gtk_binary_version gtk+-2.0`
AC_SUBST(GTK_VERSION)

# Check if it's a development (odd minor) version (obsolete with date versions)
#AC_MSG_CHECKING([development series build])
#MINOR_VERSION="`echo $PACKAGE_VERSION|cut -d. -f2`"
#if expr $MINOR_VERSION % 2 > /dev/null != "0"; then
   # Development version, disable mapping
   # and enable placeholder by default
#   icon_mapping_policy=no
#   placeholders_policy=yes
#   enable_test_themes=yes
#   AC_MSG_RESULT([yes])
#else
  # Stable version, enable mapping
  # and disable placeholders by default
  icon_mapping_policy=yes
  placeholders_policy=no
#  AC_MSG_RESULT([no])
#fi

# Configure option to force placeholders
AC_ARG_ENABLE([placeholders],
	AC_HELP_STRING([--enable-placeholders],
			[Enable placeholder icons [default=auto]]),
	enable_placeholders=$enableval,
	enable_placeholders=$placeholders_policy)

AM_CONDITIONAL(PLACEHOLDERS, test "x$enable_placeholders" != "xno")

# Configure option to force icon mapping
AC_ARG_ENABLE([icon-mapping],
        AC_HELP_STRING([--enable-icon-mapping],
                        [Enable compatibility symlinks [default=auto]]),
        enable_mapping=$enableval,
        enable_mapping=$icon_mapping_policy)

# Check for icon-naming-utils
ICONMAP="true"
if test "x$enable_mapping" != "xno"; then
   UTILS_REQUIRED=0.8.7

   AC_MSG_CHECKING([icon-naming-utils >= $UTILS_REQUIRED])
   PKG_CHECK_EXISTS(icon-naming-utils >= $UTILS_REQUIRED, have_utils=yes, have_utils=no)
   if test "x$have_utils" = "xyes"; then
      UTILS_PATH="`$PKG_CONFIG --variable=program_path icon-naming-utils`"
      ICONMAP="$UTILS_PATH/icon-name-mapping"
      AC_MSG_RESULT([yes])
   else
	AC_MSG_RESULT([no])
   	AC_MSG_ERROR([icon-naming-utils >= $UTILS_REQUIRED is required to build and install mate-themes])
   fi
fi
AC_SUBST(ICONMAP)
AM_CONDITIONAL(LEGACY_ICON_MAPPING, test "x$enable_mapping" != "xno")

# Configure options for extra a11y themes
AC_ARG_ENABLE(all-themes,
 AC_HELP_STRING([--enable-all-themes],
     [Install all a11y theme sets, default is core a11y themes only]),,
 [enable_all_themes=no])
AM_CONDITIONAL(CORE_THEMES_ONLY, test "$enable_all_themes" = no)

### Cursor theme to use for large print desktop themes.
### TODO: Should probably check whether specified/default themes are
### installed too, and do something appropriate if not.
AC_ARG_WITH(lp-cursor-theme,
[AS_HELP_STRING([--with-lp-cursor-theme=THEME],
 [cursor theme for Large Print desktop theme [default=whiteglass]])],
[LARGEPRINT_CURSOR_THEME="$withval"],
[LARGEPRINT_CURSOR_THEME="whiteglass"],
)
AC_SUBST(LARGEPRINT_CURSOR_THEME)

AC_ARG_WITH(hclp-cursor-theme,
[AS_HELP_STRING([--with-hclp-cursor-theme=THEME],
 [cursor theme for High Contrast Large Print desktop theme [default=redglass]])],
[LARGEPRINT_HC_CURSOR_THEME="$withval"],
[LARGEPRINT_HC_CURSOR_THEME="redglass"],
)
AC_SUBST(LARGEPRINT_HC_CURSOR_THEME)

AC_ARG_WITH(hclpi-cursor-theme,
[AS_HELP_STRING([--with-hclpi-cursor-theme=THEME],
 [cursor theme for High Contrast Large Print Inverse desktop theme [default=whiteglass]])],
[LARGEPRINT_HCI_CURSOR_THEME="$withval"],
[LARGEPRINT_HCI_CURSOR_THEME="whiteglass"],
)
AC_SUBST(LARGEPRINT_HCI_CURSOR_THEME)

### Icon sizes for all large print themes

LARGEPRINT_DND="48,48"
LARGEPRINT_MENU="32,32"
LARGEPRINT_PANEL_MENU="48,48"
LARGEPRINT_LARGE_TOOLBAR="48,48"
LARGEPRINT_SMALL_TOOLBAR="32,32"
LARGEPRINT_BUTTON="32,32"
LARGEPRINT_DIALOG="64,64"
LARGEPRINT_MINI_COMMANDER="24,24"

LARGEPRINT_ICON_SIZES="mini-commander-icon=$LARGEPRINT_MINI_COMMANDER:print-manager=$LARGEPRINT_DIALOG:panel-button=$LARGEPRINT_BUTTON:gtk-dnd=$LARGEPRINT_DND:gtk-menu=$LARGEPRINT_MENU:panel-menu=$LARGEPRINT_PANEL_MENU:gtk-large-toolbar=$LARGEPRINT_LARGE_TOOLBAR:gtk-small-toolbar=$LARGEPRINT_SMALL_TOOLBAR:gtk-button=$LARGEPRINT_BUTTON:gtk-dialog=$LARGEPRINT_DIALOG"

LARGEPRINT_FONT="sans 18"
LARGEPRINT_DOCUMENTS_FONT="sans 18"
LARGEPRINT_DESKTOP_FONT="sans 18"
LARGEPRINT_WINDOW_FONT="sans 18"
LARGEPRINT_MONOSPACE_FONT="monospace 18"
LARGEPRINT_CURSOR_SIZE="48"

AC_SUBST(LARGEPRINT_ICON_SIZES)
AC_SUBST(LARGEPRINT_FONT)
AC_SUBST(LARGEPRINT_DOCUMENTS_FONT)
AC_SUBST(LARGEPRINT_DESKTOP_FONT)
AC_SUBST(LARGEPRINT_WINDOW_FONT)
AC_SUBST(LARGEPRINT_MONOSPACE_FONT)
AC_SUBST(LARGEPRINT_CURSOR_SIZE)

dnl used to substitute in common sections of theme gtkrc files
gtk_stock_icons_rc=${srcdir}/common/gtk-stock-icons.rc
panel_stock_icons_rc=${srcdir}/common/panel-stock-icons.rc
media_stock_icons_rc=${srcdir}/common/media-stock-icons.rc
capplet_stock_icons_rc=${srcdir}/common/capplet-stock-icons.rc
marco_stock_icons_rc=${srcdir}/common/marco-stock-icons.rc
AC_SUBST_FILE(gtk_stock_icons_rc)
AC_SUBST_FILE(panel_stock_icons_rc)
AC_SUBST_FILE(media_stock_icons_rc)
AC_SUBST_FILE(capplet_stock_icons_rc)
AC_SUBST_FILE(marco_stock_icons_rc)

AC_CONFIG_FILES([
Makefile
common/Makefile
cursor-themes/Makefile
desktop-themes/Makefile
desktop-themes/AlaDelta/Makefile
desktop-themes/BlackMATE/Makefile
desktop-themes/BlackMATE/gtk-2.0/Makefile
desktop-themes/BlackMATE/gtk-2.0/assets/Makefile
desktop-themes/BlackMATE/gtk-2.0/Styles/Makefile
desktop-themes/BlackMATE/gtk-3.0/Makefile
desktop-themes/BlackMATE/gtk-3.0/assets/Makefile
desktop-themes/BlackMATE/metacity-1/Makefile
desktop-themes/BlackMATE/cinnamon/Makefile
desktop-themes/ContrastHigh/Makefile
desktop-themes/ContrastHigh/gtk-2.0/Makefile
desktop-themes/ContrastHigh/gtk-2.0/gtkrc
desktop-themes/ContrastHigh/gtk-3.0/Makefile
desktop-themes/ContrastHigh/metacity-1/Makefile
desktop-themes/ContrastHigh/pixmaps/Makefile
desktop-themes/ContrastHighInverse/Makefile
desktop-themes/ContrastHighInverse/gtk-2.0/Makefile
desktop-themes/ContrastHighInverse/gtk-2.0/gtkrc
desktop-themes/ContrastHighInverse/gtk-3.0/Makefile
desktop-themes/ContrastHighInverse/metacity-1/Makefile
desktop-themes/ContrastHighInverse/pixmaps/Makefile
desktop-themes/ContrastHighLargePrint/Makefile
desktop-themes/ContrastHighLargePrint/index.theme.in
desktop-themes/ContrastHighLargePrintInverse/Makefile
desktop-themes/ContrastHighLargePrintInverse/index.theme.in
desktop-themes/Fog/Makefile
desktop-themes/GreenLaguna/Makefile
desktop-themes/GreenLaguna/gtk-2.0/Makefile
desktop-themes/GreenLaguna/gtk-2.0/Styles/Makefile
desktop-themes/GreenLaguna/gtk-3.0/Makefile
desktop-themes/GreenLaguna/gtk-3.0/assets/Makefile
desktop-themes/GreenLaguna/metacity-1/Makefile
desktop-themes/LargePrint/Makefile
desktop-themes/LargePrint/index.theme.in
desktop-themes/Menta/Makefile
desktop-themes/Menta/cinnamon/Makefile
desktop-themes/Menta/gtk-2.0/Makefile
desktop-themes/Menta/gtk-2.0/apps/Makefile
desktop-themes/Menta/gtk-2.0/apps/Caja/Makefile
desktop-themes/Menta/gtk-2.0/apps/Handles/Makefile
desktop-themes/Menta/gtk-2.0/apps/Null/Makefile
desktop-themes/Menta/gtk-2.0/apps/Others/Makefile
desktop-themes/Menta/gtk-2.0/widgets/Makefile
desktop-themes/Menta/gtk-2.0/widgets/Null/Makefile
desktop-themes/Menta/gtk-2.0/widgets/Others/Makefile
desktop-themes/Menta/gtk-2.0/widgets/Panel/Makefile
desktop-themes/Menta/gtk-2.0/widgets/Scale/Makefile
desktop-themes/Menta/gtk-3.0/Makefile
desktop-themes/Menta/gtk-3.0/assets/Makefile
desktop-themes/Menta/gtk-3.0/borders/Makefile
desktop-themes/Menta/metacity-1/Makefile
desktop-themes/Menta/unity/Makefile
desktop-themes/Menta/xfwm4/Makefile
desktop-themes/BlueMenta/Makefile
desktop-themes/BlueMenta/cinnamon/Makefile
desktop-themes/BlueMenta/gtk-2.0/Makefile
desktop-themes/BlueMenta/gtk-2.0/apps/Makefile
desktop-themes/BlueMenta/gtk-2.0/apps/Caja/Makefile
desktop-themes/BlueMenta/gtk-2.0/apps/Handles/Makefile
desktop-themes/BlueMenta/gtk-2.0/apps/Null/Makefile
desktop-themes/BlueMenta/gtk-2.0/apps/Others/Makefile
desktop-themes/BlueMenta/gtk-2.0/widgets/Makefile
desktop-themes/BlueMenta/gtk-2.0/widgets/Null/Makefile
desktop-themes/BlueMenta/gtk-2.0/widgets/Others/Makefile
desktop-themes/BlueMenta/gtk-2.0/widgets/Panel/Makefile
desktop-themes/BlueMenta/gtk-2.0/widgets/Scale/Makefile
desktop-themes/BlueMenta/gtk-3.0/Makefile
desktop-themes/BlueMenta/gtk-3.0/assets/Makefile
desktop-themes/BlueMenta/gtk-3.0/borders/Makefile
desktop-themes/BlueMenta/metacity-1/Makefile
desktop-themes/BlueMenta/unity/Makefile
desktop-themes/BlueMenta/xfwm4/Makefile
desktop-themes/Quid/Makefile
desktop-themes/Shiny/Makefile
desktop-themes/Shiny/gtk-2.0/Makefile
desktop-themes/Shiny/gtk-3.0/Makefile
desktop-themes/Shiny/gtk-3.0/assets/Makefile
desktop-themes/Shiny/gtk-3.0/apps/Makefile
desktop-themes/Shiny/metacity-1/Makefile
desktop-themes/Shiny/openbox-3/Makefile
desktop-themes/Shiny/unity/Makefile
desktop-themes/Shiny/xfwm4/Makefile
desktop-themes/TraditionalGreen/Makefile
desktop-themes/TraditionalGreen/gtk-2.0/Makefile
desktop-themes/TraditionalGreen/gtk-3.0/Makefile
desktop-themes/TraditionalGreen/gtk-3.0/img/Makefile
desktop-themes/TraditionalGreen/metacity-1/Makefile
desktop-themes/TraditionalOk/Makefile
desktop-themes/TraditionalOk/doc/Makefile
desktop-themes/TraditionalOk/gtk-2.0/Makefile
desktop-themes/TraditionalOk/gtk-3.0/Makefile
desktop-themes/TraditionalOk/gtk-3.0/img/Makefile
desktop-themes/TraditionalOk/metacity-1/Makefile
desktop-themes/TraditionalOk/openbox-3/Makefile
desktop-themes/TraditionalOk/wallpapers/Makefile
desktop-themes/TraditionalOk/xfwm4/Makefile
desktop-themes/TraditionalOk/xfwm4/png/Makefile
desktop-themes/TraditionalOkTest/Makefile
desktop-themes/TraditionalOkTest/gtk-2.0/Makefile
desktop-themes/TraditionalOkTest/gtk-3.0/Makefile
desktop-themes/TraditionalOkTest/gtk-3.0/img/Makefile
desktop-themes/TraditionalOkTest/metacity-1/Makefile
marco-themes/Makefile
gtk-themes/Makefile
gtk-themes/AlaDelta/Makefile
gtk-themes/ContrastHighLargePrint/Makefile
gtk-themes/ContrastHighLargePrint/gtkrc
gtk-themes/ContrastHighLargePrintInverse/Makefile
gtk-themes/ContrastHighLargePrintInverse/gtkrc
gtk-themes/LargePrint/Makefile
gtk-themes/LargePrint/gtkrc
gtk-themes/Reverse/Makefile
gtk-themes/Simply/Makefile
icon-themes/Makefile
icon-themes/ContrastHigh/Makefile
icon-themes/ContrastHigh/16x16/Makefile
icon-themes/ContrastHigh/16x16/actions/Makefile
icon-themes/ContrastHigh/16x16/apps/Makefile
icon-themes/ContrastHigh/16x16/categories/Makefile
icon-themes/ContrastHigh/16x16/devices/Makefile
icon-themes/ContrastHigh/16x16/emblems/Makefile
icon-themes/ContrastHigh/16x16/emotes/Makefile
icon-themes/ContrastHigh/16x16/mimetypes/Makefile
icon-themes/ContrastHigh/16x16/places/Makefile
icon-themes/ContrastHigh/16x16/status/Makefile
icon-themes/ContrastHigh/16x16/stock/Makefile
icon-themes/ContrastHigh/22x22/Makefile
icon-themes/ContrastHigh/22x22/actions/Makefile
icon-themes/ContrastHigh/22x22/apps/Makefile
icon-themes/ContrastHigh/22x22/categories/Makefile
icon-themes/ContrastHigh/22x22/devices/Makefile
icon-themes/ContrastHigh/22x22/emblems/Makefile
icon-themes/ContrastHigh/22x22/emotes/Makefile
icon-themes/ContrastHigh/22x22/mimetypes/Makefile
icon-themes/ContrastHigh/22x22/places/Makefile
icon-themes/ContrastHigh/22x22/status/Makefile
icon-themes/ContrastHigh/22x22/stock/Makefile
icon-themes/ContrastHigh/24x24/Makefile
icon-themes/ContrastHigh/24x24/actions/Makefile
icon-themes/ContrastHigh/24x24/apps/Makefile
icon-themes/ContrastHigh/24x24/categories/Makefile
icon-themes/ContrastHigh/24x24/devices/Makefile
icon-themes/ContrastHigh/24x24/emblems/Makefile
icon-themes/ContrastHigh/24x24/emotes/Makefile
icon-themes/ContrastHigh/24x24/mimetypes/Makefile
icon-themes/ContrastHigh/24x24/places/Makefile
icon-themes/ContrastHigh/24x24/status/Makefile
icon-themes/ContrastHigh/24x24/stock/Makefile
icon-themes/ContrastHigh/32x32/Makefile
icon-themes/ContrastHigh/32x32/actions/Makefile
icon-themes/ContrastHigh/32x32/apps/Makefile
icon-themes/ContrastHigh/32x32/categories/Makefile
icon-themes/ContrastHigh/32x32/devices/Makefile
icon-themes/ContrastHigh/32x32/emblems/Makefile
icon-themes/ContrastHigh/32x32/emotes/Makefile
icon-themes/ContrastHigh/32x32/mimetypes/Makefile
icon-themes/ContrastHigh/32x32/places/Makefile
icon-themes/ContrastHigh/32x32/status/Makefile
icon-themes/ContrastHigh/32x32/stock/Makefile
icon-themes/ContrastHigh/48x48/Makefile
icon-themes/ContrastHigh/48x48/actions/Makefile
icon-themes/ContrastHigh/48x48/animations/Makefile
icon-themes/ContrastHigh/48x48/apps/Makefile
icon-themes/ContrastHigh/48x48/categories/Makefile
icon-themes/ContrastHigh/48x48/devices/Makefile
icon-themes/ContrastHigh/48x48/emblems/Makefile
icon-themes/ContrastHigh/48x48/emotes/Makefile
icon-themes/ContrastHigh/48x48/mimetypes/Makefile
icon-themes/ContrastHigh/48x48/places/Makefile
icon-themes/ContrastHigh/48x48/status/Makefile
icon-themes/ContrastHigh/48x48/stock/Makefile
icon-themes/ContrastHigh/256x256/Makefile
icon-themes/ContrastHigh/256x256/actions/Makefile
icon-themes/ContrastHigh/256x256/apps/Makefile
icon-themes/ContrastHigh/256x256/categories/Makefile
icon-themes/ContrastHigh/256x256/devices/Makefile
icon-themes/ContrastHigh/256x256/emblems/Makefile
icon-themes/ContrastHigh/256x256/emotes/Makefile
icon-themes/ContrastHigh/256x256/mimetypes/Makefile
icon-themes/ContrastHigh/256x256/places/Makefile
icon-themes/ContrastHigh/256x256/status/Makefile
icon-themes/ContrastHigh/256x256/stock/Makefile
icon-themes/ContrastHigh/scalable/Makefile
icon-themes/ContrastHigh/scalable/actions/Makefile
icon-themes/ContrastHigh/scalable/actions-extra/Makefile
icon-themes/ContrastHigh/scalable/apps/Makefile
icon-themes/ContrastHigh/scalable/apps-extra/Makefile
icon-themes/ContrastHigh/scalable/categories/Makefile
icon-themes/ContrastHigh/scalable/devices/Makefile
icon-themes/ContrastHigh/scalable/emblems/Makefile
icon-themes/ContrastHigh/scalable/mimetypes/Makefile
icon-themes/ContrastHigh/scalable/places/Makefile
icon-themes/ContrastHigh/scalable/places-extra/Makefile
icon-themes/ContrastHigh/scalable/status/Makefile
icon-themes/ContrastHigh/scalable/status-extra/Makefile
icon-themes/ContrastHighLargePrint/Makefile
icon-themes/ContrastHighLargePrintInverse/Makefile
icon-themes/ContrastHighLargePrintInverse/36x36/Makefile
icon-themes/ContrastHighLargePrintInverse/36x36/animations/Makefile
icon-themes/ContrastHighLargePrintInverse/48x48/Makefile
icon-themes/ContrastHighLargePrintInverse/48x48/actions/Makefile
icon-themes/ContrastHighLargePrintInverse/48x48/apps/Makefile
icon-themes/ContrastHighLargePrintInverse/48x48/categories/Makefile
icon-themes/ContrastHighLargePrintInverse/48x48/devices/Makefile
icon-themes/ContrastHighLargePrintInverse/48x48/emblems/Makefile
icon-themes/ContrastHighLargePrintInverse/48x48/mimetypes/Makefile
icon-themes/ContrastHighLargePrintInverse/48x48/places/Makefile
icon-themes/ContrastHighLargePrintInverse/48x48/status/Makefile
icon-themes/Fog/22x22/status/Makefile
icon-themes/Fog/22x22/devices/Makefile
icon-themes/Fog/22x22/actions/Makefile
icon-themes/Fog/22x22/places/Makefile
icon-themes/Fog/22x22/apps/Makefile
icon-themes/Fog/22x22/Makefile
icon-themes/Fog/16x16/status/Makefile
icon-themes/Fog/16x16/devices/Makefile
icon-themes/Fog/16x16/actions/Makefile
icon-themes/Fog/16x16/places/Makefile
icon-themes/Fog/16x16/apps/Makefile
icon-themes/Fog/16x16/Makefile
icon-themes/Fog/32x32/status/Makefile
icon-themes/Fog/32x32/devices/Makefile
icon-themes/Fog/32x32/actions/Makefile
icon-themes/Fog/32x32/places/Makefile
icon-themes/Fog/32x32/apps/Makefile
icon-themes/Fog/32x32/Makefile
icon-themes/Fog/Makefile
icon-themes/Fog/48x48/status/Makefile
icon-themes/Fog/48x48/devices/Makefile
icon-themes/Fog/48x48/actions/Makefile
icon-themes/Fog/48x48/places/Makefile
icon-themes/Fog/48x48/apps/Makefile
icon-themes/Fog/48x48/Makefile
icon-themes/Fog/24x24/status/Makefile
icon-themes/Fog/24x24/devices/Makefile
icon-themes/Fog/24x24/actions/Makefile
icon-themes/Fog/24x24/places/Makefile
icon-themes/Fog/24x24/apps/Makefile
icon-themes/Fog/24x24/Makefile
icon-themes/Fog/256x256/status/Makefile
icon-themes/Fog/256x256/devices/Makefile
icon-themes/Fog/256x256/actions/Makefile
icon-themes/Fog/256x256/places/Makefile
icon-themes/Fog/256x256/apps/Makefile
icon-themes/Fog/256x256/Makefile
icon-themes/LargePrint/Makefile
icon-themes/Quid/Makefile
icon-themes/Quid/16x16/Makefile
icon-themes/Quid/16x16/actions/Makefile
icon-themes/Quid/16x16/status/Makefile
icon-themes/Quid/16x16/places/Makefile
icon-themes/Quid/22x22/Makefile
icon-themes/Quid/22x22/actions/Makefile
icon-themes/Quid/22x22/status/Makefile
icon-themes/Quid/22x22/places/Makefile
icon-themes/Quid/24x24/Makefile
icon-themes/Quid/24x24/actions/Makefile
icon-themes/Quid/24x24/status/Makefile
icon-themes/Quid/24x24/places/Makefile
icon-themes/Quid/32x32/Makefile
icon-themes/Quid/32x32/actions/Makefile
icon-themes/Quid/32x32/status/Makefile
icon-themes/Quid/32x32/places/Makefile
icon-themes/Quid/scalable/Makefile
icon-themes/Quid/scalable/actions/Makefile
icon-themes/Quid/scalable/status/Makefile
icon-themes/Quid/scalable/places/Makefile
po/Makefile.in
])

AC_OUTPUT

dnl ==========================================================================
echo "
mate-themes-$VERSION:

	Installation prefix:	${prefix}

	Enable placeholders:         ${enable_placeholders}
	Enable legacy icons:         ${enable_mapping}
	Enable all themes:           ${enable_all_themes}
	LargePrint cursor theme:     ${LARGEPRINT_CURSOR_THEME}
	HC LargePrint cursor theme:  ${LARGEPRINT_HC_CURSOR_THEME}
	HCI LargePrint cursor theme: ${LARGEPRINT_HCI_CURSOR_THEME}

"
