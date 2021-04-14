# This is a -*- Makefile -*- fragment.
# For terms and provenance see the LICENSE file at the top of this repository.

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:

DEVELOPMENT_AREAS = \
  @module_c_prefix@ \
  @module_nonstd_prefix@ \
  @module_std_prefix@ \
  @module_string_prefix@ \
  @module_sys_prefix@ \
  $(end)
TESTING_AREAS = \
  @module_cppunit_prefix@ \
  @module_rigging_prefix@ \
  $(end)
INSTALLATION_AREAS = \
  @nonstd_cppunit_prefix@ \
  @nonstd_gcc_prefix@ \
  @std_scold_prefix@ \
  $(end)
hypogeal_twilight_prefix = @hypogeal_twilight_prefix@
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
mostlyclean-local clean-local:: clean-dependencies

include src/options/Makefrag.am
include src/tests/unit/Makefrag.am
include src/tests/parse/Makefrag.am

INSTALL_MODULES = \
  $(lib_liboptions_module_la_MODULES) \
  $(end)
include @hypogeal_twilight_datarootdir@/am/install.mk # MUST be after the *_MODULES variables are defined

lib_LTLIBRARIES = \
  $(lib_liboptions_module_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(check_bin_parse) \
  $(end)
check_LTLIBRARIES = \
  $(end)

include tests/unit/Makefrag.am
include tests/parse/Makefrag.am
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_parse_TESTS) \
  $(end)
XFAIL_TESTS = \
  $(tests_unit_XFAIL_TESTS) \
  $(tests_parse_XFAIL_TESTS) \
  $(end)

# [[REMOVEWHEN]] hypogeal-twilight >= 0.45.0-0.devel has work that supercedes t his
Makefile_nonstd_PACKAGE_CPPFLAGS_SET = 
Makefile_nonstd_PACKAGE_CFLAGS_SET   = 
Makefile_nonstd_PACKAGE_CXXFLAGS_SET = 
Makefile_nonstd_PACKAGE_LDFLAGS_SET  = 
Makefile_nonstd_CHECK_CPPFLAGS_SET   = @nonstd_cppunit_CPPFLAGS@
Makefile_nonstd_CHECK_CFLAGS_SET     = @nonstd_cppunit_CFLAGS@
Makefile_nonstd_CHECK_CXXFLAGS_SET   = @nonstd_cppunit_CXXFLAGS@
Makefile_nonstd_CHECK_LDFLAGS_SET    = @nonstd_cppunit_LDFLAGS@

Makefile_COMPILER_CPPFLAGS_SET = @CPPFLAGS_gcc@ 
Makefile_COMPILER_CFLAGS_SET   =   @CFLAGS_gcc@   @CFLAGS_gdb@
Makefile_COMPILER_CXXFLAGS_SET = @CXXFLAGS_gcc@ @CXXFLAGS_gdb@
Makefile_COMPILER_LDFLAGS_SET  =  @LDFLAGS_gcc@  @LDFLAGS_gdb@
Makefile_PACKAGE_CPPFLAGS_SET  = 
Makefile_PACKAGE_CFLAGS_SET    = 
Makefile_PACKAGE_CXXFLAGS_SET  = 
Makefile_PACKAGE_LDFLAGS_SET   = 
Makefile_CHECK_CPPFLAGS_SET    = @CPPFLAGS_cppunit@
Makefile_CHECK_CFLAGS_SET      =   @CFLAGS_cppunit@
Makefile_CHECK_CXXFLAGS_SET    = @CXXFLAGS_cppunit@
Makefile_CHECK_LDFLAGS_SET     =  @LDFLAGS_cppunit@

# assembled from .../mk/toolflags.mk in hypogeal-twilight >= 0.45.0
AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))
#end
