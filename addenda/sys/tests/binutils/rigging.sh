# source ${0%/*}/rigging.sh || exit 1
f=${0##*/}
b=${f%.test}
name=$b
# DO NOT put .../libexec/posix in the PATH
# DO NOT export PATH="${0%/*}/../../libexec/posix:$PATH"
#
# because that directory has the testable elements in it
# which are named exactly the same as the Official POSIX Implementations
# from /usr/bin, but the arguments and semantics are different.
#
# instead provide these crutch-convenience
libexec="${0%/*}/../../libexec/posix"
exe=$libexec/$name
