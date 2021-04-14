# -*- Makefile -*-
# This is a -*- Makefile -*- fragment.
# For terms and provenance see the LICENSE file at the top of this repository.

default:
include @hypogeal_twilight_datarootdir@/mk/compile.mk
# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

DEVELOPMENT_AREAS = \
  $(module_c_prefix) \
  $(module_std_prefix) \
  $(end)
TESTING_AREAS = \
  $(module_cppunit_prefix) \
  $(end)
INSTALLATION_AREAS = \
  $(nonstd_cppunit_prefix) \
  $(nonstd_gcc_prefix) \
  $(std_scold_prefix) \
  $(end)

# NOPE ... you can't say install depends upon check because
# then automake assesses that this is *the* install rule.
#install: check
default: all
# automake needs to see the ::-sense of these (not being occluded in GNUmake include)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::
include @hypogeal_twilight_datarootdir@/mk/distclean.mk
clean-dependencies::
mostlyclean-local clean-local:: clean-dependencies

module_BB_SOURCE_SET = \
  $(lib_librigging_suite_module_la_SOURCES) \
  $(lib_librigging_unit_module_la_SOURCES) \
  $(lib_librigging_bench_module_la_SOURCES) \
  $(lib_librigging_la_SOURCES) \
  $(lib_libwant_la_SOURCES) \
  $(lib_libunit_rigging_module_la_SOURCES) \
  $(lib_libunit_bench_module_la_SOURCES) \
  $(end)
include @hypogeal_twilight_datarootdir@/mk/install.mk # must be after $(module_SOURCE_SET) is defined

include src/rigging/Makefrag.am
include src/rigging/bench/Makefrag.am
# include src/rigging/exec/Makefrag.am
include src/rigging/suite/Makefrag.am
include src/rigging/unit/Makefrag.am
include src/unit/bench/Makefrag.am
include src/unit/rigging/Makefrag.am
include src/want/Makefrag.am
include src/tests/unit/Makefrag.am

# WATCHOUT _ must put rigging-suite before rigging-unit
# WATCHOUT - must put rigging-unit before bench-unit so that 'make install' works
# [[deprecated]] must put unit-rigging before unit-bench so that 'make install' works
# else
#     /bin/sh ./libtool --silent  --mode=install /usr/bin/install -c   lib/libunit-bench-module.la lib/libunit-rigging-module.la '/opt/scold/lib'
#     libtool: install: warning: relinking `lib/libunit-bench-module.la'
#
# else, the exhibition:
#
#     /bin/sh ./libtool --silent  --mode=install /usr/bin/install -p   lib/librigging-unit-module.la lib/librigging-bench-module.la lib/librigging-suite-module.la lib/libunit-rigging-module.la lib/libunit-bench-module.la '/builddir/build/BUILDROOT/echoback-peername-0.4.0-1.t99.fc27.gcc7.x86_64/usr/local/lib64'
#     /usr/bin/ld: cannot find -lrigging-suite-module
#
# The libtool libraries must be installed in the dependency order (shown below)
lib_LTLIBRARIES = \
  $(lib_librigging_suite_module_la) \
  $(lib_librigging_unit_module_la) \
  $(lib_librigging_bench_module_la) \
  $(NOT_lib_librigging_exec_module_la_NOT) \
  $(lib_libunit_rigging_module_la) \
  $(lib_libunit_bench_module_la) \
  $(end)
noinst_LTLIBRARIES = \
  $(lib_librigging_la) \
  $(lib_libwant_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(end)
check_LTLIBRARIES = \
  $(end)

$(lib_LTLIBRARIES) : $(noinst_LTLIBRARIES)
$(bin_PROGRAMS) : $(lib_LTLIBRARIES)
$(check_LTLIBRARIES) : $(lib_LTLIBRARIES)
$(check_PROGRAMS) : $(check_LTLIBRARIES) $(lib_LTLIBRARIES)

# dependencies not otherwise entailed in the above
# new school "the rigging", a.k.a. "the [test] rigging"
$(lib_librigging_unit_module_la) : $(lib_librigging_la)
$(lib_librigging_suite_module_la) : $(lib_librigging_la)
$(lib_librigging_unit_module_la) : $(lib_librigging_suite_module_la)
$(lib_librigging_bench_module_la) : $(lib_librigging_unit_module_la)
$(lib_librigging_exec_module_la) : $(lib_librigging_bench_module_la)
# old school <nonsense>"the unit"</nonsense>
$(lib_libunit_rigging_module_la) : $(lib_librigging_unit_module_la)
$(lib_libunit_bench_module_la) : $(lib_librigging_bench_module_la)

include tests/Makefrag.am
include tests/bench/Makefrag.am
include tests/suite/Makefrag.am
include tests/test/Makefrag.am
include tests/want/Makefrag.am
TESTS = \
  $(tests_TEST) \
  $(tests_want_TEST) \
  $(tests_test_TEST) \
  $(tests_bench_TEST) \
  $(tests_suite_TEST) \
  $(end)

# [[REMOVEWHEN]] [when? when? when??] hypogeal-twilight >= 0.46 has work that supercedes this (and that has been a long time coming)
Makefile_nonstd_PACKAGE_CPPFLAGS_SET = 
Makefile_nonstd_PACKAGE_CFLAGS_SET   = 
Makefile_nonstd_PACKAGE_CXXFLAGS_SET = 
Makefile_nonstd_PACKAGE_LDFLAGS_SET  = 
Makefile_nonstd_CHECK_CPPFLAGS_SET   = @nonstd_cppunit_CPPFLAGS@
Makefile_nonstd_CHECK_CFLAGS_SET     = @nonstd_cppunit_CFLAGS@
Makefile_nonstd_CHECK_CXXFLAGS_SET   = @nonstd_cppunit_CXXFLAGS@
Makefile_nonstd_CHECK_LDFLAGS_SET    = @nonstd_cppunit_LDFLAGS@

# shutup our own deprecation warnings)
# src/tests/unit/want/iterator/Fixture.xcpp:39:33: warning: ‘rigging::suite::detail::Add rigging::suite::add(CppUnit::Test*)’ is deprecated [-Wdeprecated-declarations]
_Wdeprecated_declarations = -Wno-deprecated-declarations

Makefile_COMPILER_CPPFLAGS_SET  = @CPPFLAGS_gcc@ 
Makefile_COMPILER_CFLAGS_SET    =   @CFLAGS_gcc@   @CFLAGS_gdb@
Makefile_COMPILER_CXXFLAGS_SET  = @CXXFLAGS_gcc@ @CXXFLAGS_gdb@
Makefile_COMPILER_LDFLAGS_SET   =  @LDFLAGS_gcc@  @LDFLAGS_gdb@
Makefile_PACKAGE_CPPFLAGS_SET = 
Makefile_PACKAGE_CFLAGS_SET   = 
Makefile_PACKAGE_CXXFLAGS_SET = $(_Wdeprecated_declarations)
Makefile_PACKAGE_LDFLAGS_SET  = 
Makefile_CHECK_CPPFLAGS_SET   = @CPPFLAGS_cppunit@
Makefile_CHECK_CFLAGS_SET     =   @CFLAGS_cppunit@
Makefile_CHECK_CXXFLAGS_SET   = @CXXFLAGS_cppunit@
Makefile_CHECK_LDFLAGS_SET    =  @LDFLAGS_cppunit@

# These are assembled by .../toolflags.mk in hypogeal-twilight >= 0.45
AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))
