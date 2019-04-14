#include "affichage.h"
#include <stdio.h>

/**
	*\fn int main()
	*\brief Programme principal
  *\author Nicolas Champion
*/
int main() {
  printf("* * * * * * * * * * * * * *\n");
  printf("* * * * * Yahtzee * * * * *\n");
  printf("* * * * * * * * * * * * * *\n\n\n");

  /* Affichage du menu */
  printf("\t___________\n");
  char choix[50];
  do {
    printf("1 - Jouer contre l'ordinateur\n");
    printf("2 - 2 joueurs\n");
    printf("3 - Credits\n");
    printf("4 - Quitter\n");
    printf("\tChoix : ");
    scanf("%s", choix);
  } while((choix[0] < '1') || (choix[0] > '4'));
  printf("\t___________\n\n");

  /* Choix menu */
  srand(time(NULL));
  switch (choix[0]) {
    case '1': aff1_joueur(); break;
    case '2': aff2_joueurs(); break;
    case '3':
              printf("-> Biard Sunny\n");
              printf("-> Brouard Antoine\n");
              printf("-> Champion Nicolas\n");
              printf("-> Lemarchand Thibault\n");
              printf("\n");
              printf("Projet L2 Informatique\n");
              printf("Le Mans - 2019\n");
              printf("\n");
              break;
    case '4': printf("Au revoir\n\n"); break;
  }

  return 0;
}
