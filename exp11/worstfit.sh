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
    worst=-1

    for ((j=0; j<n; j++))
    do
        if [ ${block[$j]} -ge ${process[$i]} ]
        then
            if [ $worst -eq -1 ] || [ ${block[$j]} -gt ${block[$worst]} ]
            then
                worst=$j
            fi
        fi
    done

    if [ $worst -ne -1 ]
    then
        echo "Process $((i+1)) allocated to Block $((worst+1))"
        block[$worst]=$((block[$worst] - process[$i]))
    else
        echo "Process $((i+1)) cannot be allocated"
    fi
done
