#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commun.h"
#include "fonctions_joueur.h"
#include "mains.h"

/**
	*\file fonctions_joueur.c
	*\brief Gestion des joueurs en memoire et attribution des primes
	*\version 2
*/


/**
  *\fn void init_bloc_note(t_joueur *j)
  *\param Un pointeur vers un joueur
  *\brief Permet d'initialiser les scores de la feuille de marque
  *\author Nicolas CHAMPION
*/
void init_bloc_note(t_joueur *j) {
  int i;

  for(i = AS; i < TAILLE_TAB; i++)
    j->tab[i] = VAL_INIT; /* Initialisation de la feuille de marque avec la variable globale VAL_INIT */

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

  strcpy(j->nom, nom); /* Le nom du joueur prend le nom passé en paramètre */

  init_bloc_note(j); /* Initialisation de la feuille de marque */

  /* Initialisation du tableau de dés */
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

  for(i = AS; i <= SIX; i++){ /*Calcul du score de la grille supérieure*/
    tot_tab_sup += j->tab[i];
  }

  if(tot_tab_sup >= 63) /*Si le score de la partie supérieure est supérieur ou égal
                        à 63 (nb de pts nécessaire pour avoir la prime)*/

    j->tab[PRIME_35] = 35; /*Alors on ajoute 35 pts dans la prime de la grille
                            supérieure*/

  else                     /*Sinon la prime est égale à 0*/
   j->tab[PRIME_35] = 0;
}


/**
  *\fn void calcul_totaux(t_joueur *j)
  *\brief Permet de calculer les totaux.
  *\brief Correspond aux rubriques total inferieur, superieur et general de la feulle de marque
  *\param Un pointeur vers un joueur
  *\author Thibault LEMARCHAND
*/
void calcul_totaux(t_joueur *j){
  int tot_ssup_apprime = 0;
  int tot_sinf = 0;
  int i;

  prime_tab(j); /*On regarde si le joueur dispose d'assez de points pour avoir la
                prime de 35 pts avec la grille supérieure*/

  for(i = AS; i <= PRIME_35; i++){           /*Total de points dans la grille supérieure*/
    tot_ssup_apprime += j->tab[i];
  }

  for(i = BRELAN; i <= CHANCE; i++){          /*Total de points dans la grille inférieure*/
    tot_sinf += j->tab[i];
  }

  j->tab[TOTAL_SUP] = tot_ssup_apprime; /*On entre la valeur du total supérieur dans
                                        la structure joueur*/

  j->tab[TOTAL_INF] = tot_sinf;         /*On entre la valeur du total inférieur dans
                                        la structure joueur*/

  j->tab[TOTAL_GEN] = tot_ssup_apprime+tot_sinf;/*On additionne le total supérieur
                                                et le total inférieur afin d avoir
                                                le score total du joueur*/
}
