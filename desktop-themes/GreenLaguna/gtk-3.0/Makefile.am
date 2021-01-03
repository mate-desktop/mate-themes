THEME_NAME=GreenLaguna

themedir = $(datadir)/themes/$(THEME_NAME)/gtk-3.0

theme_DATA = \
	gnome-applications.css \
	gtk.css \
	gtk-main.css \
	gtk-widgets.css \
	gtk-widgets-assets.css \
	mate-applications.css \
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
	window-controls

