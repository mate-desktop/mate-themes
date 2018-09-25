THEME_NAME=	BlackMATE
THEME_IN_FILES=index.theme.in

@INTLTOOL_THEME_RULE@
 
themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = \
	COPYING \
	index.theme \
	README

SUBDIRS =		\
	gtk-3.0		\
	metacity-1	\
	cinnamon    \
	unity       \
	apps

DISTCLEANFILES = index.theme
EXTRA_DIST = index.theme.in
