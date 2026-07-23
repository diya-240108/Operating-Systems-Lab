#!/bin/bash

echo "ENTER THE VALUE OF A:"
read a

echo "ENTER THE VALUE OF B:"
read b

echo "ENTER THE OPTION TO PERFORM"
echo "1. ADDITION"
echo "2. SUBTRACTION"
echo "3. MULTIPLICATION"
echo "4. DIVISION"

read op

case "$op" in
    1)
        echo "Result = $((a + b))"
        ;;
    2)
        echo "Result = $((a - b))"
        ;;
    3)
        echo "Result = $((a * b))"
        ;;
    4)
        echo "Result = $((a / b))"
        ;;
    *)
        echo "Invalid Option"
        ;;
esac
