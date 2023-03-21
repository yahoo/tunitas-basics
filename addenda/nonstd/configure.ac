# -*- autoconf -*-
# For terms and provenance see the LICENSE file at the top of this repository.

AC_INIT([module-nonstd], [0.6.0], [administrator@scold-lang.org])
HGTW_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)
m4_include([ac/check-half.m4])

# --with-nearby=DIRECTORY       e.g. /build/scold                        many other modules; may be given as 'no'
# --with-siblings=DIRECTORY     e.g. ..                                  next door; may be given as 'no'
# --with-submodules=DIRECTORY   e.g. ./submodules (older: ./exteranl)    the submodules area
# --with-std-scold=ROOT         e.g. /opt/scold, /usr/local/scold        the single directory tree
HGTW_COMPONENT_METADIRECTORY_TIERS

HGTW_ENABLE_CONFIGURE_VERBOSE dnl first to --enable-configure-verbose
HGTW_ENABLE_GCC
HGTW_ENABLE_GDB
HGTW_ENABLE_GNU
HGTW_ENABLE_LIBTOOL_NO_INSTALL
HGTW_ENABLE_MOCK_BUILD dnl still needed to produce something in mk/*.mk

HGTW_MSG_VERBOSE([development subsystems (alphabetical)])
HGTW_WITH_MODULE([c])
dnl this package MUST NOT depend upon module-format
HGTW_WITH_MODULE([half])
HGTW_WITH_MODULE([std])
HGTW_WITH_MODULE_ALIASED([string], [c-string])
HGTW_WITH_MODULE([want])

HGTW_MSG_VERBOSE([testing subsystems (alphabetical)])
HGTW_WITH_MODULE([cppunit])
HGTW_WITH_MODULE_ALIASED([rigging], [rigging-unit], [unit-rigging])

HGTW_MSG_VERBOSE([compiler-specific subsystems (alphabetical)])
HGTW_WITH_NONSTD([cppunit], [cppunit], [a non-standard CppUnit])
HGTW_WITH_NONSTD([gcc], [gcc], [a non-standard gcc, i.e.. modern gcc for C++26, but at least C++23])
HGTW_WITH_NONSTD([half], [half], [a non-standard Half-Float IEEE476])
HGTW_WITH_STD([scold], [scold], [The standard SCOLD installation area])

HGTW_MSG_VERBOSE([system-side subsystems (alphabetical)])
HGTW_WITH_COMPONENT([hypogeal-twilight], [hypogeal_twilight], [SCOLD autotools scaffolding])
HGTW_WITH_COMPONENT([vernacular-doggerel], [vernacular_doggerel], [SCOLD rpmbuild scaffolding])
HGTW_WITH_COMPONENT([incendiary-sophist], [incendiary_sophist], [SCOLD autotools test scaffolding])

AC_CONFIG_SRCDIR([src/nonstd/namespace.xcpp])
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
HGTW_CHECK_CPPUNIT dnl actually only needed for the test drivers
HGTW_CHECK_HALF
# Checks for libraries.
HGTW_CHECK_STD_FILESYSTEM
# Checks for header files.
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

HGTW_FINALIZE
