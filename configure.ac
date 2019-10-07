AC_PREREQ(2.53)

AC_INIT([mate-themes], [3.22.21], [https://mate-desktop.org])
AC_CONFIG_SRCDIR([icon-themes])

AM_INIT_AUTOMAKE([1.9 tar-ustar dist-xz no-dist-gzip check-news])

# Enable silent build rules by default, requires at least
# Automake-1.11. Disable by either passing --disable-silent-rules to
# configure or passing V=1 to make
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

PKG_PROG_PKG_CONFIG([0.19])
AM_GNU_GETTEXT_VERSION([0.19.8])
AM_GNU_GETTEXT([external])

# Workaround to make aclocal get the right flags
AC_SUBST(ACLOCAL_AMFLAGS, "\${ACLOCAL_FLAGS}")

# Check GTK+ theme engines
PKG_CHECK_MODULES(THEME_ENGINE,
 [gtk+-2.0 >= 2.0.0 dnl
  gdk-pixbuf-2.0 >= 2.0.0 ])

AC_CONFIG_FILES([
Makefile
cursor-themes/Makefile
cursor-themes/mate-white/Makefile
cursor-themes/mate-white/cursors/Makefile
cursor-themes/mate-black/Makefile
cursor-themes/mate-black/cursors/Makefile
desktop-themes/Makefile
desktop-themes/BlackMATE/Makefile
desktop-themes/BlackMATE/apps/Makefile
desktop-themes/BlackMATE/gtk-2.0/Makefile
desktop-themes/BlackMATE/gtk-2.0/assets/Makefile
desktop-themes/BlackMATE/gtk-2.0/Styles/Makefile
desktop-themes/BlackMATE/gtk-3.0/Makefile
desktop-themes/BlackMATE/gtk-3.0/assets/Makefile
desktop-themes/BlackMATE/gtk-3.0/window-controls/Makefile
desktop-themes/BlackMATE/metacity-1/Makefile
desktop-themes/BlackMATE/cinnamon/Makefile
desktop-themes/BlackMATE/unity/Makefile
desktop-themes/BlackMATE-border/Makefile
desktop-themes/BlackMATE-border/metacity-1/Makefile
desktop-themes/BlueMenta/Makefile
desktop-themes/BlueMenta/cinnamon/Makefile
desktop-themes/BlueMenta/emerald/Makefile
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
desktop-themes/BlueMenta/gtk-3.0/window-controls/Makefile
desktop-themes/BlueMenta/metacity-1/Makefile
desktop-themes/BlueMenta/unity/Makefile
desktop-themes/BlueMenta/xfwm4/Makefile
desktop-themes/BlueMenta-border/Makefile
desktop-themes/BlueMenta-border/metacity-1/Makefile
desktop-themes/Blue-Submarine/Makefile
desktop-themes/Blue-Submarine/cinnamon/Makefile
desktop-themes/Blue-Submarine/emerald/Makefile
desktop-themes/Blue-Submarine/gtk-2.0/Makefile
desktop-themes/Blue-Submarine/gtk-2.0/apps/Makefile
desktop-themes/Blue-Submarine/gtk-2.0/apps/Handles/Makefile
desktop-themes/Blue-Submarine/gtk-2.0/apps/Panel/Makefile
desktop-themes/Blue-Submarine/gtk-2.0/assets/Makefile
desktop-themes/Blue-Submarine/gtk-3.0/Makefile
desktop-themes/Blue-Submarine/gtk-3.0/assets/Makefile
desktop-themes/Blue-Submarine/metacity-1/Makefile
desktop-themes/Blue-Submarine-border/Makefile
desktop-themes/Blue-Submarine-border/metacity-1/Makefile
desktop-themes/ContrastHigh/Makefile
desktop-themes/GreenLaguna/Makefile
desktop-themes/GreenLaguna/gtk-2.0/Makefile
desktop-themes/GreenLaguna/gtk-2.0/Styles/Makefile
desktop-themes/GreenLaguna/gtk-3.0/Makefile
desktop-themes/GreenLaguna/gtk-3.0/assets/Makefile
desktop-themes/GreenLaguna/gtk-3.0/window-controls/Makefile
desktop-themes/GreenLaguna/metacity-1/Makefile
desktop-themes/GreenLaguna/unity/Makefile
desktop-themes/GreenLaguna-border/Makefile
desktop-themes/GreenLaguna-border/metacity-1/Makefile
desktop-themes/Green-Submarine/Makefile
desktop-themes/Green-Submarine/cinnamon/Makefile
desktop-themes/Green-Submarine/emerald/Makefile
desktop-themes/Green-Submarine/gtk-2.0/Makefile
desktop-themes/Green-Submarine/gtk-2.0/apps/Makefile
desktop-themes/Green-Submarine/gtk-2.0/apps/Handles/Makefile
desktop-themes/Green-Submarine/gtk-2.0/apps/Panel/Makefile
desktop-themes/Green-Submarine/gtk-2.0/assets/Makefile
desktop-themes/Green-Submarine/gtk-3.0/Makefile
desktop-themes/Green-Submarine/gtk-3.0/assets/Makefile
desktop-themes/Green-Submarine/metacity-1/Makefile
desktop-themes/Green-Submarine-border/Makefile
desktop-themes/Green-Submarine-border/metacity-1/Makefile
desktop-themes/HighContrastInverse/Makefile
desktop-themes/HighContrastInverse/gtk-2.0/Makefile
desktop-themes/HighContrastInverse/gtk-2.0/gtkrc
desktop-themes/HighContrastInverse/metacity-1/Makefile
desktop-themes/HighContrastInverse/pixmaps/Makefile
desktop-themes/Menta/Makefile
desktop-themes/Menta/cinnamon/Makefile
desktop-themes/Menta/emerald/Makefile
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
desktop-themes/Menta/gtk-3.0/window-controls/Makefile
desktop-themes/Menta/metacity-1/Makefile
desktop-themes/Menta/unity/Makefile
desktop-themes/Menta/xfwm4/Makefile
desktop-themes/Menta-border/Makefile
desktop-themes/Menta-border/metacity-1/Makefile
desktop-themes/TraditionalGreen/Makefile
desktop-themes/TraditionalGreen/gtk-2.0/Makefile
desktop-themes/TraditionalGreen/gtk-3.0/Makefile
desktop-themes/TraditionalGreen/gtk-3.0/img/Makefile
desktop-themes/TraditionalGreen/metacity-1/Makefile
desktop-themes/TraditionalOk/Makefile
desktop-themes/TraditionalOk/gtk-2.0/Makefile
desktop-themes/TraditionalOk/gtk-3.0/Makefile
desktop-themes/TraditionalOk/gtk-3.0/img/Makefile
desktop-themes/TraditionalOk/metacity-1/Makefile
desktop-themes/TraditionalOk/openbox-3/Makefile
desktop-themes/TraditionalOk/xfwm4/Makefile
desktop-themes/TraditionalOk/xfwm4/png/Makefile
marco-themes/Makefile
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
po/Makefile.in
])

AC_OUTPUT

dnl ==========================================================================
echo "
mate-themes-$VERSION:

	Installation prefix:	${prefix}

"
