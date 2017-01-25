all: Hello

Hello: classwork.o
	g++ classwork.o -o Hello -g

classwork.o: classwork.cpp
	g++ classwork.cpp -o classwork.o -c -g

clean:
	rm -f *.o Hello

run: Hello
	./Hello
