#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "commun.h"
#include "affichage.h"
#include "fonctions_joueur.h"
#include "ordinateur.h"
#include "fonctions_jeu.h"


/**
	*\file main.c
	*\Main du jeu
	*\version 1.0
	*\Author : Sunny BIARD
*/
void tour_joueur(t_joueur * j){
	int rel = 0, placement, i;

	t_joueur * j_choix;

	j_choix = creer_joueur("Choix");

	for(i = 0; i < 5; i++){
		lancer(j,i);
	}

	j_choix = test_mains(j);

	if((rel = relancer(j)) == 1)
	{

		j_choix = test_mains(j);
		if((rel += relancer(j)) == 2)
			j_choix = test_mains(j);

	}

	placement = choix_placement(j,j_choix);
	while(placement != 1)
		placement = choix_placement(j,j_choix);
}

int main(int argc, char **argv) {
	srand(time(NULL));

	t_joueur * j1, * j2;

	j1 = creer_joueur("J1");
	j2 = creer_joueur("J2");

	int game_over = 0;

	while(game_over == 0){

		tour_joueur(j1);
		affichage(j1,j2,j1);
		sleep(5);
		tour_joueur(j2);
		affichage(j1,j2,j1);
		sleep(5);

		if(fin_de_partie(j1) && fin_de_partie(j2))
			game_over = 1;

	}
	affichage(j1,j2,j1);

	return 0;
}
