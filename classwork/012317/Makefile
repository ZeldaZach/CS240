all: Hello

Hello: classwork.o
	g++ classwork.o -o Hello

classwork.o: classwork.cpp
	g++ classwork.cpp -o classwork.o -c

clean:
	rm -f *.o Hello
