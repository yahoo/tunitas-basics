# This is a -*- Makefile -*- fragment.
# For terms and provenance see the LICENSE file at the top of this repository.

# silent-rules has no effect, see configure.ac
# no can do:  -Wall -Werror
AUTOMAKE_OPTIONS = no-define subdir-objects foreign
ACLOCAL_AMFLAGS = -I m4

default:
# Makefrag.am:   NO SUBDIRS = @subdirs@
# configure.ac:  HGTW_CONFIG_SUBDIRS([submodule], [...list...])
include $(hypogeal_twilight_datarootdir)/am/compile.mk

DEVELOPMENT_AREAS = \
  $(module_c_prefix) \
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
INSTALLATION_AREAS =\
  $(nonstd_cppunit_prefix) \
  $(nonstd_gcc_prefix) \
  $(std_scold_prefix) \
  $(end)

#
# WATCHOUT - the following is needed to prevent make from trying to rebuild sys.o
#
#   gcc   /build/scold/module-sys/obj/modules/sys.o   -o /build/scold/module-sys/obj/modules/sys
#   /usr/bin/ld:/build/scold/module-sys/obj/modules/sys.o: file format not recognized; treating as linker script
#   /usr/bin/ld:/build/scold/module-sys/obj/modules/sys.o:1: syntax error
#
sys_DUMMIES   = $(foreach obj, / /obj/, $(foreach ppp,/ /ipp/ /hpp/ /fpp/,$(module_sys_prefix)$(obj)modules$(ppp)sys))
$(sys_DUMMIES): ; exit 0
sys_o_DUMMIES = $(foreach obj, / /obj/, $(foreach ppp,/ /ipp/ /hpp/ /fpp/,$(module_sys_prefix)$(obj)modules$(ppp)sys.o))
$(sys_o_DUMMIES): ; exit 0

# NOPE ... you can't say install depends upon check because
# then automake assesses that this is *the* install rule.
default: all
include $(hypogeal_twilight_datarootdir)/am/distclean.mk
# automake needs to see the ::-sense of these (not being occluded in GNUmake include)
clean-local::
distclean-local::
maintainer-clean-local::
mostlyclean-local::

module_BB_SOURCE_SET = $(lib_libshell_module_la_SOURCES) $(lib_libwant_la_SOURCES)
include $(hypogeal_twilight_datarootdir)/am/install.mk

# recall: the %-local suffix is a euphemism of automake, it's how you tie your actions into the mainline.
# it is our policy to use :: rules on the %-local hooks.

include src/autotools/autoconf/Makefrag.am
include src/shell/Makefrag.am
include src/shell/program/Makefrag.am
include src/want/Makefrag.am
include src/tests/unit/Makefrag.am

noinst_LTLIBRARIES = \
  $(lib_libautotools_autoconf_la) \
  $(lib_libwant_la) \
  $(end)
lib_LTLIBRARIES = \
  $(lib_libshell_module_la) \
  $(lib_libshell_program_la) \
  $(end)
check_PROGRAMS = \
  $(check_bin_unit) \
  $(end)
check_LTLIBRARIES = \
  $(end)

$(bin_PROGRAMS) : $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)
$(lib_LTLIBRARIES) : $(noinst_LTLIBRARIES)
$(check_PROGRAMS) : $(bin_PROGRAMS) $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)
$(check_LTLIBRARIES) : $(lib_LTLIBRARIES) $(noinst_LTLIBRARIES)
$(check_PROGRAMS) : $(check_LTLIBRARIES)

include tests/unit/Makefrag.am
TESTS = \
  $(tests_unit_TESTS) \
  $(end)

# [[REMOVEWHEN]] hypogeal-twilight >= 0.50? or so has work that supercedes this nonstd hackery
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
Makefile_CHECK_CPPFLAGS_SET    = @CPPFLAGS_cppunit@ @CPPFLAGS_no_install@
Makefile_CHECK_CFLAGS_SET      =   @CFLAGS_cppunit@   @CFLAGS_no_install@
Makefile_CHECK_CXXFLAGS_SET    = @CXXFLAGS_cppunit@ @CXXFLAGS_no_install@
Makefile_CHECK_LDFLAGS_SET     =  @LDFLAGS_cppunit@  @LDFLAGS_no_install@

AM_CPPFLAGS = $(PACKAGE_CPPFLAGS_SET)
AM_CFLAGS   = $(PACKAGE_CFLAGS_SET)
AM_CXXFLAGS = $(PACKAGE_CXXFLAGS_SET)
AM_LDFLAGS  = $(V_LDFLAGS_avoid.$(V))
AM_LIBTOOLFLAGS = $(V_LIBTOOLFLAGS_VERBOSE_Veq$(V))
#end
