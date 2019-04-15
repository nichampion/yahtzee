#include <stdio.h>

#include "../../src/commun.h"
#include "affichage_V1_Test_IA.h"

/**
	*\file affichage.c
	*\brief Permet l'affichage du jeu (version non graphique)
  *\version 1
*/

/**
  *\fn void affichage(t_joueur *j1, t_joueur *j2, t_joueur *jc)
  *\param 2 pointeurs sur les joueurs et un pointeur sur le joueur courant
  *\brief Affiche un tour entre 2 joueurs
  *\author Nicolas CHAMPION
*/
void affichage(t_joueur *j1, t_joueur *j2, t_joueur *jc) {

  printf("* * * * * * * * * * *  YAHTZEE  * * * * * * * * * * * * *\n");
  printf("*\t\t\t\t\t\t\t*\n");
  printf("*\t._______________________________.\t\t*\n");
  printf("*\t|\t\t%s\t%s\t|\t\t*\n", j1->nom, j2->nom);
  printf("*\t|-------------------------------|\t\t*\n");
  printf("*\t| As\t\t%d\t%d\t|\t\t*\n", j1->tab[AS], j2->tab[AS]);
  printf("*\t| Deux\t\t%d\t%d\t|\t\t*\n", j1->tab[DEUX], j2->tab[DEUX]);
  printf("*\t| Trois\t\t%d\t%d\t|\t\t*\n", j1->tab[TROIS], j2->tab[TROIS]);
  printf("*\t| Quatre\t%d\t%d\t|\t\t*\n", j1->tab[QUATRE], j2->tab[QUATRE]);
  printf("*\t| Cinq\t\t%d\t%d\t|\t\t*\n", j1->tab[CINQ], j2->tab[CINQ]);
  printf("*\t| Six\t\t%d\t%d\t|\t\t*\n", j1->tab[SIX], j2->tab[SIX]);
  printf("*\t| Total\t\t%d\t%d\t|\t\t*\n", j1->tab[TOTAL_SUP], j2->tab[TOTAL_SUP]);
  printf("*\t| Prime\t\t%d\t%d\t|\t\t*\n", j1->tab[PRIME_35], j2->tab[PRIME_35]);
  printf("*\t|-------------------------------|\t\t*\n");
  printf("*\t| Brelan\t%d\t%d\t|\t\t*\n", j1->tab[BRELAN], j2->tab[BRELAN]);
  printf("*\t| Carre\t\t%d\t%d\t|\t\t*\n", j1->tab[CARRE], j2->tab[CARRE]);
  printf("*\t| Full\t\t%d\t%d\t|\t\t*\n", j1->tab[FULL], j2->tab[FULL]);
  printf("*\t| Petite Suite\t%d\t%d\t|\t\t*\n", j1->tab[PETITE_SUITE], j2->tab[PETITE_SUITE]);
  printf("*\t| Grande Suite\t%d\t%d\t|\t\t*\n", j1->tab[GRANDE_SUITE], j2->tab[GRANDE_SUITE]);
  printf("*\t| Chance\t%d\t%d\t|\t\t*\n", j1->tab[CHANCE], j2->tab[CHANCE]);
  printf("*\t| Yahtzee\t%d\t%d\t|\t\t*\n", j1->tab[YAHTZEE], j2->tab[YAHTZEE]);
  printf("*\t| Total\t\t%d\t%d\t|\t\t*\n", j1->tab[TOTAL_INF], j2->tab[TOTAL_INF]);
  printf("*\t|-------------------------------|\t\t*\n");
  printf("*\t|TOTAL\t\t%d\t%d\t|\t\t*\n", j1->tab[TOTAL_GEN], j2->tab[TOTAL_GEN]);
  printf("*\t|_______________________________|\t\t*\n");
  printf("*\t\t\t\t\t\t\t*\n");
  printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
}
