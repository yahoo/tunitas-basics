# a -*- Makefile -*- by hand-crafted methods

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
# mirrored in release/check.spec.in
release_MAKE_OPTIONS = \
  prefix='$(prefix)' \
  SCOLDFLAGS='$(release_SCOLDFLAGS)' \
  CPPFLAGS='$(release_CPPFLAGS)' \
  CFLAGS='$(release_CFLAGS)' \
  CXXFLAGS='$(release_CXXFLAGS)' \
  LDFLAGS='$(release_LDFLAGS)' \
  $(end)
check: check-release
clean: clean-release
distclean: distclean-release
check-release clean-release distclean-release:
	$(MAKE) -C release $(patsubst %-release,%,$@) $(release_MAKE_OPTIONS)
# WATCHOUT - PWD is wrong under $(MAKE) -C
# FIXTHIS - TODO - get $(abs_top_srcdir} $(abs_top_builddir} from configure
TOP = $(PWD)
include release/compile.mk
endif
endif
endif

check: check-tests/teach
clean: clean-tests/teach
distclean: distclean-tests/teach
check-tests/teach clean-tests/teach distclean-tests/teach:
	$(MAKE) -C tests/teach $(patsubst %-tests/teach,%,$@)

MODULES = $(patsubst modules/%,%,$(wildcard modules/cppunit.*[^~]))
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

#end
