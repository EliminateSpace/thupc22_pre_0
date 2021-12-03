#!/bin/sh
g++ validator.cpp -o validator
for (( i = 1; i < 21; i++ )); do
    ./validator $i < ../data/$i.in 
done
for (( i = 1; i < 3; i++ )); do
    ./validator $i < ../down/$i.in 
done
