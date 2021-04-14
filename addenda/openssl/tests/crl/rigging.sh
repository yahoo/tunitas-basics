# source ${0%/*}/rigging.sh || exit 70
f=${0##*/}
b=${f%.test}
exe=${0%/*}; exe=${exe##*/}
name=$b
path=/${name}
__topdir=$(realpath ${0%/*}/../..)
export PATH="${__topdir?}/check/bin:${__topdir?}/bin:$PATH"
