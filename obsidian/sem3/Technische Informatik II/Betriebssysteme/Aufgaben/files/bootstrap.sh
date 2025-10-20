#!/bin/bash

./prozess.sh 1 10 &
./prozess.sh 2 20 &
./prozess.sh 3 30 &
wait

echo "Alle drei Prozesse wurden gestartet"
