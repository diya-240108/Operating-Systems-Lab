#!/bin/bash

echo "Enter Number of Processes:"
read n

for ((i=0; i<n; i++))
do
    echo "Enter Burst Time for P$((i+1)):"
    read bt[$i]

    rem[$i]=${bt[$i]}
done

echo "Enter Time Quantum:"
read tq

time=0
completed=0
wt_sum=0
tat_sum=0

while [ $completed -lt $n ]
do
    for ((i=0; i<n; i++))
    do
        if [ ${rem[$i]} -gt 0 ]
        then
            if [ ${rem[$i]} -gt $tq ]
            then
                time=$((time + tq))
                rem[$i]=$((rem[$i] - tq))
            else
                time=$((time + rem[$i]))

                tat[$i]=$time
                wt[$i]=$((tat[$i] - bt[$i]))

                wt_sum=$((wt_sum + wt[$i]))
                tat_sum=$((tat_sum + tat[$i]))

                rem[$i]=0
                completed=$((completed + 1))
            fi
        fi
    done
done

echo
echo -e "Process\tBT\tWT\tTAT"

for ((i=0; i<n; i++))
do
    echo -e "P$((i+1))\t${bt[$i]}\t${wt[$i]}\t${tat[$i]}"
done

echo
echo "Average Waiting Time = $(awk "BEGIN {printf \"%.2f\", $wt_sum/$n}")"
echo "Average Turnaround Time = $(awk "BEGIN {printf \"%.2f\", $tat_sum/$n}")"
