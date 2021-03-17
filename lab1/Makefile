lab1: main.o Executive.o LinkedList.o Node.o
	g++ -g -std=c++11 -Wall main.o Executive.o LinkedList.o Node.o -o lab1
main.o: main.cpp Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c main.cpp
Executive.o: Executive.h Executive.cpp LinkedList.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
LinkedList.o: LinkedList.h LinkedList.cpp Node.h
	g++ -g -std=c++11 -Wall -c LinkedList.cpp
Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp
clean:
	rm *.o lab1
