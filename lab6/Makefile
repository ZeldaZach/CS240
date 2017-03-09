all: lab6

lab6: Sorter.h lab6.cpp
	g++ lab6.cpp -o lab6 -g -std=c++11

run: lab6
	./lab6

checkmem: lab6
	valgrind ./lab6 --leak-check=full -v

clean:
	rm -f lab6
