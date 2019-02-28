#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "commun.h"
#include "affichage.h"
#include "fonctions_joueur.h"
#include "ordinateur.h"
#include "lancer.h"


/**
	*\file main.c
	*\brief
	*\version 1.0
*/

int main(int argc, char **argv) {
	t_joueur *j1, *j2;
	j1 = creer_joueur("Dom");
	j2 = creer_joueur("Guy");
	int game_over = 0, i, rep;

	affichage(j1,j2,j1);
/*
	while(game_over == 0){
		for(i = 0; i < 5; i++){
			lancer(j1,i);
		}

		rep = relancer(j1);
		if(rep == 1){
			rep = relancer(j1);
		}
	}*/

	return 0;
}
