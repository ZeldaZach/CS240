all: lab7

run: lab7
	./lab7

gdb: lab7
	gdb ./lab7

checkmem: lab7
	valgrind ./lab7 --leak-check=full -v

lab7: BSTree.o lab7.o
	g++ BSTree.o lab7.o -o lab7 -g -std=c++14

lab7.o: lab7.cpp
	g++ lab7.cpp -o lab7.o -c -g -std=c++14

BSTree.o: BSTree.cpp BSTree.h
	g++ BSTree.cpp -o BSTree.o -c -g -std=c++14

clean:
	rm BSTree.o lab7.o lab7

