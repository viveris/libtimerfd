#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#
#
# Process this file with autoconf to produce a configure script.
#
# Authors: Didier Barvaux <didier.barvaux@toulouse.viveris.com>
#

AC_INIT([libtimerfd], 1.0.0, [http://opensource.viveris.fr/],
        [libtimerfd], [http://opensource.viveris.fr/])
AC_CONFIG_SRCDIR([src])
AM_CONFIG_HEADER([config.h])

# Define a package homepage in a way compatible with autoconf < 2.64
m4_ifndef([AC_PACKAGE_URL],
          [AC_DEFINE([PACKAGE_URL], ["http://opensource.viveris.fr/"],
                     [Define to home page for this package])
           AC_SUBST([PACKAGE_URL], ["http://opensource.viveris.fr/"])])

# Init automake with:
#  - silent rules enabled to make 'make' less verbose, but do not call the
#    AM_SILENT_RULES macro if it is not defined to keep compatibility with
#    automake < 1.11 for the moment.
#  - color-tests to get nice colored results for tests (currently disabled
#    to keep compatibility with automake 1.10 for the moment.
#  - prefer bzip2 over gzip for dist tarballs
#  - tar-ustar to allow paths that exceeds 99 characters in the dist tarball
AM_INIT_AUTOMAKE([foreign no-dist-gzip dist-bzip2 tar-pax parallel-tests])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Init libtool:
#  - require >= 2.2.0,
#  - disable static libraries by default,
#  - ready for Windows DLL
LT_PREREQ([2.2.0])
LT_INIT([disable-static])

# CFLAGS/LDFLAGS default values, more will be added on purpose
configure_cflags="-g -Wall -Wstrict-prototypes"
configure_ldflags=""

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL

# Checks for header files.
AC_CHECK_HEADERS([time.h])
AC_CHECK_HEADERS([sys/syscall.h])

# check if -Werror must be appended to CFLAGS
AC_ARG_ENABLE(fail_on_warning,
              AS_HELP_STRING([--enable-fail-on-warning],
                             [build fails on warnings if enabled [[default=no]]]),
              fail_on_warning=$enableval,
              fail_on_warning=no)
if test "x$fail_on_warning" != "xno"; then
	configure_cflags="${configure_cflags} -Werror"
fi

# check if -D_FORTIFY_SOURCE=2 must be appended to CFLAGS
AC_ARG_ENABLE(fortify_sources,
              AS_HELP_STRING([--enable-fortify-sources],
                             [build uses -D_FORTIFY_SOURCE=2 if enabled [[default=no]]]),
              fortify_sources=$enableval,
              fortify_sources=no)
if test "x$fortify_sources" != "xno"; then
	configure_cflags="${configure_cflags} -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2"
fi

# check if tests are enabled
AC_ARG_ENABLE(tests,
              AS_HELP_STRING([--enable-tests],
                             [enable tests [[default=no]]]),
              enable_tests=$enableval,
              enable_tests=no)
AM_CONDITIONAL([BUILD_TESTS], [test x$enable_tests = xyes])

# export configure_cflags and configure_ldflags
AC_SUBST([configure_cflags], [$configure_cflags])
AC_SUBST([configure_ldflags], [$configure_ldflags])

AM_DEP_TRACK

AC_CONFIG_FILES([ \
	Makefile \
	src/Makefile \
	tests/Makefile \
	timerfd.pc \
])

AC_OUTPUT
