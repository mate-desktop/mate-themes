THEME_NAME = HighContrastInverse

themedir = $(datadir)/themes/$(THEME_NAME)
theme_in_files = index.theme.in
theme_DATA = $(theme_in_files:.theme.in=.theme)

%.theme: %.theme.in
if USE_NLS
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@
else
	$(AM_V_GEN) cp -f $< $@
endif

SUBDIRS =      \
	gtk-2.0	   \
	metacity-1 \
	pixmaps

CLEANFILES = index.theme
EXTRA_DIST = $(theme_in_files)
