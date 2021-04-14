# source ${0%/*}/rigging.sh || exit 70
f=${0##*/}
b=${f%.test}
name=$b
__topdir=$(realpath ${0%/*}/../..)
: ${TEST_SOA:=fd2f-b678-14c8.net}
: ${TEST_DOMAIN:=ares.fd2f-b678-14c8.net}
export PATH="${__topdir?}/check/bin:${__topdir?}/bin:$PATH"
