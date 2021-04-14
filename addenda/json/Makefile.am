# This is a GNU -*- Makefile -*- template that is managed by Automake
# For terms and provenance see the LICENSE file at the top of this repository.

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:

DEVELOPMENT_AREAS = \
  $(module_boost_prefix) \
  $(module_c_prefix) \
  $(module_std_prefix) \
  $(module_string_prefix) \
  $(module_sys_prefix) \
  $(end)
TESTING_AREAS = \
  $(module_cppunit_prefix) \
  $(module_rigging_prefix) \
  $(end)
INSTALLATION_AREAS = \
  $(nonstd_boost_prefix) \
  $(nonstd_cppunit_prefix) \
  $(nonstd_gcc_prefix) \
  $(nonstd_jsoncpp_prefix) \
  $(std_scold_prefix) \
  $(end)
include @hypogeal_twilight_datarootdir@/am/compile.mk

# NOPE ... you can't say install depends upon check because
# then automake assesses that this is *the* install rule.
check:
default: all
# automake needs to see the ::-sense of these (not being occluded in GNUmake include)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::
include @hypogeal_twilight_datarootdir@/am/distclean.mk

module_BB_SOURCE_SET = $(lib_libjson_module_la_SOURCES)
include @hypogeal_twilight_datarootdir@/am/install.mk

include src/json/Makefrag.am
include src/tests/unit/Makefrag.am
include src/tests/pretty/Makefrag.am

bin_PROGRAMS = \
  $(end)
lib_LTLIBRARIES = \
  $(lib_libjson_module_la) \
  $(end)
noinst_LTLIBRARIES = \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(check_bin_pretty)
  $(end)
check_LTLIBRARIES = \
  $(end)

$(bin_PROGRAMS) : $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)
$(lib_LTLIBRARIES) : $(noinst_LTLIBRARIES)
$(check_LTLIBRARIES) : $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)
$(check_PROGRAMS) : $(check_LTLIBRARIES)

include tests/unit/Makefrag.am
include tests/pretty/Makefrag.am
XFAIL_TESTS = \
  $(tests_unit_XFAIL_TESTS) \
  $(tests_pretty_XFAIL_TESTS) \
  $(end)
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_pretty_TESTS) \
  $(end)

# REMOVE WHEN: baleful_ballad:hypogeal-twilight-0.??.? has work that supercedes this
Makefile_nonstd_PACKAGE_CPPFLAGS_SET = @nonstd_boost_CPPFLAGS@ @nonstd_jsoncpp_CPPFLAGS@ 
Makefile_nonstd_PACKAGE_CFLAGS_SET   = @nonstd_boost_CFLAGS@   @nonstd_jsoncpp_CFLAGS@
Makefile_nonstd_PACKAGE_CXXFLAGS_SET = @nonstd_boost_CXXFLAGS@ @nonstd_jsoncpp_CXXFLAGS@
Makefile_nonstd_PACKAGE_LDFLAGS_SET  = @nonstd_boost_LDFLAGS@  @nonstd_jsoncpp_LDFLAGS@
Makefile_nonstd_CHECK_CPPFLAGS_SET   = @nonstd_cppunit_CPPFLAGS@
Makefile_nonstd_CHECK_CFLAGS_SET     = @nonstd_cppunit_CFLAGS@
Makefile_nonstd_CHECK_CXXFLAGS_SET   = @nonstd_cppunit_CXXFLAGS@
Makefile_nonstd_CHECK_LDFLAGS_SET    = @nonstd_cppunit_LDFLAGS@

Makefile_COMPILER_CPPFLAGS_SET  = @CPPFLAGS_gcc@ 
Makefile_COMPILER_CFLAGS_SET    =   @CFLAGS_gcc@   @CFLAGS_gdb@
Makefile_COMPILER_CXXFLAGS_SET  = @CXXFLAGS_gcc@ @CXXFLAGS_gdb@
Makefile_COMPILER_LDFLAGS_SET   =  @LDFLAGS_gcc@  @LDFLAGS_gdb@
Makefile_PACKAGE_CPPFLAGS_SET =  @CPPFLAGS_boost@ @CPPFLAGS_jsoncpp@ 
Makefile_PACKAGE_CFLAGS_SET   =    @CFLAGS_boost@   @CFLAGS_jsoncpp@
Makefile_PACKAGE_CXXFLAGS_SET =  @CXXFLAGS_boost@ @CXXFLAGS_jsoncpp@
Makefile_PACKAGE_LDFLAGS_SET  =   @LDFLAGS_boost@  @LDFLAGS_jsoncpp@
Makefile_CHECK_CPPFLAGS_SET   = @CPPFLAGS_cppunit@ @CPPFLAGS_no_install@
Makefile_CHECK_CFLAGS_SET     =   @CFLAGS_cppunit@   @CFLAGS_no_install@
Makefile_CHECK_CXXFLAGS_SET   = @CXXFLAGS_cppunit@ @CXXFLAGS_no_install@
Makefile_CHECK_LDFLAGS_SET    =  @LDFLAGS_cppunit@  @LDFLAGS_no_install@

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET) $(PACKAGE_CPPFLAGS_)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.VERBOSE_Veq$(V)) # WATCHOUT - automake does not use AM_LDFLAGS at all
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))
# end
