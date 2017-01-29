FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
PROJ_NAME = lab2
SOURCES = AntHill.o $(PROJ_NAME).o $(PROJ_NAME)

all: $(PROJ_NAME).o AntHill.o
	g++ $(FLAGS) $(PROJ_NAME).o AntHill.o -o $(PROJ_NAME)

$(PROJ_NAME).o: $(PROJ_NAME).cpp AntHill.h
	g++ $(FLAGS) $(PROJ_NAME).cpp -o $(PROJ_NAME).o -c

AntHill.o: AntHill.cpp AntHill.h
	g++ $(FLAGS) AntHill.cpp -o AntHill.o -c

run: all
	./$(PROJ_NAME)

checkmem: all
	valgrind ./$(PROJ_NAME)

clean:
	rm $(SOURCES)
