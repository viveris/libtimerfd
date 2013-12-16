################################################################################
#	Name       : Makefile
#	Author     : Didier Barvaux <didier.barvaux@toulouse.viveris.com>
#	Description: create the libtimerfd library and its tests
################################################################################

if BUILD_TESTS
TESTS_DIR = tests
else
TESTS_DIR = 
endif

SUBDIRS = src $(TESTS_DIR)

dist_doc_DATA = \
	README \
	INSTALL \
	COPYING \
	AUTHORS \
	ChangeLog

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = timerfd.pc

# configure options for distcheck
DISTCHECK_CONFIGURE_FLAGS = \
	--enable-fail-on-warning \
	--enable-fortify-sources \
	--enable-tests

# extra files for releases
EXTRA_DIST = \
	autogen.sh

