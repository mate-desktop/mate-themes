THEME_NAME=GreenLaguna-border

themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = \
	COPYING

%.theme: %.theme.in
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@

SUBDIRS = \
	metacity-1

