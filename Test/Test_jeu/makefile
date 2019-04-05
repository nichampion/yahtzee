all : Test_lancer


Test_lancer : ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o lancer.o
	gcc -o Test_lancer ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o lancer.o


lancer.o : lancer.c ../../src/commun.h ../../src/fonctions_jeu.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o lancer.o -c lancer.c -Wall -O


clean:
		rm -f Test*
		rm -f *.o
