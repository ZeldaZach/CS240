PROJ_NAME = lab5
DEPENDENCIES_O = Deck.o Card.o
FLAGS = -std=c++11 -g
DRIVER = ${PROJ_NAME}.cpp

all: ${PROJ_NAME}

${PROJ_NAME}: ${DEPENDENCIES_O} ${DRIVER}
	g++ ${DEPENDENCIES_O} ${DRIVER} ${FLAGS} -o ${PROJ_NAME}

Card.o: Card.cpp Card.h
	g++ Card.cpp -o Card.o -c ${FLAGS}
	
Deck.o: Deck.cpp Deck.h LinkedList.h Queue.h
	g++ Deck.cpp -o Deck.o -c ${FLAGS}

run: ${PROJ_NAME}
	./${PROJ_NAME}

checkmem: ${PROJ_NAME}
	valgrind ./${PROJ_NAME} --leak-check=full -v

clean:
	rm ${PROJ_NAME} ${DEPENDENCIES_O}
