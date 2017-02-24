PROJ_NAME = lab5
DEPENDENCIES_CPP = lab5.cpp Deck.cpp Card.cpp
DEPENDENCIES_H = Deck.h Card.h LinkedList.h Queue.h
FLAGS = -g -std=c++11

all: ${PROJ_NAME}

${PROJ_NAME}: ${DEPENDENCIES_CPP} ${DEPENDENCIES_H}
	g++ ${DEPENDENCIES_CPP} -o ${PROJ_NAME} ${FLAGS}

run: ${PROJ_NAME}
	./${PROJ_NAME}

clean:
	rm ${PROJ_NAME}
