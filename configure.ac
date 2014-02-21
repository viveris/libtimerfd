#  Copyright (c) 2013-2014, Viveris Technologies
#  All rights reserved.
#  
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are met: 
#  
#  1. Redistributions of source code must retain the above copyright notice, this
#     list of conditions and the following disclaimer. 
#  2. Redistributions in binary form must reproduce the above copyright notice,
#     this list of conditions and the following disclaimer in the documentation
#     and/or other materials provided with the distribution. 
#  
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
#  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
#  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
