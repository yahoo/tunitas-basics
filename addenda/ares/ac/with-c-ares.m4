dnl This is a GNU -*- autoconf -*- specification that is processed by Autoconf.
dnl For terms and provenance see the LICENSE file at the top of this repository.
dnl 
dnl ARES_WITH_C_ARES_SOURCE        (no arguments)
dnl
dnl Naming Convention Adherence
dnl
dnl   ARES_WITH_C_ARES_SOURCE
dnl   ^    ^    ^      ^
dnl   |    |    |      \----------------- the source tree 
dnl   |    |    |
dnl   |    |    \------------------------ "c-ares" is the name of the C language interface|
dnl   |    |
dnl   |    \----------------------------- "with" a subsystem
dnl   |
dnl   \---------------------------------- package prefix of this package (would be HGTW when standardized)
dnl
dnl Expectation
dnl
dnl   If you don't have the source code available then
dnl   git clone https://github.com/c-ares/c-ares.git
dnl
dnl Side-Effect:
dnl
dnl   c_ares_SOURCE becomes the source location for c-ares
dnl
dnl Usage:
dnl
dnl    configure.ac: m4_include([ac/with-c-ares.m4])
dnl    configure.ac: ARES_WITH_C_ARES_SOURCE
dnl
dnl    src/ares/addendum/Makefrag.am: $(lib_libares_addenda_la_OBJECTS) : AM_CPPFLAGS+=-I$(word 1, @c_ares_SOURCE@)
dnl
AC_DEFUN([ARES_WITH_C_ARES_SOURCE], [
    __c_ares_url=https://github.com/c-ares/c-ares.git
    __c_ares_subdir=$(pwd)/external/c-ares
    AC_ARG_WITH([c-ares-source],
                [AS_HELP_STRING([--with-c-ares-source], [(required) the top of a c-ares source tree])],
                [
                     case $withval in
                     ( yes | no )
                         HGTW_MSG_NOTICE([Expecting an instance of git clone ${__c_ares_url?}])
                         HGTW_MSG_ERROR([The value --with-c-ares-source=$withval must specify a directory location (an actual directory)])
                         ;;
                     ( * )
                         c_ares_SOURCE=$withval
                         HGTW_MSG_NOTICE([Compiling against the c-ares source tree at ${c_ares_SOURCE?}])
                         ;;
                     esac
                ], [
                    c_ares_SOURCE=${__c_ares_subdir?}
                    HGTW_MSG_NOTICE([Defaulting to use the c-ares source tree at ${c_ares_SOURCE?}])
                ])
    if ! test -d ${c_ares_SOURCE?} ; then
        HGTW_MSG_NOTICE([Expecting an instance of ${__c_ares_url?}])
        HGTW_MSG_NOTICE([Use: mkdir -p external && git clone ${__c_ares_url?} ${__c_ares_subdir?}])
        HGTW_MSG_ERROR([The option --with-c-ares-source=${c_ares_SOURCE:-(empty)} does not specify an actual directory])
    fi
    #
    # see .../src/ares/addenda/Makefrag.am
    #
    AC_SUBST([c_ares_SOURCE])

])
