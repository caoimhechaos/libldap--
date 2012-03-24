#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([libldap++], [1.0], [admins@ffii.org])
AM_INIT_AUTOMAKE
LT_INIT
AC_CONFIG_SRCDIR([connection.cc])
AC_CONFIG_HEADERS([config.h])

AC_ARG_WITH([openldap], [AC_HELP_STRING([--with-openldap=DIR], [Path to the OpenLDAP library])],
	[INCLUDES="$INCLUDES -I${withval}/include"; LDFLAGS="${LDFLAGS} -L${withval}/lib -R${withval}/lib"])
CPPFLAGS="$CPPFLAGS $INCLUDES"

# Checks for programs.
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_PROG_SED

AC_LANG(C++)

LIBRARY_VERSION=`echo $VERSION | $SED -e's/\./:/g'`
AC_SUBST(LIBRARY_VERSION)

OLDCXXFLAGS="$CXXFLAGS"
CXXFLAGS="$CXXFLAGS -std=c++0x"
AC_MSG_CHECKING([whether $CXX accepts -std=c++0x])
AC_LINK_IFELSE([AC_LANG_CALL([], [main])], [AC_MSG_RESULT(yes)], [AC_MSG_RESULT(no); CXXFLAGS="$OLDCXXFLAGS"])
unset OLDCXXFLAGS
AC_SUBST(AC_CXXFLAGS)

# Checks for libraries.
AC_CHECK_LIB([ldap], [main], [AC_LIBS="-lldap $AC_LIBS"], AC_ERROR([libldap is required]))
LIBS="$LIBS $AC_LIBS"
AC_SUBST(AC_LIBS)
AC_SUBST(LIBS)

# Checks for header files.
AC_CHECK_HEADER([ldap.h], [], AC_ERROR([OpenLDAP headers not found]))
AC_CHECK_HEADERS([ldif.h], [], [],
[
#include <stdio.h>
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <lber.h>
#include <ldif.h>
])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS(ldap_create_page_control_value ldap_control_find \
	       ldap_parse_pageresponse_control ldap_alloc_ber_with_options)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
