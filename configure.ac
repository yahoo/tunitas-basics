dnl This is a GNU -*- autoconf -*- specification that is processed by Autoconf.
dnl Copyright 2018, 2019, Oath Inc.; Copyright 2020, Verizon Media
dnl Licensed under the terms of the Apache-2.0 license.
dnl For terms, see the LICENSE file at https://github.com/yahoo/tunitas-basics/blob/master/LICENSE
dnl For terms, see the LICENSE file at https://git.tunitas.technology/all/components/basics/tree/LICENSE
dnl
dnl Build Instructions are in the nearby README.md
dnl
dnl ./maintenance/nearby is a developer-centric build recipe; it guesses about nearby source trees
dnl
dnl ./buildconf && ./configure --prefix=$(dirname $(pwd)) && make check
dnl also see ${prefix}/etc/config.site
dnl
dnl autoreconf --force --verbose --install
dnl autoreconf -vfi
dnl
dnl Reminder: this package is the only one of the tunitas series where the configure.ac has a "tunitas-" prefix.
dnl For example, the other packages are direct place names: butano, grabtown, lobitos, montara, pescadero, rockaway, tarwater.
dnl That not withstanding, the rpm packages all have a "tunitas-" prefix so they can be seen together.
dnl      ^
dnl      |
dnl      \prefix\
dnl      ||||||||
dnl      vvvvvvvv
AC_INIT([tunitas-basics], [2.0.0], [tunitas@verizonmedia.com])
TF_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)

dnl See the AUTOMAKE_OPTIONS in the Makefile.am
AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])

AC_CONFIG_SRCDIR([src/tunitas/namespace.xcpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

# To get submodules to build in place, these go as a pair
#   configure.ac declares TF_CONFIG_SUBMODULES(directory, ...list...)
#   Makefile.am  declares SUBDIRS = @subdirs@
# there are no submodules

TF_COMPONENT_METADIRECTORY_TIERS
TF_ENABLE_GNU
TF_ENABLE_GDB
TF_ENABLE_GCC
TF_ENABLE_LIBTOOL_NO_INSTALL dnl gives @LDFLAGS_no_install@
TF_ENABLE_MOCK_BUILD
TF_ENABLE_LIBTOOL_NO_INSTALL

TF_WITH_SUBSYSTEM([hypogeal-twilight], [], [The SCOLD Build System])
TF_WITH_SUBSYSTEM([temerarious-flagship], [], [The Tunitas Build System])

# minimize these
TF_WITH_MODULE([httpserver]) dnl indeed --with-module-httpserver=DIR  but --with-nonstd-libhttpserver=DIR (the extra "lib" prefix)
TF_WITH_MODULE([nonstd])
TF_WITH_MODULE([options])
TF_WITH_MODULE([posix])
TF_WITH_MODULE([std])
TF_WITH_MODULE([string])
TF_WITH_MODULE([sys]) dnl mostly sys.exits, sys.exits.constants and such

TF_WITH_MODULE([cppunit])
TF_WITH_MODULE([rigging], [], [Unit (test) Rigging])

TF_MSG_VERBOSE([compiler-specific (alphabetical)])
TF_WITH_NONSTD([cppunit])
TF_WITH_NONSTD([gcc])
#
# [[FIXTHIS]] find a way to detect this at configure time rather than just admonishing for it
# [[FIXTHIS]] WATCHOUT - you MUST have ... nonstd-libhttpserver-devel-2:0.9.0-10.1.ipv6+poll+regex+api+tdd or else the unit tests will not compile
# [[FIXTHIS]]            the use of ...... nonstd-libhttpserver-devel-2:0.9.0-9.3.ipv6+poll+regex+api is no longer sufficient
# [[FIXTHIS]]
# [[FIXTHIS]] instead prefer microhttpd++ which is a ground-up rebuild of a server (service) on (lib)microhttpd
#
TF_WITH_NONSTD([libhttpserver]) dnl (from above) the extra "lib" prefix here but not there

TF_WITH_STD([scold])
TF_WITH_STD([tunitas])

LT_PREREQ([2.4.2])
AM_PROG_AR dnl must be first
LT_INIT    dnl must be second
AC_PROG_CC
AC_PROG_CXX
AM_PROG_CC_C_O

TF_PROG_DC dnl the S.C.O.L.D. disaggregation compiler
TF_PROG_GCC dnl the correct enfreshend gcc ... we want the one closest to C++23 ...   gcc11 or gcc12 or gcc13
TF_CHECK_STD_FILESYSTEM dnl defines @libstd_filesystem@
TF_CHECK_CPPUNIT dnl defines toolflags of cppunit, @CPPFLAGS_cppunit@, @CXXFLAGS_cppunit@, @LDFLAGS_cppunit@, etc.

dnl WATCHOUT if AC_OUTPUT is not called (transitively from TF_FINALIZE) then
dnl you will see the fantastically cryptic error
dnl
dnl    Error .../am/check2.am: error: am__EXEEXT does not appear in AM_CONDITIONAL
dnl
dnl See http://silas.net.br/tech/devel/autotools.html
dnl <best-estimate>add the required AC_OUTPUT macro to configure.ac (or configure.in)?</best-estimate>
TF_FINALIZE
