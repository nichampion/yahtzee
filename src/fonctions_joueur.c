#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commun.h"
#include "fonctions_joueur.h"

/**
	*\file fonctions_joueur.c
	*\brief
	*\version 1.0
*/

/**
  *\fn void init_bloc_note(t_joueur *j)
  *\param Un pointeur vers un joueur
  *\brief Permet d'initialiser les scores de la feuille de marque
  *\author Nicolas CHAMPION
*/
void init_bloc_note(t_joueur *j) {

  j->tab.as = VAL_INIT;
  j->tab.deux = VAL_INIT;
  j->tab.trois = VAL_INIT;
  j->tab.quatres = VAL_INIT;
  j->tab.cinq = VAL_INIT;
  j->tab.six = VAL_INIT;
  j->tab.prime_35pts = VAL_INIT;

  j->tab.brelan = VAL_INIT;
  j->tab.carre = VAL_INIT;
  j->tab.full = VAL_INIT;
  j->tab.petite_Suite = VAL_INIT;
  j->tab.grande_Suite = VAL_INIT;
  j->tab.chance = VAL_INIT;
  j->tab.yahtzee = VAL_INIT;
  j->tab.prime_Yahtzee = VAL_INIT;

  j->tab.total_Sup = VAL_INIT;
  j->tab.total_Inf = VAL_INIT;

  j->tab.total_Gen = VAL_INIT;

}

/**
  *\fn t_joueur* creer_joueur(char nom[T])
  *\param Le nom du joueur
  *\brief Permet de creer et d'initialiser un joueur en memoire dynamique
  *\return Un pointeur vers le joueur fraichement cree
  *\author Nicolas CHAMPION
*/
t_joueur* creer_joueur(char nom[T]) {
  int i;
  t_joueur *j = malloc(sizeof(t_joueur));

  strcpy(j->nom, nom);

  init_bloc_note(j);

  for(i = 0; i < N; i++)
    j->des[i] = 0;

  return j;
}

/**
  *\fn void detruire_joueur(t_joueur **j)
  *\param Un pointeur vers un pointeur de joueur
  *\brief Permet de detruire un joueur en memoire dynamique
  *\author Nicolas CHAMPION
*/
void detruire_joueur(t_joueur **j) {
  free(*j);
  (*j) = NULL;
}

void calcul_totaux(t_joueur *j){
  int tot_ssup_avprime = 0;
  int tot_ssup_apprime = 0;
  int tot_sinf = 0;

  tot_ssup_avprime = (j->tab.as)+(j->tab.deux)+(j->tab.trois)+(j->tab.quatres)+
                     (j->tab.cinq)+(j->tab.six);

  if(tot_ssup_avprime >= 63)
    j->tab.prime_35pts = 35;

  tot_ssup_apprime = tot_ssup_avprime + j->tab.prime_35pts;

  tot_sinf = (j->tab.brelan)+(j->tab.carre)+(j->tab.full)+(j->tab.petite_Suite)+
             (j->tab.grande_Suite)+(j->tab.yahtzee)+(j->tab.chance)+(j->tab.prime_Yahtzee);

  j->tab.total_Gen = tot_ssup_apprime+tot_sinf;

  printf("%d",j->tab.total_Gen);
}
