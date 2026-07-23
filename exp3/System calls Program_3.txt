#!/bin/bash

exec 3< sample.txt

echo "File Opened Successfully"

exec 3<&-

echo "File Closed Successfully"
