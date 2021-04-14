# This is a GNU -*- Makefile -*- template that is managed by Automake
# For terms and provenance see the LICENSE file at the top of this repository.

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:

DEVELOPMENT_AREAS = \
  $(module_c_prefix) \
  $(module_format_prefix) \
  $(module_nonstd_prefix) \
  $(module_posix_prefix) \
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
include $(hypogeal_twilight_datarootdir)/mk/compile.mk

# WATCHOUT in automake you can't tie 'check' to 'install'
check:
default: all
# automake needs to see the ::-sense of these (not being occluded in GNUmake include)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::
include $(hypogeal_twilight_datarootdir)/am/distclean.mk

include $(module_sys_prefix)/mk/sys.o.DUMMIES.mk

include src/ip/Makefrag.am
include src/ip/inet/Makefrag.am
include src/want/Makefrag.am
include src/tests/unit/Makefrag.am

INSTALL_MODULES = \
  $(lib_libip_module_la_MODULES) \
  $(lib_libinet_module_la_MODULES) \
  $(lib_libwant_la_MODULES) \
  $(end)
include $(hypogeal_twilight_datarootdir)/mk/install.mk # MUST be AFTER all the *_MODULES variable definitions

# in case this is not otherwise declared
$(lib_libinet_module_la) : $(lib_libip_module_la)
$(lib_libip_module_la) : $(lib_libwant_la)

noinst_LTLIBRARIES = \
  $(lib_libwant_la) \
  $(end)
lib_LTLIBRARIES = \
  $(lib_libip_module_la) \
  $(lib_libinet_module_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(end)
check_LTLIBRARIES = \
  $(end)

include tests/unit/Makefrag.am
include tests/unit/ip/Makefrag.am
include tests/unit/ip/as/Makefrag.am
include tests/unit/ip/endian/Makefrag.am
include tests/unit/ip/format/Makefrag.am
include tests/unit/ip/inet/Makefrag.am
include tests/unit/want/Makefrag.am
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_unit_want_TESTS) \
  $(tests_unit_ip_TESTS) \
  $(tests_unit_ip_as_TESTS) \
  $(tests_unit_ip_endian_TESTS) \
  $(tests_unit_ip_format_TESTS) \
  $(tests_unit_ip_inet_TESTS) \
  $(tests_unit_inet_TESTS) \
  $(end)
XFAIL_TESTS = \
  $(tests_unit_XFAIL_TESTS) \
  $(tests_unit_want_XFAIL_TESTS) \
  $(tests_unit_ip_XFAIL_TESTS) \
  $(tests_unit_ip_as_XFAIL_TESTS) \
  $(tests_unit_ip_endian_XFAIL_TESTS) \
  $(tests_unit_ip_format_XFAIL_TESTS) \
  $(tests_unit_ip_inet_XFAIL_TESTS) \
  $(tests_unit_inet_XFAIL_TESTS) \
  $(end)

include tests/unit/IPv4/Makefrag.am
include tests/unit/IPv6/Makefrag.am
include tests/unit/resolv/Makefrag.am
FIXME_NO_TESTS_YET = \
  $(tests_unit_IPv4_TESTS) \
  $(tests_unit_IPv6_TESTS) \
  $(tests_unit_resolv_TESTS) \
  $(end)

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
Makefile_CHECK_CPPFLAGS_SET    = @CPPFLAGS_cppunit@ -Wno-cpp
Makefile_CHECK_CFLAGS_SET      = @CFLAGS_cppunit@   -Wno-deprecated-declarations
Makefile_CHECK_CXXFLAGS_SET    = @CXXFLAGS_cppunit@ -Wno-deprecated-declarations
Makefile_CHECK_LDFLAGS_SET     = @LDFLAGS_cppunit@ @LDFLAGS_no_install@ # hypogeal-twilight >= 0.45.0-0.devel has this

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))
