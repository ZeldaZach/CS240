FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
PROJ_NAME = lab3
SOURCES = AntHill.o Ant.o $(PROJ_NAME).o $(PROJ_NAME)

all: $(PROJ_NAME).o AntHill.o Ant.o
	g++ $(FLAGS) $(PROJ_NAME).o AntHill.o Ant.o -o $(PROJ_NAME)

$(PROJ_NAME).o: $(PROJ_NAME).cpp AntHill.h Ant.h
	g++ $(FLAGS) $(PROJ_NAME).cpp -o $(PROJ_NAME).o -c

AntHill.o: AntHill.cpp AntHill.h
	g++ $(FLAGS) AntHill.cpp -o AntHill.o -c
	
Ant.o: Ant.cpp Ant.h
	g++ $(FLAGS) Ant.cpp -o Ant.o -c

run: all
	./$(PROJ_NAME)

checkmem: all
	valgrind ./$(PROJ_NAME)

clean:
	rm $(SOURCES)
