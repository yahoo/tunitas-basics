# source ${0%/*}/rigging.sh || exit 1
d=${0%/*}; d=${d##*/}
f=${0##*/}
b=${f%.test}
name=$b
path=/path/$name
__topdir=$(realpath ${0%/*}/../../..)
export PATH="${__topdir?}/check/bin:${__topdir?}/bin:$PATH"
