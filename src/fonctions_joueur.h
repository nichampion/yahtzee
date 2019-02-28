#ifndef fonctions_joueur_h
#define fonctions_joueur_h

t_joueur* cree_joueur(char nom[T]);
void detruire_joueur(t_joueur **j);
void calcul_totaux(t_joueur *j);

#endif
