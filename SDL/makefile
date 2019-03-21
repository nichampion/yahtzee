
CC=gcc
FLAGS=-Wall -g3

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR}

PROG=jeu_sdl

all: jeu_sdl.o fonctions_jeu.o fonctions_joueur.o mains.o
	${CC} -o ${PROG} jeu_sdl.o fonctions_jeu.o fonctions_joueur.o mains.o ${LIBS} ${INCLUDES}

jeu_sdl.o : jeu_sdl.c
	gcc -o jeu_sdl.o -c jeu_sdl.c

fonctions_jeu.o : fonctions_jeu.c fonctions_jeu.h
	gcc -o fonctions_jeu.o -c fonctions_jeu.c -W -Wall -ansi -pedantic

fonctions_joueur.o : fonctions_joueur.c fonctions_joueur.h
	gcc -o fonctions_joueur.o -c fonctions_joueur.c -W -Wall -ansi -pedantic

mains.o : mains.c mains.h
	gcc -o mains.o -c mains.c -W -Wall -ansi -pedantic

clean:
	rm -f ${PROG}
	rm -f *.o
