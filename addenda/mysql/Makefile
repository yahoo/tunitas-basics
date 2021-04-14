# a -*- Makefile -*- by hand-crafted methods

default:

# configured.mk was established by ./configure; it defines
# $(prefix), $(vernacular_doggerel_datarootdir), $(hypogeal_twilight_datarootdir)
include mk/configured.mk
$(if $(prefix),$(__okay_continue),$(error prefix is unset))
distclean: distclean-mk/configured.mk
# do distclean in the tests first because they require ../../mk/configured.mk
distclean-mk/configured.mk: distclean-release distclean-tests/teach
	rm -f mk/configured.mk
	rm -f mk/extracted.mk mk/extracted.base.mk mk/extracted.check.mk
	rm -f ./configure

# WATCHOUT - configured.mk defines these variables as empty even under --without-vernacular-doggerel
ifeq "undefined" "$(flavor vernacular_doggerel_datarootdir)"
$(warning vernacular_doggerel_datarootdir is undefined)
ifeq "" "$(vernacular_doggerel_datarootdir)"
$(warning vernacular_doggerel_datarootdir is empty)
else
ifneq "2" "$(words $(wildcard $(vernacular_doggerel_datarootdir)/mk/generate.mk $(vernacular_doggerel_datarootdir)/mk/build.mk))"
$(warning $(if $(wildcard $(vernacular_doggerel_datarootdir)/mk/generate.mk),present,absent) file $(vernacular_doggerel_datarootdir)/mk/generate.mk)
$(warning $(if $(wildcard $(vernacular_doggerel_datarootdir)/mk/build.mk),present,absent) file $(vernacular_doggerel_datarootdir)/mk/build.mk)
else
# ersatz: --disable-mock-build and (not) ENABLE_MOCK_BUILD
PACKAGE_SPEC_FILE = release/package.spec
trial-package: tar_here-rpmbuild-mock
      package: git_archive-rpmbuild-mock
CHECK_SPEC_FILE = release/check.spec
CHECK_SPEC_EXTRACT_FILE = $(PACKAGE_SPEC_FILE)
CHECK_DIRECTORY = release
trial-check-package:   thrm.check_release-rpmbuild-mock
      check-package: nothrm.check_release-rpmbuild-mock
  thrm.check_release-rpmbuild-mock: release/check.spec
nothrm.check_release-rpmbuild-mock: release/check.spec
include $(vernacular_doggerel_datarootdir)/mk/generate.mk
$(CHECK_SPEC_FILE): $(PACKAGE_SPEC_FILE) $(CHECK_SPEC_FILE).in 
	$(GENERATE-CHECK_SPEC_FILE)
distclean: distclean-release/check.spec
distclean-release/check.spec:
	rm -f release/check.spec
include $(vernacular_doggerel_datarootdir)/mk/build.mk
# defines $(release_MAKE_OPTIONS)
include release/compile.mk
distclean: distclean-release
clean: clean-release
check: check-release
distclean-release clean-release check-release:
	$(MAKE) -C release $(patsubst %-release,%,$@) $(release_MAKE_OPTIONS)
endif
endif
endif
distclean-release clean-release check-release:

distclean: distclean-tests/teach
clean: clean-tests/teach
check: check-tests/teach
distclean-tests/teach clean-tests/teach check-tests/teach:
	$(MAKE) -C tests/teach $(patsubst %-tests/teach,%,$@)

MODULES = $(patsubst modules/%,%,$(wildcard modules/mysqlpp.*[^~]))
SOURCE_MODULES = $(addprefix modules/,$(MODULES))
all: $(SOURCE_MODULES)
clean: # nothing to clean

# FIXME ... these ought to be set in ./mk/configured.mk via the ./configure processing
includedir ?= $(prefix)/include
modulesdir ?= $(prefix)/modules
libdir ?= $(prefix)/$(strip $(if $(wildcard /usr/lib64), lib64, lib))
_lib ?= $(notdir $(libdir))

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

default: all
check: all
distclean: clean
realclean: distclean

# When building inside of an rpm chroot, 'make install' is context-free
# When building outside of rpm, then 'make install' requires 'make check'.
$(if $(RPM_BUILD_ROOT),$(__install_no_check), install: check)
#end
