THEME_NAME = TraditionalGreen

theme_in_files = index.theme.in
themedir = $(datadir)/themes/$(THEME_NAME)
theme_DATA = COPYING index.theme

%.theme: %.theme.in
if USE_NLS
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@
else
	$(AM_V_GEN) cp -f $< $@
endif

SUBDIRS =		\
	gtk-3.0		\
	metacity-1
if ENABLE_GTK2
SUBDIRS += gtk-2.0
endif
DIST_SUBDIRS =		\
	gtk-2.0		\
	gtk-3.0		\
	metacity-1

CLEANFILES = index.theme
EXTRA_DIST = $(theme_in_files)
