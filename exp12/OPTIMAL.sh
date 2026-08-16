#!/bin/bash

echo "Enter number of page references:"
read n

echo "Enter page reference string:"
read -a pages

echo "Enter number of frames:"
read frames

declare -a memory
faults=0

for ((i=0; i<n; i++))
do
    page=${pages[$i]}
    found=0

    for ((j=0; j<frames; j++))
    do
        if [ "${memory[$j]}" == "$page" ]
        then
            found=1
            break
        fi
    done

    if [ $found -eq 0 ]
    then
        replace=-1

        for ((j=0; j<frames; j++))
        do
            if [ -z "${memory[$j]}" ]
            then
                replace=$j
                break
            fi
        done

        if [ $replace -eq -1 ]
        then
            farthest=-1

            for ((j=0; j<frames; j++))
            do
                next=$n

                for ((k=i+1; k<n; k++))
                do
                    if [ "${memory[$j]}" == "${pages[$k]}" ]
                    then
                        next=$k
                        break
                    fi
                done

                if [ $next -gt $farthest ]
                then
                    farthest=$next
                    replace=$j
                fi
            done
        fi

        memory[$replace]=$page
        faults=$((faults + 1))
    fi

    echo -n "Page $page: "
    echo "${memory[@]}"
done

echo "Total Page Faults: $faults"
