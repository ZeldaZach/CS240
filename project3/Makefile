OBJS = project3.o Map.o City.o
EXE_NAME = project3
DEBUG_FLAGS = -g -std=c++14

all: $(OBJS)
	g++ $(OBJS) -o $(EXE_NAME) $(DEBUG_FLAGS)

$(EXE_NAME).o: $(EXE_NAME).cpp
	g++ $(EXE_NAME).cpp -o $(EXE_NAME).o -c $(DEBUG_FLAGS)

Map.o: Map.cpp Map.h City.o
	g++ Map.cpp -o Map.o -c $(DEBUG_FLAGS)

City.o: City.cpp City.h
	g++ City.cpp -o City.o -c $(DEBUG_FLAGS)

checkmem: all
	valgrind ./$(EXE_NAME) --leak-check=full -v

run: all
	./$(EXE_NAME)

clean:
	rm -f $(OBJS) $(EXE_NAME)
