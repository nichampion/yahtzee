#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "commun.h"
#include "affichage.h"
#include "fonctions_joueur.h"
#include "ordinateur.h"


/**
	*\file main.c
	*\brief
	*\version 1.0
*/
void lancer(t_joueur * j, int i){

	srand(time(NULL));
	j->des[i] = rand()%(7-1) + 1;

}

int relancer(t_joueur * j){

	int i, relance, rep;		

	printf("Voulez vous relancer ? (0 : Non, 1 : Oui) ");
	scanf("%d",&rep);

	if(rep == 1){
		for(i = 0; i < 5; i++){
			printf("Voulez vous relancer le dé n°%d ? (0 : Non, 1 : Oui) ", i+1);
			scanf("%d", &relance);
				
			if(relance == 1){
				lancer(j,i);
			}
		}
		return 1;
	}

	return 0;
}

int main(int argc, char **argv) {
	t_joueur * j1;
	int game_over = 0, i, rep;

	while(game_over == 0){
		for(i = 0; i < 5; i++){
			lancer(j1,i);
		}
		
		rep = relancer(j1);
		if(rep == 1){
			rep = relancer(j1);
		}
	}
				

}
