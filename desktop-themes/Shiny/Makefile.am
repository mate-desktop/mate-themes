THEME_NAME=Shiny
THEME_IN_FILES=index.theme.in

themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = index.theme

DISTCLEANFILES=index.theme
EXTRA_DIST=index.theme.in index.theme

SUBDIRS =	\
	gtk-2.0	\
	gtk-3.0 \
	metacity-1 \
	openbox-3 \
	unity \
	xfwm4

DIST_SUBDIRS = $(SUBDIRS)

%.theme:   %.theme.in $(INTLTOOL_MERGE) $(wildcard $(top_srcdir)/po/*.po) ; $(INTLTOOL_MERGE) $(top_srcdir)/po $< $@ -d -u -c $(top_builddir)/po/.intltool-merge-cache

