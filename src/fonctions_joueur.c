#include <stdio.h>
#include <stdlib.h>

#include "commun.h"
#include "fonctions_joueur.h"

/**
	*\file fonctions_joueur.c
	*\brief
	*\version 1.0
*/


/*void calcul_manche(t_joueur *j){

}*/


void calcul_totaux(t_joueur *j){
  tot_ssup_avprime = 0;
  tot_ssup_apprime = 0;
  tot_sinf = 0;

  tot_ssup_avprime = (j->tab.as)+(j->tab.deux)+(j->tab.trois)+(j->tab.quatres)+
                     (j->tab.cinq)+(j->tab.six);

  if(tot_ssup_avprime >= 63)
    j->tab.prime_35pts = 35;

  tot_ssup_apprime = tot_ssup_avprime + j->tab.prime_35pts;

  tot_sinf = (j->tab.brelan)+(j->tab.carre)+(j->tab.full)+(j->tab.petite_Suite)+
             (j->tab.grande_Suite)+(j->tab.yahtzee)+(j->tab.chance)+(j->tab.prime_Yahtzee);

  j->tab.total_Gen = tot_ssup_apprime+tot_sinf;

  printf("%d",j->tab.total_Gen);
}
