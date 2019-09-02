SUBDIRS = \
	po	\
	marco-themes \
	icon-themes \
	desktop-themes \
	cursor-themes

ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

EXTRA_DIST = \
	autogen.sh

DISTCLEANFILES=

# Build ChangeLog from GIT  history
ChangeLog:
	$(AM_V_GEN) if test -d $(top_srcdir)/.git; then \
		GIT_DIR="$(top_srcdir)/.git" git log --stat > $@; \
	fi

dist: ChangeLog

.PHONY: ChangeLog

# we don't want to install mo files, all translations are already stored
# in theme files
install-data-local:
	$(MAKE) -C po uninstall
