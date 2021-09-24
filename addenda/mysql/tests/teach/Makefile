# a -*- Makefile -*- of course

default:

#
# Policy #1 - Only use the searchpath and loadpath elements from mysql config
#     mysql_config emits lots of other options which aren't helpful and will cause copious warnings and even compilation errors.
#    
#     To wit:
#       /usr/include/features.h:330:4: warning: #warning _FORTIFY_SOURCE requires compiling with optimization (-O) [-Wcpp]
#         #  warning _FORTIFY_SOURCE requires compiling with optimization (-O)
#            ^~~~~~~
#       g++ -c -o each/mysql++.sql_types.o -I../modules -I/usr/include/mysql -g -pipe -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector --param=ssp-buffer-size=4 -grecord-gcc-switches  -m64 -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -fPIC  -g -static-libgcc -fno-omit-frame-pointer -fno-strict-aliasing each/mysql++.sql_types.cpp
#

#
# Policy #2 - Shut up the warnings about deprecated use of auto_ptr.  Yes, It is deprecated.  We know this.
#     unfortunately this shuts up all other warnings about deprecated interfaces.
#     We are testing for whether the disaggreated "modules" style #include files even compile
#
#     To wit:
#       g++ -c -o each/mysql++.ResultBase.o -I../modules -I/opt/mysql++/include -I/usr/include/mysql each/mysql++.ResultBase.cpp
#       /opt/mysql++/include/mysql++/refcounted.h: In constructor ‘mysql++::RefCountedPointer<T, Destroyer>::RefCountedPointer(T*)’:
#       /opt/mysql++/include/mysql++/refcounted.h:104:8: warning: ‘template<class> class std::auto_ptr’ is deprecated [-Wdeprecated-declarations]
#          std::auto_ptr<T> exception_guard(counted_);
#               ^~~~~~~~
#

# is this a multilib 64-bit system at all?
lib64 = $(if $(wildcard /lib64), lib64, lib)

topdir = ../..
top_SEARCHPATH = -I$(topdir)/modules
top_LOADPATH   = 
top_LIBRARIES  = 
top_CPPFLAGS = $(top_SEARCHPATH)
top_CXXFLAGS = 
top_LDFLAGS  = $(top_LOADPATH) $(top_LIBRARIES)

# is mysql++ installed in a multilib style?
include ../../mk/configured.mk
mysql++_prefix = $(word 1, $(wildcard $(nonstd_mysqlpp_prefix) /opt/nonstd/mysql++ /opt/mysql++ /usr))
mysql++_includedir = $(addprefix $(mysql++_prefix)/, include)
__mysql++_libdir = $(addprefix $(mysql++_prefix)/, lib)
__mysql++_libdir64 = $(addprefix $(mysql++_prefix)/, $(lib64))
mysql++_libdir = $(if $(wildcard $(__mysql++_libdir64)), $(__mysql++_libdir64), $(__mysql++_libdir))
mysql++_CPPFLAGS := $(addprefix -I, $(mysql++_includedir))
mysql++_CXXFLAGS := 
mysql++_LDFLAGS  := $(addprefix -L, $(mysql++_libdir)) -Wl,$(addprefix -rpath=, $(mysql++_libdir)) -lmysqlpp

# Witness: mariadb-devel-10.2.10-2.fc27.x86_64
# WATCHOUT - mysql_config exits nonzero (exit 1) on --help and --usage; command not found is exit 127
ifeq "FAIL" "$(shell mysql_config --port >/dev/null || test 1 = $$? || echo FAIL)"
$(error could not execute mysql_config to compute the compilation flags)
endif
mysql_CPPFLAGS := $(filter -I%, $(shell mysql_config --cflags))
mysql_CXXFLAGS := 
mysql_LDFLAGS  := $(filter -L% -l%, $(shell mysql_config --libs))

# in case a nonstd-gcc is in play
gcc_prefix = $(word 1, $(wildcard $(nonstd_gcc_prefix) /opt/nonstd/gcc /opt/gcc /usr))
gcc_includedir = $(addprefix $(gcc_prefix)/, include)
__gcc_libdir = $(addprefix $(gcc_prefix)/, lib)
__gcc_libdir64 = $(addprefix $(gcc_prefix)/, $(lib64))
gcc_libdir = $(if $(wildcard $(__gcc_libdir64)), $(__gcc_libdir64), $(__gcc_libdir))
gcc_CPPFLAGS := $(addprefix -I, $(gcc_includedir))
# recall: C++ is not a complete language unless -Wall is supplied
# recall: we're looking to proof as aggressively into C++2a, C++2b, C++2c as we can.
gcc_CXXFLAGS := -std=c++20 -fconcepts -Wall -Wno-deprecated-declarations
gcc_LDFLAGS  := $(addprefix -L, $(gcc_libdir)) -Wl,$(addprefix -rpath=, $(gcc_libdir)) -lstdc++

# recall that ${TOOL}FLAGS are reserved to the command line; e.g. CPPFLAGS, CXXFLAGS, LDFLAGS
EACH_CPPFLAGS = $(top_CPPFLAGS) $(mysql++_CPPFLAGS) $(mysql_CPPFLAGS) $(gcc_CPPFLAGS)
EACH_CXXFLAGS = $(top_CXXFLAGS) $(mysql++_CXXFLAGS) $(mysql_CXXFLAGS) $(gcc_CXXFLAGS)
EACH_LDFLAGS  = $(top_LDFLAGS)  $(mysql++_LDFLAGS)  $(mysql_LDFLAGS)  $(gcc_LDFLAGS)

all: teach

EACH_MODULES = \
  $(patsubst $(topdir)/modules/%,%, \
             $(filter-out %~, \
	                  $(wildcard $(topdir)/modules/mysqlpp.*))) \
  $(end)

# default verbosity is the same as for fully automake-managed projects
DEFAULT_VERBOSITY = 0

# chatter for test case synthesis, 1st pass
V_GEN = $(__v_GEN_$(V))
__v_GEN_ = $(__v_GEN_$(DEFAULT_VERBOSITY))
# ......... = @echo "  GEN     " $@;
__v_GEN_0 = @echo "  GEN    ($@)";
__v_GEN_1 = 
EACH_CPPFILES = $(patsubst %, each/%.cpp, $(EACH_MODULES))
$(EACH_CPPFILES) : each/%.cpp : $(topdir)/modules/%
	$(V_GEN) t99="$(@D)/t99.$$$$.$(@F).t99"; \
	echo '#include <$(<F)>' > $$t99 && chmod a-w $$t99 && mv -f $$t99 $@
clean: clean-EACH_CPPFILES
clean-EACH_CPPFILES: ; : removing EACH_CPPFILES && rm -f $(EACH_CPPFILES)

# chatter for the compilation, 2st pass
V_CXX = $(__v_CXX_$(V))
__v_CXX_ = $(__v_CXX_$(DEFAULT_VERBOSITY))
# ......... = @echo "  CXX     " $@;
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

teach: each/main.o $(EACH_OFILES)
	$(V_CXX) $(CXX) -o $@ $^ $(EACH_LDFLAGS) $(LDFLAGS)
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

#end
