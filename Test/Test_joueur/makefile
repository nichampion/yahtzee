all : Test_prime


Test_prime : ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o prime.o
	gcc -o Test_prime ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o prime.o



prime.o : prime.c ../../src/commun.h ../../src/fonctions_jeu.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o prime.o -c prime.c -Wall -O


clean:
		rm -f Test*
		rm -f *.o
