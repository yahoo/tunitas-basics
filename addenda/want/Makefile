# This is a -*- Makefile -*- fragment
# Copyright Yahoo Inc, 2021.
# Licensed under the terms of the Apache-2.0 license.
# For terms, see the license file at the top of this repository.
# Also the LICENSE file at https://github.com/yahoo/tunitas-packaging/blob/master/LICENSE (as available)
# Also the LICENSE file at https://git.tunitas.technology/all/components/$PACKAGE/tree/LICENSE (as available)

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

distclean: distclean-mk/configured.mk
# do distclean in the tests first because they require ../../mk/configured.mk
distclean-mk/configured.mk: distclean-tests/teach
	rm -f mk/configured.mk
	rm -f mk/extracted.mk mk/extracted.base.mk mk/extracted.check.mk
	rm -f ./configure

# configured.mk was established by ./configure; it defines
# $(prefix), $(vernacular_doggerel_datarootdir), $(hypogeal_twilight_datarootdir)
include mk/configured.mk
$(if $(hypogeal_twilight_datarootdir),$(__okay_continue),$(error hypogeal_twilight_datarootdir is unset))
$(if $(prefix),$(__okay_continue),$(error prefix is unset))
include $(hypogeal_twilight_datarootdir)/am/compile.mk

# reminder: DESTDIR is non-empty in an rpmbuild environment
#           DESTDIR is already in $(prefix) from mk/configure.mk
includedir = $(prefix)/include
modulesdir = $(prefix)/modules

MODULES = want
BUILT_MODULES = $(addprefix modules/,$(MODULES))
all: $(BUILT_MODULES)
clean:

__DC = $(if $(bbDC), $(bbDC),$(error bbDC is undefined)) 
# reminder: DCFLAGS, SCOLDFLAGS are reserved to the command line
#           DCFLAGS isn't yet standardized, prefer SCOLDFLAGS
__DC_OPTIONS = \
  $(DCFLAGS) $(SCOLDFLAGS) \
  --no-insert-namespace \
  $(if $(VERBOSITY_CONDITION), --verbose) \
  $(if $(DEBUGGING_CONDITION), --debug) \
  $(end)

__srcdir = src
__objdir = $(__srcdir)
__modulesdir = modules
$(if $(filter ./%, $(__srcdir) $(__objdir) $(__modulesdir)), $(error DO NOT prefix these with ./))

$(BUILT_MODULES) : modules/% : src/%.xcpp
	mkdir -p $(@D)  $(foreach pp, fpp hpp ipp, $(@D)/$(pp))
	$(__DC) $(__DC_OPTIONS) --modulesdir=$(__modulesdir) --objdir=$(__objdir) --srcdir=$(__srcdir) $<
	$(foreach file,$@ $(foreach pp, fpp hpp ipp, $(@D)/$(pp)/$(@F)), test -e $(file) && ) true
clean: clean-BUILT_MODULES
clean-BUILT_MODULES:
	rm -f $(strip \
                $(foreach mod, $(MODULES), \
	                  modules/$(mod) src/$(mod).cpp \
	                  $(foreach pp, fpp hpp ipp, \
	                            modules/$(pp)/$(mod))))

INSTALLED_MODULES = \
  $(addprefix $(modulesdir), \
              $(foreach module, $(MODULES), \
                        $(foreach sep, / /fpp/ /hpp/ /ipp/, \
                                  $(sep)$(module) ))) \
  $(end)
install: $(INSTALLED_MODULES)
$(INSTALLED_MODULES) : $(modulesdir)/% : modules/%
	install -D -m 444 $< $@
clean: # nothing to clean
#end
