all : Test_lancer Test_relancer Test_mains


Test_lancer : ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o lancer.o
	gcc -o Test_lancer ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o lancer.o

Test_relancer : ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o relancer.o
	gcc -o Test_relancer ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o relancer.o

Test_mains : aff_poss_test_mains.o ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o test_mains.o
	gcc -o Test_mains aff_poss_test_mains.o ../../obj/mains.o ../../obj/fonctions_joueur.o ../../obj/fonctions_jeu.o test_mains.o


aff_poss_test_mains.o : aff_poss_test_mains.c aff_poss_test_mains.h ../../src/commun.h
	gcc -o aff_poss_test_mains.o -c aff_poss_test_mains.c -Wall -O

lancer.o : lancer.c ../../src/commun.h ../../src/fonctions_jeu.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o lancer.o -c lancer.c -Wall -O

relancer.o : relancer.c ../../src/commun.h ../../src/fonctions_jeu.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o relancer.o -c relancer.c -Wall -O

test_mains.o : test_mains.c aff_poss_test_mains.c ../../src/commun.h ../../src/fonctions_jeu.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o test_mains.o -c test_mains.c -Wall -O


clean:
		rm -f Test*
		rm -f *.o
