#include <stdio.h>

#include "../../src/commun.h"
#include "aff_poss_test_mains.h"

#define VAL_INIT -1
/**
	*\fn : void affichage_possibilites(t_joueur * j, t_joueur * j_test)
	*\param : Un pointeur sur un joueur, un pointeur sur un joueur test
	*\brief : Affichage des combinaisons possibles et croix pour les cases déjà remplies pour le joueur j
	*\author : Sunny BIARD
*/
void affichage_possibilites(t_joueur * j, t_joueur * j_test){

	printf("* * * * * * * * * * * * TOUR %s * * * * * * * * * * * * *\n",j->nom);
  printf("*\t\t\t\t\t\t\t*\n");
  printf("*\t._______________________________.\t\t*\n");
  printf("*\t|\t\t%s\t\t|\t\t*\n", j->nom);
  printf("*\t|-------------------------------|\t\t*\n");
	if(j_test->tab[AS] != VAL_INIT)
  	  printf("*\t| 1 As\t\t%d?\t\t|\t\t*\n", j_test->tab[AS]);
	else
  	  printf("*\t| 1 As\t\t%d\t\t|\t\t*\n", j->tab[AS]);
	if(j_test->tab[DEUX] != VAL_INIT)
	  printf("*\t| 2 Deux\t%d?\t\t|\t\t*\n", j_test->tab[DEUX]);
	else
  	  printf("*\t| 2 Deux\t%d\t\t|\t\t*\n", j->tab[DEUX]);
	if(j_test->tab[TROIS] != VAL_INIT)
	  printf("*\t| 3 Trois\t%d?\t\t|\t\t*\n", j_test->tab[TROIS]);
	else
  	  printf("*\t| 3 Trois\t%d\t\t|\t\t*\n", j->tab[TROIS]);
	if(j_test->tab[QUATRE] != VAL_INIT)
	  printf("*\t| 4 Quatres\t%d?\t\t|\t\t*\n", j_test->tab[QUATRE]);
	else
  	  printf("*\t| 4 Quatres\t%d\t\t|\t\t*\n", j->tab[QUATRE]);
	if(j_test->tab[CINQ] != VAL_INIT)
	  printf("*\t| 5 Cinq\t%d?\t\t|\t\t*\n", j_test->tab[CINQ]);
	else
  	  printf("*\t| 5 Cinq\t%d\t\t|\t\t*\n", j->tab[CINQ]);
	if(j_test->tab[SIX] != VAL_INIT)
	  printf("*\t| 6 Six\t\t%d?\t\t|\t\t*\n", j_test->tab[SIX]);
	else
  	  printf("*\t| 6 Six\t\t%d\t\t|\t\t*\n", j->tab[SIX]);

	printf("*\t| Total\t\t%d\t\t|\t\t*\n", j->tab[TOTAL_SUP]);
	printf("*\t| Prime\t\t%d\t\t|\t\t*\n", j->tab[PRIME_35]);
  printf("*\t|-------------------------------|\t\t*\n");

	if(j_test->tab[BRELAN] != VAL_INIT)
	  printf("*\t| 7 Brelan\t%d?\t\t|\t\t*\n", j_test->tab[BRELAN]);
	else
  	  printf("*\t| 7 Brelan\t%d\t\t|\t\t*\n", j->tab[BRELAN]);
	if(j_test->tab[CARRE] != VAL_INIT)
	  printf("*\t| 8 Carre\t%d?\t\t|\t\t*\n", j_test->tab[CARRE]);
	else
  	  printf("*\t| 8 Carre\t%d\t\t|\t\t*\n", j->tab[CARRE]);
	if(j_test->tab[FULL] != VAL_INIT)
	  printf("*\t| 9 Full\t%d?\t\t|\t\t*\n", j_test->tab[FULL]);
	else
  	  printf("*\t| 9 Full\t%d\t\t|\t\t*\n", j->tab[FULL]);
	if(j_test->tab[PETITE_SUITE] != VAL_INIT)
	  printf("*\t| 10 P Suite\t%d?\t\t|\t\t*\n", j_test->tab[PETITE_SUITE]);
	else
  	  printf("*\t| 10 P Suite\t%d\t\t|\t\t*\n", j->tab[PETITE_SUITE]);
	if(j_test->tab[GRANDE_SUITE] != VAL_INIT)
	  printf("*\t| 11 G Suite\t%d?\t\t|\t\t*\n", j_test->tab[GRANDE_SUITE]);
	else
  	  printf("*\t| 11 G Suite\t%d\t\t|\t\t*\n", j->tab[GRANDE_SUITE]);
	if(j_test->tab[YAHTZEE] != VAL_INIT)
	  printf("*\t| 12 Yahtzee\t%d?\t\t|\t\t*\n", j_test->tab[YAHTZEE]);
	else
  	  printf("*\t| 12 Yahtzee\t%d\t\t|\t\t*\n", j->tab[YAHTZEE]);
	if(j_test->tab[CHANCE] != VAL_INIT)
	  printf("*\t| 13 Chance\t%d?\t\t|\t\t*\n", j_test->tab[CHANCE]);
	else
	  printf("*\t| 13 Chance\t%d\t\t|\t\t*\n", j->tab[CHANCE]);

	printf("*\t| Total\t\t%d\t\t|\t\t*\n", j->tab[TOTAL_INF]);
  printf("*\t|-------------------------------|\t\t*\n");
  printf("*\t|TOTAL\t\t%d\t\t|\t\t*\n", j->tab[TOTAL_GEN]);
  printf("*\t|_______________________________|\t\t*\n");
  printf("*\t\t\t\t\t\t\t*\n");
  printf("*\t.________________________________.\t\t*\n");
  printf("*\t|1\t2\t3\t4\t5|\t\t*\n");
  printf("*\t|%d\t%d\t%d\t%d\t%d|\t\t*\n", j->des[0], j->des[1], j->des[2], j->des[3], j->des[4]);
  printf("*\t.________________________________.\t\t*\n");
  printf("*\t\t\t\t\t\t\t*\n");
  printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");

}
