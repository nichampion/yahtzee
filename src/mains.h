#ifndef mains_h
#define mains_h

void tri_bulle(int tab[],int taille);
int section_superieur(t_joueur *joueur, int nb_test);
int chance(t_joueur * joueur);
int brelan(t_joueur *j);
int carre(t_joueur *j);
int full(t_joueur *j);
int petite_suite(t_joueur *j);
int grande_suite(t_joueur *j);
int yathzee(t_joueur *joueur);

#endif
