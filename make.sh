#!/bin/sh

g++ src/$1.cpp -g -o bin/$1
./bin/$1
