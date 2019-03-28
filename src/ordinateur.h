#ifndef fonctions_regles_h
#define fonctions_regles_h

  #include <string.h>

  int strat_superieur(t_joueur *j, t_joueur *j_test, int nb_lance_Restant);

  int stra_p_g_suite(t_joueur *j, t_joueur *j_test, int nb_lance_Restant);

  int utiliser_yahtzee(t_joueur *j, t_joueur *j_test);
  int strat_yahtzee(t_joueur *j, t_joueur *j_test, int nb_lance_Restant);

  int strat_brelan(t_joueur *j, t_joueur *j_test, int nb_lance_Restant);

  int strat_carre(t_joueur *j, t_joueur *j_test, int nb_lance_Restant);

  int strat_full(t_joueur *j, t_joueur *j_test, int nb_lance_Restant);

	int tour_ordinateur(t_joueur *j);

#endif
