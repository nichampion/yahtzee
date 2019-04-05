#include <stdio.h>
#include <stdlib.h>

#include "../../src/commun.h"
#include "../../src/mains.h"
#include "../../src/fonctions_joueur.h"


int main(){
	t_joueur *j1 = malloc(sizeof(t_joueur));
	int tab[5]={4,4,2,4,3};
	int test;
  int somme = 0;

  for(int i = 0;i<5;i++){
		j1->des[i] = tab[i];
    somme += j1->des[i];
  }

	test = chance(j1);
	if(test == somme)
		printf("Resultat : %d\n",test);
	else
		printf("Fonction chance Incorrecte \n");

}
