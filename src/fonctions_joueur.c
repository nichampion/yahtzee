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

  for(i = 0; i < 18; i++){ /*Initialisation de la feuille de marque avec la
                            variable globale VAL_INIT*/
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

  strcpy(j->nom, nom); /*Le nom du joueur prend le nom passé en paramètre*/

  init_bloc_note(j); /*Initialisation de la feuille de marque*/

  for(i = 0; i < N; i++) /*Initialisation du tableau de dés*/
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

  for(i = 0; i < 6; i++){ /*Calcul du score de la grille supérieure*/
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
  *\fn void prime_tab(t_joueur *j)
  *\param Un pointeur vers un joueur
  *\brief Correspond a la prime yahtzee
  *\author Thibault LEMARCHAND
*/
void prime_yahtzee(t_joueur *j){
  if(yahtzee(j) !=  VAL_INIT){  /*Si la case du yahtzee non nulle*/

    if(j->tab[YAHTZEE] == 50)   /*Si yahtzee*/

      j->tab[PRIME_YAHTZEE] = 100;  /*Si le joueur effectue un autre yahtzee
                                    alors on ajoute 100 points dans la case
                                    prime_yahtzee*/

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

  prime_tab(j); /*On regarde si le joueur dispose d'assez de points pour avoir la
                prime de 35 pts avec la grille supérieure*/

  for(i = 0; i < 7; i++){            /*Total de points dans la grille supérieure*/
    tot_ssup_apprime += j->tab[i];
  }

  for(i = 7; i < 15; i++){          /*Total de points dans la grille inférieure*/
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
