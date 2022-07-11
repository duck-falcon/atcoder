contestName=`pwd | awk -F "/" '{ print $NF }'`
d=`python3 ../library/get-test.py ${contestName} ${1}`

# mac
if [ "$(uname)" == 'Darwin' ]; then
  g++-11 ${1}.cpp -o ${1}
else
  g++ ${1}.cpp -o ${1}
fi


if [ ! -e ${1}myans ]; then
	  mkdir ${1}myans
fi

#個別テスト
if [[ $# == 2 ]]; then
	d=$2
	./${1} < ${1}in/${1}in${d}.txt > ${1}myans/${1}myans${d}.txt
	python3 ../library/auto-test.py ${1} ${d}
else
	for ((i=0 ; i<d; i++)) do
		  ./${1} < ${1}in/${1}in${i}.txt > ${1}myans/${1}myans${i}.txt
	  done
	  python3 ../library/auto-test.py ${1}
fi
