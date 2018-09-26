all: main

main: main.cpp btree.h node.h iterator.h
	g++ -std=c++11 main.cpp -o main
