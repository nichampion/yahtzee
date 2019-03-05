#ifndef fonctions_joueur_h
#define fonctions_joueur_h

#define VAL_INIT -1

void init_bloc_note(t_joueur *j);
t_joueur* creer_joueur(char nom[T]);
void detruire_joueur(t_joueur **j);
void prime_tab(t_joueur *j);
void calcul_totaux(t_joueur *j);

#endif
