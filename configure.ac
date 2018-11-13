dnl
dnl ./buildconf && ./configure --prefix=$(dirname $(pwd)) && make check
dnl also see ${prefix}/etc/config.site
dnl
dnl autoreconf --force --verbose --install
dnl autoreconf -vfi
dnl
dnl recall: $prefix/etc/config.site can hold predefined settings
dnl
AC_INIT([tuntias-basics], [1.3.0], [/dev/null@oath.com])
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
# there are nos submodules

TF_COMPONENT_METADIRECTORY_TIERS
TF_ENABLE_GNU
TF_ENABLE_GDB
TF_ENABLE_GCC
TF_ENABLE_MOCK_BUILD

TF_WITH_SUBSYSTEM([hypogeal-twilight], [], [The SCOLD Build System])
TF_WITH_SUBSYSTEM([temerarious-flagship], [], [The Tunitas Build System])

# minimize these
TF_WITH_MODULE([httpserver])
TF_WITH_MODULE([nonstd])
TF_WITH_MODULE([options])
TF_WITH_MODULE([posix])
TF_WITH_MODULE([std])
TF_WITH_MODULE([string])

TF_WITH_MODULE([cppunit])
TF_WITH_MODULE([rigging], [], [Unit (test) Rigging])

TF_MSG_VERBOSE([compiler-specific (alphabetical)])
TF_WITH_NONSTD([cppunit])
TF_WITH_NONSTD([gcc])
TF_WITH_NONSTD([libhttpserver])

TF_WITH_STD([scold])
TF_WITH_STD([tunitas])

LT_PREREQ([2.4.2])
AM_PROG_AR dnl must be first
LT_INIT    dnl mut be second
AC_PROG_CC
AC_PROG_CXX
AM_PROG_CC_C_O

TF_PROG_DC
TF_CHECK_STD_FILESYSTEM

dnl WATCHOUT if AC_OUTPUT is not called (transitively from TF_FINALIZE) then
dnl you will see the fantastically cryptic error
dnl
dnl    Error .../am/check2.am: error: am__EXEEXT does not appear in AM_CONDITIONAL
dnl
dnl See http://silas.net.br/tech/devel/autotools.html
dnl <best-estimate>add the required AC_OUTPUT macro to configure.ac (or configure.in)?</best-estimate>
TF_FINALIZE
