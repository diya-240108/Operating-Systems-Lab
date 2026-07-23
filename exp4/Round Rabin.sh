#!/bin/bash

echo "Enter Number of Processes"
read n

for ((i=0; i<n; i++))
do
    echo "Enter Burst Time for P$((i+1))"
    read bt[$i]
    rem[$i]=${bt[$i]}
done

echo "Enter Time Quantum"
read tq

time=0

echo
echo -e "Process\tBT\tWT\tTAT"

while :
do
    done=1

    for ((i=0; i<n; i++))
    do
        if [ ${rem[$i]} -gt 0 ]
        then
            done=0

            if [ ${rem[$i]} -gt $tq ]
            then
                time=$((time + tq))
                rem[$i]=$((rem[$i] - tq))
            else
                time=$((time + rem[$i]))
                wt[$i]=$((time - bt[$i]))
                tat[$i]=$time
                rem[$i]=0
            fi
        fi
    done

    if [ $done -eq 1 ]
    then
        break
    fi
done

total_wt=0
total_tat=0

for ((i=0; i<n; i++))
do
    total_wt=$((total_wt + wt[$i]))
    total_tat=$((total_tat + tat[$i]))

    echo -e "P$((i+1))\t${bt[$i]}\t${wt[$i]}\t${tat[$i]}"
done

echo
echo "Average Waiting Time = $((total_wt / n))"
echo "Average Turnaround Time = $((total_tat / n))"
