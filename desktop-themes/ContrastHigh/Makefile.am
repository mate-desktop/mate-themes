THEME_NAME=ContrastHigh
 
themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = index.theme

EXTRA_DIST = $(theme_DATA)

SUBDIRS = \
   gtk-3.0 \
   gtk-2.0 \
   metacity-1

DIST_SUBDIRS = \
   gtk-3.0 \
   gtk-2.0 \
   metacity-1

CLEANFILES = index.theme

index.theme: index.theme.in
	$(AM_V_GEN)sed \
		-e s!\@BACKGROUND_DIR\@!$(datadir)/backgrounds/mate/abstract! \
		< $< > $@

