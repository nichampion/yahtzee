#include <stdio.h>
#include <stdlib.h>

#include "../../src/commun.h"
#include "../../src/mains.h"
#include "../../src/fonctions_joueur.h"


int main(){
	t_joueur *j1 = malloc(sizeof(t_joueur));
	int tab[5]={4,4,4,4,3};
  int nb_test = 0;
	int test;

  while(nb_test<1 || nb_test>6){
    printf("Saisir le nombre a tester : ");
    scanf("%d",&nb_test);
    if(nb_test < 1 || nb_test>6)
      printf("Nombre incorrect\n");
  }
  for(int i = 0;i<5;i++)
		j1->des[i] = tab[i];

	test = section_superieure(j1,nb_test);
	if(test != -1)
		printf("Resultat : %d\n",test);
	else
		printf("Pas de nombre %d dans la main du joueur \n", nb_test);

}
