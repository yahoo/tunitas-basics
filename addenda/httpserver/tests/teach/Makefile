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
nonstd_httpserver_prefix = $(error nonstd_httpserver_prefix is invalid, use nonstd_libhttpserver_prefix ...libhttpserver, that 'lib' prefix is pesky and you learn to ignore it)


# in case it was set from ./configure --libdir=...
_lib = $(notdir $(libdir))

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

__other_httpserver_CPPFLAGS = 
__other_httpserver_CXXFLAGS = 
__other_httpserver_LDFLAGS  = 
httpserver_CPPFLAGS = $(__other_httpserver_CPPFLAGS) $(addprefix -I, $(addsuffix /include, $(nonstd_libhttpserver_prefix)))
httpserver_CXXFLAGS = $(__other_httpserver_CXXFLAGS)
httpserver_LDFLAGS  = $(__other_httpserver_LDFLAGS) $(foreach root, $(nonstd_libhttpserver_prefix), \
                                                              $(addprefix -L, $(addsuffix $(addprefix /, $(_lib)), $(root))) \
                                                              $(addprefix $(__Wlrpath), $(addsuffix $(addprefix /, $(_lib)), $(root))))

# reminder: this Makefile expects to be executed within mock's rpmbuild environment with the nonstd
# compnentry being installed in the standard areas. When operated in the development environment,
# the devel_${TOOL}FLAGS are used to communicate the nonstd locations.  The ${TOOL}FLAGS} are still
# reserved to the command line.
__SEARCHPATH = -I$(TOP)/modules
__LOADPATH   = 
__LIBRARIES  = 
__CPPFLAGS = $(__SEARCHPATH) $(httpserver_CPPFLAGS) $(gcc_CPPFLAGS)
__CXXFLAGS =                 $(httpserver_CXXFLAGS) $(gcc_CXXFLAGS)
__LDFLAGS  = $(__LOADPATH)   $(httpserver_LDFLAGS)  $(gcc_LDFLAGS) $(__LIBRARIES)

# The $(devel_${TOOL}FLAGS) are reserved to the caller (a recursive $(MAKE))
# The (${TOOL}FLAGS} are reserved to the command line (which may also be a recursive $(MAKE))
EACH_CPPFLAGS = $(__CPPFLAGS) $(devel_CPPFLAGS) $(CPPFLAGS)
EACH_CXXFLAGS = $(__CXXFLAGS) $(devel_CXXFLAGS) $(CXXFLAGS) 
TEACH_LDFLAGS = $(__LDFLAGS)  $(devel_LDFLAGS)  $(LDFLAGS) 

all: teach

EACH_MODULES = \
  $(patsubst $(TOP)/modules/%,%, \
             $(filter-out %~, \
	                  $(wildcard $(TOP)/modules/httpserver.*))) \
  $(end)

DEFAULT_VERBOSITY = 0
V_GEN = $(__v_GEN_$(V))
__v_GEN_ = $(__v_GEN_$(DEFAULT_VERBOSITY))
__v_GEN_0 = @echo "  GEN     ($@)";
__v_GEN_1 = 

V_CXX = $(__v_CXX_$(V))
__v_CXX_ = $(__v_CXX_$(DEFAULT_VERBOSITY))
__v_CXX_0 = @echo "  CXX     ($@)";
__v_CXX_1 = 

V_CXXLD = $(__v_CXXLD_$(V))
__v_CXXLD_ = $(__v_CXXLD_$(DEFAULT_VERBOSITY))
__v_CXXLD_0 = @echo "  LINK    ($@)";
__v_CXXLD_1 = 

EACH_CPPFILES = $(patsubst %, each/%.cpp, $(EACH_MODULES))
$(EACH_CPPFILES) : each/%.cpp : $(TOP)/modules/%
	$(V_GEN) t99="$(@D)/t99.$$$$.$(@F).t99"; \
	echo '#include <$(<F)>' > $$t99 && chmod a-w $$t99 && mv -f $$t99 $@
clean: clean-cppfiles
clean-cppfiles: ; rm -f $(EACH_CPPFILES)

EACH_OFILES = $(patsubst %, each/%.o, $(EACH_MODULES))
$(EACH_OFILES) : each/%.o : each/%.cpp
	$(V_CXX) $(CXX) -c -o $@ $(EACH_CPPFLAGS) $(EACH_CXXLFAGS) $<
clean: clean-ofiles
clean-ofiles: ; rm -f $(EACH_OFILES)

each/main.o: each/main.cpp
	$(V_CXX) $(CXX) -c -o $@ $(EACH_CPPFLAGS) $(EACH_CXXFLAGS) $<
clean: clean-main.o
clean-main.o: ; rm -f each/main.o

teach: each/main.o $(EACH_OFILES)
	$(V_CXXLD) $(CXX) -o $@ $^ $(TEACH_LDFLAGS)
clean: clean-teach
clean-teach: ; rm -f each/main.o ./teach

check: teach
	./teach

#end
