THEME_NAME=TraditionalOk

themedir = $(datadir)/themes/$(THEME_NAME)/gtk-3.0

theme_DATA = \
	applications.css \
	gtk.css \
	gtk-widgets.css \
	gtk-widgets-img.css \
	mate-applications.css \
	other-applications.css \
	settings.ini

%.ini: %.ini.in
	$(AM_V_GEN) sed -e 's|@bindir[@]|$(bindir)|g' $< > $@

EXTRA_DIST = \
	$(theme_DATA) \
	settings.ini.in

CLEAN = \
	settings.ini

SUBDIRS = \
	img
