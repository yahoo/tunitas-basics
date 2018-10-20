# -*- Makefile -*-

# silent-rules has no effect, see configure.ac
# cannot -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:
include @temerarious_flagship_datarootdir@/am/build.mk

# To get submodules to build in place, these go as a pair
#   configure.ac declares TF_CONFIG_SUBMODULES(directory, ...list...)
#   Makefile.am  declares SUBDIRS = @subdirs@
# there are no submodules (now).

DEVELOPMENT_AREAS = \
  @module_boost_prefix@ \
  @module_nonstd_prefix@ \
  @module_options_prefix@ \
  @module_posix_prefix@ \
  @module_std_prefix@ \
  @module_string_prefix@ \
  $(end)
TESTING_AREAS = \
  @module_cppunit_prefix@ \
  @module_rigging_prefix@ \
  $(end)
INSTALLATION_AREAS = \
  @nonstd_boost_prefix@ \
  @nonstd_cppunit_prefix@ \
  @nonstd_gcc_prefix@ \
  @std_scold_prefix@ \
  @std_tunitas_prefix@ \
  $(end)

default: all

module_SOURCE_SET = $(lib_libtunitas_module_la_SOURCES) $(lib_libwant_la_SOURCES)

.PHONY: clean-local mostlyclean-local distclean-local
clean-local mostlyclean-local distclean-local::

include src/tunitas/Makefrag.am
include src/want/Makefrag.am
include src/tests/unit/Makefrag.am

bin_PROGRAMS = 
lib_LTLIBRARIES = \
  $(lib_libtunitas_la) \
  $(end)
noinst_LTLIBRARIES = \
  $(lib_libwant_la) \
  $(end)
check_PROGRAMS = \
  $(bin_unit) \
  $(end)
check_LTLIBRARIES =

$(bin_PROGRAMS) : $(lib_LTLIBRARIES)
$(lib_LTLIBRARIES) : $(noinst_LTLIBRARIES)
$(check_PROGRAMS) : $(bin_PROGRAMS)
$(check_PROGRAMS) : $(lib_LTLIBRARIES)
$(check_PROGRAMS) : $(check_LTLIBRARIES)

include tests/unit/Makefrag.am
XFAIL_TESTS = \
  $(tests_unit_XFAIL_TESTS) \
  $(end)
XPASS_TESTS = \
  $(tests_unit_XPASS_TESTS) \
  $(end)
TESTS = \
  $(tests_unit_TESTS) \
  $(end)

gcc_CPPFLAG_SET = 
# -Wall      ... the language isn't complete without it
# -std=c++1y ... as close to C++14 and beyond as we can get
# -std=c++1z ... as close to C++17 and beyond as we can get
# -ggdb      ... and recall that -ggdb and -O2 don't play well together
#
# src/c/basic_buffer.consty.xcpp:54:35: warning: ‘implicit’ attribute directive ignored [-Wattributes]
# libstd_filesystem is -lstdc++fs or not
#
gcc_CXXFLAG_SET = -Wall -std=c++1z -fconcepts -ggdb -Wno-attributes
gcc_LDFLAG_SET = @libstd_filesystem@

# in scoped order
SEARCHPATH = \
  $(SEARCHPATH_SCOLD_MODULES) \
  $(SEARCHPATH_EXTERNAL_MODULES) \
  $(end)
LOADPATH = \
  $(DO NOT LOADPATH_SCOLD_MODULES) \
  $(LOADPATH_EXTERNAL_MODULES) \
  $(end)

AM_CPPFLAGS = \
  $(SEARCHPATH) \
  $(gcc_CPPFLAG_SET) \
  $(end)
AM_CXXFLAGS = \
  $(gcc_CXXFLAG_SET) \
  $(end)
# WATCHOUT - AM_LDFLAGS is not normally included in libtool final-link lines (whereas AM_CPPFLAGS, AM_CXXFLAGS are)
AM_LDFLAGS = \
  $(LOADPATH) \
  $(gcc_LDFLAG_SET) \
  $(end)
AM_LIBTOOLFLAGS = --silent

#end
