Test_IA : affichage_V1_Test_IA.o ../../obj/mains.o ../../obj/ordinateur.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o main.o
	gcc -o Test_IA affichage_V1_Test_IA.o ../../obj/mains.o ../../obj/ordinateur.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o main.o

affichage_V1_Test_IA.o : affichage_V1_Test_IA.c
	gcc -o affichage_V1_Test_IA.o -c affichage_V1_Test_IA.c -Wall -O

main.o : main.c ../../src/commun.h ../../src/affichage.h ../../src/ordinateur.h ../../src/fonctions_joueur.h ../../src/fonctions_jeu.h ../../src/mains.h
	gcc -o main.o -c main.c

clean:
	rm *.o
	rm Test_IA
