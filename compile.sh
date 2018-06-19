#!/bin/bash
#SRC=test.cpp
#SRC=factory.cpp
SRC=observer.cpp
#SRC=factoryMethod.cpp
#SRC=factoryAbstract.cpp
#SRC=fibonacci.cpp
#SRC=sort.cpp
#SRC=reverseInt.cpp
#SRC=makeHexa.cpp
#SRC=coin.cpp
#SRC=dp_make_1_1463.cpp
#SRC=constructor.cpp
#SRC=stl.cpp
#SRC=function_pointer.cpp
#SRC=stack.cpp
#SRC=list.cpp
#SRC=dijkstras.cpp'
#SRC=dijkstras_priority.cpp
#SRC=pointer.cpp
#SRC=binarySearch.cpp
#SRC=thread.cpp
TARGET=test
rm -rf test
g++ -std=c++0x -lpthread -Wall -I./ -o $TARGET $SRC
#g++ -std=c++0x  -Wall -o $TARGET $SRC
./test
