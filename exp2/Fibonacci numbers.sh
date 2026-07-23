#!/bin/bash

echo "ENTER THE LIMIT:"
read n

p=-1
q=1
i=1

while [ $i -le $n ]
do
    r=$((p + q))
    p=$q
    q=$r
    echo "$r"
    i=$((i + 1))
done
