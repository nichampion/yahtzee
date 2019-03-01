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
*/
int somme_des(t_joueur *j) {


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

/* chaque fonction parcours le tableau dé et renvoie vrai si le joueur a un de ces cas */

int brelan(t_joueur *joueur){
  int i,j,k;
  for(i = 0; i<=4; i++){
    for(j = 0; j<=4; j++){
      for(k = 0; k<=4; k++){
        if((joueur->des[i] == joueur->des[j] && joueur->des[j]  == joueur->des[k]) && ((i != j) && (i!= k) && (j!= k)))
          return VRAI;
      }
    }
  }
  return FAUX;
}
/**
	*\fn brelan_V2(t_joueur *j)
	*\param Un pointeur vers un joueur
	*\return Le nombre de points ou -1 si ce n'est pas un brelan
	*\brief Total des 5 des : 3 chiffres X + 2 derniers resultats des dés obligatoirement différents
*/
int brelan_V2(t_joueur *j) {
	int n1 = -1;
	int nb_n1 = 0; /* Occurence de n1 et n2 */
	int i;
  int res;

	n1 = j->des[0];
	nb_n1++;

	for(i = 1; i < N; i++) {

		if(j->des[i] == n1)
			nb_n1++;

		else
			res += j->des[i];

	}
  res = res + (n1 * 3);

	if(nb_n1 == 3)
		return res; /* Retourne le nombre de point que rapporte un brelan */

	else
		return -1; /* Retourne -1 si ce n'est pas un brelan */
}


int carre(t_joueur *joueur){
  int i,j,k,l;
  for(i = 0; i<=4; i++){
    for(j = 0; j<=4; j++){
      for(k = 0; k<=4; k++){
        for(l = 0; l<=4; l++){
          if((joueur->des[i] == joueur->des[j] && joueur->des[j] == joueur->des[k] && joueur->des[k] == joueur->des[l]) && ((i!=j) && (i!=k) && (i!=l) && (j!=k) && (j!=l) && (k!=l)))
            return VRAI;
        }
      }
    }
  }
  return FAUX;
}

/**
	*\fn carre_V2(t_joueur *j)
	*\param Un pointeur vers un joueur
	*\return Le nombre de points ou -1 si ce n'est pas un carre
	*\brief Total des 5 des : 4 chiffres X + 1 resultats des dés obligatoirement différent des 4 autres
*/
int carre_V2(t_joueur *j) {
	int n1 = -1;
	int nb_n1 = 0; /* Occurence de n1 et n2 */
	int i;
  int res;

	n1 = j->des[0];
	nb_n1++;

	for(i = 1; i < N; i++) {

		if(j->des[i] == n1)
			nb_n1++;

		else
			res += j->des[i];

	}
  res = res + (n1 * 4);

	if(nb_n1 == 4)
		return res; /* Retourne le nombre de point que rapporte un brelan */

	else
		return -1; /* Retourne -1 si ce n'est pas un brelan */
}


int full(t_joueur *joueur){
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
}

/**
	*\fn full_V2(t_joueur *j)
	*\param Un pointeur vers un joueur
	*\return Le nombre de points ou -1 si ce n'est pas un full
	*\brief Total des 5 des : 3 chiffres X + 2 y
*/
int full_V2(t_joueur *j) {
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


int petite_suite(t_joueur *joueur){
  if(((joueur->des[1] == joueur->des[0]+1) && (joueur->des[2] == joueur->des[1]+1) && (joueur->des[3] == joueur->des[2]+1)) && ((joueur->des[2] == joueur->des[1]+1) && (joueur->des[3] == joueur->des[4]+1) && (joueur->des[3] == joueur->des[2]+1)))
    return VRAI;
  return FAUX;
}

/**
	*\fn int petitesuite_V2(t_joueur *j)
	*\param Un pointeur vers un joueur
  *\return Le nombre de points ou -1 si pas de petite suite
	*\brief Total des 5 des : 4 dés se suivent + 1 dé ne suivant pas le reste
  *\Author : LEMARCHAND Thibault
*/

int petitesuite_V2(t_joueur *j) {
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

int grande_suite(t_joueur *joueur){
  if((joueur->des[1] == joueur->des[0]+1) && (joueur->des[2] == joueur->des[1]+1) && (joueur->des[3] == joueur->des[2]+1) && (joueur->des[4] == joueur->des[3]+1))
    return VRAI;
  return FAUX;
}

/**
	*\fn int grandesuite_V2(t_joueur *j)
	*\param Un pointeur vers un joueur
  *\return Le nombre de points ou -1 si pas de grandesuite
	*\brief Total des 5 des : 5 dés se suivent
  *\Author : LEMARCHAND Thibault
*/

int grandesuite_V2(t_joueur *j) {
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

int yahtzee(t_joueur *joueur){
  if(joueur->des[0] == joueur->des[1] && joueur->des[1] == joueur->des[2] && joueur->des[2] == joueur->des[3] && joueur->des[3] == joueur->des[4])
    return VRAI;
  else
    return FAUX;
}

/**
	*\fn int yahtzee_V2(t_joueur *j)
	*\param Un pointeur vers un joueur
  *\return Le nombre de points ou -1 si pas de yahtzee
	*\brief Total des 5 des : 5 dés egaux
*/
int yahtzee_V2(t_joueur *j) {
	int n1 = -1; /*Prend la valeur du dé*/
  int nb_n1 = 0;
	int i;

  n1 = j->des[0]; /*n1 prend la valeur du premier de*/
  nb_n1++;

  for(i = 1;i<5;i++){ /*Test des des*/
    if(j->des[i] == n1){ /*Si val du de precedent = val du de actuel*/
        nb_n1++;
    }
    else  /*Si pas de yahtzee*/
      return -1;
  }
    return 50; /*Retourne le resultat*/


}
