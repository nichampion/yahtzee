#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "../../src/commun.h"
#include "affichage_V1.h"
#include "../../src/fonctions_jeu.h"
#include "../../src/fonctions_joueur.h"
#include "../../src/mains.h"


int main(){
  t_joueur *j1;
  j1 = creer_joueur("Joueur");
  t_joueur *jtest;
  jtest = creer_joueur("Test");
  int i;
  int placement = 0;

  for(i=0;i<N;i++){
    lancer(j1,i);
  }

  test_mains(j1,jtest);
  placement = choix_placement(j1,jtest);
  while(placement != 1)
    placement = choix_placement(j1,jtest);

  affichage(j1,j1,j1);


  printf("\nSi -1 dans toutes les cases lors de l'affichage de la grille alors la fonction placement est incorrecte\n");
}
