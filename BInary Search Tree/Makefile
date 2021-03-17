lab4: main.o Executive.o BST.o Node.o
	g++ -g -std=c++11 -Wall main.o Executive.o BST.o Node.o -o lab4
main.o: main.cpp Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c main.cpp
Executive.o: Executive.h Executive.cpp BST.h BST.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
BST.o: BST.h BST.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c BST.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
clean:
	rm *.o lab4