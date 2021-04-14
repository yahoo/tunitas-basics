# -*- autoconf -*-
# For terms and provenance see the LICENSE file at the top of this repository.

AC_INIT(module-format, 0.18.0, operator@tunitas.technologies)
HGTW_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)

HGTW_COMPONENT_METADIRECTORY_TIERS

HGTW_ENABLE_CONFIGURE_VERBOSE dnl first to --enable-configure-verbose
HGTW_ENABLE_GCC
HGTW_ENABLE_GDB
HGTW_ENABLE_GNU
HGTW_ENABLE_MOCK_BUILD

HGTW_MSG_VERBOSE([development subsystems (alphabetical)])
HGTW_WITH_MODULE([boost])
HGTW_WITH_MODULE([half])
HGTW_WITH_MODULE([nonstd])
HGTW_WITH_MODULE([std])
HGTW_WITH_MODULE_ALIASED([string], [c-string])

HGTW_MSG_VERBOSE([testing subsystems (alphabetical)])
HGTW_WITH_MODULE([cppunit])
HGTW_WITH_MODULE_ALIASED([rigging], [rigging-unit], [unit-rigging])

HGTW_MSG_VERBOSE([compiler-specific (alphabetical)])
HGTW_WITH_NONSTD([boost], [boost], [a non-standard Boost])
HGTW_WITH_NONSTD([cppunit], [cppunit], [a non-standard CppUnit])
HGTW_WITH_NONSTD([gcc], [gcc], [a non-standard GCC, e.g. modernized gcc for C++11, C++14, C++17, and on unto C++2a])
HGTW_WITH_STD(scold, scold, [The standard HGTW installation area])

HGTW_MSG_VERBOSE([system-side subsystems (alphabetical)])
HGTW_WITH_COMPONENT([hypogeal-twilight], [hypogeal_twilight], [HGTW autotools scaffolding])
HGTW_WITH_COMPONENT([vernacular-doggerel], [vernacular_doggerel], [HGTW rpmbuild scaffolding])

AC_CONFIG_SRCDIR([src/format/namespace.xcpp])
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
HGTW_CHECK_CPPUNIT dnl actually only needed for the test drivers
# Checks for libraries.
# Checks for header files.
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

HGTW_FINALIZE
