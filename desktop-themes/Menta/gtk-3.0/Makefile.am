themedir = $(datadir)/themes/Menta/gtk-3.0

theme_DATA = \
	gnome-applications.css \
	mate-applications.css \
	gtk.css \
	gtk-fallback.css \
	gtk-main.css \
	gtk-main-common.css \
	gtk-widgets.css \
	gtk-widgets-assets.css \
	gtk-widgets-backgrounds.css \
	gtk-widgets-borders.css \
	other-applications.css \
	settings.ini \
	unity.css \
	window-controls.css

%.ini: %.ini.in
	$(AM_V_GEN) sed -e 's|@bindir[@]|$(bindir)|g' $< > $@

EXTRA_DIST = \
	$(theme_DATA) \
	settings.ini.in

CLEAN = \
	settings.ini

SUBDIRS = \
	assets \
	borders \
	window-controls
