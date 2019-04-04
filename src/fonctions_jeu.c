#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "commun.h"
#include "fonctions_jeu.h"
#include "fonctions_joueur.h"
#include "mains.h"

/**
	*\File : fonctions_jeu.c
	*\Brief : Fonctions du jeu
	*\version 1.0
	*\Author : Sunny BIARD
*/

/**
	*\Fn : void lancer(t_joueur * j, int i)
	*\Param : Un pointeur sur un joueur, un int correspondant au dé à lancer
	*\Brief : Affectation d'un nombre tiré aléatoirement entre 1 et 6 au dé n°i
	*\Author : Sunny BIARD
*/
void lancer(t_joueur * j, int i){

	j->des[i] = rand()%(7-1) + 1;

}

/**
	*\Fn : int relancer(t_joueur * j)
	*\Param : Un pointeur sur un joueur
	*\Brief : Choix du/des dé(s) à relancer, Relancement de ce(s) dé(s) par appel de "lancer"
	*\Author : Sunny BIARD
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

/**
	*\Fn : t_joueur * test_mains(t_joueur *j, t_joueur *j_test)
	*\Param : Un pointeur sur un joueur + Pointeur sur un joueur de test
	*\Brief : Test de toutes les combinaisons possibles avec les dés du joueur j
	*\Author : Sunny BIARD
	*\Author : Nicolas Champion
*/
void test_mains(t_joueur *j, t_joueur *j_test) {
	int i;
	int (*pt_fonct[TAILLE_TAB_PF])(t_joueur *j) = {brelan, carre, full, petite_suite, grande_suite, yahtzee, chance}; /* Pointe des fonctions testant les mains des sections inferieur (de la feuille de marque de Yahtzee) */

	/* Parcours section supérieur */
	for(i = AS; i <= SIX; i++) {
		if((j->tab[i]) == VAL_INIT)
			j_test->tab[i] = section_superieure(j, i + 1);
	}

	/* Parcours section inférieur */
	for(i = BRELAN; i <= CHANCE; i++) {
		if((j->tab[i]) == VAL_INIT)
			j_test->tab[i] = pt_fonct[i - (TAILLE_TAB_PF - 1)](j); /* Appel la fonction comptant les points de la main (pour une ligne de la feuille de marque du yahtzee) */
	}

		affichage_possibilites(j,j_test);
}

/**
	*\Fn : int choix_placement(t_joueur * j, t_joueur * j_test)
	*\Param : Un pointeur sur un joueur, un autre pointeur sur un joueur test
	*\Brief : Choix de remplissage d'une case du joueur courant
	*\Author : Sunny BIARD
*/
int choix_placement(t_joueur *j, t_joueur * j_test){
	int choix, placement = 0;
	printf("Choisir la case à remplir (1-14) : ");
	scanf("%d",&choix);
	while(choix < 1 || choix > 14){
		printf("Choisir la case à remplir (1-14) : ");
		scanf("%d",&choix);
	}

	switch(choix)
	{
		case 1 :
			if(j->tab[AS] == VAL_INIT){
				if(j_test->tab[AS] != VAL_INIT){
					j->tab[AS] = j_test->tab[AS];
				}
				else{
					j->tab[AS] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 2 :
			if(j->tab[DEUX] == VAL_INIT){
				if(j_test->tab[DEUX] != VAL_INIT){
					j->tab[DEUX] = j_test->tab[DEUX];
				}
				else{
					j->tab[DEUX] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 3 :
			if(j->tab[TROIS] == VAL_INIT){
				if(j_test->tab[TROIS] != VAL_INIT){
					j->tab[TROIS] = j_test->tab[TROIS];
				}
				else{
					j->tab[TROIS] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 4 :
			if(j->tab[QUATRE] == VAL_INIT){
				if(j_test->tab[QUATRE] != VAL_INIT){
					j->tab[QUATRE] = j_test->tab[QUATRE];
				}
				else{
					j->tab[QUATRE] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 5 :
			if(j->tab[CINQ] == VAL_INIT){
				if(j_test->tab[CINQ] != VAL_INIT){
					j->tab[CINQ] = j_test->tab[CINQ];
				}
				else{
					j->tab[CINQ] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 6 :
			if(j->tab[SIX] == VAL_INIT){
				if(j_test->tab[SIX] != VAL_INIT){
					j->tab[SIX] = j_test->tab[SIX];
				}
				else{
					j->tab[SIX] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 7 :
			if(j->tab[BRELAN] == VAL_INIT){
				if(j_test->tab[BRELAN] != VAL_INIT){
					j->tab[BRELAN] = j_test->tab[BRELAN];
				}
				else{
					j->tab[BRELAN] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 8 :
			if(j->tab[CARRE] == VAL_INIT){
				if(j_test->tab[CARRE] != VAL_INIT){
					j->tab[CARRE] = j_test->tab[CARRE];
				}
				else{
					j->tab[CARRE] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 9 :
			if(j->tab[FULL] == VAL_INIT){
				if(j_test->tab[FULL] != VAL_INIT){
					j->tab[FULL] = j_test->tab[FULL];
				}
				else{
					j->tab[FULL] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 10 :
			if(j->tab[PETITE_SUITE] == VAL_INIT){
				if(j_test->tab[PETITE_SUITE] != VAL_INIT){
					j->tab[PETITE_SUITE] = j_test->tab[PETITE_SUITE];
				}
				else{
					j->tab[PETITE_SUITE] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 11 :
			if(j->tab[GRANDE_SUITE] == VAL_INIT){
				if(j_test->tab[GRANDE_SUITE] != VAL_INIT){
					j->tab[GRANDE_SUITE] = j_test->tab[GRANDE_SUITE];
				}
				else{
					j->tab[GRANDE_SUITE] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 12 :
			if(j->tab[YAHTZEE] == VAL_INIT){
				if(j_test->tab[YAHTZEE] != VAL_INIT){
					j->tab[YAHTZEE] = j_test->tab[YAHTZEE];
				}
				else{
					j->tab[YAHTZEE] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 13 :
			if(j->tab[CHANCE] == VAL_INIT){
				if(j_test->tab[CHANCE] != VAL_INIT){
					j->tab[CHANCE] = j_test->tab[CHANCE];
				}
				else{
					j->tab[CHANCE] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}

	}

	return placement;

}

/**
	*\Fn : void affichage_possibilites(t_joueur * j, t_joueur * j_test)
	*\Param : Un pointeur sur un joueur, un pointeur sur un joueur test
	*\Brief : Affichage des combinaisons possibles et croix pour les cases déjà remplies pour le joueur j
	*\Author : Sunny BIARD
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

/**
	*\Fn : int fin_de_partie(t_joueur * j)
	*\Param : Un pointeur sur un joueur
	*\Brief : Test si toutes les cases du joueur sont remplies, renvoie vrai si rempli
	*\Author : Sunny BIARD
*/
int fin_de_partie(t_joueur * j){
	if(j->tab[AS] != VAL_INIT && j->tab[DEUX] != VAL_INIT && j->tab[TROIS] != VAL_INIT && j->tab[QUATRE] != VAL_INIT && j->tab[CINQ] != VAL_INIT && j->tab[SIX] != VAL_INIT && j->tab[BRELAN] != VAL_INIT && j->tab[CARRE] != VAL_INIT && j->tab[FULL] != VAL_INIT && j->tab[PETITE_SUITE] != VAL_INIT && j->tab[PETITE_SUITE] != VAL_INIT && j->tab[GRANDE_SUITE] != VAL_INIT && j->tab[YAHTZEE] != VAL_INIT && j->tab[CHANCE] != VAL_INIT){

		calcul_totaux(j);
		return 1;
	}
	else
		return 0;



}
