SUBDIRS = \
	16x16 \
	22x22 \
	24x24 \
	32x32 \
	48x48 \
	256x256 \
	scalable

indexthemedir = $(datadir)/icons/ContrastHigh
indextheme_DATA = index.theme
indextheme_in_files = $(indextheme_DATA:.theme=.theme.in)

%.theme: %.theme.in
if USE_NLS
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@
else
	$(AM_V_GEN) cp -f $< $@
endif

CLEANFILES = $(indextheme_DATA)
EXTRA_DIST = $(indextheme_in_files)
