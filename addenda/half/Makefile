# a -*- Makefile -*- by hand-crafted methods

default:

# configured.mk was established by ./configure; it defines
# $(prefix), $(hypogeal_twilight_datarootdir)
include mk/configured.mk
$(if $(prefix),$(__okay_continue),$(error prefix is unset))
distclean: distclean-mk/configured.mk
# do distclean in the tests first because they require ../../mk/configured.mk
distclean-mk/configured.mk: distclean-release distclean-tests/teach
	rm -f mk/configured.mk
	rm -f mk/extracted.mk mk/extracted.base.mk mk/extracted.check.mk
	rm -f ./configure
ifeq "" "$(nonstd_half_prefix)"
$(warning nonstd_half_prefix is unset)
$(warning it appears that this build was configured --without-nonstd-half)
$(warning there are no known "standard" implementations of half, the IEEE 746 "half-precision" library)
$(warning reconfigure using --with-nonstd-half=/opt/nonstd/half or similar)
$(error quitting)
endif

check: check-tests/teach
clean: clean-tests/teach
distclean: distclean-tests/teach
check-tests/teach clean-tests/teach distclean-tests/teach:
	$(MAKE) -C tests/teach $(patsubst %-tests/teach,%,$@)

MODULES = $(patsubst modules/%,%,$(wildcard modules/half_float.*[^~]))
SOURCE_MODULES = $(addprefix modules/,$(MODULES))
all: $(SOURCE_MODULES)
clean: # nothing to clean

# reminder: DESTDIR is non-empty in an rpmbuild environment
#           DESTDIR is already in $(prefix) from mk/configure.mk
includedir = $(prefix)/include
modulesdir = $(prefix)/modules

INSTALLED_MODULES = $(addprefix $(modulesdir)/,$(MODULES))
install: $(INSTALLED_MODULES)
$(INSTALLED_MODULES) : $(modulesdir)/% : modules/%
	install -D -m 444 $< $@
clean: # nothing to clean

default:
all:
check:
install:
usage:
clean:
realclean:
distclean:

check: all
default: all
distclean: clean
realclean: distclean

# When building inside of an rpm chroot, 'make install' is context-free
# When building outside of rpm, then 'make install' requires 'make check'.
$(if $(RPM_BUILD_ROOT),$(__install_no_check), install: check)
#end
