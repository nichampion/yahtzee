#ifndef fonctions_jeu_h
#define fonctions_jeu_h

/**
	*\file lancer.h
	*\Prototypes des fonctions de fonctions_jeu.c
	*\version 1.0
	*\Author : Sunny BIARD
*/

void lancer(t_joueur * j, int i);
int relancer(t_joueur * j);
t_joueur * test_mains(t_joueur *j);
int choix_placement(t_joueur *j, t_joueur * j_test);
void affichage_possibilites(t_joueur * j, t_joueur * j_test);
int fin_de_partie(t_joueur * j);
#endif
