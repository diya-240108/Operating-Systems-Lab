#!/bin/bash

echo "Enter number of memory blocks:"
read n

echo "Enter block sizes:"
for ((i=0; i<n; i++))
do
    read block[$i]
done

echo "Enter number of processes:"
read m

echo "Enter process sizes:"
for ((i=0; i<m; i++))
do
    read process[$i]
done

for ((i=0; i<m; i++))
do
    allocated=0

    for ((j=0; j<n; j++))
    do
        if [ ${block[$j]} -ge ${process[$i]} ]
        then
            echo "Process $((i+1)) allocated to Block $((j+1))"
            block[$j]=$((block[$j] - process[$i]))
            allocated=1
            break
        fi
    done

    if [ $allocated -eq 0 ]
    then
        echo "Process $((i+1)) cannot be allocated"
    fi
done
