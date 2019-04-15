#ifndef fonctions_jeu_h
#define fonctions_jeu_h

  #define TAILLE_TAB_PF 8

  void lancer(t_joueur * j, int i);
  int relancer(t_joueur * j);
  t_joueur * test_mains(t_joueur *j, t_joueur * j_test);
  int fin_de_partie(t_joueur * j);

#endif
