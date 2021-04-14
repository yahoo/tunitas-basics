# a -*- Makefile -*- of course

default:
all:
clean:
realclean:
distclean:
maintainer-clean maintainerclean:
check:
install:

check: all
default: all
distclean: clean
install: check
maintainer-clean maintainerclean: distclean
realclean: distclean

TOP = ../..
# defines nonstd_${COMPONENT}_prefix
include $(TOP)/mk/configured.mk

# REMOVE WHEN hypogeal-twilight >= 0.42
# WATCHOUT hypogeal-twilight v0.41 DOES NOT supply these definitions
#          hypogeal-twilight v0.42 does supply these definitions
nonstd_gcc_prefix ?= $(word 1, $(wildcard /opt/nonstd/gcc /opt/gcc))
nonstd_half_prefix ?= $(word 1, $(wildcard /opt/nonstd/half /opt/half))

# in case it was set from ./configure --libdir=...
_lib = $(notdir $(libdir))
includedir ?= $(prefix)/include
modulesdir ?= $(prefix)/modules
libdir ?= $(prefix)/$(strip $(if $(wildcard /usr/lib64), lib64, lib))
_lib ?= $(notdir $(libdir))
# NOT include compile.mk ... the compile.mk is only for ../Makefile
$(if $(includedir),$(__ok_continue),$(error includedir is undefined))
$(if $(libdir),$(__ok_continue),$(error libdir is undefined))
$(if $(modulesdir),$(__ok_continue),$(error modulesdir is undefined))
$(if $(_lib),$(ok),$(error _lib is undefined, which means libdir is undefined))

__Wlrpath = -Wl,-rpath=

# recall: C++ is not a complete language unless -Wall is supplied
# also:   nonstd-gcc's excess configurations, e.g. -Wl,-rpath=$libdir are already in tests_${TOOL}FLAGS.
__other_gcc_CPPFLAGS = 
__other_gcc_CXXFLAGS = -std=c++1z -fconcepts -Wall -Wno-deprecated-declarations
__other_gcc_LDFLAGS  = 
gcc_CPPFLAGS = $(__other_gcc_CPPFLAGS) $(addprefix -I, $(addsuffix /include, $(nonstd_gcc_prefix)))
gcc_CXXFLAGS = $(__other_gcc_CXXFLAGS)
gcc_LDFLAGS  = $(__other_gcc_LDFLAGS) $(foreach root, $(nonstd_gcc_prefix), \
                                                $(addprefix -L, $(addsuffix $(addprefix /, $(_lib)), $(root))) \
                                                $(addprefix $(__Wlrpath), $(addsuffix $(addprefix /, $(_lib)), $(root))))

__other_half_CPPFLAGS = 
__other_half_CXXFLAGS = 
__other_half_LDFLAGS  = 
half_CPPFLAGS = $(__other_half_CPPFLAGS) $(addprefix -I, $(addsuffix /include, $(nonstd_half_prefix)))
half_CXXFLAGS = $(__other_half_CXXFLAGS)
half_LDFLAGS  = $(__other_half_LDFLAGS) $(foreach root, $(nonstd_half_prefix), \
                                                    $(addprefix -L, $(addsuffix $(addprefix /, $(_lib)), $(root))) \
                                                    $(addprefix $(__Wlrpath), $(addsuffix $(addprefix /, $(_lib)), $(root))))

# reminder: this Makefile expects to be executed within mock's rpmbuild environment with the nonstd
# compnentry being installed in the standard areas. When operated in the development environment,
# the devel_${TOOL}FLAGS are used to communicate the nonstd locations.  The ${TOOL}FLAGS} are still
# reserved to the command line.
__SEARCHPATH = -I$(TOP)/modules
__LOADPATH   = 
__LIBRARIES  = 
__CPPFLAGS = $(__SEARCHPATH) $(half_CPPFLAGS) $(gcc_CPPFLAGS)
__CXXFLAGS =                 $(half_CXXFLAGS) $(gcc_CXXFLAGS)
__LDFLAGS  = $(__LOADPATH)   $(half_LDFLAGS)  $(gcc_LDFLAGS) $(__LIBRARIES)

# devel_${TOOL}FLAGS is reserved to the caller (the a recursive $(MAKE))
EACH_CPPFLAGS = $(__CPPFLAGS) $(devel_CPPFLAGS) $(CPPFLAGS)
EACH_CXXFLAGS = $(__CXXFLAGS) $(devel_CXXFLAGS) $(CXXFLAGS) 
TEACH_LDFLAGS = $(__LDFLAGS)  $(devel_LDFLAGS)  $(LDFLAGS) 

all: teach

EACH_MODULES = \
  $(patsubst $(TOP)/modules/%,%, \
             $(filter-out %~, \
	                  $(wildcard $(TOP)/modules/half_float.*))) \
  $(end)

# default verbosity is the same as for fully automake-managed projects
DEFAULT_VERBOSITY = 0

# Chatter for test case synthesis, 1st pass.
V_GEN = $(__v_GEN_$(V))
__v_GEN_ = $(__v_GEN_$(DEFAULT_VERBOSITY))
__v_GEN_0 = @echo "  GEN    ($@)";
__v_GEN_1 = 
EACH_CPPFILES = $(patsubst %, each/%.cpp, $(EACH_MODULES))
$(EACH_CPPFILES) : each/%.cpp : $(TOP)/modules/%
	$(V_GEN) t99="$(@D)/t99.$$$$.$(@F).t99"; \
	echo '#include <$(<F)>' > $$t99 && chmod a-w $$t99 && mv -f $$t99 $@
clean: clean-EACH_CPPFILES
clean-EACH_CPPFILES: ; : removing EACH_CPPFILES && rm -f $(EACH_CPPFILES)

# Chatter for the compilation, 2st pass.
V_CXX = $(__v_CXX_$(V))
__v_CXX_ = $(__v_CXX_$(DEFAULT_VERBOSITY))
__v_CXX_0 = @echo "  CXX    ($@)";
__v_CXX_1 = 
EACH_OFILES   = $(patsubst %, each/%.o, $(EACH_MODULES))
$(EACH_OFILES) : each/%.o : each/%.cpp
	$(V_CXX) $(CXX) -c -o $@ $(EACH_CPPFLAGS) $(CPPFLAGS) $(EACH_CXXFLAGS) $(CXXFLAGS) $<
clean: clean-EACH_OFILES
clean-EACH_OFILES: ; : removing EACH_OFILES && rm -f $(EACH_OFILES)

each/main.o : each/main.cpp
	$(V_CXX) $(CXX) -c -o $@ $(EACH_CXXFLAGS) $(CXXFLAGS) $<
clean: clean-each/main.o
clean-each/main.o: ; rm -f ./each/main.o

# Chatter for the linking, 3rd pass.
V_LINK = $(__v_LINK_$(V))
__v_LINK_ = $(__v_LINK_$(DEFAULT_VERBOSITY))
__v_LINK_0 = @echo "  LINK   ($@)";
__v_LINK_1 = 
teach: each/main.o $(EACH_OFILES)
	$(V_LINK) $(CXX) -o $@ $^ $(TEACH_LDFLAGS) $(LDFLAGS)
clean: clean-teach
clean-teach: ; rm -f ./teach

# chatter for the test execution, 3rd pass
V_TEST = $(__v_TEST_$(V))
__v_TEST_ = $(__v_TEST_$(DEFAULT_VERBOSITY))
# ......... = @echo "  GEN     " $@;
__v_TEST_0 = @echo "  TEST   ($@)";
__v_TEST_1 = 
check: teach
	$(V_TEST) ./teach

#end
