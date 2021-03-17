lab2: main.o Executive.o Hash.o LinkedList.o Node.o
	g++ -g -std=c++11 -Wall main.o Executive.o Hash.o LinkedList.o Node.o -o lab2
main.o: main.cpp Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c main.cpp
Executive.o: Executive.h Executive.cpp Hash.h LinkedList.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
Hash.o: Hash.h Hash.cpp LinkedList.h
	g++ -std=c++11 -g -Wall -c Hash.cpp
LinkedList.o: LinkedList.h LinkedList.cpp Node.h
	g++ -g -std=c++11 -Wall -c LinkedList.cpp
Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -Wall -c Node.cpp
clean:
	rm *.o lab2
