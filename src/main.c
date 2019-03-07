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
	t_joueur *j1, *j2;
	j1 = creer_joueur("J1");
	j2 = creer_joueur("J2");
	int game_over = 0, i, rep;

	//while(game_over == 0){
		for(i = 0; i < 5; i++){
			lancer(j1,i);
		}

		affichage(j1,j2,j1);

		if((rep = relancer(j1)) == 1){
			affichage(j1,j2,j1);
			if((rep = relancer(j1)) == 1)
				affichage(j1,j2,j1);
		}

	//}

	return 0;
}
