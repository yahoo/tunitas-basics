# source ${0%/*}/framework.sh || exit 1
d=${0%/*}; d=${d##*/}
f=${0##*/}
b=${f%.test}
name=$b
#path=/$d/$b
path=/format/json/$b
export PATH="${0%/*}/../../../bin:$PATH"
