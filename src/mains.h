#ifndef mains_h
#define mains_h

  	/* Section supérieure */
  int section_superieure(t_joueur *joueur, int nb_test);

  /* Section inférieure */
  int chance(t_joueur * joueur);
  int brelan(t_joueur *j);
  int carre(t_joueur *j);
  int full(t_joueur *j);
  int petite_suite(t_joueur *j);
  int grande_suite(t_joueur *j);
  int yahtzee(t_joueur *joueur);

#endif
