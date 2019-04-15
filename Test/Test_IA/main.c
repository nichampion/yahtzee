#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "../../src/commun.h"
#include "affichage_V1_Test_IA.h"
#include "../../src/ordinateur.h"
#include "../../src/fonctions_joueur.h"
#include "../../src/fonctions_jeu.h"


/**
	*\File : main.c
	*\Brief : Main du jeu
	*\version 1.0
	*\Author : Sunny BIARD
*/


int main(int argc, char **argv) {
	int i, j, nb_test, game_over;
	FILE *fichier = NULL;
	t_joueur *jo = creer_joueur("PC");

	srand(time(NULL));

	printf("\nProgramme de test permettant de vérifier le bon fonctionnement de la stratégie de l'ordinateur\n");
	printf("Entrer le nombre de test à effectuer : ");
	scanf("%d", &nb_test);

	for(i = 0; i < nb_test; i++) {
		/* Initialisation */
			/*Initialisation de la feuille de marque*/
		init_bloc_note(jo);

			/*Initialisation du tableau de dés*/
	  for(j = 0; j < N; j++)
	    jo->des[j] = 0;

		game_over = 0;

		while(game_over == 0){

			tour_ordinateur(jo);
			affichage(jo,jo,jo);

			if(fin_de_partie(jo))
				game_over = 1;
		}

		fichier = fopen("res_prog.csv", "a");
		fprintf(fichier, "%d;%d;\n", jo->tab[TOTAL_GEN], i);
		fclose(fichier);
	}

	return 0;
}
