THEME_NAME=BlackMATE-border

themedir = $(datadir)/themes/$(THEME_NAME)

$(theme_DATA): $(THEME_IN_FILES)
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@

SUBDIRS = \
	metacity-1

