lab3: main.o Executive.o DHash.o QProb.o Bucket.o
	g++ -g -std=c++11 -Wall main.o Executive.o DHash.o QProb.o Bucket.o -o lab3
main.o: main.cpp Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c main.cpp
Executive.o: Executive.h Executive.cpp DHash.h DHash.cpp QProb.h QProb.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
Bucket.o: Bucket.h Bucket.cpp
	g++ -std=c++11 -g -Wall -c Bucket.cpp
DHash.o: DHash.h DHash.cpp Bucket.h Bucket.cpp
	g++ -std=c++11 -g -Wall -c DHash.cpp
QProb.o: QProb.h QProb.cpp Bucket.h Bucket.cpp
	g++ -std=c++11 -g -Wall -c QProb.cpp
clean:
	rm *.o lab3
