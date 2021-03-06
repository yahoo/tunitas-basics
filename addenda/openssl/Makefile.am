# This is a GNU -*- Makefile -*- template that is managed by Automake
# For terms and provenance see the LICENSE file at the top of this repository.

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:
include @hypogeal_twilight_datarootdir@/mk/compile.mk

# configure.ac these declarations must match the HGTW_WITH_MODULE declarations
DEVELOPMENT_AREAS = \
  $(module_c_prefix) \
  $(module_nonstd_prefix) \
  $(module_posix_prefix) \
  $(module_slurp_prefix) \
  $(module_std_prefix) \
  $(module_string_prefix) \
  $(module_sys_prefix) \
  $(end)
TESTING_AREAS = \
  $(module_cppunit_prefix) \
  $(module_rigging_prefix) \
  $(end)
INSTALLATION_AREAS = \
  $(nonstd_cppunit_prefix) \
  $(nonstd_gcc_prefix) \
  $(std_scold_prefix) \
  $(end)

# NOPE ... you can't say install depends upon check because
# then automake assesses that this is *the* install rule.
#install: check
default: all
# automake needs to see the ::-sense of these (not being occluded in GNUmake include)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::
include @hypogeal_twilight_datarootdir@/mk/distclean.mk
clean-dependencies::
mostlyclean-local:: clean-dependencies
clean-local:: clean-dependencies

module_BB_SOURCE_SET = \
  $(lib_libopenssl_module_la_SOURCES) \
  $(lib_libwant_la_SOURCES) \
  $(end)
include $(hypogeal_twilight_datarootdir)/mk/install.mk # must be after $(module_SOURCE_SET) is defined

include src/openssl/Makefrag.am
include src/want/Makefrag.am
include src/tests/Makefrag.am
include src/tests/unit/Makefrag.am
include src/tests/ec/Makefrag.am
include src/tests/rsa/Makefrag.am
include src/tests/ca/Makefrag.am
include src/tests/crt/Makefrag.am
include src/tests/crl/Makefrag.am
include src/tests/req/Makefrag.am

lib_LTLIBRARIES = \
  $(lib_libopenssl_module_la) \
  $(end)
noinst_LTLIBRARIES = \
  $(lib_libwant_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(check_bin_ec) \
  $(check_bin_rsa) \
  $(check_bin_ca) \
  $(check_bin_crt) \
  $(check_bin_crl) \
  $(check_bin_req) \
  $(end)
check_LTLIBRARIES = \
  $(lib_libtests_la) \
  $(end)
$(check_PROGRAMS) : $(check_LTLIBRARIES) $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)
$(bin_PROGRAMS) : $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)
$(lib_LTLIBRARIES) : $(noinst_LTLIBRARIES)
$(check_LTLIBRARIES) : $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)

# in alphabetical order, for clarity.
include tests/ca/Makefrag.am
include tests/crl/Makefrag.am
include tests/crt/Makefrag.am
include tests/ec/Makefrag.am
include tests/req/Makefrag.am
include tests/rsa/Makefrag.am
include tests/unit/Makefrag.am
# in positional order, as stated.
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_ec_TESTS) \
  $(tests_rsa_TESTS) \
  $(tests_ca_TESTS) \
  $(tests_crt_TESTS) \
  $(tests_crl_TESTS) \
  $(tests_req_TESTS) \
  $(end)
XFAIL_TESTS = \
  $(tests_unit_XFAIL_TESTS) \
  $(tests_ec_XFAIL_TESTS) \
  $(tests_rsa_XFAIL_TESTS) \
  $(tests_ca_XFAIL_TESTS) \
  $(tests_crt_XFAIL_TESTS) \
  $(tests_crl_XFAIL_TESTS) \
  $(tests_req_XFAIL_TESTS) \
  $(end)

# REMOVE WHEN: baleful_ballad:hypogeal-twilight-0.30.1 has work that supercedes this
Makefile_nonstd_PACKAGE_CPPFLAGS_SET = 
Makefile_nonstd_PACKAGE_CFLAGS_SET   = 
Makefile_nonstd_PACKAGE_CXXFLAGS_SET = 
Makefile_nonstd_PACKAGE_LDFLAGS_SET  = 
Makefile_nonstd_CHECK_CPPFLAGS_SET   = @nonstd_cppunit_CPPFLAGS@
Makefile_nonstd_CHECK_CFLAGS_SET     = @nonstd_cppunit_CFLAGS@
Makefile_nonstd_CHECK_CXXFLAGS_SET   = @nonstd_cppunit_CXXFLAGS@
Makefile_nonstd_CHECK_LDFLAGS_SET    = @nonstd_cppunit_LDFLAGS@

Makefile_COMPILER_CPPFLAGS_SET  = @CPPFLAGS_gcc@ 
Makefile_COMPILER_CFLAGS_SET    =   @CFLAGS_gcc@   @CFLAGS_gdb@
Makefile_COMPILER_CXXFLAGS_SET  = @CXXFLAGS_gcc@ @CXXFLAGS_gdb@
Makefile_COMPILER_LDFLAGS_SET   =  @LDFLAGS_gcc@  @LDFLAGS_gdb@ @libstd_filesystem@
Makefile_PACKAGE_CPPFLAGS_SET = 
Makefile_PACKAGE_CFLAGS_SET   = 
Makefile_PACKAGE_CXXFLAGS_SET = 
Makefile_PACKAGE_LDFLAGS_SET  = 
Makefile_CHECK_CPPFLAGS_SET   = @CPPFLAGS_cppunit@ @CPPFLAGS_no_install@
Makefile_CHECK_CFLAGS_SET     =   @CFLAGS_cppunit@   @CFLAGS_no_install@
Makefile_CHECK_CXXFLAGS_SET   = @CXXFLAGS_cppunit@ @CXXFLAGS_no_install@
Makefile_CHECK_LDFLAGS_SET    =  @LDFLAGS_cppunit@  @LDFLAGS_no_install@

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
# WATCHOUT - AM_LDFLAGS is not mentioned in any automake final-link rules (avoid it or manually add it)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))

#end
