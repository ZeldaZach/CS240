all: main

User.o: User.cpp User.h
	g++ User.cpp -o User.o -g -c

main.o: main.cpp User.h
	g++ main.cpp -o main.o -g -c

main: User.o main.o
	g++ User.o main.o -o main

clean:
	rm *.o main
