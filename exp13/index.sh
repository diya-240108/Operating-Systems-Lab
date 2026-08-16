#!/bin/bash 
 
echo "Enter Student Records" 
 
echo "101 Arun" > index.txt 
echo "102 Kumar" >> index.txt 
echo "103 Ravi" >> index.txt 
 
echo "Enter Register Number to Search:" 
read key 
 
grep "^$key" index.txt
