# source ${0%/*}/framework.sh || exit 1
f=${0##*/}
b=${f%.test}
name=$b
export PATH="${0%/*}/../../check/bin:${0%/*}/../../bin:$PATH"
