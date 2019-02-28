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
        if((t_joueur->des[i] == t_joueur->des[j] == t_joueur->des[k]) && (i != j) && (i!= k) && (j!= k))
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
          if((t_joueur->des[i] == t_joueur->des[j] == t_joueur->des[k] == t_joueur->des[l]) && (i!=j) && (i!=k) && (i!=l) (j!=k) && (j!=l) && (k!=l))
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
            if((t_joueur->des[i] == t_joueur->des[j] == t_joueur->des[k] != t_joueur->des[l] == t_joueur->des[m]) && (i!=j) && (i!=k) && (i!=l) && (i!=m) && (j!=k) && (j!=l) && (j!=m) && (k!=l) && (k!=m) && (l!=m))
              return VRAI;
          }
        }
      }
    }
  }
  return FAUX;
}

int petite_suite(t_joueur *joueur){
  if((t_joueur->des[1] == t_joueur->des[0]+1 && t_joueur->des[2] == t_joueur->des[1]+1 && t_joueur->des[3] == t_joueur->des[2]+1) && ((t_joueur->des[2] == t_joueur->des[1]+1 && t_joueur->des[3] == t_joueur->des[4]+1 && t_joueur->des[3] == t_joueur->des[2]+1))
    return VRAI;
  return FAUX;
}

int grande_suite(t_joueur *joueur){
  if(t_joueur->des[1] == t_joueur->des[0]+1 && t_joueur->des[2] == t_joueur->des[1]+1 && t_joueur->des[3] == t_joueur->des[2]+1 && t_joueur->des[4] == t_joueur->des[3]+1)
    return VRAI;
  return FAUX;
}

int yathzee(t_joueur *joueur){
  if(t_joueur->des[0] == t_joueur->des[1] == t_joueur->des[2] == t_joueur->des[3] == t_joueur->des[4])
    return VRAI;
  else
    return FAUX;
}
