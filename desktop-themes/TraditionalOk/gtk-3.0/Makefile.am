THEME_NAME=TraditionalOk

themedir = $(datadir)/themes/$(THEME_NAME)/gtk-3.0

theme_DATA = \
	gtk.css \
	settings.ini

%.ini: %.ini.in
	$(AM_V_GEN) sed -e 's|@bindir[@]|$(bindir)|g' $< > $@

EXTRA_DIST = \
	$(theme_DATA) \
	settings.ini.in

CLEAN = \
	settings.ini

SUBDIRS = \
	assets
