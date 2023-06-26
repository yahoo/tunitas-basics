dnl This is a GNU -*- autoconf -*- specification that is processed by Autoconf.
dnl Copyright Yahoo Inc, 2021.
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
AC_INIT([tunitas-basics], [2.2.0], [tunitas@yahooinc.com])
TF_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)
AM_SILENT_RULES([yes]) dnl See the AUTOMAKE_OPTIONS in the Makefile.am

AC_CONFIG_SRCDIR([src/tunitas/namespace.xcpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_MACRO_DIRS([m4 ac])
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
TF_WITH_SUBSYSTEM([microhttpd++], [], [Micro HTTPd Server])

TF_WITH_NONSTD([boost])
TF_WITH_MODULE([boost])
TF_WITH_NONSTD([gmp])
TF_WITH_NONSTD([half])
TF_WITH_MODULE([half])
TF_WITH_MODULE([langu])
TF_WITH_MODULE([nonstd])
TF_WITH_MODULE([cli-core])
TF_WITH_MODULE([sys])

dnl [[deprecating]] having been subsumed into the v2-series APIS of langu, nonstd, options, sys
TF_WITH_MODULE([cli])
TF_WITH_MODULE([format])
TF_WITH_MODULE([ip])
TF_WITH_MODULE([options])
TF_WITH_MODULE([posix])
TF_WITH_MODULE([std])
TF_WITH_MODULE([string])

TF_WITH_NONSTD([cppunit])
TF_WITH_MODULE([cppunit])
TF_WITH_MODULE([rigging-core])
TF_WITH_MODULE([rigging])

TF_MSG_VERBOSE([compiler-specific (alphabetical)])
TF_WITH_NONSTD([gcc])

TF_WITH_OPT([scold])
TF_WITH_OPT([tunitas])

AC_PREREQ([2.71])
LT_PREREQ([2.4.7])
LT_INIT
AC_LANG([C++])
AC_PROG_CC
AC_PROG_CXX
AM_PROG_CC_C_O

TF_PROG_DC dnl the S.C.O.L.D. disaggregation compiler
TF_PROG_GCC dnl the correct enfreshend gcc ... we want the one closest to C++23 ...   gcc11 or gcc12 or gcc13
TF_CHECK_STD_FILESYSTEM dnl defines @libstd_filesystem@
TF_CHECK_BOOST
TF_CHECK_CPPUNIT dnl defines toolflags of cppunit, @CPPFLAGS_cppunit@, @CXXFLAGS_cppunit@, @LDFLAGS_cppunit@, etc.
TF_CHECK_GMP_CXX
TF_CHECK_HALF

dnl [[FIXTHIS,TODO]] move this into a captured macro, e.g. TF_CHECK_PACKAGE([microhttpd++-devel]) ... or such
dnl Just one (1) of these should be enough to probe that (package) microhttpd++-devel is installed, but just in case.
dnl this checkes whether libhttpd++devel is installed by probing to see if the "module-as-#include-header" so named exists for compilation
TF_CHECK_PACKAGES([microhttpd microhttpd.Daemon microhttpd.Render microhttpd.Request microhttpd.Response microhttpd.Router microhttpd.Service], [microhttpd++-devel])

dnl gmp-6.2.1
dnl Specimen:
dnl
dnl   gmp-6.2.1-3.fc37.x86_64
dnl   gmp-c++-6.2.1-3.fc37.x86_64
dnl   gmp-devel-6.2.1-3.fc37.x86_64
dnl
TF_CHECK_PACKAGES_ERROR([gmpxx.h], [gmp-devel])

dnl boost-1.78
dnl Specimen:
dnl
dnl   boost-devel-1.78.0-9.fc37.x86_64
dnl
CPPFLAGS="${CPPFLAGS} ${module_boost_prefix:+-I${module_boost_prefix?}/modules -I${module_boost_prefix?}/include} ${nonstd_boost_prefix:+-I${nonstd_boost_prefix?}/include}" # [[FIXTHIS]] fix TF_CHECK_PACKAGES to be cognizant of the now-accreted searchpath
TF_CHECK_PACKAGES_ERROR([boost/multiprecision/cpp_int.hpp], [boost-devel])
TF_CHECK_PACKAGES_ERROR([boost.multiprecision.cpp_int], [module-boost])

dnl nonstd-half
dnl Specimen:
dnl
dnl   nonstd-half-1.12.0-2.0.fc31.gcc9.x86_64
dnl   nonstd-half-devel-1.12.0-2.0.fc31.gcc9.x86_64
dnl
CPPFLAGS="${CPPFLAGS} ${module_half_prefix:+-I${module_half_prefix?}/modules -I${module_half_prefix?}/include} ${nonstd_half_prefix:+-I${nonstd_half_prefix?}/include}" # [[FIXTHIS]] fix TF_CHECK_PACKAGES to be cognizant of the now-accreted searchpath
TF_CHECK_PACKAGES_ERROR([half/half.hpp], [nonstd-half-devel])

dnl WATCHOUT if AC_OUTPUT is not called (transitively from TF_FINALIZE) then
dnl you will see the fantastically cryptic error
dnl
dnl    Error .../am/check2.am: error: am__EXEEXT does not appear in AM_CONDITIONAL
dnl
dnl See http://silas.net.br/tech/devel/autotools.html
dnl <best-estimate>add the required AC_OUTPUT macro to configure.ac (or configure.in)?</best-estimate>
TF_FINALIZE
