################################################################################
# Name       : Makefile
# Author     : Didier Barvaux <didier.barvaux@toulouse.viveris.com>
# Description: create the libtimerfd tests
################################################################################


TESTS = \
	test_timerfd_create \
	test_timerfd_settime

check_PROGRAMS = \
	test_timerfd_create \
	test_timerfd_settime


test_timerfd_create_SOURCES = \
	test_timerfd_create.c
test_timerfd_create_CFLAGS = \
	$(configure_cflags)
test_timerfd_create_CPPFLAGS = \
	-I$(top_srcdir)/src/include
test_timerfd_create_LDADD = \
	-ltimerfd
test_timerfd_create_LDFLAGS = \
	$(configure_ldflags) \
	-L$(top_builddir)/src/.libs


test_timerfd_settime_SOURCES = \
	test_timerfd_settime.c
test_timerfd_settime_CFLAGS = \
	$(configure_cflags)
test_timerfd_settime_CPPFLAGS = \
	-I$(top_srcdir)/src/include
test_timerfd_settime_LDADD = \
	-ltimerfd
test_timerfd_settime_LDFLAGS = \
	$(configure_ldflags) \
	-L$(top_builddir)/src/.libs

