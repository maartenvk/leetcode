#!/bin/sh

if [ $1 == "clean" ]; then
    rm bin/*
    exit
fi

g++ src/$1*.cpp -g -o bin/$1 -Wall -Wextra
./bin/$1
