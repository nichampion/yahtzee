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
	*\Fn : t_joueur * test_mains(t_joueur * j)
	*\Param : Un pointeur sur un joueur
	*\Brief : Test de toutes les combinaisons possibles avec les dés du joueur j
	*\Author : Sunny BIARD
*/
t_joueur * test_mains(t_joueur *j){

	t_joueur * j_test = creer_joueur("Choix");

	if((j->tab[0]) == VAL_INIT)
		j_test->tab[0] = section_superieure(j,1);

	if((j->tab[1]) == VAL_INIT)
		j_test->tab[1] = section_superieure(j,2);

	if((j->tab[2]) == VAL_INIT)
		j_test->tab[2] = section_superieure(j,3);

	if((j->tab[3]) == VAL_INIT)
		j_test->tab[3] = section_superieure(j,4);

	if((j->tab[4]) == VAL_INIT)
		j_test->tab[4] = section_superieure(j,5);

	if((j->tab[5]) == VAL_INIT)
		j_test->tab[5] = section_superieure(j,6);

	if((j->tab[7]) == VAL_INIT)
		j_test->tab[7] = brelan(j);

	if((j->tab[8]) == VAL_INIT)
		j_test->tab[8] = carre(j);

	if((j->tab[9]) == VAL_INIT)
		j_test->tab[9] = full(j);

	if((j->tab[10]) == VAL_INIT)
		j_test->tab[10] = petite_suite(j);

	if((j->tab[11]) == VAL_INIT)
		j_test->tab[11] = grande_suite(j);

	if((j->tab[12]) == VAL_INIT)
		j_test->tab[12] = yahtzee(j);
	else if((j->tab[13]) == 50)
		j_test->tab[14] = 100;

	if((j->tab[13]) == VAL_INIT)
		j_test->tab[13] = chance(j);

	return j_test;

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
			if(j->tab[0] == VAL_INIT){
				if(j_test->tab[0] != VAL_INIT){
					j->tab[0] = j_test->tab[0];
				}
				else{
					j->tab[0] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 2 :
			if(j->tab[1] == VAL_INIT){
				if(j_test->tab[1] != VAL_INIT){
					j->tab[1] = j_test->tab[1];
				}
				else{
					j->tab[1] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 3 :
			if(j->tab[2] == VAL_INIT){
				if(j_test->tab[2] != VAL_INIT){
					j->tab[2] = j_test->tab[2];
				}
				else{
					j->tab[2] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 4 :
			if(j->tab[3] == VAL_INIT){
				if(j_test->tab[3] != VAL_INIT){
					j->tab[3] = j_test->tab[3];
				}
				else{
					j->tab[3] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 5 :
			if(j->tab[4] == VAL_INIT){
				if(j_test->tab[4] != VAL_INIT){
					j->tab[4] = j_test->tab[4];
				}
				else{
					j->tab[4] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 6 :
			if(j->tab[5] == VAL_INIT){
				if(j_test->tab[5] != VAL_INIT){
					j->tab[5] = j_test->tab[5];
				}
				else{
					j->tab[5] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 7 :
			if(j->tab[7] == VAL_INIT){
				if(j_test->tab[7] != VAL_INIT){
					j->tab[7] = j_test->tab[7];
				}
				else{
					j->tab[7] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 8 :
			if(j->tab[8] == VAL_INIT){
				if(j_test->tab[8] != VAL_INIT){
					j->tab[8] = j_test->tab[8];
				}
				else{
					j->tab[8] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 9 :
			if(j->tab[9] == VAL_INIT){
				if(j_test->tab[9] != VAL_INIT){
					j->tab[9] = j_test->tab[9];
				}
				else{
					j->tab[9] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 10 :
			if(j->tab[10] == VAL_INIT){
				if(j_test->tab[10] != VAL_INIT){
					j->tab[10] = j_test->tab[10];
				}
				else{
					j->tab[10] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 11 :
			if(j->tab[11] == VAL_INIT){
				if(j_test->tab[11] != VAL_INIT){
					j->tab[11] = j_test->tab[11];
				}
				else{
					j->tab[11] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 12 :
			if(j->tab[12] == VAL_INIT){
				if(j_test->tab[12] != VAL_INIT){
					j->tab[12] = j_test->tab[12];
				}
				else{
					j->tab[12] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 13 :
			if(j->tab[13] == VAL_INIT){
				if(j_test->tab[13] != VAL_INIT){
					j->tab[13] = j_test->tab[13];
				}
				else{
					j->tab[13] = 0;
				}
				placement = 1;
				break;
			}
			else{
				printf("Impossible de remplir cette case. Veuillez en choisir une autre.\n");
				break;
			}
		case 14 :
			if(j->tab[14] == VAL_INIT){
				if(j_test->tab[14] != VAL_INIT){
					j->tab[14] = j_test->tab[14];
				}
				else{
					j->tab[14] = 0;
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
	if(j_test->tab[0] != VAL_INIT)
  	  printf("*\t| 1 As\t\t%d?\t\t|\t\t*\n", j_test->tab[0]);
	else
  	  printf("*\t| 1 As\t\t%d\t\t|\t\t*\n", j->tab[0]);
	if(j_test->tab[1] != VAL_INIT)
	  printf("*\t| 2 Deux\t%d?\t\t|\t\t*\n", j_test->tab[1]);
	else
  	  printf("*\t| 2 Deux\t%d\t\t|\t\t*\n", j->tab[1]);
	if(j_test->tab[2] != VAL_INIT)
	  printf("*\t| 3 Trois\t%d?\t\t|\t\t*\n", j_test->tab[2]);
	else
  	  printf("*\t| 3 Trois\t%d\t\t|\t\t*\n", j->tab[2]);
	if(j_test->tab[3] != VAL_INIT)
	  printf("*\t| 4 Quatres\t%d?\t\t|\t\t*\n", j_test->tab[3]);
	else
  	  printf("*\t| 4 Quatres\t%d\t\t|\t\t*\n", j->tab[3]);
	if(j_test->tab[4] != VAL_INIT)
	  printf("*\t| 5 Cinq\t%d?\t\t|\t\t*\n", j_test->tab[4]);
	else
  	  printf("*\t| 5 Cinq\t%d\t\t|\t\t*\n", j->tab[4]);
	if(j_test->tab[5] != VAL_INIT)
	  printf("*\t| 6 Six\t\t%d?\t\t|\t\t*\n", j_test->tab[5]);
	else
  	  printf("*\t| 6 Six\t\t%d\t\t|\t\t*\n", j->tab[5]);

	printf("*\t| Total\t\t%d\t\t|\t\t*\n", j->tab[15]);
	printf("*\t| Prime\t\t%d\t\t|\t\t*\n", j->tab[6]);
  printf("*\t|-------------------------------|\t\t*\n");

	if(j_test->tab[7] != VAL_INIT)
	  printf("*\t| 7 Brelan\t%d?\t\t|\t\t*\n", j_test->tab[7]);
	else
  	  printf("*\t| 7 Brelan\t%d\t\t|\t\t*\n", j->tab[7]);
	if(j_test->tab[8] != VAL_INIT)
	  printf("*\t| 8 Carre\t%d?\t\t|\t\t*\n", j_test->tab[8]);
	else
  	  printf("*\t| 8 Carre\t%d\t\t|\t\t*\n", j->tab[8]);
	if(j_test->tab[9] != VAL_INIT)
	  printf("*\t| 9 Full\t%d?\t\t|\t\t*\n", j_test->tab[9]);
	else
  	  printf("*\t| 9 Full\t%d\t\t|\t\t*\n", j->tab[9]);
	if(j_test->tab[10] != VAL_INIT)
	  printf("*\t| 10 P Suite\t%d?\t\t|\t\t*\n", j_test->tab[10]);
	else
  	  printf("*\t| 10 P Suite\t%d\t\t|\t\t*\n", j->tab[10]);
	if(j_test->tab[11] != VAL_INIT)
	  printf("*\t| 11 G Suite\t%d?\t\t|\t\t*\n", j_test->tab[11]);
	else
  	  printf("*\t| 11 G Suite\t%d\t\t|\t\t*\n", j->tab[11]);
	if(j_test->tab[12] != VAL_INIT)
	  printf("*\t| 12 Yahtzee\t%d?\t\t|\t\t*\n", j_test->tab[12]);
	else
  	  printf("*\t| 12 Yahtzee\t%d\t\t|\t\t*\n", j->tab[12]);
	if(j_test->tab[13] != VAL_INIT)
	  printf("*\t| 13 Chance\t%d?\t\t|\t\t*\n", j_test->tab[13]);
	else
	  printf("*\t| 13 Chance\t%d\t\t|\t\t*\n", j->tab[13]);
	if(j_test->tab[14] != VAL_INIT)
	  printf("*\t| 14 Prime\t%d?\t\t|\t\t*\n", j->tab[14]);
	else
	  printf("*\t| 14 Prime\t%d\t\t|\t\t*\n", j_test->tab[14]);

	printf("*\t| Total\t\t%d\t\t|\t\t*\n", j->tab[16]);
  printf("*\t|-------------------------------|\t\t*\n");
  printf("*\t|TOTAL\t\t%d\t\t|\t\t*\n", j->tab[17]);
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
	if(j->tab[0] != VAL_INIT && j->tab[1] != VAL_INIT && j->tab[2] != VAL_INIT && j->tab[3] != VAL_INIT && j->tab[4] != VAL_INIT && j->tab[5] != VAL_INIT && j->tab[7] != VAL_INIT && j->tab[8] != VAL_INIT && j->tab[9] != VAL_INIT && j->tab[10] != VAL_INIT && j->tab[10] != VAL_INIT && j->tab[11] != VAL_INIT && j->tab[12] != VAL_INIT && j->tab[13] != VAL_INIT && j->tab[14] != VAL_INIT){
		calcul_totaux(j);
		prime_tab(j);
		return 1;
	}
	else
		return 0;



}
