#!/bin/bash 
 
echo "Enter Number of Blocks:" 
read n 
 
echo "Enter Block Numbers:" 
 
for ((i=0;i<n;i++)) 
do 
    read block[$i] 
done 
 
echo "Linked Allocation:" 
 
for ((i=0;i<n-1;i++)) 
do 
    echo -n "${block[$i]} --> " 
done 

 
 
echo "${block[$((n-1))]} --> NULL"
