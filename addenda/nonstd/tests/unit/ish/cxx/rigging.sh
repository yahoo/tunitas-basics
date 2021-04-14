# source ${0%/*}/rigging.sh || exit 70
d=${0%/*}; d=${d##*/}
f=${0##*/}
b=${f%.test}
name=$b
if [[ cases == $b ]] ; then path=/ish/$d ; else path=/ish/$d/$b ; fi
__topdir=$(realpath ${0%/*}/../../../..)
export PATH="${__topdir?}/check/bin:${__topdir?}/bin:$PATH"

