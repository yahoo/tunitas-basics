# This is a GNU -*- Makefile -*- which is managed by automake.
# Copyright Yahoo Inc. 2021
# Licensed under the terms of the Apache-2.0 license.
# For terms, see the LICENSE file at https://github.com/yahoo/tunitas-basics/blob/master/LICENSE
# For terms, see the LICENSE file at https://git.tunitas.technology/all/components/basics/tree/LICENSE

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
  $(module_format_prefix) \
  $(module_ip_prefix) \
  $(module_langu_prefix) \
  $(module_nonstd_prefix) \
  $(module_options_prefix) \
  $(module_posix_prefix) \
  $(module_std_prefix) \
  $(module_string_prefix) \
  $(module_sys_prefix) \
  $(microhttpd___prefix) \
  $(end)
TESTING_AREAS = \
  $(module_cppunit_prefix) \
  $(module_rigging_prefix) \
  $(end)
INSTALLATION_AREAS = \
  $(nonstd_cppunit_prefix) \
  $(nonstd_half_prefix) \
  $(nonstd_gcc_prefix) \
  $(std_scold_prefix) \
  $(std_tunitas_prefix) \
  $(end)

default: all

.PHONY: clean-local mostlyclean-local distclean-local
clean-local mostlyclean-local distclean-local::
clean-dependencies::
clean-local:: clean-dependencies

#
# WATCHOUT - module-sys >= 0.28.0-0.devel has an affectation on a module named 'sys.o'
#
#   #import sys.o         (problems occureven imported transitively by something you an't see)
#
# WATCHOUT - the following is needed to prevent make from trying to rebuild sys.o
#
#   gcc   /build/scold/module-sys/obj/modules/sys.o   -o /build/scold/module-sys/obj/modules/sys
#   /usr/bin/ld:/build/scold/module-sys/obj/modules/sys.o: file format not recognized; treating as linker script
#   /usr/bin/ld:/build/scold/module-sys/obj/modules/sys.o:1: syntax error
#
sys_o_DUMMIES = $(foreach obj, / /obj/, $(foreach ppp,/ /ipp/ /hpp/ /fpp/,$(module_sys_prefix)$(obj)modules$(ppp)sys.o))
.PHONY: $(sys_o_DUMMIES)
sys_DUMMIES = $(foreach obj, / /obj/, $(foreach ppp,/ /ipp/ /hpp/ /fpp/,$(module_sys_prefix)$(obj)modules$(ppp)sys))
.PHONY: $(sys_DUMMIES)

include src/tunitas/Makefrag.am
include src/tunitas/app/Makefrag.am
include src/tunitas/application/Makefrag.am
include src/tunitas/server/Makefrag.am
include src/want/Makefrag.am
include src/tests/unit/Makefrag.am
include src/tests/base64/Makefrag.am
include src/tests/outcome/Makefrag.am
include src/tests/urlsafe/Makefrag.am

# install rules from @temerarious_flagship_datadir@/am/install.am
INSTALL_MODULES = \
  $(lib_libtunitas_application_la_MODULES) \
  $(lib_libtunitas_server_la_MODULES) \
  $(lib_libtunitas_la_MODULES) \
 $(lib_libwant_la_MODULES) \
  $(end)
$(if $(DEBUGGING_CONDITION),$(info DEBUG INSTALL_MODULES=$(INSTALL_MODULES)))

# Whereas automake already takes care of this dependency (except in the lib_LTLIBRARIES installation ordering)
# NO NEED ---> $(lib_libtunitas_application_la) : $(lib_libtunitas_la) 
# NO NEED ---> $(lib_libtunitas_server_la) : $(lib_libtunitas_la) 

# WATCHOUT - the lib_LTLIBRARIES list MUST be in this order so that upon install the final link establishes the dependencies
bin_PROGRAMS = 
lib_LTLIBRARIES = \
  $(lib_libtunitas_la) \
  $(lib_libtunitas_app_la) \
  $(lib_libtunitas_application_la) \
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
# [[REMOVEWHEN]] temerarious-flagship supplies this, e.g. temerarious-flagship >= 1.1.2
include $(if $(filter 1,$(hypogeal_twilight_toolflags_mk_included)), /dev/null, @hypogeal_twilight_datadir@/mk/toolflags.mk)

# configure.ac: TF_ENABLE_GCC enables these @-variables
Makefile_COMPILER_CPPFLAGS_SET =                @CPPFLAGS_gcc@
Makefile_COMPILER_CFLAGS_SET   =   @CFLAGS_gdb@   @CFLAGS_gcc@
Makefile_COMPILER_CXXFLAGS_SET = @CXXFLAGS_gdb@ @CXXFLAGS_gcc@ -Wno-attributes
Makefile_COMPILER_LDFLAGS_SET  =  @LDFLAGS_gdb@  @LDFLAGS_gcc@  @libstd_filesystem@

# configure.ac: TF_WITH_NONSTD([something-something])
Makefile_nonstd_CPPFLAGS_SET = 
Makefile_nonstd_CFLAGS_SET   = 
Makefile_nonstd_CXXLAGS_SET  = 
Makefile_nonstd_LDFLAGS_SET  = 

# extras not otherwise covered by the TF_WITH_MODULE([...]) declarations
Makefile_PACKAGE_CPPFLAGS_SET = 
Makefile_PACKAGE_CFLAGS_SET   = 
Makefile_PACKAGE_CXXLAGS_SET  = 
Makefile_PACKAGE_LDFLAGS_SET  = 

#                                                  if    did not substitute away                      then use this
#                                                  |           |                                      |            else use the substitution
#                                                  |           |              @CPPFLAGS_no_install@   |            |
#                                                  |           |              |                       |            |
#                                                  |           |              |                       |            |
#                                                  v           v              v                       v            v
Makefile_CHECK_CPPFLAGS_SET = @CPPFLAGS_cppunit@ $(if $(filter %_no_install@, @CPPFLAGS_no_install@), $(empty),    @CPPFLAGS_no_install@)
Makefile_CHECK_CFLAGS_SET   =   @CFLAGS_cppunit@ $(if $(filter %_no_install@, @CFLAGS_no_install@),   $(empty),    @CFLAGS_no_install@)
Makefile_CHECK_CXXFLAGS_SET = @CXXFLAGS_cppunit@ $(if $(filter %_no_install@, @CXXFLAGS_no_install@), $(empty),    @CXXFLAGS_no_install@)
Makefile_CHECK_LDFLAGS_SET  =  @LDFLAGS_cppunit@ $(if $(filter %_no_install@, @LDFLAGS_no_install@),  -no-install, @LDFLAGS_no_install@)

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
# WATCHOUT - AM_LDFLAGS is not normally included in libtool final-link lines (whereas AM_CPPFLAGS, AM_CXXFLAGS are)
AM_LDFLAGS = $(PACKAGE_LDFLAGS_SET)
AM_LIBTOOLFLAGS = --silent

#end
