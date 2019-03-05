#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "commun.h"
#include "fonctions_jeu.h"
#include "fonctions_joueurs.h"
#include "mains.h"

/**
	*\file lancer.c
	*\brief
	*\version 1.0
	*\Author : Sunny BIARD
*/

void lancer(t_joueur * j, int i){

	srand(time(NULL));
	j->des[i] = rand()%(7-1) + 1;

}

int relancer(t_joueur * j){

	int i, relance, rep;

	printf("Voulez vous relancer ? (0 : Non, 1 : Oui) ");
	scanf("%d",&rep);

	if(rep == 1){
		for(i = 0; i < 5; i++){
			printf("Voulez vous relancer le dé n°%d ? (0 : Non, 1 : Oui) ", i+1);
			scanf("%d", &relance);

			if(relance == 1){
				lancer(j,i);
			}
		}
		return 1;
	}

	return 0;
}

int test_mains(t_joueur *j){

	t_joueur * j_test;
	init_bloc_note(j_test);

	if((j->as) == VAL_INIT)
		j_test.tab->as = section_superieure(j,1);

	if((j->deux) == VAL_INIT)
		j_test.tab->deux = section_superieure(j,2);

	if((j->trois) == VAL_INIT)
		j_test.tab->trois = section_superieure(j,3);

	if((j->quatre) == VAL_INIT)
		j_test.tab->quatre = section_superieure(j,4);

	if((j->cinq) == VAL_INIT)
		j_test.tab->cinq = section_superieure(j,5);

	if((j->six) == VAL_INIT)
		j_test.tab->six = section_superieure(j,6);

	if((j->brelan) == VAL_INIT)
		j_test.tab->brelan = brelan(j);

	if((j->carre) == VAL_INIT)
		j_test.tab->carre = carre(j);

	if((j->full) == VAL_INIT)
		j_test.tab->full = full(j);

	if((j->petite_Suite) == VAL_INIT)
		j_test.tab->petite_Suite = petite_suite(j);

	if((j->grande_Suite) == VAL_INIT)
		j_test.tab->grande_Suite = grande_suite(j);

	if((j->chance) == VAL_INIT)
		j_test.tab->chance = chance(j);

	if((j->yahtzee) == VAL_INIT)
		j_test.tab->yahtzee = yahtzee(j);
	else if((j->yahtzee) == 50))
		j_test.tab->prime_Yahtzee == 100;

	affichage_possibilites(j,j_test);

}

void affichage_possibilites(t_joueur * j, t_joueur * j_test){

	printf("* * * * * * * * * * CHOIX POSSIBLES * * * * * * * * * * * \n");
  printf("*\t\t\t\t\t\t\t*\n");
  printf("*\t._______________________________.\t\t*\n");
  printf("*\t|\t\t%s\t\t*\n", j->nom);
  printf("*\t|-------------------------------|\t\t*\n");
	if(j_test.tab->as)
  	printf("*\t| As\t\t%d\t\t*\n", j_test.tab->as);
	else
  	printf("*\t| As\t\tX\t\t*\n");
	if(j_test.tab->deux)
	  printf("*\t| Deux\t\t%d\t\t*\n", j_test.tab->deux);
	else
	  printf("*\t| Deux\t\tX\t\t*\n", j_test.tab->deux);
	if(j_test.tab->trois)
	  printf("*\t| Trois\t\t%d\t\t*\n", j_test.tab->trois);
	else
	  printf("*\t| Trois\t\tX\t\t*\n", j_test.tab->trois);
	if(j_test.tab->quatre)
	  printf("*\t| Quatre\t\t%d\t\t*\n", j_test.tab->quatre);
	else
	  printf("*\t| Quatre\t\tX\t\t*\n", j_test.tab->quatre);
	if(j_test.tab->cinq)
	  printf("*\t| Cinq\t\t%d\t\t*\n", j_test.tab->cinq);
	else
	  printf("*\t| Cinq\t\tX\t\t*\n", j_test.tab->cinq);
	if(j_test.tab->six)
	  printf("*\t| Six\t\t%d\t\t*\n", j_test.tab->six);
	else
	  printf("*\t| Six\t\tX\t\t*\n", j_test.tab->six);

	printf("*\t| Total\t\t%d\t\t*\n", j->tab.total_Sup);
	printf("*\t| Prime\t\t%d\t\t*\n", j->tab.prime_35pts);
  printf("*\t|-------------------------------|\t\t*\n");

	if(j_test.tab->brelan
	  printf("*\t| Brelan\t\t%d\t\t*\n", j_test.tab->brelan);
	else
	  printf("*\t| Brelan\t\tX\t\t*\n", j_test.tab->brelan);
	if(j_test.tab->carre
	  printf("*\t| Carre\t\t%d\t\t*\n", j_test.tab->carre);
	else
	  printf("*\t| Carre\t\tX\t\t*\n", j_test.tab->carre);
	if(j_test.tab->full
	  printf("*\t| Full\t\t%d\t\t*\n", j_test.tab->full);
	else
	  printf("*\t| Full\t\tX\t\t*\n", j_test.tab->full);
	if(j_test.tab->petite_Suite
	  printf("*\t| Petite Suite\t\t%d\t\t*\n", j_test.tab->petite_Suite);
	else
	  printf("*\t| Petite Suite\t\tX\t\t*\n", j_test.tab->petite_Suite);
	if(j_test.tab->grande_Suite
	  printf("*\t| Grande Suite\t\t%d\t\t*\n", j_test.tab->grande_Suite);
	else
	  printf("*\t| Grande Suite\t\tX\t\t*\n", j_test.tab->grande_Suite);
	if(j_test.tab->chance
	  printf("*\t| Chance\t\t%d\t\t*\n", j_test.tab->chance);
	else
	  printf("*\t| Chance\t\tX\t\t*\n", j_test.tab->chance);
	if(j_test.tab->yahtzee
	  printf("*\t| Yahtzee\t\t%d\t\t*\n", j_test.tab->yahtzee);
	else
	  printf("*\t| Yahtzee\t\tX\t\t*\n", j_test.tab->yahtzee);
	if(j_test.tab->prime_Yahtzee
	  printf("*\t| Prime\t\t%d\t\t*\n", j->tab.prime_Yahtzee);
	else
	  printf("*\t| Prime\t\tX\t\t*\n", j->tab.prime_Yahtzee);

	printf("*\t| Total\t\t%d\t\t*\n", j->tab.total_Inf);
  printf("*\t|-------------------------------|\t\t*\n");
  printf("*\t|TOTAL\t\t%d\t\t*\n", j->tab.total_Gen);
  printf("*\t|_______________________________|\t\t*\n");
  printf("*\t\t\t\t\t\t\t*\n");
  printf("*\t.________________________________.\t\t*\n");
  printf("*\t|1\t2\t3\t4\t5|\t\t*\n");
  printf("*\t|%d\t%d\t%d\t%d\t%d|\t\t*\n", j->des[0], j->des[1], j->des[2], j->des[3], j->des[4]);
  printf("*\t.________________________________.\t\t*\n");
  printf("*\t\t\t\t\t\t\t*\n");
  printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");

}
