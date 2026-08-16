#!/bin/bash

echo "Enter number of processes:"
read n

echo "Enter number of resources:"
read m

echo "Enter Allocation Matrix:"

for ((i=0; i<n; i++))
do
    for ((j=0; j<m; j++))
    do
        read alloc[$i,$j]
    done
done

echo "Enter Request Matrix:"

for ((i=0; i<n; i++))
do
    for ((j=0; j<m; j++))
    do
        read request[$i,$j]
    done
done

echo "Enter Available Resources:"

for ((j=0; j<m; j++))
do
    read avail[$j]
done

# Initialize finish array
for ((i=0; i<n; i++))
do
    finish[$i]=0
done

count=0

# Deadlock Detection
while [ $count -lt $n ]
do
    found=0

    for ((i=0; i<n; i++))
    do
        if [ ${finish[$i]} -eq 0 ]
        then
            possible=1

            for ((j=0; j<m; j++))
            do
                if [ ${request[$i,$j]} -gt ${avail[$j]} ]
                then
                    possible=0
                    break
                fi
            done

            if [ $possible -eq 1 ]
            then
                for ((j=0; j<m; j++))
                do
                    avail[$j]=$((avail[$j] + alloc[$i,$j]))
                done

                finish[$i]=1
                count=$((count + 1))
                found=1
            fi
        fi
    done

    if [ $found -eq 0 ]
    then
        break
    fi
done

if [ $count -eq $n ]
then
    echo
    echo "No Deadlock Detected."
else
    echo
    echo "Deadlock Detected."
    echo -n "Deadlocked Processes: "

    for ((i=0; i<n; i++))
    do
        if [ ${finish[$i]} -eq 0 ]
        then
            echo -n "P$i "
        fi
    done

    echo
fi
