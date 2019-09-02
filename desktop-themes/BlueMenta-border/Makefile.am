THEME_NAME=BlueMenta-border
THEME_IN_FILES=index.theme.in

themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = \
	COPYING \
	index.theme \
	README

%.theme: %.theme.in
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@

SUBDIRS =		\
	metacity-1

DISTCLEANFILES = index.theme
EXTRA_DIST = index.theme.in
