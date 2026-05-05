THEME_NAME = Green-Submarine

themedir = $(datadir)/themes/$(THEME_NAME)
theme_in_files = index.theme.in
theme_DATA = $(theme_in_files:.theme.in=.theme)

%.theme: %.theme.in
if USE_NLS
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@
else
	$(AM_V_GEN) cp -f $< $@
endif

SUBDIRS =		\
	cinnamon	\
	emerald		\
	gtk-3.0		\
	metacity-1
if ENABLE_GTK2
SUBDIRS += gtk-2.0
endif
DIST_SUBDIRS =		\
	cinnamon	\
	emerald		\
	gtk-2.0		\
	gtk-3.0		\
	metacity-1

CLEANFILES = index.theme
EXTRA_DIST = $(theme_in_files)
