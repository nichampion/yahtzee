#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "commun.h"
#include "ordinateur.h"
#include "mains.h"
#include "fonctions_joueur.h"
#include "fonctions_jeu.h"

/**
	*\file ordinateur.c
	*\brief
	*\version 1.0
*/

/*Lien strat 1 -> http://www.ultraboardgames.com/yahtzee/tips.php*/
/*Lien strat 2 -> https://fr.wikihow.com/jouer-au-yahtzee*/


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
  for(i = 0; i<N; i++){
    if(joueur->des[i] == nb_test)
      res += 1;
  }
  return res;
}


/* ****************** Calcul de la meilleur main ****************** */


/**
	*\fn void test_max(int *val, int *max, char pos_max[20], char ligne_courante[20])
	*\param Un pointeur vers la valeur courante d'un dès, la valeur max, une chaine stockant la position de la plus grande par rappport a la feuille de marque du yahtzee et une chaine de caractere stockant la position courante dans le feuille de marque du yahtzee
  *\brief Sous fonction. Intervient dans la fonction meilleur_score
	*\author Nicolas Champion
*/
static
void test_max(int *val, int *max, char pos_max[20], char ligne_courante[20]) {
  if(*val > *max) {
    *max = *val;
    strcpy(pos_max, ligne_courante);
  }
}


/**
  *\brief Sous fonction. Intervient dans la fonction meilleur_score
	*\author Nicolas Champion
*/
static
void choisir_max(t_joueur *j, int max, char pos_max[20]) {
	if(max == VAL_INIT)
		max = 0;

	printf("On joue %d sur %s\n", max, pos_max);

    if(strcmp(pos_max,"null") == 0) return;
    if(strcmp(pos_max,"as") == 0) j->tab[AS] = max;
    if(strcmp(pos_max,"deux") == 0) j->tab[DEUX] = max;
    if(strcmp(pos_max,"trois") == 0) j->tab[TROIS] = max;
    if(strcmp(pos_max,"quatres") == 0) j->tab[QUATRE] = max;
    if(strcmp(pos_max,"cinq") == 0) j->tab[CINQ] = max;
    if(strcmp(pos_max,"six") == 0) j->tab[SIX] = max;
    if(strcmp(pos_max,"brelan") == 0) j->tab[BRELAN] = max;
    if(strcmp(pos_max,"carre") == 0) j->tab[CARRE] = max;
    if(strcmp(pos_max,"full") == 0) j->tab[FULL] = max;
    if(strcmp(pos_max,"petite_Suite") == 0) j->tab[PETITE_SUITE] = max;
    if(strcmp(pos_max,"grande_Suite") == 0) j->tab[GRANDE_SUITE] = max;
    if(strcmp(pos_max,"yahtzee") == 0) j->tab[YAHTZEE] = max;
    if(strcmp(pos_max,"chance") == 0) j->tab[CHANCE] = max;

}

/**
  *\brief Choisi la main qui rapporte le plus de points pour une combinaison de des donnée.
	*\author Nicolas Champion
*/
void meilleur_score(t_joueur *j, t_joueur *j_test) {
  int max = -2;
  char pos_max[20] = "null";

  /* Parcourir feuille de marque de j_test */
  if(j->tab[AS] == VAL_INIT)
    test_max(&(j_test->tab[AS]), &max, pos_max, "as");

  if(j->tab[DEUX] == VAL_INIT)
    test_max(&(j_test->tab[DEUX]), &max, pos_max, "deux");

  if(j->tab[TROIS] == VAL_INIT)
    test_max(&(j_test->tab[TROIS]), &max, pos_max, "trois");

  if(j->tab[QUATRE] == VAL_INIT)
    test_max(&(j_test->tab[QUATRE]), &max, pos_max, "quatres");

  if(j->tab[CINQ] == VAL_INIT)
    test_max(&(j_test->tab[CINQ]), &max, pos_max, "cinq");

  if(j->tab[SIX] == VAL_INIT)
    test_max(&(j_test->tab[SIX]), &max, pos_max, "six");

  if(j->tab[BRELAN] == VAL_INIT)
    test_max(&(j_test->tab[BRELAN]), &max, pos_max, "brelan");

  if(j->tab[CARRE] == VAL_INIT)
    test_max(&(j_test->tab[CARRE]), &max, pos_max, "carre");

  if(j->tab[FULL] == VAL_INIT)
    test_max(&(j_test->tab[FULL]), &max, pos_max, "full");

  if(j->tab[PETITE_SUITE] == VAL_INIT)
    test_max(&(j_test->tab[PETITE_SUITE]), &max, pos_max, "petite_Suite");

  if(j->tab[GRANDE_SUITE] == VAL_INIT)
    test_max(&(j_test->tab[GRANDE_SUITE]), &max, pos_max, "grande_Suite");

  if(j->tab[YAHTZEE] == VAL_INIT)
    test_max(&(j_test->tab[YAHTZEE]), &max, pos_max, "yahtzee");

  if(j->tab[CHANCE] == VAL_INIT)
    test_max(&(j_test->tab[CHANCE]), &max, pos_max, "chance");

  /* Enregistrer dans j le max */
  choisir_max(j, max, pos_max);

}


/* ****************** Obtention du bonus supérieurs ****************** */


/**
  *\brief Strategie permettant d'obtenir le maximum de points dans la section superieur de la feuille de marque
	*\author Nicolas Champion
*/
void val_des_max(int val_c, int *val_max, int nb_des_c, int *nb_des_max) {
  if(nb_des_c >= *nb_des_max) {
    *val_max = val_c;
    *nb_des_max = nb_des_c;
  }
}


/**
  *\brief Retourne la val des des les plus elevee en plus grand nombre et disponible (Valeur non jouée dans la feuille de marque)
	*\author Nicolas Champion
*/
int choix_des_strat_sup(int tab[6], t_joueur *j) {
  int val_max = 0;
  int nb_des_max = 0;

  if(j->tab[AS] == VAL_INIT)
    val_des_max(1, &val_max, tab[0], &nb_des_max);

  if(j->tab[DEUX] == VAL_INIT)
    val_des_max(2, &val_max, tab[1], &nb_des_max);

  if(j->tab[TROIS] == VAL_INIT)
    val_des_max(3, &val_max, tab[2], &nb_des_max);

  if(j->tab[QUATRE] == VAL_INIT)
    val_des_max(4, &val_max, tab[3], &nb_des_max);

  if(j->tab[CINQ] == VAL_INIT)
    val_des_max(5, &val_max, tab[4], &nb_des_max);

  if(j->tab[SIX] == VAL_INIT)
    val_des_max(6, &val_max, tab[5], &nb_des_max);

  return val_max;
}


/**
  *\brief Applique la stratégie consisitant a obtenir la prime dans la section superieure (de la feuille de marque Yahtzee)
	*\author Nicolas Champion
*/
int strat_superieur(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant) {
  int i;
  int nb_des[6];

  /* Verif si cette strat est applicable */
    /* Si tab sup est entierement plein => impossible */
  if((j->tab[AS] != VAL_INIT) && (j->tab[DEUX] != VAL_INIT) && (j->tab[TROIS] != VAL_INIT) && (j->tab[QUATRE] != VAL_INIT) && (j->tab[CINQ] != VAL_INIT) && (j->tab[SIX]!= VAL_INIT))
    return 0;

  /* Compter les des */
  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

  /* Choisir des (plus eleve, en plus gd nombre et dispo (non joue)) */
  int val_des_a_garder = choix_des_strat_sup(nb_des, j);

  /* Relancer les des pour obtenir le plus de des de cette valeur */
  /* 2 fois et tant que tous les des ne sont = a des_a_garder */
  for(; *nb_lance_Restant > 0; (*nb_lance_Restant)--) {
    for(i = 0; i < 5; i++) {
      if(j->des[i] != val_des_a_garder)
        lancer(j, i);
    }
    test_mains(j, j_test); // Permet l'affichage

		/* Test : Si jamais on obtient un yahtzee */
		if(yahtzee(j) != -1) {
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
  switch(val_des_a_garder) {
		case 1 :  j->tab[AS] = j_test->tab[AS]; break;
    case 2 :  j->tab[DEUX] = j_test->tab[DEUX]; break;
    case 3 :  j->tab[TROIS] = j_test->tab[TROIS]; break;
    case 4 :  j->tab[QUATRE] = j_test->tab[QUATRE]; break;
    case 5 :  j->tab[CINQ] = j_test->tab[CINQ]; break;
    case 6 :  j->tab[SIX] = j_test->tab[SIX]; break;
  }

  return 1; // Fin de la strategie

}


/* ****************** Obtention des suites (Petite et grande) ****************** */


/**
  *\return Renvoie un booleen
	*\author Nicolas Champion
*/
int val_dans_tab(int val, int tab[], int taille) {
  int i;

  for(i = 0; i < taille; i++) {
    if(tab[i] == val)
      return 1;
  }

  return 0;
}


/**
	*\author Nicolas Champion
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

  /* Analyse de la main => On surveille les sequences 2-3-4 OU 4-5-6 */
  int val_des_a_garder[3];

    /* Seq 2-3-4 */
  if((nb_des[1] != 0) && (nb_des[2] != 0) && (nb_des[3] != 0)) {
    val_des_a_garder[0] = 2;
    val_des_a_garder[1] = 3;
    val_des_a_garder[2] = 4;
  }

    /* Seq 4-5-6 */
  else if((nb_des[3] != 0) && (nb_des[4] != 0) && (nb_des[5] != 0)) {
    val_des_a_garder[0] = 4;
    val_des_a_garder[1] = 5;
    val_des_a_garder[2] = 6;
  }

    /* Les autres cas seront geres par la fonction meilleur_score */
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

    test_mains(j, j_test); // Permet l'a	nb_ffichage

    /* Si on a Gde ou Pte suite => On utilise */
    if((j_test->tab[GRANDE_SUITE] != VAL_INIT) && (j->tab[GRANDE_SUITE] == VAL_INIT)) {
        exit_code = -1;
        (*nb_lance_Restant) = -1;
    }
    else if((j_test->tab[PETITE_SUITE] != VAL_INIT) && (j->tab[PETITE_SUITE] == VAL_INIT)) {
        exit_code = -2;
        (*nb_lance_Restant) = -1;
    }
  }

  /* Cas gde suite */
  if(exit_code == -1) {
    printf("Gde SUITE en rel\n");
    j->tab[GRANDE_SUITE] = j_test->tab[GRANDE_SUITE];
    return 1; // fin de la stratégie
  }

  /* Cas pte suite */
  else if(exit_code == -2) {
    printf("Pte SUITE en rel\n");
    j->tab[PETITE_SUITE] = j_test->tab[PETITE_SUITE];
    return 1; // fin de la stratégie
  }

  // Rien obtenu
  else
    return 0;
}


/* ****************** Obtention Yahtzee (Avec sacrifice si besoin) ****************** */


/**
  *\brief Renvoi la valeur présente le plus grand nombre de fois dans la main.
	*\author Nicolas Champion
*/
static
int val_qte_max_tab(int tab[], int taille)  {
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
  *\brief On suppose que l'on a une main de type yahtzee (Donc tous les des identiques)
	*\author Nicolas Champion
*/
int utiliser_yahtzee(t_joueur *j, t_joueur *j_test) {

	/* Sacrifier */
	if((j->tab[SIX] == VAL_INIT) && (j->des[0] == 6)) {
		j->tab[SIX] = j_test->tab[SIX];
		return 2; // L'ordi a joué mais pas un yahtzee
	}
	else if((j->tab[CINQ] == VAL_INIT) && (j->des[0] == 5)) {
		j->tab[CINQ] = j_test->tab[CINQ];
		return 2; // L'ordi a joué mais pas un yahtzee
	}
	else if((j->tab[QUATRE] == VAL_INIT) && (j->des[0] == 4)) {
		j->tab[QUATRE] = j_test->tab[QUATRE];
		return 2; // L'ordi a joué mais pas un yahtzee
	}

	else {
		if(j->tab[YAHTZEE] == VAL_INIT)
			j->tab[YAHTZEE] = j_test->tab[YAHTZEE];
		else
			j->tab[PRIME_YAHTZEE] = j_test->tab[PRIME_YAHTZEE];
		return 1; // L'ordi joue un yahtzee
	}

}


/**
  *\brief Permet (d'essayer) d'obtenir une main de type yahtzee en relancant
	*\author Nicolas Champion
*/
int strat_yahtzee(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant) {
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
		for(i = 0; i < 5; i++) {
			if(j->des[i] != val_des_a_garder)
				lancer(j, i);
		}
		test_mains(j, j_test); // Permet l'affichage

		/* Test : Si jamais on obtient un yahtzee */
		if(yahtzee(j) != -1) {
			utiliser_yahtzee(j, j_test); // Jouer le yahtzee
			return 1;
		}
	}

	return 0; // Pas de yahtzee

}


/* ****************** Obtention brelan ****************** */


/**
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

		test_mains(j, j_test); // Permet l'affichage

		/* Test : Si jamais on obtient un brelan */
		if(brelan(j) != -1) {
			j->tab[BRELAN] = j_test->tab[BRELAN]; // Jouer le brelan
			return 1;
		}
	}

	return 0; // Pas de brelan

}


/* ****************** Obtention carre ****************** */


/**
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

		/* Cas : Mois de 3 des identiques */
		for(i = 0; i < 5; i++) {
			if(j->des[i] != val_des_a_garder)
				lancer(j, i);
		}

		test_mains(j, j_test); // Permet l'affichage

		/* Test : Si jamais on obtient un carre */
		if(carre(j) != -1) {
			j->tab[CARRE] = j_test->tab[CARRE]; // Jouer le carre
			return 1;
		}
	}

	return 0; // Pas de carre

}


/* ****************** Obtention full ****************** */


/**
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
					i = 5; // Permet de n'en relancer qu'un
				}
			}
		}

		/* Cas : 3 des identiques => Relancer 1 des pour obtenir une paire */
		else if(nb_des[val_des_a_garder - 1] == 3) {
			for(i = 0; i < 5; i++) {

				/* Sous Cas 1 : 3 des identiques */
				if(j->des[i] != val_des_a_garder) {
					lancer(j, i);
					i = 5; // Permet de n'en relancer qu'un
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

		test_mains(j, j_test); // Permet l'affichage

		/* Test : Si jamais on obtient un full */
		if(full(j) != -1) {
			j->tab[FULL] = j_test->tab[FULL]; // Jouer le full
			return 1;
		}

		/* (re)Compter les des */
		for(i = 0; i < 6; i++)
			nb_des[i] = compter_des(j, i + 1);
	}

	return 0; // Pas de full

}


/* ***************************************************************************** */


/**
  *\brief
	*\author Thibault Lemarchand
	*\author Nicolas Champion
*/
int tour_ordinateur(t_joueur *j) {
  int i, nb_lance = 2;
  t_joueur *tempo = creer_joueur("tempo");


  for(i = 0; i < 5; i++)
    lancer(j, i);


  /* Val de tests */
	// Verifier a chaque relancement qu'on a pas un yahtzee !!!!!
  /*  j->des[0] = 4;
  j->des[1] = 4;
  j->des[2] = 4;
  j->des[3] = 4;
  j->des[4] = 5;*/

  test_mains(j, tempo); 

	if(yahtzee(j) != -1) {
		utiliser_yahtzee(j, tempo);
		return 2; // L'ordi a joue (mais pas la strat sup)
	}

	else if(strat_superieur(j, tempo, &nb_lance))
    return 0; // Strategie a pu etre applique, l'ordi a jouer

	else if(strat_yahtzee(j, tempo, &nb_lance))
	  return 0; // Strategie a pu etre applique, l'ordi a jouer

  else if((tempo->tab[GRANDE_SUITE] != VAL_INIT) && (j->tab[GRANDE_SUITE] == VAL_INIT)) {
		j->tab[GRANDE_SUITE] = tempo->tab[GRANDE_SUITE];
		return 0;
	}

  else if((tempo->tab[PETITE_SUITE] != VAL_INIT) && (j->tab[PETITE_SUITE] == VAL_INIT)) {
		j->tab[PETITE_SUITE] = tempo->tab[PETITE_SUITE];
		return 0;
	}

	else if(strat_p_g_suite(j, tempo, &nb_lance))
		return 0; // Strategie a pu etre applique, l'ordi a jouer

	else if((tempo->tab[CARRE] != VAL_INIT) && (j->tab[CARRE] == VAL_INIT)) {
		j->tab[CARRE] = tempo->tab[CARRE];
		return 0;
	}

	else if(strat_carre(j, tempo, &nb_lance))
	 return 0; // Strategie a pu etre applique, l'ordi a jouer

	else if((tempo->tab[BRELAN] != VAL_INIT) && (j->tab[BRELAN] == VAL_INIT)) {
		j->tab[BRELAN] = tempo->tab[BRELAN];
		return 0;
	}

	else if(strat_brelan(j, tempo, &nb_lance))
		return 0; // Strategie a pu etre applique, l'ordi a jouer

	else if((tempo->tab[FULL] != VAL_INIT) && (j->tab[FULL] == VAL_INIT)) {
		j->tab[FULL] = tempo->tab[FULL];
		return 0;
	}

	else if(strat_full(j, tempo, &nb_lance))
	 return 0; // Strategie a pu etre applique, l'ordi a jouer

	meilleur_score(j, tempo);
	return 0;

}
