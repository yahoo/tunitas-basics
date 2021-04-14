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

# is this a multilib 64-bit system at all?
lib64 = $(if $(wildcard /lib64), lib64, lib)

test_SEARCHPATH = -I$(TOP)/modules
test_LOADPATH   = 
test_LIBRARIES  = 
# recall: C++ is not a complete language unless -Wall is supplied
test_CXXFLAGS = $(test_SEARCHPATH) -Wall -Wno-deprecated-declarations
test_LDFLAGS  = $(test_LOADPATH) $(test_LIBRARIES)

all: teach

EACH_MODULES = \
  $(patsubst $(TOP)/modules/%,%, \
  $(filter-out $(TOP)/modules/j99.%, \
  $(filter-out $(TOP)/modules/t99.%, \
  $(filter-out $(TOP)/modules/%~, \
  $(wildcard $(TOP)/modules/*))))) \
  $(end)

AM_DEFAULT_VERBOSITY = 0
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
#. ........ = @echo "  GEN     " $@;
am__v_GEN_0 = @echo "  GEN     ($@)";
am__v_GEN_1 = 

AM_V_CXX = $(am__v_CXX_$(V))
am__v_CXX_ = $(am__v_CXX_$(AM_DEFAULT_VERBOSITY))
#. ........ = @echo "  CXX     " $@;
am__v_CXX_0 = @echo "  CXX     ($@)";
am__v_CXX_1 = 

AM_V_CXXLD = $(am__v_CXXLD_$(V))
am__v_CXXLD_ = $(am__v_CXXLD_$(AM_DEFAULT_VERBOSITY))
# ........... = @echo "  CXXLD   " $@;
am__v_CXXLD_0 = @echo "  CXXLD   ($@)";
am__v_CXXLD_1 = 


EACH_CPPFILES = $(patsubst %, each/%.cpp, $(EACH_MODULES))
$(EACH_CPPFILES) : each/%.cpp : $(TOP)/modules/%
	$(AM_V_GEN) t99="$(@D)/t99.$$$$.$(@F).t99"; \
	echo '#include <$(<F)>' > $$t99 && chmod a-w $$t99 && mv -f $$t99 $@
clean: clean-cppfiles
clean-cppfiles: ; rm -f $(EACH_CPPFILES)

EACH_OFILES   = $(patsubst %, each/%.o, $(EACH_MODULES))
$(EACH_OFILES) : each/%.o : each/%.cpp
	$(AM_V_CXX) $(CXX) -c -o $@ $(test_CXXFLAGS) $(CXXFLAGS) $<
clean: clean-ofiles
clean-ofiles: ; rm -f $(EACH_OFILES)

each/main.o: each/main.cpp
	$(AM_V_CXX) $(CXX) -c -o $@ $(test_CXXFLAGS) $(CXXFLAGS) $<
clean: clean-main.o
clean-main.o: ; rm -f each/main.o

# FIXME when is this necessary; when is this not necessary?
gcc_LDFLAGS := $(shell \
    gccpath=`type -p $(CXX)`; \
    if test /usr/bin/g++ != $$gccpath ; then \
        case `uname -m` in (x86_64) lib=lib64;; (*) lib=lib;; esac; \
        echo -Xlinker -rpath "$${gccpath%/*/*}/$$lib"; \
    fi \
)

teach: each/main.o $(EACH_OFILES)
	$(AM_V_CXXLD) $(CXX) -o $@ $^ $(test_LDFLAGS) $(LDFLAGS)
clean: clean-teach
clean-teach: ; rm -f each/main.o ./teach

check: teach
	./teach

#end
