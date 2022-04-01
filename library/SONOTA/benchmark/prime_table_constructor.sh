#!/bin/bash
filename=prime_table_constructor
N=8
#os=Windows
os=Mac
if [[ "$os" == "Mac" ]]; then
/usr/local/bin/g++ ${filename}.cpp -o ${filename}
fi
if [[ "$os" == "Windows" ]]; then
/c/MinGW/bin/g++ ${filename}.cpp -o ${filename}
fi

k=1
for ((i=1 ; i<N+1 ; i++)) do
echo $((k=k*10))
./${filename} ${k}
done