################################################################################
# Name       : Makefile
# Authors    : Didier Barvaux <didier.barvaux@toulouse.viveris.com>
# Description: create the libtimerfd library
################################################################################

lib_LTLIBRARIES = libtimerfd.la

libtimerfd_la_SOURCES = \
	timerfd.c

libtimerfd_la_LIBADD =

libtimerfd_la_LDFLAGS = \
	$(configure_ldflags) \
	-no-undefined \
	-version-info 0:0:0

libtimerfd_la_CFLAGS = \
	$(configure_cflags)

libtimerfd_la_CPPFLAGS =

sysheadersdir = $(includedir)/sys
sysheaders_HEADERS = include/sys/timerfd.h

bitsheadersdir = $(includedir)/bits
bitsheaders_HEADERS = include/bits/timerfd.h

noinst_HEADERS = syscall.h

