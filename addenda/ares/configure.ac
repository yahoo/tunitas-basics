# -*- autoconf -*-
# For terms and provenance see the LICENSE file at the top of this repository.

AC_INIT([module-ares], [0.4.0], [administrator@scold-lang.org])
HGTW_INIT(AC_PACKAGE_NAME, AC_PACKAGE_VERSION, AC_PACKAGE_BUGREPORT)

HGTW_COMPONENT_METADIRECTORY_TIERS
HGTW_ENABLE_CONFIGURE_VERBOSE
HGTW_ENABLE_GCC
HGTW_ENABLE_GDB
HGTW_ENABLE_GNU
HGTW_ENABLE_LIBTOOL_NO_INSTALL
HGTW_ENABLE_MOCK_BUILD

# Makefile.am these declarations must match the DEVELOPMENT_AREAS, TESTING_AREAS, INSTALLATION_AREAS
HGTW_MSG_VERBOSE([development subsystems (alphabetical)])
HGTW_WITH_MODULE([c])
HGTW_WITH_MODULE([ip])
HGTW_WITH_MODULE([nonstd])
HGTW_WITH_MODULE([posix])
HGTW_WITH_MODULE([std])
HGTW_WITH_MODULE([sys])
HGTW_WITH_ALIASED_MODULE([string], [c-string], [(C-type) Strings])

HGTW_MSG_VERBOSE([testing subsystems (alphabetical)])
HGTW_WITH_MODULE([cppunit])
HGTW_WITH_ALIASED_MODULE([rigging], [rigging-unit], [unit-rigging])

HGTW_MSG_VERBOSE([compiler-specific subsystems (alphabetical)])
dnl --with-std-scold is entailed above
HGTW_WITH_NONSTD([cppunit], [cppunit], [a non-standard CppUnit])
HGTW_WITH_NONSTD([gcc], [gcc], [a non-standard GCC, i.e.. modern gcc for C++26, but at least C++23])

HGTW_MSG_VERBOSE([system-side subsystems (alphabetical)])
HGTW_WITH_COMPONENT([hypogeal-twilight], [hypogeal_twilight], [S.C.O.L.D. Build System around The Autotools])
HGTW_WITH_COMPONENT([incendiary-sophist], [incendiary-sophist], [S.C.O.L.D. Test System around The Autotools])

AC_CONFIG_SRCDIR([src/ares/namespace.xcpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_FILES([Makefile ares_config.h lib/tests/config.sh])
AC_CONFIG_HEADERS([config.h])

AC_PREREQ([2.69])
AM_PROG_AR             dnl first
AC_PROG_LIBTOOL
AC_PROG_CXX
LT_PREREQ([2.4.2])
LT_INIT                dnl second
AC_LANG([C++])
# Checks for tools
HGTW_CHECK_DC
HGTW_CHECK_GCC
# Checks for packages
HGTW_CHECK_CPPUNIT
# Checks for libraries.
# Checks for header files.
# These are needed to build ares/addenda, which requires (a) the #define HAVE_* definitions and (b) the c-ares source code.
AC_CHECK_HEADERS([ \
    arpa/inet.h \
    arpa/in.h \
    arpa/nameser_compat.h \
    arpa/nameser.h \
    assert.h \
    errno.h \
    limits.h \
    netdb.h \
    net/if.h \
    netinet/in.h \
    netinet/tcp.h \
    socket.h \
    stdbool.h \
    strings.h \
    sys/ioctl.h \
    sys/param.h \
    sys/select.h \
    sys/socket.h \
    sys/time.h \
    sys/types.h \
    sys/uio.h \
    time.h \
])
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.

m4_include([ac/with-c-ares.m4])
ARES_WITH_C_ARES_SOURCE

# And ... you can build c-ares on systems that lack IPv6 but that is not our situation
# We force these because if you don't have them ... we don't want to be there.
AC_DEFINE_UNQUOTED(HAVE_AF_INET6, 1, [As such])
AC_DEFINE_UNQUOTED(HAVE_PF_INET6, 1, [As such])
AC_DEFINE_UNQUOTED(HAVE_STRUCT_TIMEVAL, 1, [As such])
AC_DEFINE_UNQUOTED(HAVE_BOOL_T, 1, [As such])
AC_DEFINE_UNQUOTED(HAVE_STRUCT_IN6_ADDR, 1, [As such])
AC_DEFINE_UNQUOTED(HAVE_STRUCT_IN_ADDR, 1, [As such])
AC_DEFINE_UNQUOTED(HAVE_STRUCT_SOCKADDR_IN, 1, [As such])
AC_DEFINE_UNQUOTED(HAVE_STRUCT_SOCKADDR_IN6, 1, [As such])
AC_DEFINE_UNQUOTED(HAVE_STRUCT_ADDRINFO, 1, [As such])
AC_DEFINE_UNQUOTED(HAVE_WRITEV, 1, [As such])

dnl Impliciations ... must also be defined.
dnl If HAVE_RECV is defined then RECV_TYPE_ARG1, RECV_TYPE_ARG2, RECV_TYPE_ARG3, RECV_TYPE_ARG4 and RECV_TYPE_RETV
dnl If HAVE_SEND is defined then SEND_TYPE_ARG1, SEND_QUAL_ARG2, SEND_TYPE_ARG2, SEND_TYPE_ARG3, SEND_TYPE_ARG4 and SEND_TYPE_RETV
dnl
dnl AC_DEFINE_UNQUOTED(HAVE_SEND, 1, [As such])
dnl AC_DEFINE_UNQUOTED(HAVE_RECV, 1, [As such])
dnl AC_DEFINE_UNQUOTED(HAVE_SENDTO, 1, [As such])
dnl AC_DEFINE_UNQUOTED(HAVE_RECVFROM, 1, [As such])
dnl
dnl See also the hackaround code in ./ares_config.h.in

HGTW_FINALIZE
