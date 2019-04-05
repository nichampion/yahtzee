CC=gcc
FLAGS=-Wall -g3

SDL_DIR=${HOME}/SDL2
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include

LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDL_INC_DIR}

PROG1=jeu_1j
PROG2=jeu_2j

all: jeu_1j.o jeu_2j.o fonctions_jeu.o fonctions_joueur.o mains.o ordinateur.o
	${CC} -o ${PROG1} jeu_1j.o fonctions_jeu.o fonctions_joueur.o mains.o ordinateur.o ${LIBS} ${INCS} ${FLAGS}
	${CC} -o ${PROG2} jeu_2j.o fonctions_jeu.o fonctions_joueur.o mains.o ordinateur.o ${LIBS} ${INCS} ${FLAGS}

jeu_1j.o : jeu_1j.c
	${CC} -o jeu_1j.o -c jeu_1j.c ${LIBS} ${INCS} ${FLAGS}

jeu_2j.o : jeu_2j.c
	${CC} -o jeu_2j.o -c jeu_2j.c ${LIBS} ${INCS} ${FLAGS}

fonctions_jeu.o : fonctions_jeu.c fonctions_jeu.h
	${CC} -o fonctions_jeu.o -c fonctions_jeu.c -W -Wall -ansi -pedantic

fonctions_joueur.o : fonctions_joueur.c fonctions_joueur.h
	${CC} -o fonctions_joueur.o -c fonctions_joueur.c -W -Wall -ansi -pedantic

mains.o : mains.c mains.h
	${CC} -o mains.o -c mains.c -W -Wall -ansi -pedantic

ordinateur.o : ordinateur.c ordinateur.h
	${CC} -o ordinateur.o -c ordinateur.c -W -Wall -ansi -pedantic -std=c99

clean:
	rm -f ${PROG}
	rm -f *.o
