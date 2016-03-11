THEME_NAME=TraditionalGreen
THEME_IN_FILES=index.theme.in

@INTLTOOL_THEME_RULE@
 
themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = \
	COPYING \
	index.theme

SUBDIRS =		\
	gtk-2.0		\
	gtk-3.0		\
	metacity-1

DISTCLEANFILES = index.theme
EXTRA_DIST = index.theme.in
