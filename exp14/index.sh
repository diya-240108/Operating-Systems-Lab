#!/bin/bash 
 
echo "Enter Index Block:" 
read index 
 
echo "Enter Number of Blocks:" 
read n 
 
echo "Enter Block Numbers:" 
 
for ((i=0;i<n;i++)) 
do 
    read block[$i] 
done 
 
echo "Index Block : $index" 
 
echo -n "Allocated Blocks : " 
 
for ((i=0;i<n;i++)) 
do 
    echo -n "${block[$i]} " 
done 
 
echo
