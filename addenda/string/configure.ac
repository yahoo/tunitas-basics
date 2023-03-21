# -*- autoconf -*-
# Copyright Yahoo Inc. 2021.
# Licensed under the terms of the Apache-2.0 license.
# For terms, see the license file at the top of this repository.
# Also the LICENSE file at https://github.com/yahoo/tunitas-packaging/blob/master/LICENSE (as available)
# Also the LICENSE file at https://git.tunitas.technology/all/components/$PACKAGE/tree/LICENSE (as available)

AC_INIT([module-string], [0.14.0], [operator@tunitas.technologies])
HGTW_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)

# --with-nearby=DIRECTORY       e.g. /build/scold                    an areas of many other modules
# --with-siblings=DIRECTORY     e.g. ..                              an areas of co-developed modules
# --with-submodules=DIRECTORY   e.g. ./submodules                    the submodules area
# --with-std-scold=ROOT         e.g. /opt/scold, /usr/local/scold    the single directory tree
HGTW_COMPONENT_METADIRECTORY_TIERS

HGTW_ENABLE_CONFIGURE_VERBOSE dnl first to --enable-configure-verbose
HGTW_ENABLE_GCC
HGTW_ENABLE_GDB
HGTW_ENABLE_GNU
HGTW_ENABLE_MOCK_BUILD

HGTW_MSG_VERBOSE([development subsystems (alphabetical)])
HGTW_WITH_MODULE([c])
HGTW_WITH_MODULE([std])

HGTW_MSG_VERBOSE([testing subsystems (alphabetical)])
HGTW_WITH_MODULE([cppunit])
HGTW_WITH_MODULE_ALIASED([rigging], [rigging-unit], [unit-rigging])

HGTW_MSG_VERBOSE([compiler-specific subsystems (alphabetical)])
dnl --with-std-scold is entailed above
HGTW_WITH_NONSTD([cppunit], [cppunit], [a non-standard CppUnit])
HGTW_WITH_NONSTD([gcc], [gcc], [a non-standard gcc, i.e.. modern gcc for C++26, but at least C++23])

HGTW_MSG_VERBOSE([system-side subsystems (alphabetical)])
HGTW_WITH_COMPONENT([hypogeal-twilight], [hypogeal_twilight], [HGTW autotools scaffolding])
HGTW_WITH_COMPONENT([vernacular-doggerel], [vernacular_doggerel], [HGTW rpmbuild scaffolding])

AC_CONFIG_SRCDIR([src/c/argv.xcpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_HEADERS([config.h])

AC_PREREQ([2.69])
AM_PROG_AR             dnl first
AC_PROG_LIBTOOL
AC_PROG_CXX
LT_PREREQ([2.4.2])
LT_INIT                dnl second
AC_LANG([C++])
# Checks for tools
HGTW_CHECK_DC
HGTW_CHECK_GCC
# Checks for packages
HGTW_CHECK_CPPUNIT
# Checks for libraries.
# Checks for header files.
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

HGTW_FINALIZE
