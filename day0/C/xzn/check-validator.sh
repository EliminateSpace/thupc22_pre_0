#!/bin/sh
g++ validator.cpp -o validator
for (( i = 1; i < 21; i++ )); do
    echo "Running on data case $i"
    ./validator $i < ../data/$i.in 
done
for (( i = 1; i < 3; i++ )); do
    echo "Running on down case $i"
    ./validator $i < ../down/$i.in 
done
