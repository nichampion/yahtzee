#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "aff_poss_test_mains.h"
#include "../../src/commun.h"
#include "../../src/fonctions_jeu.h"
#include "../../src/fonctions_joueur.h"
#include "../../src/mains.h"

int main(){
  t_joueur *j1;
  j1 = creer_joueur("Joueur");
  t_joueur *jtest;
  jtest = creer_joueur("Test");
  int i;

  for(i=0;i<N;i++){
    lancer(j1,i);
  }

  test_mains(j1,jtest);

  affichage_possibilites(j1,jtest);
  
  printf("\nSi aucune possibilités, alors fonction test_mains incorrecte\n");
}
