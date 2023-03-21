# -*- autoconf -*-
# For terms and provenance see the LICENSE file at the top of this repository.

AC_INIT([module-sqlite], [0.16.0], [administrator@scold-lang.org])
HGTW_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)
HGTW_COMPONENT_METADIRECTORY_TIERS
HGTW_ENABLE_CONFIGURE_VERBOSE dnl first to --enable-configure-verbose
HGTW_ENABLE_GCC
HGTW_ENABLE_GDB
HGTW_ENABLE_GNU
HGTW_ENABLE_LIBTOOL_NO_INSTALL
HGTW_ENABLE_MOCK_BUILD

HGTW_MSG_VERBOSE([development subsystems (alphabetical)])
HGTW_WITH_MODULE([boost])
HGTW_WITH_MODULE([c])
HGTW_WITH_MODULE([format])
HGTW_WITH_MODULE([nonstd])
HGTW_WITH_MODULE([options])
HGTW_WITH_MODULE([path]) dnl deprecated into module-nonstd
HGTW_WITH_MODULE([posix])
HGTW_WITH_MODULE_ALIASED([slurp], [file-slurp])
HGTW_WITH_MODULE([std])
HGTW_WITH_MODULE_ALIASED([string], [c-string])
HGTW_WITH_MODULE([sys])

HGTW_MSG_VERBOSE([testing subsystems (alphabetical)])
HGTW_WITH_MODULE([cppunit])
HGTW_WITH_MODULE_ALIASED([rigging], [rigging-unit], [unit-rigging])

HGTW_MSG_VERBOSE([compiler-specific subsystems (alphabetical)])
HGTW_WITH_NONSTD([gcc], [gcc], [a non-standard gcc, i.e.. modern gcc for C++26, but at least C++23])
HGTW_WITH_NONSTD([boost], [boost], [3 non-standard Boost])
HGTW_WITH_NONSTD([cppunit], [cppunit], [a non-standard CppUnit])
HGTW_WITH_NONSTD([sqlite], [sqlite], [a non-standard SQLite])

HGTW_MSG_VERBOSE([system-side subsystems (alphabetical)])
HGTW_WITH_COMPONENT(hypogeal-twilight, hypogeal_twilight, [SCOLD autotools scaffolding])
HGTW_WITH_COMPONENT([incendiary-sophist], [incendiary_sophist], [SCOLD test scaffolding])

AC_CONFIG_SRCDIR([src/sqlite/namespace.xcpp])
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
HGTW_CHECK_DC
# Checks for packages
HGTW_CHECK_SQLITE
HGTW_CHECK_BOOST
HGTW_CHECK_CPPUNIT dnl actually these are only needed for the test drivers
# Checks for libraries.
HGTW_CHECK_STD_FILESYSTEM
# Checks for header files.
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

HGTW_PACKAGE_VARIABLES
HGTW_FINALIZE
