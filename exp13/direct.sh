#!/bin/bash 
 
echo "Enter Record:" 
read rec 
 
echo "$rec" > random.txt 

 
echo "Random Access Record" 
 
sed -n '1p' random.txt
