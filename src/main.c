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

int main(int argc, char **argv) {
	srand(time(NULL));
	t_joueur *j1, *j2, *j_choix;
	j1 = creer_joueur("J1");
	j2 = creer_joueur("J2");
	j_choix = creer_joueur("Choix");
	int game_over = 0, i, rel, placement;

	affichage(j1,j2,j1);
	while(game_over == 0){
		rel = 0;
		for(i = 0; i < 5; i++){
			lancer(j1,i);
		}

		j_choix = test_mains(j1);

		if((rel = relancer(j1)) == 1)
		{

			j_choix = test_mains(j1);
			if((rel += relancer(j1)) == 2)
				j_choix = test_mains(j1);

		}

		placement = choix_placement(j1,j_choix);
		while(placement != 1)
			placement = choix_placement(j1,j_choix);
		
		affichage(j1,j2,j1);

		game_over = fin_de_partie(j1);

	}

	return 0;
}
