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

void test_mains_NC(t_joueur *j, t_joueur *j_test) {

	if((j->tab.as) == VAL_INIT)
		j_test->tab.as = section_superieure(j,1);

	if((j->tab.deux) == VAL_INIT)
		j_test->tab.deux = section_superieure(j,2);

	if((j->tab.trois) == VAL_INIT)
		j_test->tab.trois = section_superieure(j,3);

	if((j->tab.quatres) == VAL_INIT)
		j_test->tab.quatres = section_superieure(j,4);

	if((j->tab.cinq) == VAL_INIT)
		j_test->tab.cinq = section_superieure(j,5);

	if((j->tab.six) == VAL_INIT)
		j_test->tab.six = section_superieure(j,6);

	if((j->tab.brelan) == VAL_INIT)
		j_test->tab.brelan = brelan(j);

	if((j->tab.carre) == VAL_INIT)
		j_test->tab.carre = carre(j);

	if((j->tab.full) == VAL_INIT)
		j_test->tab.full = full(j);

	if((j->tab.petite_Suite) == VAL_INIT)
		j_test->tab.petite_Suite = petite_suite(j);

	if((j->tab.grande_Suite) == VAL_INIT)
		j_test->tab.grande_Suite = grande_suite(j);

	if((j->tab.chance) == VAL_INIT)
		j_test->tab.chance = chance(j);

	if((j->tab.yahtzee) == VAL_INIT)
		j_test->tab.yahtzee = yahtzee(j);
	else if((j->tab.yahtzee) != VAL_INIT)
		prime_yahtzee(j_test);

	affichage_possibilites(j,j_test);

}

/**
  *\brief Sous fonction. Intervient dans plusieurs fonctions.
  *\return Le nombre de des nb_test qu'il y a dans la main du joueur.
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
  *\brief Sous fonction. Intervient dans la fonction meilleur_score
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
*/
static
void choisir_max(t_joueur *j, int max, char pos_max[20]) {
	if(max == VAL_INIT)
		max = 0;

	printf("On joue %d sur %s\n", max, pos_max);

    if(strcmp(pos_max,"null") == 0) return;
    if(strcmp(pos_max,"as") == 0) j->tab.as = max;
    if(strcmp(pos_max,"deux") == 0) j->tab.deux = max;
    if(strcmp(pos_max,"trois") == 0) j->tab.trois = max;
    if(strcmp(pos_max,"quatres") == 0) j->tab.quatres = max;
    if(strcmp(pos_max,"cinq") == 0) j->tab.cinq = max;
    if(strcmp(pos_max,"six") == 0) j->tab.six = max;
    if(strcmp(pos_max,"brelan") == 0) j->tab.brelan = max;
    if(strcmp(pos_max,"carre") == 0) j->tab.carre = max;
    if(strcmp(pos_max,"full") == 0) j->tab.full = max;
    if(strcmp(pos_max,"petite_Suite") == 0) j->tab.petite_Suite = max;
    if(strcmp(pos_max,"grande_Suite") == 0) j->tab.grande_Suite = max;
    if(strcmp(pos_max,"yahtzee") == 0) j->tab.yahtzee = max;
    if(strcmp(pos_max,"chance") == 0) j->tab.chance = max;

}

/**
  *\brief Choisi la main qui rapporte le plus de points pour une combinaison de des donnée.
*/
void meilleur_score(t_joueur *j, t_joueur *j_test) {
  int max = -2;
  char pos_max[20] = "null";

  /* Parcourir feuille de marque de j_test */
  if(j->tab.as == VAL_INIT)
    test_max(&(j_test->tab.as), &max, pos_max, "as");

  if(j->tab.deux == VAL_INIT)
    test_max(&(j_test->tab.deux), &max, pos_max, "deux");

  if(j->tab.trois == VAL_INIT)
    test_max(&(j_test->tab.trois), &max, pos_max, "trois");

  if(j->tab.quatres == VAL_INIT)
    test_max(&(j_test->tab.quatres), &max, pos_max, "quatres");

  if(j->tab.cinq == VAL_INIT)
    test_max(&(j_test->tab.cinq), &max, pos_max, "cinq");

  if(j->tab.six == VAL_INIT)
    test_max(&(j_test->tab.six), &max, pos_max, "six");

  if(j->tab.brelan == VAL_INIT)
    test_max(&(j_test->tab.brelan), &max, pos_max, "brelan");

  if(j->tab.carre == VAL_INIT)
    test_max(&(j_test->tab.carre), &max, pos_max, "carre");

  if(j->tab.full == VAL_INIT)
    test_max(&(j_test->tab.full), &max, pos_max, "full");

  if(j->tab.petite_Suite == VAL_INIT)
    test_max(&(j_test->tab.petite_Suite), &max, pos_max, "petite_Suite");

  if(j->tab.grande_Suite == VAL_INIT)
    test_max(&(j_test->tab.grande_Suite), &max, pos_max, "grande_Suite");

  if(j->tab.yahtzee == VAL_INIT)
    test_max(&(j_test->tab.yahtzee), &max, pos_max, "yahtzee");

  if(j->tab.chance == VAL_INIT)
    test_max(&(j_test->tab.chance), &max, pos_max, "chance");

  /* Enregistrer dans j le max */
  choisir_max(j, max, pos_max);

}


/* ****************** Obtention du bonus supérieurs ****************** */


/**
  *\brief Strategie permettant d'obtenir le maximum de points dans la section superieur de la feuille de marque
*/
void val_des_max(int val_c, int *val_max, int nb_des_c, int *nb_des_max) {
  if(nb_des_c >= *nb_des_max) {
    *val_max = val_c;
    *nb_des_max = nb_des_c;
  }
}


/**
  *\brief Retourne la val des des les plus elevee en plus grand nombre et disponible (Valeur non jouée dans la feuille de marque)
*/
int choix_des_strat_sup(int tab[6], t_joueur *j) {
  int val_max = 0;
  int nb_des_max = 0;

  if(j->tab.as == VAL_INIT)
    val_des_max(1, &val_max, tab[0], &nb_des_max);

  if(j->tab.deux == VAL_INIT)
    val_des_max(2, &val_max, tab[1], &nb_des_max);

  if(j->tab.trois == VAL_INIT)
    val_des_max(3, &val_max, tab[2], &nb_des_max);

  if(j->tab.quatres == VAL_INIT)
    val_des_max(4, &val_max, tab[3], &nb_des_max);

  if(j->tab.cinq == VAL_INIT)
    val_des_max(5, &val_max, tab[4], &nb_des_max);

  if(j->tab.six == VAL_INIT)
    val_des_max(6, &val_max, tab[5], &nb_des_max);

  return val_max;
}


/**
  *\brief Applique la stratégie consisitant a obtenir la prime dans la section superieure (de la feuille de marque Yahtzee)
*/
int strat_superieur(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant) {
  int i;
  int nb_des[6];

  /* Verif si cette strat est applicable */
    /* Si tab sup est entierement plein => impossible */
  if((j->tab.as != VAL_INIT) && (j->tab.deux != VAL_INIT) && (j->tab.trois != VAL_INIT) && (j->tab.quatres != VAL_INIT) && (j->tab.cinq != VAL_INIT) && (j->tab.six!= VAL_INIT))
    return 0;

  /* Compter les des */
  for(i = 0; i < 6; i++)
    nb_des[i] = compter_des(j, i + 1);

  /* Choisir des (plus eleve, en plus gd nombre et dispo (non joue)) */
  int val_des_a_garder = choix_des_strat_sup(nb_des, j);

  /* Relancer les des pour obtenir le plus de des de cette valeur */
  /* 2 fois et tant que tous les des ne sont = a des_a_garder */
	int nb_lance;
  for(nb_lance = *nb_lance_Restant; nb_lance > 0; nb_lance--) {
    for(i = 0; i < 5; i++) {
      if(j->des[i] != val_des_a_garder)
        lancer(j, i);
    }
    j_test = test_mains(j); // Permet l'affichage

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
  j_test = test_mains(j);
  switch(val_des_a_garder) {
		case 1 :  j->tab.as = j_test->tab.as; break;
    case 2 :  j->tab.deux = j_test->tab.deux; break;
    case 3 :  j->tab.trois = j_test->tab.trois; break;
    case 4 :  j->tab.quatres = j_test->tab.quatres; break;
    case 5 :  j->tab.cinq = j_test->tab.cinq; break;
    case 6 :  j->tab.six = j_test->tab.six; break;
  }

  return 1; // Fin de la strategie

}


/* ****************** Obtention des suites (Petite et grande) ****************** */


/**
  *\return Renvoie un booleen
*/
int val_dans_tab(int val, int tab[], int taille) {
  int i;

  for(i = 0; i < taille; i++) {
    if(tab[i] == val)
      return 1;
  }

  return 0;
}

int strat_p_g_suite(t_joueur *j, t_joueur *j_test, int *nb_lance_Restant) {
  int i;
  int nb_des[6];

  /* Verif si cette strat est applicable */
  if(j->tab.petite_Suite != VAL_INIT || j->tab.grande_Suite != VAL_INIT)
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
	int nb_lance;
  for(nb_lance = *nb_lance_Restant; (nb_lance > 0); nb_lance--) {
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

    test_mains_NC(j, j_test); // Permet l'a	nb_ffichage

    /* Si on a Gde ou Pte suite => On utilise */
    if((j_test->tab.grande_Suite != VAL_INIT) && (j->tab.grande_Suite == VAL_INIT)) {
        exit_code = -1;
        nb_lance = -1;
    }
    else if((j_test->tab.petite_Suite != VAL_INIT) && (j->tab.petite_Suite == VAL_INIT)) {
        exit_code = -2;
        nb_lance = -1;
    }
  }

  /* Cas gde suite */
  if(exit_code == -1) {
    printf("Gde SUITE en rel\n");
    j->tab.grande_Suite = j_test->tab.grande_Suite;
    return 1; // fin de la stratégie
  }

  /* Cas pte suite */
  else if(exit_code == -2) {
    printf("Pte SUITE en rel\n");
    j->tab.petite_Suite = j_test->tab.petite_Suite;
    return 1; // fin de la stratégie
  }

  // Rien obtenu
  else
    return 0;
}


/* ****************** Obtention Yahtzee (Avec sacrifice si besoin) ****************** */


/**
  *\brief Renvoi la valeur présente le plus grand nombre de fois dans la main.
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
*/
int utiliser_yahtzee(t_joueur *j, t_joueur *j_test) {

	/* Sacrifier */
	if((j->tab.six == VAL_INIT) && (j->des[0] == 6)) {
		j->tab.six = j_test->tab.six;
		return 2; // L'ordi a joué mais pas un yahtzee
	}
	else if((j->tab.cinq == VAL_INIT) && (j->des[0] == 5)) {
		j->tab.cinq = j_test->tab.cinq;
		return 2; // L'ordi a joué mais pas un yahtzee
	}
	else if((j->tab.quatres == VAL_INIT) && (j->des[0] == 4)) {
		j->tab.quatres = j_test->tab.quatres;
		return 2; // L'ordi a joué mais pas un yahtzee
	}

	else {
		if(j->tab.yahtzee == VAL_INIT)
			j->tab.yahtzee = j_test->tab.yahtzee;
		else
			j->tab.prime_Yahtzee = j_test->tab.prime_Yahtzee;
		return 1; // L'ordi joue un yahtzee
	}

}


/**
  *\brief Permet (d'essayer) d'obtenir une main de type yahtzee en relancant
*//**
  *\brief Permet (d'essayer) d'obtenir une main de type yahtzee en relancant
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
	int nb_lance;
	for(nb_lance = *nb_lance_Restant; nb_lance > 0; nb_lance--) {
		for(i = 0; i < 5; i++) {
			if(j->des[i] != val_des_a_garder)
				lancer(j, i);
		}
		j_test = test_mains(j); // Permet l'affichage

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
	if(j->tab.brelan != VAL_INIT)
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
	int nb_lance;
	for(nb_lance = *nb_lance_Restant; nb_lance > 0; nb_lance--) {

		/* Cas : Mois de 3 des identiques */
		for(i = 0; i < 5; i++) {
			if(j->des[i] != val_des_a_garder)
				lancer(j, i);
		}

		j_test = test_mains(j); // Permet l'affichage

		/* Test : Si jamais on obtient un brelan */
		if(brelan(j) != -1) {
			j->tab.brelan = j_test->tab.brelan; // Jouer le brelan
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
	if(j->tab.carre != VAL_INIT)
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
	int nb_lance;
	for(nb_lance = *nb_lance_Restant; nb_lance > 0; nb_lance--) {

		/* Cas : Mois de 3 des identiques */
		for(i = 0; i < 5; i++) {
			if(j->des[i] != val_des_a_garder)
				lancer(j, i);
		}

		j_test = test_mains(j); // Permet l'affichage

		/* Test : Si jamais on obtient un carre */
		if(carre(j) != -1) {
			j->tab.carre = j_test->tab.carre; // Jouer le carre
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
	if(j->tab.full != VAL_INIT)
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
	int nb_lance;
	for(nb_lance = *nb_lance_Restant; nb_lance > 0; nb_lance--) {

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

		j_test = test_mains(j); // Permet l'affichage

		/* Test : Si jamais on obtient un full */
		if(full(j) != -1) {
			j->tab.full = j_test->tab.full; // Jouer le full
			return 1;
		}

		/* (re)Compter les des */
		for(i = 0; i < 6; i++)
			nb_des[i] = compter_des(j, i + 1);
	}

	return 0; // Pas de full

}


/* ***************************************************************************** */


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

  test_mains_NC(j, tempo); // Celle de Zack => Fuite memoire !!!!!!!!!

	if(yahtzee(j) != -1) {
		utiliser_yahtzee(j, tempo);
		return 2; // L'ordi a joue (mais pas la strat sup)
	}

	else if(strat_superieur(j, tempo, &nb_lance))
    return 0; // Strategie a pu etre applique, l'ordi a jouer

	else if(strat_yahtzee(j, tempo, &nb_lance))
	  return 0; // Strategie a pu etre applique, l'ordi a jouer

  else if((tempo->tab.grande_Suite != VAL_INIT) && (j->tab.grande_Suite == VAL_INIT)) {
		j->tab.grande_Suite = tempo->tab.grande_Suite;
		return 0;
	}

  else if((tempo->tab.petite_Suite != VAL_INIT) && (j->tab.petite_Suite == VAL_INIT)) {
		j->tab.petite_Suite = tempo->tab.petite_Suite;
		return 0;
	}

	else if(strat_p_g_suite(j, tempo, &nb_lance))
		return 0; // Strategie a pu etre applique, l'ordi a jouer

	else if((tempo->tab.carre != VAL_INIT) && (j->tab.carre == VAL_INIT)) {
		j->tab.carre = tempo->tab.carre;
		return 0;
	}

	else if(strat_carre(j, tempo, &nb_lance))
	 return 0; // Strategie a pu etre applique, l'ordi a jouer

	else if((tempo->tab.brelan != VAL_INIT) && (j->tab.brelan == VAL_INIT)) {
		j->tab.brelan = tempo->tab.brelan;
		return 0;
	}

	else if(strat_brelan(j, tempo, &nb_lance))
		return 0; // Strategie a pu etre applique, l'ordi a jouer

	else if((tempo->tab.full != VAL_INIT) && (j->tab.full == VAL_INIT)) {
		j->tab.full = tempo->tab.full;
		return 0;
	}

	else if(strat_full(j, tempo, &nb_lance))
	 return 0; // Strategie a pu etre applique, l'ordi a jouer

	meilleur_score(j, tempo);
	return 0;

}
