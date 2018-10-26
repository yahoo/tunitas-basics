# -*- Makefile -*-

# silent-rules has no effect, see configure.ac
# cannot -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:
include @temerarious_flagship_datarootdir@/am/build.am

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
clean-dependencies::
clean-local:: clean-dependencies

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

MODULES = \
  $(lib_libtunitas_la_MODULES) \
  $(lib_libwant_la_MODULES) \
  $(bin_unit_MODULES)  \
  $(end)
OBJECTS = \
  $(lib_libtunitas_la_OBJECTS) \
  $(lib_libwant_la_OBJECTS) \
  $(bin_unit_OBJECTS)  \
  $(end)
$(OBJECTS) : $(MODULES)

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

# The Makefile_*SET variables are assembled by .../toolflags.mk
# via @temerarious_flagship_datadir@/am/build.am and its constituents.

# configure.ac:  TF_ENABLE_GCC
Makefile_COMPILER_CPPFLAGS_SET = @CPPFLAGS_gcc@
Makefile_COMPILER_CFLAGS_SET   = @CFLAGS_gcc@
Makefile_COMPILER_CXXFLAGS_SET = @CXXFLAGS_gcc@ -Wno-attributes
Makefile_COMPILER_LDFLAGS_SET  = @LDFLAGS_gcc@  @libstd_filesystem@

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
