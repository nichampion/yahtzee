#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "commun.h"
#include "ordinateur.h"
#include "fonctions_joueur.h"
#include "fonctions_jeu.h"

/**
	*\file ordinateur.c
	*\brief
	*\version 1.0
*/

/*Lien strat 1 -> http://www.ultraboardgames.com/yahtzee/tips.php*/


/* ****************** Calcul de la meilleur main ****************** */


/**
  *\brief Sous fonction. Intervient dans la fonction meilleur_score
*/
static
void test_max(int *val, int *max, char pos_max[20], char ligne_courante[20]) {
  if(*val > *max) {
    *max = *val;
    strcpy(pos_max, ligne_courante);
  }
}


/**
  *\brief Sous fonction. Intervient dans la fonction meilleur_score
*/
static
void choisir_max(t_joueur *j, int max, char pos_max[20]) {

    if(strcmp(pos_max,"null") == 0) return;
    if(strcmp(pos_max,"as") == 0) j->tab.as = max;
    if(strcmp(pos_max,"deux") == 0) j->tab.deux = max;
    if(strcmp(pos_max,"trois") == 0) j->tab.trois = max;
    if(strcmp(pos_max,"quatres") == 0) j->tab.quatres = max;
    if(strcmp(pos_max,"cinq") == 0) j->tab.cinq = max;
    if(strcmp(pos_max,"six") == 0) j->tab.six = max;
    if(strcmp(pos_max,"brelan") == 0) j->tab.brelan = max;
    if(strcmp(pos_max,"carre") == 0) j->tab.carre = max;
    if(strcmp(pos_max,"full") == 0) j->tab.full = max;
    if(strcmp(pos_max,"petite_Suite") == 0) j->tab.petite_Suite = max;
    if(strcmp(pos_max,"grande_Suite") == 0) j->tab.grande_Suite = max;
    if(strcmp(pos_max,"yahtzee") == 0) j->tab.yahtzee = max;
    if(strcmp(pos_max,"chance") == 0) j->tab.chance = max;

}


/**
  *\brief Choisi la main qui rapporte le plus de points pour une combinaison de des donnée.
*/
void meilleur_score(t_joueur *j, t_joueur *j_test) {
  int max = VAL_INIT;
  char pos_max[20] = "null";

  /* Parcourir feuille de marque de j_test */
  if(j->tab.as == VAL_INIT)
    test_max(&(j_test->tab.as), &max, pos_max, "as");

  if(j->tab.deux == VAL_INIT)
    test_max(&(j_test->tab.deux), &max, pos_max, "deux");

  if(j->tab.trois == VAL_INIT)
    test_max(&(j_test->tab.trois), &max, pos_max, "trois");

  if(j->tab.quatres == VAL_INIT)
    test_max(&(j_test->tab.quatres), &max, pos_max, "quatres");

  if(j->tab.cinq == VAL_INIT)
    test_max(&(j_test->tab.cinq), &max, pos_max, "cinq");

  if(j->tab.six == VAL_INIT)
    test_max(&(j_test->tab.six), &max, pos_max, "six");

  if(j->tab.brelan == VAL_INIT)
    test_max(&(j_test->tab.brelan), &max, pos_max, "brelan");

  if(j->tab.carre == VAL_INIT)
    test_max(&(j_test->tab.carre), &max, pos_max, "carre");

  if(j->tab.full == VAL_INIT)
    test_max(&(j_test->tab.full), &max, pos_max, "full");

  if(j->tab.petite_Suite == VAL_INIT)
    test_max(&(j_test->tab.petite_Suite), &max, pos_max, "petite_Suite");

  if(j->tab.grande_Suite == VAL_INIT)
    test_max(&(j_test->tab.grande_Suite), &max, pos_max, "grande_Suite");

  if(j->tab.yahtzee == VAL_INIT)
    test_max(&(j_test->tab.yahtzee), &max, pos_max, "yahtzee");

  if(j->tab.chance == VAL_INIT)
    test_max(&(j_test->tab.chance), &max, pos_max, "chance");

  /* Enregistrer dans j le max */
  choisir_max(j, max, pos_max);

}


/* ****************** Obtention du bonus supérieurs ****************** */


int compter_des(t_joueur *joueur, int nb_test){
  int i, res = 0;
  for(i = 0; i<N; i++){
    if(joueur->des[i] == nb_test)
      res += 1;
  }
  return res;
}

/**
  *\brief Strategie permettant d'obtenir le maximum de points dans la section superieur de la feuille de marque
*/

void val_des_max(int val_c, int *val_max, int nb_des_c, int *nb_des_max) {
  if(nb_des_c >= *nb_des_max) {
    *val_max = val_c;
    *nb_des_max = nb_des_c;
  }
}


/**
  *\brief Retourne la val des des les plus elevee en plus grand nombre et disponible (Valeur non jouée dans la feuille de marque)
*/
int choix_des_strat_sup(int tab[6], t_joueur *j) {
  int val_max = 0;
  int nb_des_max = 0;

  if(j->tab.as == VAL_INIT)
    val_des_max(1, &val_max, tab[0], &nb_des_max);

  if(j->tab.deux == VAL_INIT)
    val_des_max(2, &val_max, tab[1], &nb_des_max);

  if(j->tab.trois == VAL_INIT)
    val_des_max(3, &val_max, tab[2], &nb_des_max);

  if(j->tab.quatres == VAL_INIT)
    val_des_max(4, &val_max, tab[3], &nb_des_max);

  if(j->tab.cinq == VAL_INIT)
    val_des_max(5, &val_max, tab[4], &nb_des_max);

  if(j->tab.six == VAL_INIT)
    val_des_max(6, &val_max, tab[5], &nb_des_max);

  return val_max;
}


int strat_superieur(t_joueur *j, t_joueur *j_test) {
  int i;
  int nb_des[6];

  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

  /* Verif si cette strat est applicable */
  if((j->tab.as != VAL_INIT) && (j->tab.deux != VAL_INIT) && (j->tab.trois != VAL_INIT) && (j->tab.quatres != VAL_INIT) && (j->tab.cinq != VAL_INIT) && (j->tab.six!= VAL_INIT))
    return 0;

  /* Choisir des (plus eleve, en plus gd nombre et dispo (non joue)) */
  int val_des_a_garder = choix_des_strat_sup(nb_des, j);

  printf("Val a garder : %d\n", val_des_a_garder);

  /* Relancer les des pour obtenir le plus de des de cette valeur */
  int nb_lance;
  /* 3 fois et tant que tous les des ne sont = a des_a_garder */
  for(nb_lance = 3; nb_lance > 1; nb_lance--) {
    for(i = 0; i < 5; i++) {
      if(j->des[i] != val_des_a_garder)
        lancer(j, i);
    }
    test_mains(j);
  }

  /* Cela est-il pertinent d'appliquer cette stratégie ? */
  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

  if(nb_des[val_des_a_garder - 1] < 3)
    return 0;

  /* On applique cette stratégie */
  j_test = test_mains(j);
  switch(val_des_a_garder) {
		case 1 :  j->tab.as = j_test->tab.as; break;
    case 2 :  j->tab.deux = j_test->tab.deux; break;
    case 3 :  j->tab.trois = j_test->tab.trois; break;
    case 4 :  j->tab.quatres = j_test->tab.quatres; break;
    case 5 :  j->tab.cinq = j_test->tab.cinq; break;
    case 6 :  j->tab.six = j_test->tab.six; break;
  }

  return 1;

}


int tour_ordinateur(t_joueur *j) {
  int i;
  t_joueur *tempo = creer_joueur("tempo");

  for(i = 0; i < 5; i++)
    lancer(j, i);

  tempo = test_mains(j);

  strat_superieur(j, tempo);

  //choix_placement(j,tempo);

  //meilleur_score(j, tempo);

  return 0; // A changer par la suite

}
