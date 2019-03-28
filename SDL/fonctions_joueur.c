#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commun.h"
#include "fonctions_joueur.h"
#include "mains.h"

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
  int i;

  for(i = 0; i < 18; i++){
    j->tab[i] = VAL_INIT;
  }

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

/**
  *\fn void prime_tab(t_joueur *j)
  *\param Un pointeur vers un joueur
  *\brief Correspond a la prime des 35 pts
  *\author Thibault LEMARCHAND
*/
void prime_tab(t_joueur *j){
  int tot_tab_sup = 0;
  int i;

  for(i = 0; i < 6; i++){
    tot_tab_sup += j->tab[i];
  }

  if(tot_tab_sup >= 63)
    j->tab[6] = 35;
  else
   j->tab[6] = 0;
}


/**
  *\fn void prime_tab(t_joueur *j)
  *\param Un pointeur vers un joueur
  *\brief Correspond a la prime yahtzee
  *\author Thibault LEMARCHAND
*/
void prime_yahtzee(t_joueur *j){
  if(yahtzee(j) !=  VAL_INIT){
    if(j->tab[13] == 50)
      j->tab[14] = 100;
  }
}


/**
  *\fn void calcul_totaux(t_joueur *j)
  *\param Un pointeur vers un joueur
  *\brief Permet de calculer les totaux.
  *\brief Correspond aux rubriques total inferieur, superieur et general de la feulle de marque
  *\return Un pointeur vers le joueur fraichement cree
  *\author Thibault LEMARCHAND
*/
void calcul_totaux(t_joueur *j){
  int tot_ssup_apprime = 0;
  int tot_sinf = 0;
  int i;

  prime_tab(j);

  for(i = 0; i < 7; i++){
    tot_ssup_apprime += j->tab[i];
  }

  for(i = 7; i < 15; i++){
    tot_sinf += j->tab[i];
  }

  j->tab[15] = tot_ssup_apprime;
  j->tab[16] = tot_sinf;
  j->tab[17] = tot_ssup_apprime+tot_sinf;
}
