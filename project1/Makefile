PROJ_NAME = project1
DEPENDENCIES_H = LinkedList.h Ant.h AntHill.h
DEPENDENCIES_CPP = $(PROJ_NAME).cpp LinkedList.cpp Ant.cpp AntHill.cpp
FLAGS = -g

all: $(PROJ_NAME)

$(PROJ_NAME): $(DEPENDENCIES_CPP) $(DEPENDENCIES_H)
	g++ $(DEPENDENCIES_CPP) $(FLAGS) -o $(PROJ_NAME)

run: $(PROJ_NAME)
	./$(PROJ_NAME)

checkmem: $(PROJ_NAME)
	valgrind ./$(PROJ_NAME) --leak-check=full -v

clean:
	rm -f $(PROJ_NAME) anthill.log
