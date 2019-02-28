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

int petite_suite(t_joueur *joueur){
  if(((joueur->des[1] == joueur->des[0]+1) && (joueur->des[2] == joueur->des[1]+1) && (joueur->des[3] == joueur->des[2]+1)) && ((joueur->des[2] == joueur->des[1]+1) && (joueur->des[3] == joueur->des[4]+1) && (joueur->des[3] == joueur->des[2]+1)))
    return VRAI;
  return FAUX;
}

int grande_suite(t_joueur *joueur){
  if((joueur->des[1] == joueur->des[0]+1) && (joueur->des[2] == joueur->des[1]+1) && (joueur->des[3] == joueur->des[2]+1) && (joueur->des[4] == joueur->des[3]+1))
    return VRAI;
  return FAUX;
}

int yahtzee(t_joueur *joueur){
  if(joueur->des[0] == joueur->des[1] && joueur->des[1] == joueur->des[2] && joueur->des[2] == joueur->des[3] && joueur->des[3] == joueur->des[4])
    return VRAI;
  else
    return FAUX;
}
