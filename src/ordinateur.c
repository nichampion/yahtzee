#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "commun.h"
#include "ordinateur.h"

/**
	*\file ordinateur.c
	*\brief
	*\version 1.0
*/

/*Lien strat 1 -> http://www.ultraboardgames.com/yahtzee/tips.php*/

int joueur(t_joueur *j);
int adversaire(t_joueur *j);

/*int compter_des(t_joueur *joueur, int nb_test){
  int i, res = 0;
  for(i = 0; i<N; i++){
    if(joueur->des[i] == nb_test)
      res += 1;
  }
  return res;
}*/

int coup_gagnant(t_joueur *j){
  int test = longcourse - valMax;
  int test2 = 0;
  int i = 0;

  test2 = yahtzee(j);
  if(test2 != 0)
    

  for(i = 0;i < valMax; i++){
    if((test + i) == longcourse)
      test2 = 1;
  }
  if(test2 == 1)
    return i;

  else
    return 0;

}


int joueur(t_joueur *j) {
  int i, max = -2, temp;
  int nouvel_val;

  if(coup_gagnant(val) != -1)
    return 1;

  else {
    /* Pour tous les coups possibles */
    for(i = 1; i <= Pas_Max; i++) {
        nouvel_val = val + i;
        temp = adversaire(nouvel_val);
        if(temp > max)
          max = temp;
    }

    /* Retourner le coup possible le plus elevee */
    return max;
  }

}


int adversaire(t_joueur *j) {
  int i, min = 2, temp;
  int nouvel_val;

  if(coup_gagnant(val) != -1)
    return -1;

  else {
    /* Pour tous les coups possibles (ils doivent etre valides !) */
    for(i = 1; i <= Pas_Max; i++) {
        nouvel_val = val + i;
        temp = joueur(nouvel_val);
        if(temp < min)
          min = temp;
    }

    /* Retourner le coup possible le plus faible */
    return min;
  }

}


/* Correspond a la fonction tour_du_joueur dans l'algorithme MIN-MAX */
int strategie_gagnante(t_joueur *j) {
  int i, nouvel_val;
  int temp;

  /* Coup terminant la partie et qui fait gagner l'ordinateur */
  temp = coup_gagnant(val);
  if(temp != -1)
    return temp;

  else {
    /* Pour tous les coups possibles */
    for(i = 1; i <= Pas_Max; i++) {
        nouvel_val = val + i;

        temp = adversaire(nouvel_val);

        if(temp == 1)
          return i; // Retourner le coup correspondant


      }
      return nombre_aleatoire(val);
  }

}
