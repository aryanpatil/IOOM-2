CXX = g++
FLAGS = -Wall

all: A1 A2 A3

A1: A1/Array.h A1/Array.cpp A1/main.cpp A1/Address.h A1/Address.cpp
	$(CXX) $(FLAGS) A1/Array.cpp A1/Address.cpp A1/main.cpp -o a1.o

A3: A3/BinarySearchTree.h A3/main.cpp
	$(CXX) $(FLAGS) A3/main.cpp -o a3.o

A2: A2/exceptions.h A2/main.cpp
	$(CXX) $(FLAGS) A2/main.cpp -o a2.o

clean: *.o
	rm *.o
