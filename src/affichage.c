#include <stdio.h>

#include "commun.h"
#include "affichage.h"

/**
	*\file affichage.c
	*\brief
*/

void affichage(t_joueur *j1, t_joueur *j2, t_joueur *jc) {

  printf("* * * * * * * * * * *  YAHTZEE  * * * * * * * * * * *\n");
  printf("*													*\n");
  printf("*			   .________________________.			*\n");
  printf("*			   |				%s 	%s 	|			*\n", j1->nom, j2->nom);
  printf("*			   |------------------------|			*\n");
  printf("*			   | As				%d 	%d 	|			*\n", j1->tab.as, j2->tab.as);
  printf("*			   | Deux			%d 	%d 	|			*\n", j1->tab.deux, j2->tab.deux);
  printf("*			   | Trois			%d 	%d 	|			*\n", j1->tab.trois, j2->tab.trois);
  printf("*			   | Quatres		%d 	%d 	|			*\n", j1->tab.quatres, j2->tab.quatres);
  printf("*			   | Cinq 			%d 	%d 	|			*\n", j1->tab.cinq, j2->tab.cinq);
  printf("*			   | Six 			%d 	%d 	|			*\n", j1->tab.six, j2->tab.six);
  printf("*			   | Total 			%d 	%d 	|			*\n", j1->tab.total_Sup, j2->tab.total_Sup);
  printf("*			   | Prime 			%d 	%d 	|			*\n", j1->tab.prime_35pts, j2->tab.prime_35pts);
  printf("*			   |------------------------|			*\n");
  printf("*			   | Brelan			%d 	%d 	|			*\n", j1->tab.brelan, j2->tab.brelan);
  printf("*			   | Carre 			%d 	%d 	|			*\n", j1->tab.carre, j2->tab.carre);
  printf("*			   | Petite Suite	%d 	%d 	|			*\n", j1->tab.petite_Suite, j2->tab.as);
  printf("*			   | Grande Suite	%d 	%d 	|			*\n", j1->tab.grande_Suite, j2->tab.grande_Suite);
  printf("*			   | Chance			%d 	%d 	|			*\n", j1->tab.chance, j2->tab.chance);
  printf("*			   | Yahtzee 		%d 	%d 	|			*\n", j1->tab.yahtzee, j2->tab.yahtzee);
  printf("*			   | Prime			%d 	%d 	|			*\n", j1->tab.prime_Yahtzee, j2->tab.prime_Yahtzee);
  printf("*			   | Total			%d 	%d 	|			*\n", j1->tab.total_Inf, j2->tab.total_Inf);
  printf("*			   |------------------------|			*\n");
  printf("*			   |TOTAL 			%d 	%d 	|			*\n", j1->tab.total_Gen, j2->tab.total_Gen);
  printf("*			   |________________________|			*\n");
  printf("*													*\n");
  printf("*		   .________________________________.		*\n");
  printf("*		   |Des		|	1	2	3	4	5	|		*\n");
  printf("*		   |		|	%d 	%d 	%d 	%d 	%d 	|		*\n", jc->des[0], jc->des[1], jc->des[2], jc->des[3], jc->des[4]);
  printf("*		   |________|_______________________|		*\n");
  printf("*													*\n");
  printf("* * * * * * * * * * * * * * * * * * * * * * * * * *	* \n");

}
