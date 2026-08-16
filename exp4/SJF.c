#!/bin/bash

echo "Enter Number of Processes:"
read n

for ((i=0; i<n; i++))
do
    echo "Enter Burst Time for P$((i+1)):"
    read bt[$i]
    p[$i]=$((i+1))
done

# Sort processes according to Burst Time
for ((i=0; i<n; i++))
do
    for ((j=i+1; j<n; j++))
    do
        if [ ${bt[$i]} -gt ${bt[$j]} ]
        then
            temp=${bt[$i]}
            bt[$i]=${bt[$j]}
            bt[$j]=$temp

            temp=${p[$i]}
            p[$i]=${p[$j]}
            p[$j]=$temp
        fi
    done
done

wt[0]=0

for ((i=1; i<n; i++))
do
    wt[$i]=$((wt[$((i-1))] + bt[$((i-1))]))
done

avg_wt=0
avg_tat=0

echo
echo -e "Process\tBT\tWT\tTAT"

for ((i=0; i<n; i++))
do
    tat[$i]=$((wt[$i] + bt[$i]))

    avg_wt=$((avg_wt + wt[$i]))
    avg_tat=$((avg_tat + tat[$i]))

    echo -e "P${p[$i]}\t${bt[$i]}\t${wt[$i]}\t${tat[$i]}"
done

echo
echo "Average Waiting Time = $(awk "BEGIN {printf \"%.2f\", $avg_wt/$n}")"
echo "Average Turnaround Time = $(awk "BEGIN {printf \"%.2f\", $avg_tat/$n}")"
