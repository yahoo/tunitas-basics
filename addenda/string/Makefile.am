# This is a -*- Makefile -*- fragment
# Copyright Yahoo Inc, 2021.
# Licensed under the terms of the Apache-2.0 license.
# For terms, see the license file at the top of this repository.
# Also the LICENSE file at https://github.com/yahoo/tunitas-packaging/blob/master/LICENSE (as available)
# Also the LICENSE file at https://git.tunitas.technology/all/components/$PACKAGE/tree/LICENSE (as available)

default:

DEVELOPMENT_AREAS = \
  @module_c_prefix@ \
  @module_std_prefix@ \
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
# include the compile.mk first because the src/.../Makefrag.am reference its definitions
# most functionality is available through in .../compile.mk
include @hypogeal_twilight_datarootdir@/mk/compile.mk

# NOPE ... you can't say install depends upon check because
# then automake assesses that this is *the* install rule.
#install: check
check:
default: all
# automake needs to see the ::-sense of these (not being occluded in GNUmake include)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::
include @hypogeal_twilight_datarootdir@/mk/distclean.mk

module_BB_SOURCE_SET = \
  $(lib_libc_string_module_la_SOURCES) \
  $(lib_libstring_module_la_SOURCES) \
  $(lib_libbyte_la_SOURCES) \
  $(lib_libc_runtime_la_SOURCES) \
  $(lib_libre_la_SOURCES) \
  $(lib_libstd_la_SOURCES) \
  $(lib_libwant_la_SOURCES) \
  $(end)
include @hypogeal_twilight_datarootdir@/mk/install.mk

# With corresponding mentions in configure.ac
include src/byte/Makefrag.am
include src/c/Makefrag.am
include src/re/Makefrag.am
include src/std/Makefrag.am
include src/string/Makefrag.am
include src/want/Makefrag.am
include src/tests/unit/Makefrag.am

the_DEPENDENCIES_SET = \
  obj/src/byte/dependencies.mk \
  obj/src/c/dependencies.mk \
  obj/src/std/dependencies.mk \
  obj/src/want/dependencies.mk \
  obj/src/tests/unit/dependencies.mk \
  $(end)
dependencies: $(the_DEPENDENCIES_SET)

the_OBJECTS_SET = \
  $(lib_libbyte_la_OBJECTS) \
  $(lib_libc_string_module_la_OBJECTS) \
  $(lib_libstring_module_la_OBJECTS) \
  $(lib_libbyte_la_OBJECTS) \
  $(lib_libc_runtime_la_OBJECTS) \
  $(lib_libre_la_OBJECTS) \
  $(lib_libstd_la_OBJECTS) \
  $(lib_libwant_la_OBJECTS) \
  $(bin_unit_OBJECTS) \
  $(end)
objects: $(the_OBJECTS_SET)

the_MODULES_SET = \
  $(lib_libbyte_la_MODULES) \
  $(lib_libc_string_module_la_MODULES) \
  $(lib_libstring_module_la_MODULES) \
  $(lib_libbyte_la_MODULES) \
  $(lib_libc_runtime_la_MODULES) \
  $(lib_libre_la_MODULES) \
  $(lib_libstd_la_MODULES) \
  $(lib_libwant_la_MODULES) \
  $(end)
modules: $(the_MODULES_SET)

noinst_LTLIBRARIES = \
  $(lib_libbyte_la) \
  $(lib_libc_runtime_la) \
  $(lib_libre_la) \
  $(lib_libstd_la) \
  $(lib_libwant_la) \
  $(end)
# WATCHOUT - the order here is important for installation as -lc-string entails -lstring
lib_LTLIBRARIES = \
  $(lib_libstring_module_la) \
  $(lib_libc_string_module_la) \
  $(end)
check_PROGRAMS = \
  $(bin_unit) \
  $(end)
check_LTLIBRARIES = \
  $(end)

$(lib_LTLIBRARIES) : $(noinst_LIBRARIES)
$(lib_libc_string_module_la) : $(lib_libstring_module_la)
$(bin_PROGRAMS) : $(lib_LTLIBRARIES)
$(check_PROGRAMS) : $(lib_LTLIBRARIES) $(check_LTLIBRARIES)

include tests/unit/Makefrag.am
include tests/unit/byte/Makefrag.am
include tests/unit/c/Makefrag.am
include tests/unit/re/Makefrag.am
include tests/unit/re/construct/Makefrag.am
include tests/unit/std/Makefrag.am
include tests/unit/want/Makefrag.am
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_unit_byte_TESTS) \
  $(tests_unit_c_TESTS) \
  $(tests_unit_re_TESTS) \
  $(tests_unit_re_construct_TESTS) \
  $(tests_unit_std_TESTS) \
  $(tests_unit_want_TESTS) \
  $(end)

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

# SEARCHPATH ought to come after the cpp options, merely because it is so very big
# LOADPATH ought to come before the -llibrary names for the libraries (is that still a rule?)
SEARCHPATH = $(SEARCHPATH_SCOLD_MODULES) $(SEARCHPATH_EXTERNAL_MODULES)
LOADPATH   = $(LOADPATH_SCOLD_MODULES)   $(LOADPATH_EXTERNAL_MODULES)

# REMOVE WHEN: baleful_ballad:hypogeal-twilight-0.30.1 has work that supercedes this
__nonstd_PACKAGE_CPPFLAGS_SET = 
__nonstd_PACKAGE_CFLAGS_SET   = 
__nonstd_PACKAGE_CXXFLAGS_SET = 
__nonstd_PACKAGE_LDFLAGS_SET  = 
__nonstd_CHECK_CPPFLAGS_SET   = @nonstd_cppunit_CPPFLAGS@
__nonstd_CHECK_CFLAGS_SET     = @nonstd_cppunit_CFLAGS@
__nonstd_CHECK_CXXFLAGS_SET   = @nonstd_cppunit_CXXFLAGS@
__nonstd_CHECK_LDFLAGS_SET    = @nonstd_cppunit_LDFLAGS@

__COMPILER_CPPFLAGS_SET  = @CPPFLAGS_gcc@ 
__COMPILER_CFLAGS_SET    = @CFLAGS_gcc@   @CFLAGS_gdb@
__COMPILER_CXXFLAGS_SET  = @CXXFLAGS_gcc@ @CXXFLAGS_gdb@
__COMPILER_LDFLAGS_SET   = @LDFLAGS_gcc@ @LDFLAGS_gdb@
__COMPONENT_CPPFLAGS_SET = 
__COMPONENT_CFLAGS_SET   = 
__COMPONENT_CXXFLAGS_SET = 
__COMPONENT_LDFLAGS_SET  = 
__TESTING_CPPFLAGS_SET   = @CPPFLAGS_cppunit@
__TESTING_CFLAGS_SET     = @CFLAGS_cppunit@
__TESTING_CXXFLAGS_SET   = @CXXFLAGS_cppunit@
__TESTING_LDFLAGS_SET    = @LDFLAGS_cppunit@

PACKAGE_CPPFLAGS_SET = $(SEARCHPATH) $(__COMPONENT_CPPFLAGS_SET) $(__COMPILER_CPPFLAGS_SET) $(__nonstd_PACKAGE_CPPFLAGS_SET)
PACKAGE_CFLAGS_SET   =               $(__COMPONENT_CFLAGS_SET)   $(__COMPILER_CFLAGS_SET)   $(__nonstd_PACKAGE_CFLAGS_SET)
PACKAGE_CXXFLAGS_SET =               $(__COMPONENT_CXXFLAGS_SET) $(__COMPILER_CXXFLAGS_SET) $(__nonstd_PACKAGE_CXXFLAGS_SET)
PACKAGE_LDFLAGS_SET  = $(LOADPATH)   $(__COMPONENT_LDFLAGS_SET)  $(__COMPILER_LDFLAGS_SET)  $(__nonstd_PACKAGE_LDFLAGS_SET)

CHECK_CPPFLAGS_SET = $(PACKAGE_CPPFLAGS_SET) $(__TESTING_CPPFLAGS_SET) $(__nonstd_CHECK_CPPFLAGS_SET)
CHECK_CFLAGS_SET   = $(PACKAGE_CFLAGS_SET)   $(__TESTING_CFLAGS_SET)   $(__nonstd_CHECK_CFLAGS_SET)
CHECK_CXXFLAGS_SET = $(PACKAGE_CXXFLAGS_SET) $(__TESTING_CXXFLAGS_SET) $(__nonstd_CHECK_CXXFLAGS_SET)
CHECK_LDFLAGS_SET  = $(PACKAGE_LDFLAGS_SET)  $(__TESTING_LDFLAGS_SET)  $(__nonstd_CHECK_LDFLAGS_SET)

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
