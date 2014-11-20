THEME_NAME=Menta
 
themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = \
	COPYING \
	index.theme \
	README

EXTRA_DIST = $(theme_DATA) index.theme.in

SUBDIRS = \
	cinnamon \
	gtk-2.0	\
	gtk-3.0	\
	metacity-1 \
	unity \
	xfwm4

CLEANFILES = index.theme

index.theme: index.theme.in
	$(AM_V_GEN)sed \
		-e s!\@BACKGROUND_DIR\@!$(datadir)/backgrounds/mate/desktop! \
		< $< > $@
