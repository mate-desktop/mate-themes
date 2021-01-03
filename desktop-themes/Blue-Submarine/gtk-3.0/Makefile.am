themedir = $(datadir)/themes/Blue-Submarine/gtk-3.0

theme_DATA = \
	gnome-applications.css \
	gtk.css \
	gtk-widgets-assets.css \
	gtk-widgets.css \
	mate-applications.css \
	menu.css \
	other-applications.css \
	scrollbar.css \
	settings.ini \
	sidebar.css

%.ini: %.ini.in
	$(AM_V_GEN) sed -e 's|@bindir[@]|$(bindir)|g' $< > $@

EXTRA_DIST = \
	$(theme_DATA) \
	settings.ini.in

CLEAN = \
	settings.ini

SUBDIRS = \
	assets

DIST_SUBDIRS = \
	assets
