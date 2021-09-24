# -*- autoconf -*-
# For terms and provenance see the LICENSE file at the top of this repository.

AC_INIT([module-json], [0.10.0], [administrator@scold-lang.org])
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
HGTW_WITH_MODULE([std])
HGTW_WITH_MODULE_ALIASED([string], [c-string])
HGTW_WITH_MODULE([sys])

HGTW_MSG_VERBOSE([testing subsystems (alphabetical)])
HGTW_WITH_MODULE([cppunit])
HGTW_WITH_MODULE_ALIASED([rigging], [rigging-unit], [unit-rigging])

# see .../etc/config.site.in for the defaults for these values
dnl --with-std-scold is entailed above
HGTW_MSG_VERBOSE([compiler-specific (alphabetical)])
HGTW_WITH_NONSTD([boost], [boost], [a non-standard Boost])
HGTW_WITH_NONSTD([cppunit], [cppunit], [a non-standard CppUnit])
HGTW_WITH_NONSTD([gcc], [gcc], [a non-standard GCC, e.g. modernized gcc for C++11, C++14, C++17, C++20, and on unto C++23])
HGTW_WITH_NONSTD([jsoncpp], [jsoncpp], [non-standard JSON C++, e.g. jsoncpp beyond v1.7])
HGTW_WITH_STD([scold], [scold], [The standard SCOLD installation area])

HGTW_MSG_VERBOSE([system-side subsystems (alphabetical)])
HGTW_WITH_HYPOGEAL_TWILIGHT
HGTW_WITH_INCENDIARY_SOPHIST

AC_CONFIG_SRCDIR([src/json/Features.xcpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_HEADERS([config.h])

dnl WATCHOUT they must be built in exactly this order
dnl HGTW_CONFIG_SUBMODULES([external] ... list ... )

AC_PREREQ([2.69])
AM_PROG_AR             dnl first
AC_PROG_LIBTOOL
AC_PROG_CXX
LT_PREREQ([2.4.2])
LT_INIT                dnl second
AC_LANG([C++])
# Checks for packages
HGTW_CHECK_DC
HGTW_CHECK_GCC
# Checks for libraries
HGTW_CHECK_BOOST
HGTW_CHECK_CPPUNIT
HGTW_CHECK_JSONCPP
# Checks for header files.
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

HGTW_FINALIZE
