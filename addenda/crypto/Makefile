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
# $(prefix), $(hypogeal_twilight_datarootdir)
include mk/configured.mk
$(if $(prefix),$(__okay_continue),$(error prefix is unset, did you forget to ./buildconf && ./configure?))
distclean: distclean-mk/configured.mk
# do distclean in the tests first because they require ../../mk/configured.mk
distclean-mk/configured.mk: distclean-tests/teach
	rm -f mk/configured.mk
	rm -f mk/extracted.mk mk/extracted.base.mk mk/extracted.check.mk
	rm -f ./configure

# [[FIXTHIS]] These should be in ./configure
# [[FIXTHIS]] but ./configure is wholly boilerplate from ./buildconf
# [[FIXTHIS]] so there is no room for any custom checking
#
# What follows here is a very very crude check that Crypto++ is installed
#
# WATCHOUT - the constituent interfaces (header files) of Crypto++ have migrated & oscillated wildly since
# Fedora 27 - cryptopp-devel-5.6.5-2.fc27
# Fedora 28 - cryptopp-devel-6.1.0-2.fc28
# Fedora 29 - cryptopp-devel-7.0.0-2.fc29
# Fedora 30 - cryptopp-devel-8.2.0-1.fc30
# Fedora 31 - cryptopp-devel-8.2.0-2.fc31
# 2020-04-15 - Crypto++ 8.2 - https://www.cryptopp.com/wiki/Main_Page
#
cryptopp_prefix = /usr
cryptopp_includedir = $(cryptopp_prefix)/include
all: $(cryptopp_includedir)/cryptopp/cryptlib.h

check: check-tests/teach
clean: clean-tests/teach
distclean: distclean-tests/teach
check-tests/teach clean-tests/teach distclean-tests/teach:
	$(MAKE) -C tests/teach $(patsubst %-tests/teach,%,$@)

MODULES = \
  cryptopp \
  $(patsubst modules/%,%,$(wildcard modules/cryptopp.*[^~])) \
  $(end)
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
