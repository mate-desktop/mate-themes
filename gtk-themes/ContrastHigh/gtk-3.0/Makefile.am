gtk.gresource: gtk.gresource.xml  $(shell $(GLIB_COMPILE_RESOURCES) --generate-dependencies $(srcdir)/gtk.gresource.xml)
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES) --target=$@ --sourcedir=$(srcdir)  $<

themedir = $(datadir)/themes/ContrastHigh/gtk-3.0
theme_DATA = \
	gtk.css \
	gtk.gresource \
	settings.ini

EXTRA_DIST = \
	gtk.css \
	gtk-widgets.css \
	gtk.gresource.xml \
	settings.ini

CLEANFILES = \
	gtk.gresource

-include $(top_srcdir)/git.mk
