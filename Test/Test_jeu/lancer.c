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
    int i;

    for(i = 0;i<N;i++){
          j1->des[i] = 0;
    }

    for(i = 0;i<N;i++){
        lancer(j1,i);

    }

    for(i = 0;i<N;i++){
        if((j1->des[i] < 1)||(j1->des[i] > 6)){
          printf("Fonction lancer incorrecte\n");
          return 0;
        }
    }

    if(i == N)
      printf("Fonction lancer correcte \n");

}
