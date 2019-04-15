#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "commun.h"
#include "ordinateur.h"
#include "mains.h"
#include "fonctions_joueur.h"
#include "fonctions_jeu.h"

/**
	*\file ordinateur.c
	*\brief Fonctions permettant d'appliquer une stratégie
	*\version 2.0
*/

/* Sources d'inspirations pour la stratégie */
/* Lien stratégie 1 -> http://www.ultraboardgames.com/yahtzee/tips.php */
/* Lien stratégie 2 -> https://fr.wikihow.com/jouer-au-yahtzee */


/**
	*\fn int compter_des(t_joueur *joueur, int nb_test)
	*\param Un pointeur vers un t_joueur (représentant le joueur) et la valeur de dès à compter
  *\brief Sous fonction. Intervient dans plusieurs fonctions.
  *\return Le nombre de des nb_test(valeur) qu'il y a dans la main du joueur.
	*\author Nicolas Champion
*/
static
int compter_des(t_joueur *joueur, int nb_test){
  int i, res = 0;

  for(i = 0; i < N; i++){
    if(joueur->des[i] == nb_test)
      res += 1;
  }
  return res;
}


/**
	*\fn int val_des(int ref_des)
	*\param Le nom de la valeur du des
  *\brief Renvoie la valeur d'un AS, DEUX, ...
  *\return Une valeur numerique
	*\author Nicolas Champion
*/
static
int val_des(int ref_des) {
  return ref_des + 1;
}


/* ****************** Calcul de la meilleur main ****************** */


/**
	*\fn void test_max(int *val_c, int *val_max, int *pos_max, int pos_courante)
	*\param Pointeur sur la valeur courante et la valeur max, la postion sur la feuille de marque du des max et du des courant
  *\brief Sous fonction. Intervient dans la fonction meilleur_score
  *\brief Permet de choisir la ligne à jouer dans la feuille de marque.
	*\author Nicolas Champion
*/
static
void test_max(int *val_c, int *val_max, int *pos_max, int pos_courante) {
  if(*val_c > *val_max) {
    *val_max = *val_c;
    *pos_max = pos_courante;
  }
}


/**
  *\fn void meilleur_score(t_joueur *j, t_joueur *j_test)
  *\brief Choisi la main qui rapporte le plus de points pour une combinaison de des donnée.
  *\brief stratégie par défaut
  *\param Un pointeur vers le joueur courant et vers un joueur temporaire permettant d'effectuer les tests
	*\author Nicolas Champion
*/
void meilleur_score(t_joueur *j, t_joueur *j_test) {
  int val_max = VAL_INIT - 1; /* Doit etre inférieure a VAL_INIT */
  int pos_max = -1;
  int i;

  /* Parcourir feuille de marque de j_test */
    /* Parcours section supérieur */
  for(i = AS; i <= SIX; i++) {
    if(j->tab[i] == VAL_INIT)
      test_max(&(j_test->tab[i]), &val_max, &pos_max, i);
  }

    /* Parcours section inférieur */
  for(i = BRELAN; i <= CHANCE; i++) {
    if(j->tab[i] == VAL_INIT)
      test_max(&(j_test->tab[i]), &val_max, &pos_max, i);
  }

  /* Enregistrer dans j le max */
  if(val_max == VAL_INIT)
    val_max = 0;
  j->tab[pos_max] = val_max;
}


/* ****************** Obtention du bonus supérieurs ****************** */


/**
  *\fn void val_des_max(int val_c, int *val_max, int nb_des_c, int *nb_des_max)
  *\brief Strategie permettant d'obtenir le maximum de points dans la section superieur de la feuille de marque
  *\brief Il faut avoir compter les des de la main avant !!
  *\param La valeur courante du des, un pointeur vers la valeur max, le nombre de des courant et un pointeur vers le nombre de des avec la valeur max.
	*\author Nicolas Champion
*/
static
void val_des_max(int val_c, int *val_max, int nb_des_c, int *nb_des_max) {
  if(nb_des_c >= *nb_des_max) {
    *val_max = val_c;
    *nb_des_max = nb_des_c;
  }
}


/**
  *\fn int choix_des_strat_sup(int tab[6], t_joueur *j)
  *\param Un tableau indiquant le nombre d'exemplaire de chaque des en fonction de leur valeur
  *\brief Il faut avoir compter les des de la main avant !!
  *\brief Retourne la val des dès les plus elevee en plus grand nombre et disponible (Valeur non jouée dans la feuille de marque)
	*\author Nicolas Champion
*/
static
int choix_des_strat_sup(int tab[6], t_joueur *j) {
  int val_max = 0, nb_des_max = 0;
  int i;

  for(i = AS; i <= SIX; i++) {
    if(j->tab[i] == VAL_INIT)
      val_des_max(val_des(i), &val_max, tab[i], &nb_des_max);
  }

  return val_max;
}


/**
  *\fn int strat_superieur(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant)
  *\param Un pointeur vers le joeur courant et vers un joueur temporaire permettant d'effectuer les tests et le nombre de relancer restants
  *\return Renvoie un booleen indiquant si la strategiee a pu etre appliqué.
  *\brief Essaye d'appliquer la stratégie consisitant a obtenir la prime dans la section superieure (de la feuille de marque Yahtzee)
	*\author Nicolas Champion
*/
int strat_superieur(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant) {
  int i;
  int nb_des[6];

  /* Verif si cette strat est applicable */
    /* Si tab sup est entierement plein => impossible */
  if((j->tab[AS] != VAL_INIT) && (j->tab[DEUX] != VAL_INIT) && (j->tab[TROIS] != VAL_INIT) && (j->tab[QUATRE] != VAL_INIT) && (j->tab[CINQ] != VAL_INIT) && (j->tab[SIX]!= VAL_INIT)) {
    return 0;
  }

  /* Compter les des */
  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

  /* Choisir des (plus eleve, en plus gd nombre et dispo (non joue)) */
  int val_des_a_garder = choix_des_strat_sup(nb_des, j);

  /* Cela vaut-il le coup d'appliquer cette strat */
  if(nb_des[val_des_a_garder - 1] < 1)
    return 0;

  /* Relancer les des pour obtenir le plus de des de cette valeur */
  /* 2 fois et tant que tous les des ne sont = a des_a_garder */
  for(; *nb_lance_Restant > 0; (*nb_lance_Restant)--) {
    for(i = 0; i < 5; i++) {
      if(j->des[i] != val_des_a_garder)
        lancer(j, i);
    }
    test_mains(j, j_test); /* Permet l'affichage */

		/* Test : Si jamais on obtient un yahtzee */
		if((j->tab[YAHTZEE] == VAL_INIT) && (yahtzee(j) != -1)) {
			utiliser_yahtzee(j, j_test);
			return 2; // L'ordi a joue (mais pas la strat sup)
		}
  }

  /* Est-il pertinent d'appliquer cette stratégie ? */
  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

  if(nb_des[val_des_a_garder - 1] < 3) /* Cas : pas assez de des identiques pour obtenir le bonus superieur */
    return 0;

  /* On applique cette stratégie */
  test_mains(j, j_test);
  for(i = AS; i <= SIX; i++) {
    if(val_des_a_garder == val_des(i)) {
      j->tab[i] = j_test->tab[i]; /* Enregistrement du score */
      return 1; /* Fin de la strategie */
    }
  }

  return 0;

}


/* ****************** Obtention des suites (Petite et grande) ****************** */


/**
  *\fn int val_dans_tab(int val, int tab[], int taille)
  *\param Une valeur, un tableau et la taille du tableau
  *\brief Indique si la variable val est dans le tablau de taille 'taille'
  *\return Renvoie un booleen
	*\author Nicolas Champion
*/
static
int val_dans_tab(int val, int tab[], int taille) {
  int i;

  for(i = 0; i < taille; i++) {
    if(tab[i] == val)
      return 1; /* La valeur est dans le tableau */
  }

  return 0; /* La valeur n'est pas dans le tableau */
}


/**
  *\fn int strat_p_g_suite(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant)
  *\param Un pointeur vers le joueur courant et vers un joueur temporaire permettant d'effectuer les tests, le nombre de relance disponible
  *\return Renvoie un booleen indiquant si la stratgie a pu etre appliqué
  *\brief Strategie permettant d'essayer d'obtenir les petite et grande suites (si possible)
	*\author Nicolas Champion
  *\author Thibault Lemarchand
*/
int strat_p_g_suite(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant) {
  int i;
  int nb_des[6];

  /* Verif si cette strat est applicable */
  if(j->tab[PETITE_SUITE] != VAL_INIT || j->tab[GRANDE_SUITE] != VAL_INIT)
    return 0;

  /* Compter les des */
  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

  /* Analyse de la main => On surveille les sequences suivantes */
  int val_des_a_garder[3]; // Tableau enregistrant les valeurs des dès à garder

    /* Seq 2-3-4 */
  if((nb_des[1] != 0) && (nb_des[2] != 0) && (nb_des[3] != 0)) {
    val_des_a_garder[0] = 2;
    val_des_a_garder[1] = 3;
    val_des_a_garder[2] = 4;
  }

    /* Seq 3-4-5 */
  else if((nb_des[2] != 0) && (nb_des[3] != 0) && (nb_des[4] != 0)) {
    val_des_a_garder[0] = 3;
    val_des_a_garder[1] = 4;
    val_des_a_garder[2] = 5;
  }

    /* Seq 1-2-3 */
  else if((nb_des[0] != 0) && (nb_des[1] != 0) && (nb_des[2] != 0)) {
    val_des_a_garder[0] = 1;
    val_des_a_garder[1] = 2;
    val_des_a_garder[2] = 3;
  }

    /* Seq 4-5-6 */
  else if((nb_des[3] != 0) && (nb_des[4] != 0) && (nb_des[5] != 0)) {
    val_des_a_garder[0] = 4;
    val_des_a_garder[1] = 5;
    val_des_a_garder[2] = 6;
  }

    /* Seq 1-2-4 */
  else if((nb_des[0] != 0) && (nb_des[1] != 0) && (nb_des[3] != 0)) {
    val_des_a_garder[0] = 1;
    val_des_a_garder[1] = 2;
    val_des_a_garder[2] = 4;
  }

    /* Seq 1-3-4 */
  else if((nb_des[0] != 0) && (nb_des[2] != 0) && (nb_des[3] != 0)) {
    val_des_a_garder[0] = 1;
    val_des_a_garder[1] = 3;
    val_des_a_garder[2] = 4;
  }

    /* Seq 2-4-5 */
  else if((nb_des[1] != 0) && (nb_des[3] != 0) && (nb_des[4] != 0)) {
    val_des_a_garder[0] = 2;
    val_des_a_garder[1] = 4;
    val_des_a_garder[2] = 5;
  }

    /* Seq 3-5-6 */
  else if((nb_des[2] != 0) && (nb_des[4] != 0) && (nb_des[5] != 0)) {
    val_des_a_garder[0] = 3;
    val_des_a_garder[1] = 5;
    val_des_a_garder[2] = 6;
  }

    /* Les autres cas seront geres par les autres fonction */
  else
    return 0; /* Si aucune sequence reperes => Sortir de cette fonction */

  /* Relancement */
  int exit_code = 0;
  for(; (*nb_lance_Restant > 0); (*nb_lance_Restant)--) {
    for(i = 0; i < 5; i++) {

      /* Cas ou il ne faut pas relancer => des a garder ET 1 exemplaire */

      if(! (val_dans_tab(j->des[i], val_des_a_garder, 3) && (nb_des[j->des[i] - 1] == 1))) {

        if(nb_des[j->des[i] - 1] > 1)
          nb_des[j->des[i] - 1]--; /* Permet de ne pas selectionner le dernier exemplaire du des a garder */

        /* Relancement */
        lancer(j, i);
      }

    }

    /* Compter les des */
    for(i = 0; i < 6; i++)
      nb_des[i] = compter_des(j, i + 1);

    test_mains(j, j_test); /* Permet l'affichage */

    /* Si on a Gde ou Pte suite => On utilise */
    if((j_test->tab[GRANDE_SUITE] != VAL_INIT) && (j->tab[GRANDE_SUITE] == VAL_INIT)) {
        exit_code = -1;
        (*nb_lance_Restant) = -1; // Permet de sortir de la boucle
    }
    else if((j_test->tab[PETITE_SUITE] != VAL_INIT) && (j->tab[PETITE_SUITE] == VAL_INIT)) {
        exit_code = -2;
        (*nb_lance_Restant) = -1; // Permet de sortir de la boucle
    }
  }

  /* Cas gde suite */
  if(exit_code == -1) {
    j->tab[GRANDE_SUITE] = j_test->tab[GRANDE_SUITE];
    return 1; /* fin de la stratégie */
  }

  /* Cas pte suite */
  else if(exit_code == -2) {
    j->tab[PETITE_SUITE] = j_test->tab[PETITE_SUITE];
    return 1; /* fin de la stratégie */
  }

  /* Rien obtenu */
  else
    return 0;
}


/* ****************** Obtention Yahtzee (Avec sacrifice si besoin) ****************** */


/**
  *\fn int val_qte_max_tab(int tab[], int taille)
  *\param Un tableau de int et sa taille
  *\return La valeur la plus grande et la plus fréquente
  *\brief Renvoi la valeur présente le plus grand nombre de fois dans le tablau.
	*\author Nicolas Champion
*/
static
int val_qte_max_tab(int tab[], int taille) {
	int i, qte_max = 0, val_qte_max;

	for(i = 0; i < taille; i++) {
		if(tab[i] > qte_max) {
			qte_max = tab[i];
			val_qte_max = i + 1;
		}
	}

	return val_qte_max;
}


/**
  *\fn int utiliser_yahtzee(t_joueur *j, t_joueur *j_test)
  *\brief On suppose que l'on a une main de type yahtzee (Donc tous les des identiques)
  *\brief Joue de maniere strategique un yahtzee dans la feuille de marque
  *\param Un pointeur vers le joueur courant et vers un joueur temporaire permettant d'effectuer les tests
  *\return Un booleen
	*\author Nicolas Champion
*/
int utiliser_yahtzee(t_joueur *j, t_joueur *j_test) {

	/* Sacrifier */
	if((j->tab[SIX] == VAL_INIT) && (j->des[0] == 6)) {
		j->tab[SIX] = j_test->tab[SIX];
		return 2; /* L'ordi a joué mais pas un yahtzee */
	}
	else if((j->tab[CINQ] == VAL_INIT) && (j->des[0] == 5)) {
		j->tab[CINQ] = j_test->tab[CINQ];
		return 2; /* L'ordi a joué mais pas un yahtzee */
	}
	else if((j->tab[QUATRE] == VAL_INIT) && (j->des[0] == 4)) {
		j->tab[QUATRE] = j_test->tab[QUATRE];
		return 2; /* L'ordi a joué mais pas un yahtzee */
	}

	else {
		j->tab[YAHTZEE] = j_test->tab[YAHTZEE];
		return 1; /* L'ordi joue un yahtzee */
	}

}


/**
  *\fn int strat_yahtzee(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant)
  *\param Un pointeur vers le joueur courant et vers un joueur temporaire permettant d'effectuer les tests et le nombre de relances restantes
  *\brief Permet (d'essayer) d'obtenir une main de type yahtzee en relancant
  *\return Un booleen
	*\author Nicolas Champion
*/
int strat_yahtzee(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant) {
	int i;
  int nb_des[6];

  /* Verif si cette strat est applicable */
  if(j->tab[YAHTZEE] != VAL_INIT)
    return 0; /* On ne peut pas faire plus d'1 yahtzee */

	/* Compter les des */
  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

	/* Choisir des a garder (Val en plus grand nombre) */
	int val_des_a_garder = val_qte_max_tab(nb_des, 6);

  /* Cala vaut-il le coup d'applique cette strategie */
  if(nb_des[val_des_a_garder - 1] < 3) {
      return 0; /* Pas de yahtzee */
  }


	/* Relancer les des pour obtenir le plus de des de cette valeur */
	/* 2 fois et tant que tous les des ne sont = a des_a_garder */
	for(; *nb_lance_Restant > 0; (*nb_lance_Restant)--) {
		for(i = 0; i < 5; i++) {
			if(j->des[i] != val_des_a_garder)
				lancer(j, i);
		}
		test_mains(j, j_test); /* Permet l'affichage */

		/* Test : Si jamais on obtient un yahtzee */
		if(yahtzee(j) != -1) {
			utiliser_yahtzee(j, j_test); /* Jouer le yahtzee */
			return 1;
		}
	}

	return 0; /* Pas de yahtzee */

}


/* ****************** Obtention brelan ****************** */


/**
  *\fn int strat_brelan(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant)
  *\param Un pointeur vers le joueur courant et vers un joueur temporaire permettant d'effectuer les tests et le nombre de relances restantes
  *\return Un booleen
  *\brief Permet (d'essayer) d'obtenir une main de type brelan en relancant
	*\author Thibault Lemarchand
	*\author Nicolas Champion
*/
int strat_brelan(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant) {

	/* Strategie possible */
	if(j->tab[BRELAN] != VAL_INIT)
		return 0; /* Strat non applicable */

	int i;
	int nb_des[6];

	/* Compter les des */
  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

	/* Choisir des a garder (Val en plus grand nombre) */
	int val_des_a_garder = val_qte_max_tab(nb_des, 6);

	/* Relancer les des pour obtenir le plus de des de cette valeur */
	/* 2 fois et tant que tous les des ne sont = a des_a_garder */
	for(; *nb_lance_Restant > 0; (*nb_lance_Restant)--) {

		/* Cas : Mois de 3 des identiques */
		for(i = 0; i < 5; i++) {
			if(j->des[i] != val_des_a_garder)
				lancer(j, i);
		}

		test_mains(j, j_test); /* Permet l'affichage */

		/* Test : Si jamais on obtient un brelan */
		if(brelan(j) != -1) {
			j->tab[BRELAN] = j_test->tab[BRELAN]; /* Jouer le brelan */
			return 1;
		}
	}

	return 0; /* Pas de brelan */

}


/* ****************** Obtention carre ****************** */


/**
  *\fn int strat_carre(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant)
  *\param Un pointeur vers le joueur courant et vers un joueur temporaire permettant d'effectuer les tests et le nombre de relances restantes
  *\return Un booleen
  *\brief Permet (d'essayer) d'obtenir une main de type carre en relancant
	*\author Thibault Lemarchand
	*\author Nicolas Champion
*/
int strat_carre(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant) {

	/* Strategie possible */
	if(j->tab[CARRE] != VAL_INIT)
		return 0; /* Strat non applicable */

	int i;
	int nb_des[6];

	/* Compter les des */
  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

	/* Choisir des a garder (Val en plus grand nombre) */
	int val_des_a_garder = val_qte_max_tab(nb_des, 6);

	/* Relancer les des pour obtenir le plus de des de cette valeur */
	/* 2 fois et tant que tous les des ne sont = a des_a_garder */
	for(; *nb_lance_Restant > 0; (*nb_lance_Restant)--) {

		/* Cas : Moins de 3 des identiques */
		for(i = 0; i < 5; i++) {
			if(j->des[i] != val_des_a_garder)
				lancer(j, i);
		}

		test_mains(j, j_test); /* Permet l'affichage */

		/* Test : Si jamais on obtient un carre */
		if(carre(j) != -1) {
			j->tab[CARRE] = j_test->tab[CARRE]; /* Jouer le carre */
			return 1;
		}
	}

	return 0; /* Pas de carre */

}


/* ****************** Obtention full ****************** */


/**
  *\fn int strat_full(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant)
  *\param Un pointeur vers le joueur courant et vers un joueur temporaire permettant d'effectuer les tests et le nombre de relances restantes
  *\return Un booleen
  *\brief Permet (d'essayer) d'obtenir une main de type full en relancant
	*\author Thibault Lemarchand
	*\author Nicolas Champion
*/
int strat_full(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant) {

	/* Strategie possible */
	if(j->tab[FULL] != VAL_INIT)
		return 0; /* Strat non applicable */

	int i;
	int nb_des[6];

	/* Compter les des */
  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

	/* Choisir des a garder (Val en plus grand nombre) */
	int val_des_a_garder = val_qte_max_tab(nb_des, 6);

	/* Relancer les des pour obtenir le plus de des de cette valeur */
	/* 2 fois et tant que tous les des ne sont = a des_a_garder */
	for(; *nb_lance_Restant > 0; (*nb_lance_Restant)--) {

		/* Cas : 4 des identiques */
		if(nb_des[val_des_a_garder - 1] == 4) {
			for(i = 0; i < 5; i++) {

				/* Sous Cas 1 : 3 des identiques */
				if(j->des[i] == val_des_a_garder) {
					lancer(j, i);
					i = 5; /* Permet de n'en relancer qu'un */
				}
			}
		}

		/* Cas : 3 des identiques => Relancer 1 des pour obtenir une paire */
		else if(nb_des[val_des_a_garder - 1] == 3) {
			for(i = 0; i < 5; i++) {

				/* Sous Cas 1 : 3 des identiques */
				if(j->des[i] != val_des_a_garder) {
					lancer(j, i);
					i = 5; /* Permet de n'en relancer qu'un */
				}
			}
		}

		/* Cas : moins de 3 des identiques */
		else if(nb_des[val_des_a_garder - 1] < 3) {
			/* On compte les paires */
			int nb_paire = 0, val_des_a_relancer = 0;
			for(i = 0; i < 6; i++) {
				if(nb_des[i] == 2)
					nb_paire++;
				else
					val_des_a_relancer = i + 1;
			}

			/* Sous cas : 2 paires */
			if(nb_paire == 2) {
				for(i = 0; i < 5; i++) {

					if(j->des[i] == val_des_a_relancer) {
						lancer(j, i);
					}
				}
			}


			/* Sous cas : 1 paire */
			else if(nb_paire == 1) {
				for(i = 0; i < 5; i++) {

					if(j->des[i] != val_des_a_garder) {
						lancer(j, i);
					}
				}
			}

			/* Sous cas : aucune paire */
			else {
				for(i = 1; i < 5; i++) {
						lancer(j, i);
				}
			}

		}

		test_mains(j, j_test); /* Permet l'affichage */

		/* Test : Si jamais on obtient un full */
		if(full(j) != -1) {
			j->tab[FULL] = j_test->tab[FULL]; /* Jouer le full */
			return 1;
		}

		/* (re)Compter les des */
		for(i = 0; i < 6; i++)
			nb_des[i] = compter_des(j, i + 1);
	}

	return 0; /* Pas de full */

}


/* ***************************************************************************** */


/**
  *\fn int tour_ordinateur(t_joueur *j)
  *\param Un pointeur vers une structure de type t_joueur : Il s'agit de l'ordinateur
  *\return Renvoie un booleen indiquant que l'ordinateur a bien joué
  *\brief Permet d'appliquer une stratégie de jeu au yahtzee par l'appel de plusieurs stratégies
	*\author Thibault Lemarchand
	*\author Nicolas Champion
*/
int tour_ordinateur(t_joueur *j) {
  int i, nb_lance = 2;
  t_joueur *tempo = creer_joueur("tempo");


  /* Lancement de la main */
  for(i = 0; i < 5; i++)
    lancer(j, i);


  test_mains(j, tempo);

	if((j->tab[YAHTZEE] == VAL_INIT) && (yahtzee(j) != -1)) {
		utiliser_yahtzee(j, tempo);
		return 1; /* L'ordi a joue (mais pas la strat sup) */
	}

	else if(strat_superieur(j, tempo, &nb_lance)) {
    return 0; /*  Strategie a pu etre applique, l'ordi a jouer */
  }

  else if((tempo->tab[GRANDE_SUITE] != VAL_INIT) && (j->tab[GRANDE_SUITE] == VAL_INIT)) {
		j->tab[GRANDE_SUITE] = tempo->tab[GRANDE_SUITE];
		return 0;
	}

  else if((tempo->tab[PETITE_SUITE] != VAL_INIT) && (j->tab[PETITE_SUITE] == VAL_INIT)) {
		j->tab[PETITE_SUITE] = tempo->tab[PETITE_SUITE];
		return 0;
	}

	else if(strat_p_g_suite(j, tempo, &nb_lance)) {
    return 0; /* Strategie a pu etre applique, l'ordi a jouer */
  }

	else if((tempo->tab[CARRE] != VAL_INIT) && (j->tab[CARRE] == VAL_INIT)) {
		j->tab[CARRE] = tempo->tab[CARRE];
		return 0;
	}

	else if(strat_carre(j, tempo, &nb_lance)) {
    return 0; /* Strategie a pu etre applique, l'ordi a jouer */
  }

	else if((tempo->tab[BRELAN] != VAL_INIT) && (j->tab[BRELAN] == VAL_INIT)) {
		j->tab[BRELAN] = tempo->tab[BRELAN];
		return 0;
	}

	else if(strat_brelan(j, tempo, &nb_lance)) {
    return 0; /* Strategie a pu etre applique, l'ordi a jouer */
  }

	else if((tempo->tab[FULL] != VAL_INIT) && (j->tab[FULL] == VAL_INIT)) {
		j->tab[FULL] = tempo->tab[FULL];
		return 0;
	}

	else if(strat_full(j, tempo, &nb_lance)) {
    return 0; /* Strategie a pu etre applique, l'ordi a jouer */
  }

  else if(strat_yahtzee(j, tempo, &nb_lance)){
    return 0; /* Strategie a pu etre applique, l'ordi a jouer */
  }

	meilleur_score(j, tempo);
	return 0;

}
