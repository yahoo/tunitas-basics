# -*- Makefile -*-
# For terms and provenance see the LICENSE file at the top of this repository.

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:
DEVELOPMENT_AREAS = \
  $(module_c_prefix) \
  $(module_nonstd_prefix) \
  $(module_options_prefix) \
  $(module_posix_prefix) \
  $(module_std_prefix) \
  $(module_string_prefix) \
  $(module_sys_prefix) \
  $(end)
TESTING_AREAS = \
  $(module_rigging_prefix) \
  $(module_cppunit_prefix) \
  $(end)
INSTALLATION_AREAS = \
  $(nonstd_gcc_prefix) \
  $(std_scold_prefix) \
  $(end)
include @hypogeal_twilight_datarootdir@/am/EXTERNAL-PATHS.mk
include @hypogeal_twilight_datarootdir@/am/compile.mk

# NOPE ... you can't say install depends upon check because
# then automake assesses that this is *the* install rule.
#install: check
default: all
# automake needs to see the ::-sense of these (not being occluded in GNUmake include)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::
include @hypogeal_twilight_datarootdir@/am/distclean.mk
clean-dependencies::
mostlyclean-local:: clean-dependencies
clean-local:: clean-dependencies

module_BB_SOURCE_SET = $(lib_libslurp_module_la_SOURCES) $(lib_libwant_la_SOURCES)
include @hypogeal_twilight_datarootdir@/am/install.mk

# these are matched with SCOLD_INSERT_GNUmakefrag declarations in configure.ac
include src/slurp/Makefrag.am
include src/want/Makefrag.am
include src/tests/cat/Makefrag.am
include src/tests/rev/Makefrag.am
include src/tests/tac/Makefrag.am
include src/tests/unit/Makefrag.am
include src/tests/ver/Makefrag.am

$(lib_libslurp_module_la) : $(lib_libwant_la)
$(bin_unit) : $(lib_libslurp_module_la)
$(bin_cat) : $(lib_libslurp_module_la)
$(bin_tac) : $(lib_libslurp_module_la)
$(bin_rev) : $(lib_libslurp_module_la)
$(bin_ver) : $(lib_libslurp_module_la)

# unnecessary nowadays with .../dependencies.mk and baleful-ballad
# $(bin_unit_OBJECTS): $(lib_libslurp_module_la_MODULES)

lib_LTLIBRARIES = \
  $(lib_libslurp_module_la) \
  $(end)
noinst_LTLIBRARIES = \
  $(lib_libwant_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(check_bin_cat) \
  $(check_bin_tac) \
  $(check_bin_rev) \
  $(check_bin_ver) \
  $(end)
check_LTLIBRARIES = \
  $(end)

include tests/unit/Makefrag.am
include tests/unit/slurp/Makefrag.am
include tests/unit/slurp/file/Makefrag.am
include tests/unit/slurp/directory/Makefrag.am
include tests/unit/slurp/named/Makefrag.am
include tests/unit/slurp/named/file/Makefrag.am
include tests/unit/slurp/named/directory/Makefrag.am

include tests/cat/Makefrag.am
include tests/tac/Makefrag.am
include tests/rev/Makefrag.am
include tests/ver/Makefrag.am
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_slurp_TESTS) \
  $(tests_slurp_file_TESTS) \
  $(tests_slurp_directory_TESTS) \
  $(tests_slurp_named_TESTS) \
  $(tests_slurp_named_file_TESTS) \
  $(tests_slurp_named_directory_TESTS) \
  $(tests_cat_TESTS) \
  $(tests_tac_TESTS) \
  $(tests_rev_TESTS) \
  $(tests_ver_TESTS) \
  $(end)

# REMOVE WHEN: baleful_ballad:hypogeal-twilight-0.??.? has work that supercedes this
Makefile_nonstd_PACKAGE_CPPFLAGS_SET = 
Makefile_nonstd_PACKAGE_CFLAGS_SET   = 
Makefile_nonstd_PACKAGE_CXXFLAGS_SET = 
Makefile_nonstd_PACKAGE_LDFLAGS_SET  = 
Makefile_nonstd_CHECK_CPPFLAGS_SET   = @nonstd_cppunit_CPPFLAGS@
Makefile_nonstd_CHECK_CFLAGS_SET     = @nonstd_cppunit_CFLAGS@
Makefile_nonstd_CHECK_CXXFLAGS_SET   = @nonstd_cppunit_CXXFLAGS@
Makefile_nonstd_CHECK_LDFLAGS_SET    = @nonstd_cppunit_LDFLAGS@

Makefile_COMPILER_CPPFLAGS_SET  = @CPPFLAGS_gcc@ 
Makefile_COMPILER_CFLAGS_SET    =   @CFLAGS_gcc@   @CFLAGS_gdb@
Makefile_COMPILER_CXXFLAGS_SET  = @CXXFLAGS_gcc@ @CXXFLAGS_gdb@
Makefile_COMPILER_LDFLAGS_SET   =  @LDFLAGS_gcc@  @LDFLAGS_gdb@
Makefile_PACKAGE_CPPFLAGS_SET   = 
Makefile_PACKAGE_CFLAGS_SET     = 
Makefile_PACKAGE_CXXFLAGS_SET   = 
Makefile_PACKAGE_LDFLAGS_SET    = 
Makefile_CHECK_CPPFLAGS_SET     = @CPPFLAGS_cppunit@ @CPPFLAGS_no_install@
Makefile_CHECK_CFLAGS_SET       =   @CFLAGS_cppunit@   @CFLAGS_no_install@
Makefile_CHECK_CXXFLAGS_SET     = @CXXFLAGS_cppunit@ @CXXFLAGS_no_install@
Makefile_CHECK_LDFLAGS_SET      =  @LDFLAGS_cppunit@  @LDFLAGS_no_install@

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))
#end
