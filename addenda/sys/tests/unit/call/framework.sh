# source ${0%/*}/framework.sh || exit 1
f=${0##*/}
b=${f%.test}
name=$b
__topdir=$(realpath ${0%/*}/../../..)
export PATH="${__topdir?}/check/bin:${__topdir?}/bin:$PATH"
