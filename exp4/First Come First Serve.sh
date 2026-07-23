#!/bin/bash

echo "Enter Number of Processes"
read n

# Input Burst Times
for ((i=0; i<n; i++))
do
    echo "Enter Burst Time for P$((i+1))"
    read bt[$i]
done

# Calculate Waiting Time
wt[0]=0

for ((i=1; i<n; i++))
do
    wt[$i]=$((wt[i-1] + bt[i-1]))
done

echo
echo -e "Process\tBT\tWT\tTAT"

total_wt=0
total_tat=0

# Calculate Turnaround Time and Display
for ((i=0; i<n; i++))
do
    tat[$i]=$((wt[$i] + bt[$i]))

    total_wt=$((total_wt + wt[$i]))
    total_tat=$((total_tat + tat[$i]))

    echo -e "P$((i+1))\t${bt[$i]}\t${wt[$i]}\t${tat[$i]}"
done

avg_wt=$(echo "scale=2; $total_wt/$n" | bc)
avg_tat=$(echo "scale=2; $total_tat/$n" | bc)

echo
echo "Average Waiting Time = $avg_wt"
echo "Average Turnaround Time = $avg_tat"
