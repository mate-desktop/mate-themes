THEME_NAME = YaruOk

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
	gtk-2.0		\
	gtk-3.0		\
	metacity-1	\
	openbox-3	\
	xfwm4

CLEANFILES = index.theme
EXTRA_DIST = $(theme_in_files)
