#!/bin/bash

echo "Enter number of page references:"
read n

echo "Enter page reference string:"
read -a pages

echo "Enter number of frames:"
read frames

declare -a memory
declare -a recent

faults=0

for ((i=0; i<n; i++))
do
    page=${pages[$i]}
    found=-1

    for ((j=0; j<frames; j++))
    do
        if [ "${memory[$j]}" == "$page" ]
        then
            found=$j
            break
        fi
    done

    if [ $found -ne -1 ]
    then
        recent[$found]=$i
    else
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
            replace=0

            for ((j=1; j<frames; j++))
            do
                if [ ${recent[$j]} -lt ${recent[$replace]} ]
                then
                    replace=$j
                fi
            done
        fi

        memory[$replace]=$page
        recent[$replace]=$i
        faults=$((faults + 1))
    fi

    echo -n "Page $page: "
    echo "${memory[@]}"
done

echo "Total Page Faults: $faults"
