# -*- autoconf -*-
# Copyright Verizon Media.
# Licensed under the terms of the Apache-2.0 license.
# For terms, see the license file at the top of this repository.
# Also the LICENSE file at https://github.com/yahoo/tunitas-packaging/blob/master/LICENSE (as available)
# Also the LICENSE file at https://git.tunitas.technology/all/components/$PACKAGE/tree/LICENSE (as available)

AC_INIT([module-uuid], [0.5.0], [operator@tunitas.technologies])
HGTW_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)
HGTW_COMPONENT_METADIRECTORY_TIERS

HGTW_ENABLE_CONFIGURE_VERBOSE dnl first to --enable-configure-verbose
HGTW_ENABLE_GCC
HGTW_ENABLE_GDB
HGTW_ENABLE_GNU
HGTW_ENABLE_MOCK_BUILD dnl still needed to create something in mk/*.mk

HGTW_MSG_VERBOSE([development subsystems (alphabetical)])
HGTW_WITH_MODULE([c])
HGTW_WITH_MODULE([posix])
HGTW_WITH_MODULE([std])
HGTW_WITH_MODULE_ALIASED([string], [c-string])
HGTW_WITH_MODULE([sys])

HGTW_MSG_VERBOSE([testing subsystems (alphabetical)])
HGTW_WITH_MODULE([cppunit])
HGTW_WITH_MODULE_ALIASED([rigging], [rigging-unit], [unit-rigging])

HGTW_MSG_VERBOSE([compiler-specific subsystems (alphabetical)])
HGTW_WITH_NONSTD([cppunit], [cppunit], [a non-standard CppUnit])
HGTW_WITH_NONSTD([gcc], [gcc], [a non-standard GCC, e.g. modernized gcc for C++11, C++14, C++17, and on unto C++2a])
HGTW_WITH_NONSTD([uuid], [uuid], [non-standard UUID, teach the controversy: uuid vs libuuid])
HGTW_WITH_STD([scold], [scold], [The standard SCOLD installation area])

HGTW_MSG_VERBOSE([system-side subsystems (alphabetical)])
HGTW_WITH_HYPOGEAL_TWILIGHT
HGTW_WITH_INCENDIARY_SOPHIST

AC_CONFIG_SRCDIR([src/uuid/namespace.xcpp])
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
HGTW_CHECK_UUID
# Checks for libraries.
# Checks for header files.
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

HGTW_FINALIZE
