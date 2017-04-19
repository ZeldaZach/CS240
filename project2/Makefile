EXE_NAME = project2
ALL_OBJS = Heap.o Player.o Card.o Deck.o Table.o project2.o
D_FLAGS = -g -std=c++14

all: $(ALL_OBJS)

$(EXE_NAME): $(ALL_OBJS)
	g++ $(ALL_OBJS) -o $(EXE_NAME) $(D_FLAGS)

$(EXE_NAME).o: $(EXE_NAME).cpp
	g++ $(EXE_NAME).cpp -o $(EXE_NAME).o $(D_FLAGS) -c

Heap.o: Heap.cpp Heap.h Player.o
	g++ Heap.cpp -o Heap.o $(D_FLAGS) -c

Player.o: Player.cpp Player.h Card.o
	g++ Player.cpp -o Player.o $(D_FLAGS) -c

Card.o: Card.cpp Card.h
	g++ Card.cpp -o Card.o $(D_FLAGS) -c

Deck.o: Deck.cpp Deck.h Queue.h LinkedList.h
	g++ Deck.cpp -o Deck.o $(D_FLAGS) -c

Table.o: Table.cpp Table.h
	g++ Table.cpp -o Table.o $(D_FLAGS) -c

run: $(EXE_NAME)
	./$(EXE_NAME)

checkmem: $(EXE_NAME)
	valgrind ./$(EXE_NAME) --leak-check=full -v

clean:
	rm -f $(ALL_OBJS) $(EXE_NAME)
