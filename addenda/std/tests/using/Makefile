# This is a regular GNU -*- Makefile -*- without any autotools support expectations
default:
all:
check:
clean:
distclean:

LIBS = $(none)

EXE = prove
SRCS = main.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

topdir = ../..
# the ${TOOL}FLAGS are reserved to the command line
Makefile_CPPFLAGS = -I$(topdir)/modules -I$(topdir)/include
Makefile_CXXFLAGS = -ggdb -std=c++1z -fconcepts
Makefile_LDFLAGS  = -lstdc++fs

_COMPILE = $(Makefile_CPPFLAGS) $(CPPFLAGS) $(Makefile_CXXFLAGS) $(CXXFLAGS)
clean: clean-OBJS
clean-OBJS: ; rm -f $(OBJS)
$(OBJS) : %.o : %.cpp
	$(CXX) -o $@ -c $(_COMPILE) $<
_LINK = $(Makefile_LDFLAGS) $(LDFLAGS)
CXXLD = $(CXX)
clean: clean-EXE
clean-EXE: ;rm -f $(EXE)
$(EXE) : $(OBJS)
	$(CXXLD) -o $@ $(_LINK) $< $(LIBS)

run: $(EXE)
	./$(EXE)

check: run
all: $(EXE)
default: all
