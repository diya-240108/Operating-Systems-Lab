#!/bin/bash

LOCKFILE="/tmp/semaphore.lock"

# Function to acquire semaphore
acquire()
{
    while [ -e "$LOCKFILE" ]
    do
        sleep 1
    done

    touch "$LOCKFILE"
}

# Function to release semaphore
release()
{
    rm -f "$LOCKFILE"
}

# Child Process
(
    acquire

    echo "Child Process Entering Critical Section"
    sleep 3
    echo "Child Process Leaving Critical Section"

    release
) &

# Parent Process
acquire

echo "Parent Process Entering Critical Section"
sleep 3
echo "Parent Process Leaving Critical Section"

release

wait

echo "Semaphore Execution Completed"
