# This is a GNU -*- Makefile -*- which is managed by automake.
# Copyright Yahoo Inc. 2021
# Licensed under the terms of the Apache-2.0 license.
# For terms, see the LICENSE file at https://github.com/yahoo/tunitas-basics/blob/master/LICENSE
# For terms, see the LICENSE file at https://git.tunitas.technology/all/components/basics/tree/LICENSE

# silent-rules has no effect, see configure.ac
# cannot -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4
AM_MAKEFLAGS= \
  DO_NOT_REPASS_MAKEFLAGS='$(MAKEFLAGS)' \
  CPPFLAGS='$(CPPFLAGS)' \
  CXXFLAGS='$(CXXFLAGS)' \
  LDFLAGS='$(LDFLAGS)' \
  $(end)

# Whereas automake already takes care of this dependency (except in the lib_LTLIBRARIES installation ordering)
# NO NEED ---> $(lib_libtunitas_application_la) : $(lib_libtunitas_la) 
# NO NEED ---> $(lib_libtunitas_server_la) : $(lib_libtunitas_la) 

# WATCHOUT - the lib_LTLIBRARIES list MUST be in this order so that upon install the final link establishes the dependencies
bin_PROGRAMS = 
lib_LTLIBRARIES = \
  lib/libtunitas.la \
  lib/libtunitas-app.la \
  lib/libtunitas-application.la \
  lib/libtunitas-number.la \
  lib/libtunitas-server.la \
  $(end)
noinst_LTLIBRARIES = \
  noinst/lib/libtunitas.la \
  noinst/lib/libtunitas-application.la \
  noinst/lib/libtunitas-server.la \
  noinst/lib/libtunitas-number.la \
  noinst/lib/libstd+tunitas.la \
  noinst/lib/libwant.la \
  $(end)
check_PROGRAMS = \
  check/bin/unit \
  check/bin/base64-decode \
  check/bin/base64-encode \
  check/bin/outcome-error_code \
  check/bin/outcome-error_condition \
  check/bin/urlsafe-decode \
  check/bin/urlsafe-encode \
  $(end)
check_LTLIBRARIES = \
  check/lib/libtests-base64.la \
  check/lib/libtests-outcome.la \
  check/lib/libtests-urlsafe.la \
  $(end)

default:
# This bad design ... with limited tooling ... trying to get 'make' and one Makefile to do too many things "automatically"
# This recursion and the ordering can't be fixed or overridden.
#
# WATCHOUT ---> The default 'all' rule DOES NOT pass command-line variable embellishments down one gratuitous level
# WATCHOUT ---> all: config.h
# WATCHOUT --->	     $(MAKE) $(AM_MAKEFLAGS) all-am
# WATCHOUT --->	     $(MAKE) $(AM_MAKEFLAGS) all-am
# WATCHOUT ---> all-am: Makefile $(PROGRAMS) $(LTLIBRARIES) config.h
# WATCHOUT ---> 
# WATCHOUT ---> The default 'check' rule DOES NOT pass command-line variable embellishments down one gratuitous level
# WATCHOUT ---> check: check-am
# WATCHOUT ---> check-am: all-am
# WATCHOUT ---> 	$(MAKE) $(AM_MAKEFLAGS) $(check_PROGRAMS) $(check_LTLIBRARIES)
# WATCHOUT ---> 	$(MAKE) $(AM_MAKEFLAGS) check-TESTS
#
include tests/Makefrag.am
include @temerarious_flagship_datadir@/am/build.am
# [[REMOVEWHEN]] temerarious-1.1.0 provides .../am/build.am
$(if $(scold_cxxdir),$(__ok),$(error @temerarious_flagship_datadir@/am/build.am was incomplete))

# To get submodules to build in place, these go as a pair
#   configure.ac declares TF_CONFIG_SUBMODULES(directory, ...list...)
#   Makefile.am  declares SUBDIRS = @subdirs@
# there are no submodules (now).

DEVELOPMENT_AREAS = \
  $(module_cli_prefix) \
  $(module_half_prefix) \
  $(module_langu_prefix) \
  $(module_nonstd_prefix) \
  $(module_sys_prefix) \
  $(microhttpd___prefix) \
  $(deprecated_DEVELOPMENT_AREAS) \
  $(end)
TESTING_AREAS = \
  $(module_rigging_core_prefix) \
  $(deprecated_TESTING_AREAS) \
  $(end)
INSTALLATION_AREAS = \
  $(nonstd_cppunit_prefix) \
  $(nonstd_gcc_prefix) \
  $(nonstd_gmp_prefix) \
  $(nonstd_half_prefix) \
  $(opt_scold_prefix) \
  $(opt_tunitas_prefix) \
  $(deprecated_INSTALLATION_AREAS) \
  $(end)

default: all

.PHONY: clean-local mostlyclean-local distclean-local
clean-local mostlyclean-local distclean-local::
clean-dependencies::
clean-local:: clean-dependencies

# SHOULD already be supplied in .../am/build.am
# NEED ---> module_sys_datadir = $(dir $(word 1, $(wildcard $(addsuffix /mk /share/module-sys/mk,$(module_sys_prefix) $(std_scold_prefix) $(prefix)))))
# NEED ---> .PRECIOUS: $(module_sys_datadir)/mk/sys.o.DUMMIES.mk
# NEED ---> include $(module_sys_datadir)/mk/sys.o.DUMMIES.mk

include lib/libtunitas.am
include noinst/lib/libtunitas.am
include noinst/lib/libstd+tunitas.am
include noinst/lib/libwant.am

include check/bin/base64-encode.am
include check/bin/base64-decode.am
include check/lib/libtests-base64.am
include check/bin/unit.am

include lib/libtunitas-app.am
include lib/libtunitas-application.am
include noinst/lib/libtunitas-application.am
include lib/libtunitas-number.am
include noinst/lib/libtunitas-number.am
include lib/libtunitas-server.am
include noinst/lib/libtunitas-server.am

include check/bin/outcome-error_code.am
include check/bin/outcome-error_condition.am
include check/lib/libtests-outcome.am

include check/bin/urlsafe-encode.am
include check/bin/urlsafe-decode.am
include check/lib/libtests-urlsafe.am

# install rules from @temerarious_flagship_datadir@/am/install.am
INSTALL_MODULES = \
  $(noinst_lib_libtunitas_application_la_MODULES) \
  $(noinst_lib_libtunitas_server_la_MODULES) \
  $(noinst_lib_libtunitas_la_MODULES) \
  $(noinst_lib_libwant_la_MODULES) \
  $(end)
$(if $(DEBUGGING_CONDITION),$(info DEBUG INSTALL_MODULES=$(INSTALL_MODULES)))

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
Makefile_nonstd_CPPFLAGS_SET = @nonstd_gmp_c___CPPFLAGS@ @nonstd_half_CPPFLAGS@
Makefile_nonstd_CFLAGS_SET   =   @nonstd_gmp_c___CFLAGS@   @nonstd_half_CFLAGS@
Makefile_nonstd_CXXLAGS_SET  =  @nonstd_gmp_c___CXXLAGS@  @nonstd_half_CXXLAGS@
Makefile_nonstd_LDFLAGS_SET  = # the nonstd gmp-c++ LDFLAGS are applied in libtunitas-number.la (only)

# extras not otherwise covered by the TF_WITH_MODULE([...]) declarations
Makefile_PACKAGE_CPPFLAGS_SET = @CPPFLAGS_gmp_c__@
Makefile_PACKAGE_CFLAGS_SET   =   @CFLAGS_gmp_c__@
Makefile_PACKAGE_CXXLAGS_SET  = @CXXFLAGS_gmp_c__@
Makefile_PACKAGE_LDFLAGS_SET  = # the nonstd gmp-c++ LDFLAGS are applied in libtunitas-number.la (only)

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

deprecated_DEVELOPMENT_AREAS = \
  $(module_format_prefix) \
  $(module_ip_prefix) \
  $(module_options_prefix) \
  $(module_posix_prefix) \
  $(module_std_prefix) \
  $(module_string_prefix) \
  $(end)
deprecated_TESTING_AREAS = \
  $(module_cppunit_prefix) \
  $(module_rigging_prefix) \
  $(end)
deprecated_INSTALLATION_AREAS = \
  $(nonstd_cppunit_prefix) \
  $(end)
