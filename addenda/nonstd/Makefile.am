# This is a -*- Makefile -*- fragment.
# For terms and provenance see the LICENSE file at the top of this repository.

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:
include @hypogeal_twilight_datarootdir@/mk/compile.mk

DEVELOPMENT_AREAS = \
  $(module_c_prefix) \
  $(module_half_prefix) \
  $(module_std_prefix) \
  $(module_string_prefix) \
  $(module_want_prefix) \
  $(end)
TESTING_AREAS = \
  $(module_cppunit_prefix) \
  $(module_rigging_prefix) \
  $(end)
INSTALLATION_AREAS = \
  $(nonstd_cppunit_prefix) \
  $(nonstd_gcc_prefix) \
  $(nonstd_half_prefix) \
  $(std_scold_prefix) \
  $(end)

# NOPE ... you can't say install depends upon check because
# then automake assesses that this is *the* install rule.
default: all
# automake needs to see the ::-sense of these (not being occluded in GNUmake include)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::
include @hypogeal_twilight_datarootdir@/mk/distclean.mk
clean-dependencies::
mostlyclean-local clean-local:: clean-dependencies

include src/ish/Makefrag.am
include src/mvr/Makefrag.am
include src/nonstd/Makefrag.am
include src/nonstd/module/Makefrag.am
include src/nonstd/path/Makefrag.am
include src/nonstd/stream/Makefrag.am
include src/org/semver/Makefrag.am
include src/path/Makefrag.am
include src/stream/Makefrag.am
include src/tests/unit/Makefrag.am
include src/want/Makefrag.am

INSTALL_MODULES = \
  $(lib_libish_module_la_MODULES) \
  $(lib_libnonstd_la_MODULES) \
  $(lib_libnonstd_mvr_la_MODULES) \
  $(lib_libnonstd_path_la_MODULES) \
  $(lib_libnonstd_stream_la_MODULES) \
  $(lib_liborg_semver_la_MODULES) \
  $(lib_libpath_la_MODULES) \
  $(lib_libstream_la_MODULES) \
  $(lib_libwant_la_MODULES) \
  $(end)
include $(hypogeal_twilight_datarootdir)/mk/install.mk # must be after these variables are set

noinst_LTLIBRARIES = \
  $(lib_libnonstd_mvr_la) \
  $(lib_libnonstd_path_la) \
  $(lib_libnonstd_stream_la) \
  $(lib_liborg_semver_la) \
  $(lib_libpath_la) \
  $(lib_libstream_la) \
  $(lib_libwant_la) \
  $(end)
# WATCHOUT - the order here is critical because upon actual install, the dependent libraries must already exist in place
# ... There is a libtool final link stage which elaborates the dependencies
lib_LTLIBRARIES = \
  $(lib_libnonstd_la) \
  $(lib_libnonstd_module_la) \
  $(lib_libish_module_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(end)
check_LTLIBRARIES = \
  $(end)

include tests/unit/Makefrag.am
include tests/unit/ish/Makefrag.am
include tests/unit/ish/bash/Makefrag.am
include tests/unit/ish/cxx/Makefrag.am
include tests/unit/ish/make/Makefrag.am
include tests/unit/ish/perl/Makefrag.am
include tests/unit/ish/shell/Makefrag.am
include tests/unit/ish/tuple/Makefrag.am
include tests/unit/path/Makefrag.am
XFAIL_TESTS = \
  $(tests_unit_XFAIL_TESTS) \
  $(tests_unit_ish_XFAIL_TESTS) \
  $(tests_unit_ish_XFAIL_TESTS) \
  $(tests_unit_ish_bash_XFAIL_TESTS) \
  $(tests_unit_ish_cxx_XFAIL_TESTS) \
  $(tests_unit_ish_make_XFAIL_TESTS) \
  $(tests_unit_ish_perl_XFAIL_TESTS) \
  $(tests_unit_ish_shell_XFAIL_TESTS) \
  $(tests_unit_ish_tuple_XFAIL_TESTS) \
  $(tests_unit_path_XFAIL_TESTS) \
  $(end)
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_unit_ish_TESTS) \
  $(tests_unit_ish_TESTS) \
  $(tests_unit_ish_bash_TESTS) \
  $(tests_unit_ish_cxx_TESTS) \
  $(tests_unit_ish_make_TESTS) \
  $(tests_unit_ish_perl_TESTS) \
  $(tests_unit_ish_shell_TESTS) \
  $(tests_unit_ish_tuple_TESTS) \
  $(tests_unit_path_TESTS) \
  $(end)

# [[REMOVEWHEN]] hypogeal-twilight >= 0.45? subsumes this work and supercedes it (by supplying the nonstd flags)
Makefile_nonstd_PACKAGE_CPPFLAGS_SET = @nonstd_half_CPPFLAGS@
Makefile_nonstd_PACKAGE_CFLAGS_SET   = @nonstd_half_CFLAGS@
Makefile_nonstd_PACKAGE_CXXFLAGS_SET = @nonstd_half_CXXFLAGS@
Makefile_nonstd_PACKAGE_LDFLAGS_SET  = @nonstd_half_LDFLAGS@
Makefile_nonstd_CHECK_CPPFLAGS_SET   = @nonstd_cppunit_CPPFLAGS@
Makefile_nonstd_CHECK_CFLAGS_SET     = @nonstd_cppunit_CFLAGS@
Makefile_nonstd_CHECK_CXXFLAGS_SET   = @nonstd_cppunit_CXXFLAGS@
Makefile_nonstd_CHECK_LDFLAGS_SET    = @nonstd_cppunit_LDFLAGS@

Makefile_COMPILER_CPPFLAGS_SET = @CPPFLAGS_gcc@ 
Makefile_COMPILER_CFLAGS_SET   =   @CFLAGS_gcc@   @CFLAGS_gdb@
Makefile_COMPILER_CXXFLAGS_SET = @CXXFLAGS_gcc@ @CXXFLAGS_gdb@
Makefile_COMPILER_LDFLAGS_SET  =  @LDFLAGS_gcc@  @LDFLAGS_gdb@ @libstd_filesystem@
Makefile_PACKAGE_CPPFLAGS_SET  = 
Makefile_PACKAGE_CFLAGS_SET    = 
Makefile_PACKAGE_CXXFLAGS_SET  = 
Makefile_PACKAGE_LDFLAGS_SET   = 
Makefile_CHECK_CPPFLAGS_SET    = @CPPFLAGS_cppunit@ @CPPFLAGS_no_install@
Makefile_CHECK_CFLAGS_SET      =   @CFLAGS_cppunit@   @CFLAGS_no_install@
Makefile_CHECK_CXXFLAGS_SET    = @CXXFLAGS_cppunit@ @CXXFLAGS_no_install@
Makefile_CHECK_LDFLAGS_SET     =  @LDFLAGS_cppunit@  @LDFLAGS_no_install@

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.VERBOSE_Veq$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))
