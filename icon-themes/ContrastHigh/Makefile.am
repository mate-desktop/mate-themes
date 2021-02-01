indexthemedir =	$(datadir)/icons/ContrastHigh/

SUBDIRS = \
	16x16 \
	22x22 \
	24x24 \
	32x32 \
	48x48 \
	256x256 \
	scalable

indextheme_DATA = index.theme
indextheme_in_files = $(indextheme_DATA:.theme=.theme.in)

$(indextheme_DATA): $(indextheme_in_files)
	$(AM_V_GEN) $(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@

CLEANFILES = $(indextheme_DATA)
EXTRA_DIST = $(indextheme_in_files)
