THEME_NAME=ContrastHigh
THEME_IN_FILES=index.theme.in

themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = index.theme

$(theme_DATA): $(THEME_IN_FILES)
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@

DISTCLEANFILES = index.theme
EXTRA_DIST = index.theme.in
