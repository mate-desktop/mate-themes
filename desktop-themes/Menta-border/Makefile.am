THEME_NAME=Menta-border

themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = \
	COPYING \
	README

%.theme: %.theme.in
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@

SUBDIRS = \
	metacity-1

