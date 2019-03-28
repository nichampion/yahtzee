#ifndef commun_h
#define commun_h

#define N 5 /* Nombre de des */
#define T 3 /* Taille nom joueur */

/**
  *\file commun.h
  *\brief
	*\version 1.0
*/

/**
	*\struct t_tableau
	*\brief Feuille de marque du Yahtzee
	*\brief Correspond a un joueur, pour une partie.
*/

	/* Section supérieure */
	/**< tab[0] : Total des 1 */
	/**< tab[1] : Total des 2 */
	/**< tab[2] : Total des 3 */
	/**< tab[3] : Total des 4 */
	/**< tab[4] : Total des 5 */
	/**< tab[5] : Total des 6 */
	/**< tab[6] : Bonus section supérieure (+35pts si total de la borne supérieure >= 63) */

	/* Section inférieure */
	/**< tab[7] : (Brelan) Total des 5 des : 3 chiffres X + 2 autres quelconques */
	/**< tab[8] : (Carre) Total des 5 des : 4 chiffres X + 1 chiffres Y */
	/**< tab[9] : (Full) 25 points : 3 chiffres X + 2 chiffres Y */
	/**< tab[10] : (Petite Suite) 30 points (4 des) */
	/**< tab[11] : (Grande Suite) 40 points (5 des) */
	/**< tab[12] : (Chance) Total des 5 des */
	/**< tab[13] : (Yahtzee) 50 points :  5 chiffres identiques */
	/**< tab[14] : (Prime Yahtzee) 100 points */

	/* Totaux */
	/**< tab[15] : Total de la borne supérieure */
	/**< tab[16] : Total de la borne inférieure */
	/**< tab[17] : Total global */

/**
	*\struct t_joueur
	*\brief Type joueur avec sa feuille de marque et des
*/
typedef struct {
	int tab[18];
	int des[N];
	char nom[T];
} t_joueur;

#endif
