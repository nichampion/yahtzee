#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "commun.h"
#include "fonctions_jeu.h"
#include "fonctions_joueur.h"
#include "mains.h"

/**
	*\file lancer.c
	*\Fonctions du jeu
	*\version 1.0
	*\Author : Sunny BIARD
*/

/************************
 Fonction de lancer de dé
 ************************
 Affectation d'un nombre tiré aléatoirement entre 1 et 6 au dé n°i
*/
void lancer(t_joueur * j, int i){

	srand(time(NULL));
	j->des[i] = rand()%(7-1) + 1;

}

/************************
 Fonction de relancement de dé
 ************************
 Choix du/des dés à relancer
 Relancement de ces dés par appel de "lancer"
*/
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

/*******************************************
 Fonction de test des combinaisons possibles
 *******************************************
 Test de toutes les combinaisons possibles avec les dés du joueur j
 Affichage de ces possibilités de jeu
*/
void test_mains(t_joueur *j){

	t_joueur * j_test;
	init_bloc_note(j_test);

	if((j->tab.as) == VAL_INIT)
		j_test->tab.as = section_superieure(j,1);

	if((j->tab.deux) == VAL_INIT)
		j_test->tab.deux = section_superieure(j,2);

	if((j->tab.trois) == VAL_INIT)
		j_test->tab.trois = section_superieure(j,3);

	if((j->tab.quatres) == VAL_INIT)
		j_test->tab.quatres = section_superieure(j,4);

	if((j->tab.cinq) == VAL_INIT)
		j_test->tab.cinq = section_superieure(j,5);

	if((j->tab.six) == VAL_INIT)
		j_test->tab.six = section_superieure(j,6);

	if((j->tab.brelan) == VAL_INIT)
		j_test->tab.brelan = brelan(j);

	if((j->tab.carre) == VAL_INIT)
		j_test->tab.carre = carre(j);

	if((j->tab.full) == VAL_INIT)
		j_test->tab.full = full(j);

	if((j->tab.petite_Suite) == VAL_INIT)
		j_test->tab.petite_Suite = petite_suite(j);

	if((j->tab.grande_Suite) == VAL_INIT)
		j_test->tab.grande_Suite = grande_suite(j);

	if((j->tab.chance) == VAL_INIT)
		j_test->tab.chance = chance(j);

	if((j->tab.yahtzee) == VAL_INIT)
		j_test->tab.yahtzee = yahtzee(j);
	else if((j->tab.yahtzee) == 50)
		j_test->tab.prime_Yahtzee = 100;

	affichage_possibilites(j,j_test);

}

/***********************************************
 Fonction d'affichage des combinaisons possibles
 ***********************************************
 Affichage des combinaisons possibles et croix pour les cases déjà remplies pour le joueur j
*/
void affichage_possibilites(t_joueur * j, t_joueur * j_test){

	printf("* * * * * * * * * * CHOIX POSSIBLES * * * * * * * * * * * \n");
  printf("*\t\t\t\t\t\t\t*\n");
  printf("*\t._______________________________.\t\t*\n");
  printf("*\t|\t\t%s\t\t*\n", j->nom);
  printf("*\t|-------------------------------|\t\t*\n");
	if(j_test->tab.as)
  	printf("*\t| As\t\t%d\t\t*\n", j_test->tab.as);
	else
  	printf("*\t| As\t\tX\t\t*\n");
	if(j_test->tab.deux)
	  printf("*\t| Deux\t\t%d\t\t*\n", j_test->tab.deux);
	else
	  printf("*\t| Deux\t\tX\t\t*\n");
	if(j_test->tab.trois)
	  printf("*\t| Trois\t\t%d\t\t*\n", j_test->tab.trois);
	else
	  printf("*\t| Trois\t\tX\t\t*\n");
	if(j_test->tab.quatres)
	  printf("*\t| quatres\t\t%d\t\t*\n", j_test->tab.quatres);
	else
	  printf("*\t| quatres\t\tX\t\t*\n");
	if(j_test->tab.cinq)
	  printf("*\t| Cinq\t\t%d\t\t*\n", j_test->tab.cinq);
	else
	  printf("*\t| Cinq\t\tX\t\t*\n");
	if(j_test->tab.six)
	  printf("*\t| Six\t\t%d\t\t*\n", j_test->tab.six);
	else
	  printf("*\t| Six\t\tX\t\t*\n");

	printf("*\t| Total\t\t%d\t\t*\n", j->tab.total_Sup);
	printf("*\t| Prime\t\t%d\t\t*\n", j->tab.prime_35pts);
  printf("*\t|-------------------------------|\t\t*\n");

	if(j_test->tab.brelan)
	  printf("*\t| Brelan\t\t%d\t\t*\n", j_test->tab.brelan);
	else
	  printf("*\t| Brelan\t\tX\t\t*\n");
	if(j_test->tab.carre)
	  printf("*\t| Carre\t\t%d\t\t*\n", j_test->tab.carre);
	else
	  printf("*\t| Carre\t\tX\t\t*\n");
	if(j_test->tab.full)
	  printf("*\t| Full\t\t%d\t\t*\n", j_test->tab.full);
	else
	  printf("*\t| Full\t\tX\t\t*\n");
	if(j_test->tab.petite_Suite)
	  printf("*\t| Petite Suite\t\t%d\t\t*\n", j_test->tab.petite_Suite);
	else
	  printf("*\t| Petite Suite\t\tX\t\t*\n");
	if(j_test->tab.grande_Suite)
	  printf("*\t| Grande Suite\t\t%d\t\t*\n", j_test->tab.grande_Suite);
	else
	  printf("*\t| Grande Suite\t\tX\t\t*\n");
	if(j_test->tab.chance)
	  printf("*\t| Chance\t\t%d\t\t*\n", j_test->tab.chance);
	else
	  printf("*\t| Chance\t\tX\t\t*\n");
	if(j_test->tab.yahtzee)
	  printf("*\t| Yahtzee\t\t%d\t\t*\n", j_test->tab.yahtzee);
	else
	  printf("*\t| Yahtzee\t\tX\t\t*\n");
	if(j_test->tab.prime_Yahtzee)
	  printf("*\t| Prime\t\t%d\t\t*\n", j->tab.prime_Yahtzee);
	else
	  printf("*\t| Prime\t\tX\t\t*\n");

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
