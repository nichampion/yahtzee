all : Test_brelan Test_carre Test_gdeSuite Test_pteSuite Test_yahtzee Test_full Test_SecSup Test_chance


Test_brelan : ../../obj/mains.o ../../obj/fonctions_joueur.o  brelan.o
	gcc -o Test_brelan ../../obj/mains.o ../../obj/fonctions_joueur.o brelan.o

Test_carre : ../../obj/mains.o ../../obj/fonctions_joueur.o  carre.o
	gcc -o Test_carre ../../obj/mains.o ../../obj/fonctions_joueur.o carre.o

Test_gdeSuite : ../../obj/mains.o ../../obj/fonctions_joueur.o  grandesuite.o
	gcc -o Test_gdeSuite ../../obj/mains.o ../../obj/fonctions_joueur.o grandesuite.o

Test_pteSuite : ../../obj/mains.o ../../obj/fonctions_joueur.o  petite_suite.o
	gcc -o Test_pteSuite ../../obj/mains.o ../../obj/fonctions_joueur.o petite_suite.o

Test_yahtzee : ../../obj/mains.o ../../obj/fonctions_joueur.o  yahtzee.o
	gcc -o Test_yahtzee ../../obj/mains.o ../../obj/fonctions_joueur.o yahtzee.o

Test_full : ../../obj/mains.o ../../obj/fonctions_joueur.o  full.o
	gcc -o Test_full ../../obj/mains.o ../../obj/fonctions_joueur.o full.o

Test_SecSup : ../../obj/mains.o ../../obj/fonctions_joueur.o  SecSup.o
	gcc -o Test_SecSup ../../obj/mains.o ../../obj/fonctions_joueur.o SecSup.o

Test_chance : ../../obj/mains.o ../../obj/fonctions_joueur.o  chance.o
	gcc -o Test_chance ../../obj/mains.o ../../obj/fonctions_joueur.o chance.o

brelan.o : brelan.c ../../src/commun.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o brelan.o -c brelan.c -Wall -O

carre.o : carre.c ../../src/commun.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o carre.o -c carre.c -Wall -O

grandesuite.o : grandesuite.c ../../src/commun.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o grandesuite.o -c grandesuite.c -Wall -O

petite_suite.o : petite_suite.c ../../src/commun.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o petite_suite.o -c petite_suite.c -Wall -O

yahtzee.o : yahtzee.c ../../src/commun.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o yahtzee.o -c yahtzee.c -Wall -O

full.o : full.c ../../src/commun.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o full.o -c full.c -Wall -O

SecSup.o : SecSup.c ../../src/commun.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o SecSup.o -c SecSup.c -Wall -O

chance.o : chance.c ../../src/commun.h ../../src/fonctions_joueur.h ../../src/mains.h
	gcc -o chance.o -c chance.c -Wall -O

clean:
		rm -f Test*
		rm -f *.o
