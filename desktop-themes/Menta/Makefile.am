THEME_NAME=Menta
 
themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = \
	COPYING \
	index.theme \
	panelbg.png \
	README


EXTRA_DIST = $(theme_DATA)

SUBDIRS = \
	cinnamon \
	gnome-shell \
	gtk-2.0	\
	gtk-3.0	\
	metacity-1 \
	unity \
	xfwm4

DIST_SUBDIRS = \
	cinnamon \
	gnome-shell \
	gtk-2.0	\
	gtk-3.0	\
	metacity-1 \
	unity \
	xfwm4

CLEANFILES = index.theme

index.theme: index.theme.in
	$(AM_V_GEN)sed \
		-e s!\@BACKGROUND_DIR\@!$(datadir)/backgrounds/mate/abstract! \
		< $< > $@
