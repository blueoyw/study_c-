#!/bin/bash
#SRC=fibonacci.cpp
#SRC=constructor.cpp
SRC=stl.cpp
#SRC=pointer.cpp
#SRC=thread.cpp
TARGET=test
g++ -std=c++0x -lpthread -Wall -o $TARGET $SRC
#g++ -std=c++0x  -Wall -o $TARGET $SRC
./test
