#!/bin/bash

echo "ENTER THE RANGE:"
read n

x=1
sum=0

while [ $x -le $n ]
do
    sum=$((sum + x))
    x=$((x + 2))
done

echo "SUM OF ODD NUMBERS = $sum"
