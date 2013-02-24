SUBDIRS = \
   gtk-3.0 \
   gtk-2.0 \
   metacity-1

THEME_NAME=ContrastHigh

themedir = $(datadir)/themes/$(THEME_NAME)

noinst_PROGRAMS =
if GTK3
noinst_PROGRAMS += create-contrasthigh
endif

create_contrasthigh_SOURCES = create-contrasthigh.c
create_contrasthigh_CFLAGS = $(CONTRASTHIGH_CFLAGS)
create_contrasthigh_LDADD = $(CONTRASTHIGH_LIBS) -lm

-include $(top_srcdir)/git.mk
