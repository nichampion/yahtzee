all : Test_lancer Test_placement Test_relancer Test_mains


Test_lancer : ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o lancer.o
	gcc -o Test_lancer ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o lancer.o

Test_placement : affichage_V1.o ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o placement.o
	gcc -o Test_lancer affichage_V1.o ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o placement.o

Test_relancer : ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o relancer.o
	gcc -o Test_relancer ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o relancer.o

test_mains : ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o test_mains.o
	gcc -o Test_mains ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o test_mains.o


affichage_V1.o : affichage_V1.c
	gcc -o affichage_V1.o -c affichage_V1.c -Wall -O

lancer.o : lancer.c ../../src/commun.h ../../src/fonctions_jeu.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o lancer.o -c lancer.c -Wall -O

placement.o : placement.c affichage_V1.h ../../src/commun.h ../../src/fonctions_jeu.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o placement.o -c placement.c -Wall -O

relancer.o : relancer.c ../../src/commun.h ../../src/fonctions_jeu.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o relancer.o -c relancer.c -Wall -O

test_mains.o : test_mains.c ../../src/commun.h ../../src/fonctions_jeu.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o test_mains.o -c test_mains.c -Wall -O


clean:
		rm -f Test*
		rm -f *.o
