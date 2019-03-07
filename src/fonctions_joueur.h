#ifndef fonctions_joueur_h
#define fonctions_joueur_h

  #define VAL_INIT -1

  /* Fonctions gérant les t_joueurs */
  void init_bloc_note(t_joueur *j);
  t_joueur* creer_joueur(char nom[T]);
  void detruire_joueur(t_joueur **j);

  /* Fonctions gérant les feuilles de marque pour un t_joueurs */
  void prime_tab(t_joueur *j);
  void prime_yahtzee(t_joueur *j)
  void calcul_totaux(t_joueur *j);

#endif
