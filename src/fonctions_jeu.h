#ifndef lancer_h
#define lancer_h

/**
	*\file lancer.h
	*\Prototypes des fonctions de fonctions_jeu.c
	*\version 1.0
	*\Author : Sunny BIARD
*/

void lancer(t_joueur * j, int i);
int relancer(t_joueur * j);
void test_mains(t_joueur *j);
void affichage_possibilites(t_joueur * j, t_joueur * j_test);
#endif
