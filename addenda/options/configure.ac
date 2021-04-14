# -*- autoconf -*-
# For terms and provenance see the LICENSE file at the top of this repository.

dnl see the nearby ChangeLog for the details on the versions
dnl via semver.org
dnl
dnl    MAJOR version when you make incompatible API changes,
dnl    MINOR version when you add functionality in a backwards-compatible manner,
dnl    PATCH version when you make backwards-compatible bug fixes.
dnl
AC_INIT([module-options], [0.16.0], [administrator@scold-lang.org])
HGTW_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)

# --with-nearby=DIRECTORY       e.g. /build/scold                        many other modules; may be 'no'
# --with-siblings=DIRECTORY     e.g. ..                                  next door; may be 'no'
# --with-submodules=DIRECTORY   e.g. ./submodules (older: ./exteranl)    the submodules area (is misnamed)
# --with-std-scold=ROOT         e.g. /opt/scold, /usr/local/scold        the single directory tree
HGTW_COMPONENT_METADIRECTORY_TIERS

HGTW_ENABLE_CONFIGURE_VERBOSE dnl first to --enable-configure-verbose
HGTW_ENABLE_GCC
HGTW_ENABLE_GDB
HGTW_ENABLE_GNU
HGTW_ENABLE_MOCK_BUILD dnl needed to create something in mk/*.mk

HGTW_MSG_VERBOSE([development subsystems (alphabetical)])
HGTW_WITH_MODULE([c])
HGTW_WITH_MODULE([std])
HGTW_WITH_MODULE([nonstd])
HGTW_WITH_MODULE_ALIASED([string], [c-string])
HGTW_WITH_MODULE([sys])

HGTW_MSG_VERBOSE([testing subsystems (alphabetical)])
HGTW_WITH_MODULE([cppunit])
HGTW_WITH_MODULE_ALIASED([rigging], [rigging-unit], [unit-rigging])

HGTW_MSG_VERBOSE([compiler-specific subsystems (alphabetical)])
dnl --with-std-scold is entailed above
HGTW_WITH_NONSTD([cppunit], [cppunit], [a non-standard CppUnit])
HGTW_WITH_NONSTD([gcc], [gcc], [a non-standard GCC, e.g. modernized gcc for C++11, C++14, C++17 and on unto C++2a])

HGTW_MSG_VERBOSE([system-side subsystems (alphabetical)])
HGTW_WITH_COMPONENT([hypogeal-twilight], [hypogeal_twilight], [SCOLD autotools scaffolding])
HGTW_WITH_COMPONENT([vernacular-doggerel], [vernacular_doggerel], [SCOLD rpmbuild scaffolding])

AC_CONFIG_SRCDIR([src/options/Program.xcpp])
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
HGTW_CHECK_GCC
# Checks for packages
HGTW_CHECK_CPPUNIT
# Checks for libraries.
# Checks for header files.
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

HGTW_FINALIZE
