all: Hello

Hello: main.o dog.o
	g++ main.o dog.o -o Hello -g

dog.o: dog.cpp dog.h
	g++ dog.cpp -o dog.o -g -c

main.o: main.cpp dog.h cat.h
	g++ main.cpp -o main.o -g -c

clean:
	rm -f *.o Hello

run: Hello
	./Hello
