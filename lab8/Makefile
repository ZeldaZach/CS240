PROJ_NAME = lab8
ALL_OBJ = Hash.o lab8.o
D_FLAGS = -g -std=c++14

all: $(PROJ_NAME)

$(PROJ_NAME): $(ALL_OBJ)
	g++ $(ALL_OBJ) -o $(PROJ_NAME) $(D_FLAGS)

lab8.o: lab8.cpp
	g++ -c lab8.cpp -o lab8.o $(D_FLAGS)

Hash.o: Hash.cpp Hash.h
	g++ -c Hash.cpp -o Hash.o $(D_FLAGS)

checkmem: $(PROJ_NAME)
	valgrind ./$(PROJ_NAME) --leak-check=full -v

run: $(PROJ_NAME)
	./$(PROJ_NAME)

clean:
	rm -f $(ALL_OBJ) $(PROJ_NAME)
