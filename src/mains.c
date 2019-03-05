#include <stdio.h>
#include <stdlib.h>

#define VRAI 1
#define FAUX 0
#include "commun.h"
#include "mains.h"


/**
	*\fn int somme_des(t_joueur *j)
	*\param Un pointeur vers un joueur
	*\return La somme des des
	*\brief Somm les 5 des du joueurs
  *\author CHAMPION Nicolas
*/
int somme_des(t_joueur *j) {
  int i, somme = 0;

  for(i = 0; i < N; i++)
    somme += j->des[i];

  return somme;
}


/**
	*\fn void tri_bulle(int tab[],int taille)
	*\param Un tableau d entier et sa taille
	*\brief Trie dans l ordre croissant le Tableau
  *\Author : LEMARCHAND Thibault
*/
void tri_bulle(int tab[],int taille){
  int i, test,temp;

  do{
    test = 0;

    for(i=0;i<N-1;i++){
      if(tab[i]>tab[i+1]){
        temp = tab[i];
        tab[i]= tab[i+1];
        tab[i+1] = temp;
        test = 1;
      }
    }
  }while(test);
}

/**
	*\fn section_superieur(t_joueur *joueur, int nb_test)
	*\param Un pointeur vers un joueur et un le nombre que l'on souhaite tester
	*\return Le nombre de points
	*\brief calcul le nombre de dé ayant le nombre voulu par le joueur
  *\author BROUARD Antoine
*/
int section_superieur(t_joueur *joueur, int nb_test){
  int i, res = 0;
  for(i = 0; i<N; i++){
    if(joueur->des[i] == nb_test)
      res += nb_test;
  }
  return nb_test;
}

/**
	*\fn chance(t_joueur * joueur)
	*\param Un pointeur vers un joueur
	*\return Le nombre de points total des 5 dés
	*\brief calcul le nombre de points total des 5 dés
  *\author BROUARD Antoine
*/
int chance(t_joueur * joueur){
  return(somme_des(joueur));
}

/**
	*\fn brelan(t_joueur *j)
	*\param Un pointeur vers un joueur
	*\return Le nombre de points ou -1 si ce n'est pas un brelan
	*\brief Total des 5 des : 3 chiffres X + 2 derniers resultats des dés obligatoirement différents
  *\author CHAMPION Nicolas
*/
int brelan(t_joueur *j) {
	int n1 = -1, n2 = -1, n3 = -1;
	int nb_n1 = 0, nb_n2 = 0, nb_n3 = 0; /* Occurence de n1, n2 et n3 */
	int i;

	n1 = j->des[0];
	nb_n1++;

	for(i = 1; i < N; i++) {

		if(j->des[i] == n1)
			nb_n1++;

    else if(n2 == -1) {
      n2 = j->des[i];
      nb_n2++;
    }
		else if(j->des[i] == n2)
			nb_n2++;

    else if(n3 == -1) {
      n3 = j->des[i];
      nb_n3++;
    }
		else if(j->des[i] == n3)
			nb_n3++;

		else
			return -1;  /* Retourne -1 si ce n'est pas un brelan */

	}

  if((nb_n1 == 1) && (nb_n2 == 1) && (nb_n3 == 3))
    return somme_des(j);
  else if((nb_n1 == 1) && (nb_n2 == 3) && (nb_n3 == 1))
    return somme_des(j);
  else if((nb_n1 == 3) && (nb_n2 == 1) && (nb_n3 == 1))
    return somme_des(j);
	else
		return -1; /* Retourne -1 si ce n'est pas un brelan */
}


/**
	*\fn carre(t_joueur *j)
	*\param Un pointeur vers un joueur
	*\return Le nombre de points ou -1 si ce n'est pas un carre
	*\brief Total des 5 des : 4 chiffres X + 1 resultats des dés obligatoirement différent des 4 autres
*/
int carre(t_joueur *j) {
  int n1 = -1, n2 = -1;
	int nb_n1 = 0, nb_n2 = 0; /* Occurence de n1, n2 */
	int i;


	n1 = j->des[0];
	nb_n1++;

	for(i = 1; i < N; i++) {

		if(j->des[i] == n1)
			nb_n1++;

    else if(n2 == -1) {
      n2 = j->des[i];
      nb_n2++;
    }
		else if(j->des[i] == n2)
			nb_n2++;

		else
			return -1;  /* Retourne -1 si ce n'est pas un carre */

	}

  if((nb_n1 == 4) && (nb_n2 == 1))
    return somme_des(j);
  else if((nb_n1 == 1) && (nb_n2 == 4))
    return somme_des(j);

	else
		return -1; /* Retourne -1 si ce n'est pas un brelan */
}


/*int full(t_joueur *joueur){
  int i,j,k,l,m;
  for(i = 0; i<=4; i++){
    for(j = 0; j<=4; j++){
      for(k = 0; k<=4; k++){
        for(l = 0; l<=4; l++){
          for(m = 0; m<=4; m++){
            if((joueur->des[i] == joueur->des[j] && joueur->des[j] == joueur->des[k] && joueur->des[k] != joueur->des[l] && joueur->des[l] == joueur->des[m]) && ((i!=j) && (i!=k) && (i!=l) && (i!=m) && (j!=k) && (j!=l) && (j!=m) && (k!=l) && (k!=m) && (l!=m)))
              return VRAI;
          }
        }
      }
    }
  }
  return FAUX;
}*/

/**
	*\fn full(t_joueur *j)
	*\param Un pointeur vers un joueur
	*\return Le nombre de points ou -1 si ce n'est pas un full
	*\brief Total des 5 des : 3 chiffres X + 2 y
*/
int full(t_joueur *j) {
	int n1 = -1, n2 = -1;
	int nb_n1 = 0, nb_n2 = 0; /* Occurence de n1 et n2 */
	int i;

	n1 = j->des[0];
	nb_n1++;

	for(i = 1; i < N; i++) {

		if(j->des[i] == n1)
			nb_n1++;

		/* Cas non initialisee */
		else if(n2 == -1) {
			n2 = j->des[i];
			nb_n2++;
		}

		else if(j->des[i] == n2)
			nb_n2++;

		/* Cas ou il y a un 3 nombre */
		else
			return -1;
	}

	if((nb_n1 == 2 && nb_n2 == 3) || (nb_n1 == 3 && nb_n2 == 2))
		return 25; /* Retourne le nombre de point que rapporte un full */

	else
		return -1; /* Retourne -1 si ce n'est pas un full */
}


/**
	*\fn int petitesuite(t_joueur *j)
	*\param Un pointeur vers un joueur
  *\return Le nombre de points ou -1 si pas de petite suite
	*\brief Total des 5 des : 4 dés se suivent + 1 dé ne suivant pas le reste
  *\Author : LEMARCHAND Thibault
*/

int petitesuite(t_joueur *j) {
	int n1 = -1; /*Prend la valeur du dé*/
	int i;
  int tab[5]; /*Tableau de dé*/
  int dep; /*Depart de la boucle for si exemple des -> 1 3 4 5 6 donc petite suite -> 3 4 5 6*/
  int test = 1; /*Permet de savoir si on a testé*/

  for(i=0;i<5;i++) /*On met les des du joueur dans le tableau tab afin de pouvoir trier par ondre croissant les des*/
    tab[i] = j->des[i];

  tri_bulle(tab,5);

  n1 = tab[0]; /*n1 prend la valeur du premier de*/

  if(tab[1] == n1 + 1){ /*Si petite suite au debut du tableau*/
    dep = 1; /*On commence donc les tests a partir du 2e de*/
  }

  else{ /*Si premiere valeur du tableau tab n est pas comprise dans la petite suite*/
    n1 = tab[1]; /*n1 prend la valeur du 2e de pour tester la suite*/
    dep = 2; /*On commence donc les tests a partir du 2e des*/
  }

  for(i = dep;i<5 && test < 4;i++){ /*Test des des a partir du pt de depart précedemment calculé*/
    if(tab[i] == (n1+1)){ /*Si val du de precedent = val du de actuel*/
      n1 = tab[i]; /*De precedent = de actuel*/
      test++;/*Incrementation du nombre de test nécessaire afin de valider la petite suite si celle ci au debut du tab ->
      ex : 1 2 3 4 6 si pas de test alors le programme ne valide pas la petite suite car 4 et 6 ne se suivent pas*/
    }
    else  /*Si pas de petite suite*/
      return -1;
  }

  return 30; /*Retourne le resultat*/

}

/**
	*\fn int grandesuite(t_joueur *j)
	*\param Un pointeur vers un joueur
  *\return Le nombre de points ou -1 si pas de grandesuite
	*\brief Total des 5 des : 5 dés se suivent
  *\Author : LEMARCHAND Thibault
*/

int grandesuite(t_joueur *j) {
	int n1 = -1; /*Prend la valeur du dé*/
	int i;
  int tab[5]; /*Tableau de dé*/

  for(i=0;i<5;i++) /*On met les des du joueur dans le tableau tab afin de pouvoir trier par ondre croissant les des*/
    tab[i] = j->des[i];

  tri_bulle(tab,5);

  n1 = tab[0]; /*n1 prend la valeur du premier de*/


  for(i = 1;i<5;i++){ /*Test des des a partir du pt de depart précedemment calculé*/
    if(tab[i] == (n1+1)){ /*Si val du de precedent = val du de actuel*/
      n1 = tab[i]; /*De precedent = de actuel*/
    }
    else  /*Si pas de grande suite*/
      return -1;
  }

  return 40; /*Retourne le resultat*/

}

/**
	*\fn int yahtzee(t_joueur *j)
	*\param Un pointeur vers un joueur
  *\return Le nombre de points ou -1 si pas de yahtzee
	*\brief Total des 5 des : 5 dés egaux
  *\Author : BROUARD Antoine
*/

int yahtzee(t_joueur *joueur){
  if(joueur->des[0] == joueur->des[1] && joueur->des[1] == joueur->des[2] && joueur->des[2] == joueur->des[3] && joueur->des[3] == joueur->des[4])
    return 50;
  else
    return -1;
}
