#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Please specify exactly two arguments: processId, sleepTime"
  exit 1
fi

sleep $2
echo "Hier Prozess $1"
sleep $2
echo "Hier Prozess $1"
