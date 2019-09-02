THEME_NAME=GreenLaguna
THEME_IN_FILES=index.theme.in

themedir = $(datadir)/themes/$(THEME_NAME)

theme_DATA = \
	COPYING \
	index.theme \
	README

%.theme: %.theme.in
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@

SUBDIRS =		\
	gtk-2.0		\
	gtk-3.0		\
	metacity-1  \
	unity

DISTCLEANFILES = index.theme
EXTRA_DIST = index.theme.in
