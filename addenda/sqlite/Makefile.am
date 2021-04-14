# This is a GNU -*- Makefile -*- template that is managed by Automake
# For terms and provenance see the LICENSE file at the top of this repository.

default:
# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

DEVELOPMENT_AREAS = \
  $(module_boost_prefix) \
  $(module_c_prefix) \
  $(module_format_prefix) \
  $(module_nonstd_prefix) \
  $(module_options_prefix) \
  $(module_path_prefix) \
  $(module_posix_prefix) \
  $(module_slurp_prefix) \
  $(module_std_prefix) \
  $(module_string_prefix) \
  $(module_sys_prefix) \
  $(end)
TESTING_AREAS = \
  $(module_cppunit_prefix) \
  $(module_rigging_prefix) \
  $(end)
INSTALLATION_AREAS =\
  $(nonstd_boost_prefix) \
  $(nonstd_cppunit_prefix) \
  $(nonstd_gcc_prefix) \
  $(nonstd_sqlite_prefix) \
  $(std_scold_prefix) \
  $(end)
include @hypogeal_twilight_datarootdir@/am/compile.mk

# WATCHOUT in automake you can't tie 'check' to 'install'
check:
default: all
# automake needs to see the ::-sense of these (not occluded somehow)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::
include $(hypogeal_twilight_datarootdir)/mk/distclean.mk

include src/sqlite/Makefrag.am
include src/want/Makefrag.am
include src/tests/unit/Makefrag.am
include src/tests/execute/Makefrag.am
include src/tests/words/Makefrag.am

INSTALL_MODULES = \
  $(lib_libsqlite_module_la_MODULES) \
  $(lib_libwant_la_MODULES) \
  $(end)

noinst_LTLIBRARIES = \
  $(lib_libwant_la) \
  $(end)
lib_LTLIBRARIES = \
  $(lib_libsqlite_module_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(check_bin_execute) \
  $(check_bin_words) \
  $(end)
check_LTLIBRARIES = \
  $(end)

include tests/unit/Makefrag.am
include tests/execute/Makefrag.am
include tests/words/Makefrag.am
# unit tests first, then the larger test subsystems
XFAIL_TESTS = \
  $(tests_unit_XFAIL_TESTS) \
  $(tests_execute_XFAIL_TESTS) \
  $(tests_words_XFAIL_TESTS) \
  $(end)
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_execute_TESTS) \
  $(tests_words_TESTS) \
  $(end)

# [[REMOVEWHEN]]: hypogeal-twilight >= 0.?? as work that supercedes this, maybe 0.55, 0.66, 0.77 ... WHEN?
Makefile_nonstd_PACKAGE_CPPFLAGS_SET = @nonstd_boost_CPPFLAGS@ @nonstd_sqlite_CPPFLAGS@ 
Makefile_nonstd_PACKAGE_CFLAGS_SET   = @nonstd_boost_CFLAGS@   @nonstd_sqlite_CFLAGS@
Makefile_nonstd_PACKAGE_CXXFLAGS_SET = @nonstd_boost_CXXFLAGS@ @nonstd_sqlite_CXXFLAGS@
Makefile_nonstd_PACKAGE_LDFLAGS_SET  = @nonstd_boost_LDFLAGS@  @nonstd_sqlite_LDFLAGS@
Makefile_nonstd_CHECK_CPPFLAGS_SET   = @nonstd_cppunit_CPPFLAGS@
Makefile_nonstd_CHECK_CFLAGS_SET     = @nonstd_cppunit_CFLAGS@
Makefile_nonstd_CHECK_CXXFLAGS_SET   = @nonstd_cppunit_CXXFLAGS@
Makefile_nonstd_CHECK_LDFLAGS_SET    = @nonstd_cppunit_LDFLAGS@

Makefile_COMPILER_CPPFLAGS_SET  = @CPPFLAGS_gcc@ 
Makefile_COMPILER_CFLAGS_SET    =   @CFLAGS_gcc@   @CFLAGS_gdb@
Makefile_COMPILER_CXXFLAGS_SET  = @CXXFLAGS_gcc@ @CXXFLAGS_gdb@
Makefile_COMPILER_LDFLAGS_SET   =  @LDFLAGS_gcc@  @LDFLAGS_gdb@ @libstd_filesystem@
Makefile_PACKAGE_CPPFLAGS_SET =  @CPPFLAGS_boost@ @CPPFLAGS_sqlite@ 
Makefile_PACKAGE_CFLAGS_SET   =    @CFLAGS_boost@   @CFLAGS_sqlite@
Makefile_PACKAGE_CXXFLAGS_SET =  @CXXFLAGS_boost@ @CXXFLAGS_sqlite@
Makefile_PACKAGE_LDFLAGS_SET  =   @LDFLAGS_boost@  @LDFLAGS_sqlite@
Makefile_CHECK_CPPFLAGS_SET   = @CPPFLAGS_cppunit@ @CPPFLAGS_no_install@
Makefile_CHECK_CFLAGS_SET     =   @CFLAGS_cppunit@   @CFLAGS_no_install@
Makefile_CHECK_CXXFLAGS_SET   = @CXXFLAGS_cppunit@ @CXXFLAGS_no_install@
Makefile_CHECK_LDFLAGS_SET    =  @LDFLAGS_cppunit@  @LDFLAGS_no_install@

# These are populated by the .../toolflags.mk in hypogeal-twilight >= 0.45.0-0.devel
AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.VERBOSE_Veq$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))
