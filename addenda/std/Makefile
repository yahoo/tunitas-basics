# a -*- Makefile -*- by hand-crafted methods

default:

# configured.mk was established by ./configure; it defines
# $(prefix), $(vernacular_doggerel_datarootdir), $(hypogeal_twilight_datarootdir)
include mk/configured.mk
$(if $(prefix),$(__okay_continue),$(error prefix is unset))
distclean: distclean-mk/configured.mk
# do distclean in the tests first because they require ../../mk/configured.mk
distclean-mk/configured.mk:
	rm -f mk/configured.mk
	rm -f mk/extracted.mk mk/extracted.base.mk mk/extracted.check.mk
	rm -f ./configure

check: check-tests/teach
clean: clean-tests/teach
distclean: distclean-tests/teach
distclean-mk/configured.mk: distclean-tests/teach
check-tests/teach clean-tests/teach distclean-tests/teach:
	$(MAKE) -C tests/teach $(patsubst %-tests/teach,%,$@)

check: check-tests/using
clean: clean-tests/using
distclean: distclean-tests/using
distclean-mk/configured.mk: distclean-tests/using
check-tests/using clean-tests/using distclean-tests/using:
	$(MAKE) -C tests/using $(patsubst %-tests/using,%,$@)

# reminder: DESTDIR is non-empty in an rpmbuild environment
#           DESTDIR is already in $(prefix) from mk/configure.mk
includedir = $(prefix)/include
modulesdir = $(prefix)/modules

MODULES = $(patsubst modules/%,%,$(wildcard modules/std.*[^~]))
SOURCE_MODULES = $(addprefix modules/,$(MODULES))
all: $(SOURCE_MODULES)
clean: clean-MODULES
clean-MODULES: # nothing to clean?

INSTALLED_MODULES = $(addprefix $(modulesdir)/,$(MODULES))
install: $(INSTALLED_MODULES)
$(INSTALLED_MODULES) : $(modulesdir)/% : modules/%
	install -D -m 444 $< $@

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
