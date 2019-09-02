THEME_NAME=mate-black
THEME_IN_FILES=index.theme.in

themedir = $(datadir)/icons/$(THEME_NAME)

theme_DATA = \
	index.theme

$(theme_DATA): $(THEME_IN_FILES)
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@

SUBDIRS = \
	cursors

DISTCLEANFILES = index.theme
EXTRA_DIST = index.theme.in
