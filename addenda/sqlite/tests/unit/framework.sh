# source ${0%/*}/framework.sh || exit 80
f=${0##*/}
b=${f%.test}
name=$b
exe=unit
__topdir="${0%/*}/../.."
export PATH="${__topdir?}/check/bin:${__topdir?}/bin:$PATH"
