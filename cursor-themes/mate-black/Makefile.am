THEME_NAME = mate-black

themedir = $(datadir)/icons/$(THEME_NAME)
theme_in_files = index.theme.in
theme_DATA = $(theme_in_files:.theme.in=.theme)

%.theme: %.theme.in
if USE_NLS
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@
else
	$(AM_V_GEN) cp -f $< $@
endif

SUBDIRS = cursors

CLEANFILES = $(theme_DATA)
EXTRA_DIST = $(theme_in_files)
