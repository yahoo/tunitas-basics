# This is a -*- Makefile -*- fragment
# Copyright Yahoo Inc, 2021.
# Licensed under the terms of the Apache-2.0 license.
# For terms, see the license file at the top of this repository.
# Also the LICENSE file at https://github.com/yahoo/tunitas-packaging/blob/master/LICENSE (as available)
# Also the LICENSE file at https://git.tunitas.technology/all/components/$PACKAGE/tree/LICENSE (as available)

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:

DEVELOPMENT_AREAS = \
  $(module_c_prefix) \
  $(module_posix_prefix) \
  $(module_std_prefix) \
  $(module_string_prefix) \
  $(module_sys_prefix) \
  $(end)
TESTING_AREAS = \
  $(module_cppunit_prefix) \
  $(module_rigging_prefix) \
  $(end)
INSTALLATION_AREAS =\
  $(nonstd_cppunit_prefix) \
  $(nonstd_uuid_prefix) \
  $(nonstd_gcc_prefix) \
  $(end)
include @hypogeal_twilight_datarootdir@/am/EXTERNAL-PATHS.mk
include @hypogeal_twilight_datarootdir@/am/compile.mk

# NOPE ... you can't say install depends upon check because
# then automake assesses that this is *the* install rule.
default: all
# automake needs to see the ::-sense of these (not being occluded in GNUmake include)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::
include @hypogeal_twilight_datarootdir@/am/distclean.mk
clean-dependencies::
maintainer-clean-local mostlyclean-local:: clean-dependencies

module_BB_SOURCE_SET = $(lib_libuuid_module_la_SOURCES) $(lib_libwant_la_SOURCES)
include @hypogeal_twilight_datarootdir@/am/install.mk

# there is a corresponding SCOLD_INDIRECT_GNUmakefrag in configure.ac
include src/uuid/Makefrag.am
include src/tests/unit/Makefrag.am

noinst_LTLIBRARIES = \
  $(end)
lib_LTLIBRARIES = \
  $(lib_libuuid_module_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(end)
check_LTLIBRARIES = \
  $(end)

include tests/unit/Makefrag.am
XFAIL_TESTS = \
  $(tests_unit_XFAIL_TESTS) \
  $(end)
TESTS = \
  $(tests_unit_TESTS) \
  $(end)

# REMOVE WHEN: baleful_ballad and hypogeal-twilight >= 0.??.1 has work that supercedes this
Makefile_nonstd_PACKAGE_CPPFLAGS_SET = @nonstd_uuid_CPPFLAGS@
Makefile_nonstd_PACKAGE_CFLAGS_SET   = @nonstd_uuid_CFLAGS@
Makefile_nonstd_PACKAGE_CXXFLAGS_SET = @nonstd_uuid_CXXFLAGS@
Makefile_nonstd_PACKAGE_LDFLAGS_SET  = @nonstd_uuid_LDFLAGS@
Makefile_nonstd_CHECK_CPPFLAGS_SET   = @nonstd_cppunit_CPPFLAGS@
Makefile_nonstd_CHECK_CFLAGS_SET     = @nonstd_cppunit_CFLAGS@
Makefile_nonstd_CHECK_CXXFLAGS_SET   = @nonstd_cppunit_CXXFLAGS@
Makefile_nonstd_CHECK_LDFLAGS_SET    = @nonstd_cppunit_LDFLAGS@

Makefile_COMPILER_CPPFLAGS_SET  = @CPPFLAGS_gcc@ 
Makefile_COMPILER_CFLAGS_SET    =   @CFLAGS_gcc@   @CFLAGS_gdb@
Makefile_COMPILER_CXXFLAGS_SET  = @CXXFLAGS_gcc@ @CXXFLAGS_gdb@
Makefile_COMPILER_LDFLAGS_SET   =  @LDFLAGS_gcc@  @LDFLAGS_gdb@
Makefile_PACKAGE_CPPFLAGS_SET   = @CPPFLAGS_uuid@
Makefile_PACKAGE_CFLAGS_SET     =   @CFLAGS_uuid@
Makefile_PACKAGE_CXXFLAGS_SET   = @CXXFLAGS_uuid@
Makefile_PACKAGE_LDFLAGS_SET    =  @LDFLAGS_uuid@
Makefile_TESTING_CPPFLAGS_SET   = @CPPFLAGS_cppunit@
Makefile_TESTING_CFLAGS_SET     =   @CFLAGS_cppunit@
Makefile_TESTING_CXXFLAGS_SET   = @CXXFLAGS_cppunit@
Makefile_TESTING_LDFLAGS_SET    =  @LDFLAGS_cppunit@

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.VERBOSE_Veq$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))
#end
