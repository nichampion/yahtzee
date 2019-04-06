#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "../../src/commun.h"
#include "../../src/fonctions_jeu.h"
#include "../../src/fonctions_joueur.h"
#include "../../src/mains.h"

int main(){
  t_joueur *j1 = malloc(sizeof(t_joueur));
  int des[N];
  int i;
  int test = 0;

  for(i=0;i<N;i++){
    lancer(j1,i);
    des[i] = j1->des[i];
  }

  relancer(j1);
  for(i = 0;i<N;i++){
    if(j1->des[i] == des[i])
      test = 1;
    else{
      printf("Fonction relancer opérationnelle\n");
      return 0;
    }
  }

  if(test == 1)
    printf("Fonction relancer incorrecte \n");
}
