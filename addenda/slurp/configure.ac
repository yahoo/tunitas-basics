# -*- autoconf -*-
# For terms and provenance see the LICENSE file at the top of this repository.

AC_INIT([module-slurp], [0.13.0], [administrator@scold-lang.org])
HGTW_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)

# --with-nearby=DIRECTORY       e.g. /build/scold                        many other modules; may be given as 'no'
# --with-siblings=DIRECTORY     e.g. ..                                  next door; may be given as 'no'
# --with-submodules=DIRECTORY   e.g. ./submodules (older: ./exteranl)    the submodules area (is misnamed)
# --with-std-scold=ROOT         e.g. /opt/scold, /usr/local/scold        the single directory tree
HGTW_COMPONENT_METADIRECTORY_TIERS

HGTW_ENABLE_CONFIGURE_VERBOSE dnl first to --enable-configure-verbose
HGTW_ENABLE_GCC
HGTW_ENABLE_GDB
HGTW_ENABLE_GNU
HGTW_ENABLE_LIBTOOL_NO_INSTALL
HGTW_ENABLE_MOCK_BUILD dnl still needed to create something in mk/*.mk

HGTW_MSG_VERBOSE([development subsystems (alphabetical)])
HGTW_WITH_MODULE([c])
HGTW_WITH_MODULE([nonstd])
HGTW_WITH_MODULE([options]) dnl only needed for the test programs (tac, cat, ver, rev)
HGTW_WITH_MODULE([posix])
HGTW_WITH_MODULE([std])
HGTW_WITH_MODULE_ALIASED([string], [c-string])
HGTW_WITH_MODULE([sys])

HGTW_MSG_VERBOSE([testing subsystems (alphabetical)])
HGTW_WITH_MODULE_ALIASED([rigging], [rigging-unit], [unit-rigging])
HGTW_WITH_MODULE([cppunit])

HGTW_MSG_VERBOSE([compiler-specific (alphabetical)])
HGTW_WITH_NONSTD([cppunit], [cppunit], [a non-standard CppUnit])
HGTW_WITH_NONSTD([gcc], [gcc], [a non-standard GCC, i.e.. modern gcc for C++26, but at least C++23])
HGTW_WITH_STD([scold], [scold], [the standard HGTW installation area])

HGTW_MSG_VERBOSE([system-side subsystems (alphabetical)])
HGTW_WITH_COMPONENT([hypogeal-twilight], [hypogeal_twilight], [SCOLD autotools scaffolding])

AC_CONFIG_SRCDIR([src/slurp/file/namespace.xcpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_HEADER([config.h])

AC_PREREQ([2.69])
AM_PROG_AR             dnl first
AC_PROG_LIBTOOL
AC_PROG_CXX
AC_PREREQ([2.69])
LT_PREREQ([2.4.2])
LT_INIT                dnl second
AC_LANG([C++])
# Checks for tools
HGTW_CHECK_GCC
# Checks for packages
HGTW_CHECK_CPPUNIT
# Checks for libraries.
# Checks for header files.
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

HGTW_FINALIZE
