#include <stdio.h>
#include <stdlib.h>

#define VRAI 1
#define FAUX 0
#include "commun.h"
#include "mains.h"

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
