#!/bin/bash

echo "Enter Number of Processes"
read n

# Input Burst Time and Priority
for ((i=0; i<n; i++))
do
    echo "Enter Burst Time for P$((i+1))"
    read bt[$i]

    echo "Enter Priority for P$((i+1))"
    read pr[$i]
done

# Sort according to Priority (Lower number = Higher priority)
for ((i=0; i<n-1; i++))
do
    for ((j=i+1; j<n; j++))
    do
        if [ ${pr[$i]} -gt ${pr[$j]} ]
        then
            temp=${pr[$i]}
            pr[$i]=${pr[$j]}
            pr[$j]=$temp

            temp=${bt[$i]}
            bt[$i]=${bt[$j]}
            bt[$j]=$temp
        fi
    done
done

# Calculate Waiting Time
wt[0]=0

for ((i=1; i<n; i++))
do
    wt[$i]=$((wt[i-1] + bt[i-1]))
done

echo
echo -e "Process\tPriority\tBT\tWT\tTAT"

total_wt=0
total_tat=0

for ((i=0; i<n; i++))
do
    tat[$i]=$((wt[$i] + bt[$i]))

    total_wt=$((total_wt + wt[$i]))
    total_tat=$((total_tat + tat[$i]))

    echo -e "P$((i+1))\t${pr[$i]}\t\t${bt[$i]}\t${wt[$i]}\t${tat[$i]}"
done

echo
echo "Average Waiting Time = $((total_wt / n))"
echo "Average Turnaround Time = $((total_tat / n))"
