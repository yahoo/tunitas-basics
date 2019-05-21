# This is a GNU -*- Makefile -*- which is managed by automake.
# Copyright 2018-2019, Oath Inc.
# Licensed under the terms of the Apache-2.0 license.
# See the LICENSE file in https://github.com/yahoo/tunitas-basics/blob/master/LICENSE for terms.

# silent-rules has no effect, see configure.ac
# cannot -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:
include @temerarious_flagship_datadir@/am/build.am
# [[REMOVEWHEN]] temerarious-1.1.0 provides .../am/build.am
$(if $(scold_cxxdir),$(__ok),$(error @temerarious_flagship_datadir@/am/build.am was incomplete))

# To get submodules to build in place, these go as a pair
#   configure.ac declares TF_CONFIG_SUBMODULES(directory, ...list...)
#   Makefile.am  declares SUBDIRS = @subdirs@
# there are no submodules (now).

DEVELOPMENT_AREAS = \
  $(module_httpserver_prefix) \
  $(module_nonstd_prefix) \
  $(module_options_prefix) \
  $(module_posix_prefix) \
  $(module_std_prefix) \
  $(module_string_prefix) \
  $(end)
TESTING_AREAS = \
  $(module_cppunit_prefix) \
  $(module_rigging_prefix) \
  $(end)
INSTALLATION_AREAS = \
  $(nonstd_cppunit_prefix) \
  $(nonstd_half_prefix) \
  $(nonstd_libhttpserver_prefix) \
  $(nonstd_gcc_prefix) \
  $(std_scold_prefix) \
  $(std_tunitas_prefix) \
  $(end)

default: all

# install rules from @temerarious_flagship_datadir@/am/install.am
$(if $(DEBUGGING_CONDITION),$(info DEBUG module_SOURCE_SET=$(module_SOURCE_SET)))
module_SOURCE_SET = $(lib_libtunitas_la_SOURCES) $(lib_libwant_la_SOURCES)

.PHONY: clean-local mostlyclean-local distclean-local
clean-local mostlyclean-local distclean-local::
clean-dependencies::
clean-local:: clean-dependencies

include src/tunitas/Makefrag.am
include src/tunitas/server/Makefrag.am
include src/want/Makefrag.am
include src/tests/unit/Makefrag.am
include src/tests/base64/Makefrag.am
include src/tests/outcome/Makefrag.am
include src/tests/urlsafe/Makefrag.am

bin_PROGRAMS = 
lib_LTLIBRARIES = \
  $(lib_libtunitas_la) \
  $(lib_libtunitas_server_la) \
  $(end)
noinst_LTLIBRARIES = \
  $(lib_libwant_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(check_bin_base64_decode) \
  $(check_bin_base64_encode) \
  $(check_bin_outcome_error_code) \
  $(check_bin_outcome_error_condition) \
  $(check_bin_urlsafe_decode) \
  $(check_bin_urlsafe_encode) \
  $(end)
check_LTLIBRARIES = \
  $(check_lib_libtests_base64_la) \
  $(check_lib_libtests_outcome_la) \
  $(check_lib_libtests_urlsafe_la) \
  $(end)

$(lib_libtunitas_server_la) : $(lib_libtunitas_la)

$(bin_PROGRAMS) : $(lib_LTLIBRARIES)
$(lib_LTLIBRARIES) : $(noinst_LTLIBRARIES)
$(check_PROGRAMS) : $(bin_PROGRAMS)
$(check_PROGRAMS) : $(lib_LTLIBRARIES)
$(check_PROGRAMS) : $(check_LTLIBRARIES)

MODULES = \
  $(lib_libtunitas_la_MODULES) \
  $(lib_libtunitas_server_la_MODULES) \
  $(lib_libwant_la_MODULES) \
  $(check_bin_unit_MODULES)  \
  $(check_bin_base64_decode_MODULES) \
  $(check_bin_base64_encode_MODULES) \
  $(check_bin_outcome_error_code_MODULES) \
  $(check_bin_outcome_error_condition_MODULES) \
  $(check_bin_urlsafe_decode_MODULES) \
  $(check_bin_urlsafe_encode_MODULES) \
  $(check_lib_libtests_base64_la_MODULES) \
  $(check_lib_libtests_outcome_la_MODULES) \
  $(check_lib_libtests_urlsafe_la_MODULES) \
  $(end)
OBJECTS = \
  $(lib_libtunitas_la_OBJECTS) \
  $(lib_libtunitas_server_la_OBJECTS) \
  $(lib_libwant_la_OBJECTS) \
  $(check_bin_unit_OBJECTS)  \
  $(check_bin_base64_decode_OBJECTS) \
  $(check_bin_base64_encode_OBJECTS) \
  $(check_bin_outcome_error_code_OBJECTS) \
  $(check_bin_outcome_error_condition_OBJECTS) \
  $(check_bin_urlsafe_decode_OBJECTS) \
  $(check_bin_urlsafe_encode_OBJECTS) \
  $(check_lib_libtests_base64_la_OBJECTS) \
  $(check_lib_libtests_outcome_la_OBJECTS) \
  $(check_lib_libtests_urlsafe_la_OBJECTS) \
  $(end)
$(OBJECTS) : $(MODULES)

include tests/unit/Makefrag.am
include tests/base64/decode/Makefrag.am
include tests/base64/encode/Makefrag.am
include tests/outcome/error_code/Makefrag.am
include tests/outcome/error_condition/Makefrag.am
include tests/urlsafe/decode/Makefrag.am
include tests/urlsafe/encode/Makefrag.am
XFAIL_TESTS = \
  $(tests_unit_XFAIL_TESTS) \
  $(tests_base64_decode_XFAIL_TESTS) \
  $(tests_base64_encode_XFAIL_TESTS) \
  $(tests_outcome_error_code_XFAIL_TESTS) \
  $(tests_outcome_error_condition_XFAIL_TESTS) \
  $(tests_urlsafe_error_code_XFAIL_TESTS) \
  $(tests_urlsafe_error_condition_XFAIL_TESTS) \
  $(end)
XPASS_TESTS = \
  $(tests_unit_XPASS_TESTS) \
  $(tests_base64_decode_XPASS_TESTS) \
  $(tests_base64_encode_XPASS_TESTS) \
  $(tests_outcome_error_code_XPASS_TESTS) \
  $(tests_outcome_error_condition_XPASS_TESTS) \
  $(tests_urlsafe_error_code_XPASS_TESTS) \
  $(tests_urlsafe_error_condition_XPASS_TESTS) \
  $(end)
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_base64_decode_TESTS) \
  $(tests_base64_encode_TESTS) \
  $(tests_outcome_error_code_TESTS) \
  $(tests_outcome_error_condition_TESTS) \
  $(tests_urlsafe_error_code_TESTS) \
  $(tests_urlsafe_error_condition_TESTS) \
  $(end)

# The Makefile_*SET variables are assembled by .../toolflags.mk
# via @temerarious_flagship_datadir@/am/build.am and its constituents.
# [[REMOVEWHEN]] temerarious-flagship supplies this, e.g. 1.1.2
include $(if $(filter 1,$(hypogeal_twilight_toolflags_mk_included)), /dev/null, @hypogeal_twilight_datadir@/mk/toolflags.mk)

# configure.ac:  TF_ENABLE_GCC
Makefile_COMPILER_CPPFLAGS_SET =                @CPPFLAGS_gcc@
Makefile_COMPILER_CFLAGS_SET   = @CFLAGS_gdb@   @CFLAGS_gcc@
Makefile_COMPILER_CXXFLAGS_SET = @CXXFLAGS_gdb@ @CXXFLAGS_gcc@ -Wno-attributes
Makefile_COMPILER_LDFLAGS_SET  = @LDFLAGS_gdb@  @LDFLAGS_gcc@  @libstd_filesystem@

# configure.ac: TF_WITH_NONSTD([nonstd-libhttpserver])
Makefile_nonstd_CPPFLAGS_SET = @nonstd_libhttpserver_CPPFLAGS@
Makefile_nonstd_CFLAGS_SET   = @nonstd_libhttpserver_CFLAGS@
Makefile_nonstd_CXXLAGS_SET  = @nonstd_libhttpserver_CXXFLAGS@
Makefile_nonstd_LDFLAGS_SET  = @nonstd_libhttpserver_LDFLAGS@

# extras not otherwise covered by the TF_WITH_MODULE([...]) declarations
Makefile_PACKAGE_CPPFLAGS_SET = 
Makefile_PACKAGE_CFLAGS_SET   = 
Makefile_PACKAGE_CXXLAGS_SET  = 
Makefile_PACKAGE_LDFLAGS_SET  = 

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
# WATCHOUT - AM_LDFLAGS is not normally included in libtool final-link lines (whereas AM_CPPFLAGS, AM_CXXFLAGS are)
AM_LDFLAGS = $(PACKAGE_LDFLAGS_SET)
AM_LIBTOOLFLAGS = --silent

#end
