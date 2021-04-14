# This is a GNU -*- Makefile -*- template that is managed by Automake
# For terms and provenance see the LICENSE file at the top of this repository.

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:
include @hypogeal_twilight_datarootdir@/mk/compile.mk

DEVELOPMENT_AREAS = \
  $(module_c_prefix) \
  $(module_nonstd_prefix) \
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
clean-dependencies:: #                   REVERSED ... do use clean-dependencies ---> DEPRECATING clean-dependencies -- do not use in new work
mostlyclean-local:: clean-dependencies # REVERSED ... do use clean-dependencies ---> DEPRECATING clean-dependencies -- do not use in new work
clean-local:: clean-dependencies #       REVERSED ... do use clean-dependencies ---> DEPRECATING clean-dependencies -- do not use in new work

minuslsys_module = -lsys-module
minuslsys_call_module = $(info WARNING -lsys-call-module never did exist, instead use -lsys-module) -lsys-module
minuslsys_exits_module = $(info NOTICE -lsys-exits-module is deprecated, instead use -lsys-module) -lsys-exits-module
minuslsys_directory_module = -lsys-directory-module
minuslsys_posix_module = -lsys-posix-module
minuslsys_time_module = -lsys-time-module

include src/std/Makefrag.am
include src/sys/Makefrag.am
include src/sys/af/Makefrag.am
include src/sys/at/Makefrag.am
include src/sys/call/argument/Makefrag.am
include src/sys/call/result/Makefrag.am
include src/sys/detail/Makefrag.am
include src/sys/directory/Makefrag.am
include src/sys/dn/Makefrag.am
include src/sys/e/Makefrag.am
include src/sys/entry/Makefrag.am
include src/sys/error/Makefrag.am
include src/sys/ex/Makefrag.am
include src/sys/exit/Makefrag.am
include src/sys/exits/Makefrag.am
include src/sys/f/Makefrag.am
include src/sys/fd/Makefrag.am
include src/sys/flags/Makefrag.am
include src/sys/flagset/Makefrag.am
include src/sys/flock/Makefrag.am
include src/sys/id/Makefrag.am
include src/sys/ip/Makefrag.am
include src/sys/itimer/Makefrag.am
include src/sys/lck/Makefrag.am
include src/sys/lease/Makefrag.am
include src/sys/lock/Makefrag.am
include src/sys/lockf/Makefrag.am
include src/sys/log/Makefrag.am
include src/sys/msg/Makefrag.am
include src/sys/net/Makefrag.am
include src/sys/o/Makefrag.am
include src/sys/ok/Makefrag.am
include src/sys/p/Makefrag.am
include src/sys/pf/Makefrag.am
include src/sys/posix/packaging/Makefrag.am
include src/sys/posix/Makefrag.am
include src/sys/required/Makefrag.am
include src/sys/r/Makefrag.am
include src/sys/s/Makefrag.am
include src/sys/seek/Makefrag.am
include src/sys/shut/Makefrag.am
include src/sys/sig/Makefrag.am
include src/sys/sock/Makefrag.am
include src/sys/time/Makefrag.am
include src/sys/un/Makefrag.am
include src/sys/unlock/Makefrag.am
include src/sys/w/Makefrag.am
include src/sys/wait/Makefrag.am
include src/want/Makefrag.am

include src/tests/Makefrag.am
include src/tests/binutils/Makefrag.am
include src/tests/execing/Makefrag.am
include src/tests/flags/Makefrag.am
include src/tests/guardian/Makefrag.am
include src/tests/model/Makefrag.am
include src/tests/unit/Makefrag.am
include src/tests/unit/af/Makefrag.am
include src/tests/unit/at/Makefrag.am
include src/tests/unit/call/Makefrag.am
include src/tests/unit/detail/Makefrag.am
include src/tests/unit/directory/Makefrag.am
include src/tests/unit/dn/Makefrag.am
include src/tests/unit/e/Makefrag.am
include src/tests/unit/error/Makefrag.am
include src/tests/unit/ex/Makefrag.am
include src/tests/unit/exit/Makefrag.am
include src/tests/unit/exits/Makefrag.am
include src/tests/unit/f/Makefrag.am
include src/tests/unit/fd/Makefrag.am
include src/tests/unit/flagset/Makefrag.am
include src/tests/unit/flock/Makefrag.am
include src/tests/unit/id/Makefrag.am
include src/tests/unit/ip/Makefrag.am
include src/tests/unit/itimer/Makefrag.am
include src/tests/unit/lease/Makefrag.am
include src/tests/unit/lock/Makefrag.am
include src/tests/unit/lockf/Makefrag.am
include src/tests/unit/log/Makefrag.am
include src/tests/unit/msg/Makefrag.am
include src/tests/unit/o/Makefrag.am
include src/tests/unit/ok/Makefrag.am
include src/tests/unit/p/Makefrag.am
include src/tests/unit/pf/Makefrag.am
include src/tests/unit/posix/Makefrag.am
include src/tests/unit/r/Makefrag.am
include src/tests/unit/s/Makefrag.am
include src/tests/unit/seek/Makefrag.am
include src/tests/unit/shut/Makefrag.am
include src/tests/unit/sig/Makefrag.am
include src/tests/unit/sock/Makefrag.am
include src/tests/unit/sys/Makefrag.am
include src/tests/unit/time/Makefrag.am
include src/tests/unit/un/Makefrag.am
include src/tests/unit/w/Makefrag.am
include src/tests/unit/wait/Makefrag.am
include src/tests/unit/want/Makefrag.am
include src/tests/usage/Makefrag.am

handcoded_MODULES = \
  modules/sys.posix.af \
  modules/sys.posix.af.constants \
  modules/sys.posix.af.Type \
  modules/sys.posix.ipproto \
  modules/sys.posix.ipproto.Type \
  modules/sys.posix.pf \
  modules/sys.posix.pf.constants \
  modules/sys.posix.pf.Type \
  modules/sys.posix.sock \
  modules/sys.posix.sock.constants \
  modules/sys.posix.sock.Type \
  $(end)
INSTALL__MODULES = \
  $(hand_coded_MODULES) \
  $(lib_libsys_module_la_MODULES) \
  $(lib_libsys_error_module_la_MODULES) \
  $(lib_libsys_directory_module_la_MODULES) \
  $(lib_libsys_exits_module_la_MODULES) \
  $(lib_libsys_posix_module_la_MODULES) \
  $(lib_libsys_time_module_la_MODULES) \
  $(lib_libwant_la_MODULES) \
  $(end)
include $(hypogeal_twilight_datarootdir)/mk/install.mk # must be after all the include .../Makefrag.am where the MODULES variables are defined

lib_LTLIBRARIES = \
  $(lib_libsys_module_la) \
  $(lib_libsys_error_module_la) \
  $(lib_libsys_exits_module_la) \
  $(lib_libsys_directory_module_la) \
  $(lib_libsys_posix_module_la) \
  $(lib_libsys_time_module_la) \
  $(end)
noinst_LTLIBRARIES = \
  $(lib_libwant_la) \
  $(lib_libsys_log_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_execing) \
  $(check_bin_unit) \
  $(src_tests_binutils_CHECK_PROGRAMS_SET) \
  $(end)
check_LTLIBRARIES = \
  $(check_lib_libtests_la) \
  $(check_lib_libtests_flags_la) \
  $(check_lib_libtests_guardian_la) \
  $(src_tests_binutils_CHECK_LTLIBRARIES_SET) \
  $(end)
$(check_PROGRAMS) : $(check_LTLIBRARIES) $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)
$(bin_PROGRAMS) : $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)
$(lib_LTLIBRARIES) : $(noinst_LTLIBRARIES)
$(check_LTLIBRARIES) : $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)
#
# and link dependencies not covered by the above
#
# these are backwards-compatibility schemes with link dependencies
# these are deprecating...
$(lib_libsys_exits_module_la) : $(lib_libsys_module_la)
$(lib_libsys_error_module_la) : $(lib_libsys_module_la)

include tests/binutils/Makefrag.am
include tests/execing/Makefrag.am
include tests/unit/Makefrag.am
include tests/unit/call/Makefrag.am
include tests/unit/directory/Makefrag.am
include tests/unit/error/Makefrag.am
include tests/unit/exits/Makefrag.am
include tests/unit/posix/Makefrag.am
include tests/unit/sys/Makefrag.am
include tests/unit/time/Makefrag.am
include tests/unit/want/Makefrag.am
# in order, as stated.
TESTS = \
  $(tests_unit_TESTS) \
  $(tests_unit_call_TESTS) \
  $(tests_unit_directory_TESTS) \
  $(tests_unit_error_TESTS) \
  $(tests_unit_exits_TESTS) \
  $(tests_unit_posix_TESTS) \
  $(tests_unit_sys_TESTS) \
  $(tests_unit_time_TESTS) \
  $(tests_unit_want_TESTS) \
  $(tests_binutils_TESTS) \
  $(tests_execing_TESTS) \
  $(end)
XFAIL_TESTS = \
  $(tests_unit_XFAIL_TESTS) \
  $(tests_unit_call_XFAIL_TESTS) \
  $(tests_unit_directory_XFAIL_TESTS) \
  $(tests_unit_error_XFAIL_TESTS) \
  $(tests_unit_exits_XFAIL_TESTS) \
  $(tests_unit_posix_XFAIL_TESTS) \
  $(tests_unit_sys_XFAIL_TESTS) \
  $(tests_unit_time_XFAIL_TESTS) \
  $(tests_unit_want_XFAIL_TESTS) \
  $(tests_binutils_XFAIL_TESTS) \
  $(tests_execing_XFAIL_TESTS) \
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
Makefile_PACKAGE_CPPFLAGS_SET   = 
Makefile_PACKAGE_CFLAGS_SET     = 
Makefile_PACKAGE_CXXFLAGS_SET   = 
Makefile_PACKAGE_LDFLAGS_SET    = 
Makefile_CHECK_CPPFLAGS_SET     = @CPPFLAGS_cppunit@
Makefile_CHECK_CFLAGS_SET       = @CFLAGS_cppunit@
Makefile_CHECK_CXXFLAGS_SET     = @CXXFLAGS_cppunit@
Makefile_CHECK_LDFLAGS_SET      = @LDFLAGS_cppunit@ -no-install # hypogeal-twilight >= 0.45.0-0.devel will supply -no-install in CHECK

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
# WATCHOUT - AM_LDFLAGS is not mentioned in any automake final-link rules (avoid it or manually add it)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))
#end
