#include <stdio.h>

#include "commun.h"
#include "affichage.h"

/**
	*\file affichage.c
	*\brief Permet l'affichage du jeu
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
  printf("*\t| As\t\t%d\t%d\t|\t\t*\n", j1->tab.as, j2->tab.as);
  printf("*\t| Deux\t\t%d\t%d\t|\t\t*\n", j1->tab.deux, j2->tab.deux);
  printf("*\t| Trois\t\t%d\t%d\t|\t\t*\n", j1->tab.trois, j2->tab.trois);
  printf("*\t| Quatre\t%d\t%d\t|\t\t*\n", j1->tab.quatre, j2->tab.quatre);
  printf("*\t| Cinq\t\t%d\t%d\t|\t\t*\n", j1->tab.cinq, j2->tab.cinq);
  printf("*\t| Six\t\t%d\t%d\t|\t\t*\n", j1->tab.six, j2->tab.six);
  printf("*\t| Total\t\t%d\t%d\t|\t\t*\n", j1->tab.total_Sup, j2->tab.total_Sup);
  printf("*\t| Prime\t\t%d\t%d\t|\t\t*\n", j1->tab.prime_35pts, j2->tab.prime_35pts);
  printf("*\t|-------------------------------|\t\t*\n");
  printf("*\t| Brelan\t%d\t%d\t|\t\t*\n", j1->tab.brelan, j2->tab.brelan);
  printf("*\t| Carre\t\t%d\t%d\t|\t\t*\n", j1->tab.carre, j2->tab.carre);
  printf("*\t| Full\t\t%d\t%d\t|\t\t*\n", j1->tab.full, j2->tab.full);
  printf("*\t| Petite Suite\t%d\t%d\t|\t\t*\n", j1->tab.petite_Suite, j2->tab.petite_Suite);
  printf("*\t| Grande Suite\t%d\t%d\t|\t\t*\n", j1->tab.grande_Suite, j2->tab.grande_Suite);
  printf("*\t| Chance\t%d\t%d\t|\t\t*\n", j1->tab.chance, j2->tab.chance);
  printf("*\t| Yahtzee\t%d\t%d\t|\t\t*\n", j1->tab.yahtzee, j2->tab.yahtzee);
  printf("*\t| Prime\t\t%d\t%d\t|\t\t*\n", j1->tab.prime_Yahtzee, j2->tab.prime_Yahtzee);
  printf("*\t| Total\t\t%d\t%d\t|\t\t*\n", j1->tab.total_Inf, j2->tab.total_Inf);
  printf("*\t|-------------------------------|\t\t*\n");
  printf("*\t|TOTAL\t\t%d\t%d\t|\t\t*\n", j1->tab.total_Gen, j2->tab.total_Gen);
  printf("*\t|_______________________________|\t\t*\n");
  printf("*\t\t\t\t\t\t\t*\n");
  printf("*\t.________________________________.\t\t*\n");
  printf("*\t|1\t2\t3\t4\t5|\t\t*\n");
  printf("*\t|%d\t%d\t%d\t%d\t%d|\t\t*\n", jc->des[0], jc->des[1], jc->des[2], jc->des[3], jc->des[4]);
  printf("*\t.________________________________.\t\t*\n");
  printf("*\t\t\t\t\t\t\t*\n");
  printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
}
