all: lab1

lab1: lab1.o
	g++ -g lab1.o -lm -o lab1

lab1.o: lab1.cpp
	g++ -c -g lab1.cpp -o lab1.o

clean:
	rm *.o lab1