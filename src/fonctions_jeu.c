*\author#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "commun.h"
#include "fonctions_jeu.h"
#include "fonctions_joueur.h"
#include "mains.h"

/**
	*\file fonctions_jeu.c
	*\brief Permet le controle des parties, le relancement et le choix des dès
	*\version 2
*/


/**
	*\fn void lancer(t_joueur * j, int i)
	*\param Un pointeur sur un joueur, un int correspondant au dé à lancer
	*\brief Affectation d'un nombre tiré aléatoirement entre 1 et 6 au dé n°i
	*\author Sunny BIARD
*/
void lancer(t_joueur * j, int i){

	j->des[i] = rand()%(7-1) + 1;

}


/**
	*\fn int relancer(t_joueur * j)
	*\param Un pointeur sur un joueur
	*\brief Choix du/des dé(s) à relancer, Relancement de ce(s) dé(s) par appel de "lancer"
	*\author Sunny BIARD
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
	*\fn t_joueur * test_mains(t_joueur *j, t_joueur *j_test)
	*\param Un pointeur sur un joueur + Pointeur sur un joueur de test
	*\brief Test de toutes les combinaisons possibles avec les dés du joueur j
	*\author Sunny BIARD
	*\author Nicolas Champion
*/
t_joueur * test_mains(t_joueur *j, t_joueur *j_test) {
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

	return j_test;
}


/**
	*\fn int fin_de_partie(t_joueur * j)
	*\param Un pointeur sur un joueur
	*\brief Test si toutes les cases du joueur sont remplies, renvoie vrai si rempli
	*\Author Sunny BIARD
*/
int fin_de_partie(t_joueur * j){
	if(j->tab[AS] != VAL_INIT && j->tab[DEUX] != VAL_INIT && j->tab[TROIS] != VAL_INIT && j->tab[QUATRE] != VAL_INIT && j->tab[CINQ] != VAL_INIT && j->tab[SIX] != VAL_INIT && j->tab[BRELAN] != VAL_INIT && j->tab[CARRE] != VAL_INIT && j->tab[FULL] != VAL_INIT && j->tab[PETITE_SUITE] != VAL_INIT && j->tab[PETITE_SUITE] != VAL_INIT && j->tab[GRANDE_SUITE] != VAL_INIT && j->tab[YAHTZEE] != VAL_INIT && j->tab[CHANCE] != VAL_INIT){

		calcul_totaux(j);
		return 1;
	}
	else
		return 0;

}
