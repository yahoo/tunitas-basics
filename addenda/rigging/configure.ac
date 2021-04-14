# -*- autoconf -*-
# For terms and provenance see the LICENSE file at the top of this repository.

AC_INIT([module-rigging], [0.12.0], [administrator@tunitas.technologies])
HGTW_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)
HGTW_COMPONENT_METADIRECTORY_TIERS
HGTW_ENABLE_CONFIGURE_VERBOSE dnl first to --enable-configure-verbose
HGTW_ENABLE_GCC
HGTW_ENABLE_GDB
HGTW_ENABLE_GNU
HGTW_ENABLE_MOCK_BUILD dnl is still required to make some ./mk/*.mk

HGTW_MSG_VERBOSE([development subsystems (alphabetical)])
HGTW_WITH_MODULE([c])
HGTW_WITH_MODULE([std])

HGTW_MSG_VERBOSE([testing subsystems (alphabetical)])
HGTW_WITH_MODULE([cppunit])

HGTW_MSG_VERBOSE([compiler-specific subsystems (alphabetical)])
HGTW_WITH_NONSTD([cppunit], [cppunit], [a non-standard CppUnit])
HGTW_WITH_NONSTD([gcc], [gcc], [a non-standard gcc, e.g. modernized gcc for C++11, C++14, C++17 and on unto C++2a])

HGTW_MSG_VERBOSE([system-side subsystems (alphabetical)])
HGTW_WITH_COMPONENT([hypogeal-twilight], [hypogeal_twilight], [SCOLD autotools scaffolding])
HGTW_WITH_COMPONENT([incendiary-sophist], [incendiary_sophist], [SCOLD test scaffolding])
HGTW_WITH_COMPONENT([vernacular-doggerel], [vernacular_doggerle], [SCOLD rpmbuild scaffolding])

AC_CONFIG_SRCDIR([src/unit/rigging/Usage.xcpp])
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
HGTW_CHECK_PACKAGE([std.ostream_joiner], [module-std-devel])
HGTW_CHECK_PACKAGE([cppunit.text.ProgressListener], [cppunit-devel])
if false ; then
AC_CHECK_HEADER([cppunit.text.ProgressListener], [: ok],
                [AC_MSG_ERROR([cannot find module cppunit.text.ProgressListener])],
                [-I${module_cppunit_prefix}/modules -I${module_cppunit_prefix}/include -I${module_cppunit_prefix}/obj/modules
                 ${nonstd_cppunit_includedir:+-I${nonstd_cppunit_includedir}}])
fi
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

HGTW_FINALIZE
