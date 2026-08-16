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

echo "Enter Maximum Matrix:"

for ((i=0; i<n; i++))
do
    for ((j=0; j<m; j++))
    do
        read max[$i,$j]
    done
done

echo "Enter Available Resources:"

for ((j=0; j<m; j++))
do
    read avail[$j]
done

# Calculate Need Matrix
for ((i=0; i<n; i++))
do
    for ((j=0; j<m; j++))
    do
        need[$i,$j]=$((max[$i,$j] - alloc[$i,$j]))
    done
done

for ((i=0; i<n; i++))
do
    finish[$i]=0
done

count=0
safe_sequence=()

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
                if [ ${need[$i,$j]} -gt ${avail[$j]} ]
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
                safe_sequence+=("P$i")

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
    echo "System is in SAFE state."
    echo -n "Safe Sequence: "

    for ((i=0; i<n; i++))
    do
        echo -n "${safe_sequence[$i]}"

        if [ $i -lt $((n-1)) ]
        then
            echo -n " -> "
        fi
    done

    echo
else
    echo
    echo "System is NOT in a safe state."
fi
