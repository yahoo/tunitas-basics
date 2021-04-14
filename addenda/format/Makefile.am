# -*- Makefile -*-
# This is a -*- Makefile -*- fragment.
# For terms and provenance see the LICENSE file at the top of this repository.

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:

DEVELOPMENT_AREAS = \
  @module_boost_prefix@ \
  @module_half_prefix@ \
  @module_nonstd_prefix@ \
  @module_std_prefix@ \
  @module_string_prefix@ \
  $(end)
TESTING_AREAS = \
  @module_cppunit_prefix@ \
  @module_rigging_prefix@ \
  $(end)
INSTALLATION_AREAS =\
  @nonstd_boost_prefix@ \
  @nonstd_cppunit_prefix@ \
  @nonstd_gcc_prefix@ \
  @std_scold_prefix@ \
  $(end)
hypogeal_twilight_prefix = @hypogeal_twilight_prefix@
include @hypogeal_twilight_datarootdir@/am/EXTERNAL-PATHS.mk
include @hypogeal_twilight_datarootdir@/am/compile.mk

# WATCHOUT in automake you can't tie 'check' to 'install'
check:
default: all
# automake needs to see the ::-sense of these (not being occluded in GNUmake include)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::
include @hypogeal_twilight_datarootdir@/am/distclean.mk

module_BB_SOURCE_SET = $(lib_libformat_module_la_SOURCES)
include @hypogeal_twilight_datarootdir@/am/install.mk

include src/format/Makefrag.am
include src/want/Makefrag.am
include src/tests/unit/Makefrag.am

the_DEPENDENCIES_SET = \
  obj/src/format/dependencies.mk \
  obj/src/want/dependencies.mk \
  obj/src/tests/unit/dependencies.mk \
  $(end)
dependencies: $(the_DEPENDENCIES_SET)

the_OBJECTS_SET = \
  $(bin_unit_OBJECTS) \
  $(lib_libformat_module_la_OBJECTS) \
  $(lib_libwant_la_OBJECTS) \
  $(end)
objects: $(the_OBJECTS_SET)

the_MODULES_SET = \
  $(lib_libformat_module_la_MODULES) \
  $(lib_libwant_la_MODULES) \
  $(end)
modules: $(the_MODULES_SET)

lib_LTLIBRARIES = \
  $(lib_libformat_module_la) \
  $(end)
noinst_LTLIBRARIES = \
  $(lib_libwant_la) \
  $(end)
check_PROGRAMS = \
  $(bin_unit) \
  $(end)
check_LTLIBRARIES = \
  $(end)

include tests/unit/Makefrag.am
include tests/unit/funcall/Makefrag.am
include tests/unit/json/Makefrag.am
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_unit_funcall_TESTS) \
  $(tests_unit_json_TESTS) \
  $(end)

# all this is assembled by hypogeal-twilight's .../toolflags.mk
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

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))

V_LIBTOOLFLAGS_VERBOSE_Veq0 = --silent
V_LIBTOOLFLAGS_VERBOSE_Veq1 = --verbose

# AM_LDFLAGS is deprecating.
# AM_LDFLAGS is variously used.
# Do not use AM_LDFLAGS; though LDFLAGS remains reserved caller the top-level caller (of make)
#
# used by CXXLINK
#         which is used to make convenience libraries; e.g. libwant.la
#         this appears to be a leftover accident.
#         in this case there is libwant_la_LIBADD but no libwant_la_LDFLAGS
# NOT used by lib_lib${LIBRARY}_la_LINK, e.g. lib/libsomething-module.la
#             which is used to make final-link{ed,able} shared libraries.
# NOT used by bin_${PROGRAM}_LINK, e.g. bin/unit
#             which is used o make final-linked executables.
#
V_LDFLAGS_avoid.0 = $(empty)
V_LDFLAGS_avoid.1 = $(warning $@, \
the AM_LDFLAGS variable is deprecated,  instead, use \
$(subst .,_,$(subst -,_,$(@F)_LIBADD)) \
or if available, \
$(subst .,_,$(subst -,_,$(@F)_LDFLAGS)))
#end
