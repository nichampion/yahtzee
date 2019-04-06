#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "../../src/commun.h"
#include "../../src/fonctions_jeu.h"
#include "../../src/fonctions_joueur.h"
#include "../../src/mains.h"

int main(){
  t_joueur *j1;
  j1 = creer_joueur("Joueur");
  int i;
  int somme = 0;

  j1->tab[AS] = 4;
  j1->tab[DEUX] = 4;
  j1->tab[TROIS] = 6;
  j1->tab[QUATRE] = 16;
  j1->tab[CINQ] = 10;
  j1->tab[SIX] = 18;

  for (i=AS;i<=SIX;i++){
    somme+=j1->tab[i];
  }

  prime_tab(j1);
  printf("somme = %d\n",somme);

  if(j1->tab[PRIME_35] == 35 && somme < 63)
    printf("Fonction prime_tab incorrecte\n");

  else
    printf("Fonction prime_tab correcte\n");

}
