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
typedef struct {
	/* Section supérieure */
	int as;				/**< Total des 1 */
	int deux;			/**< Total des 2 */
	int trois;			/**< Total des 3 */
	int quatres;		/**< Total des 4 */
	int cinq;			/**< Total des 5 */
	int six;			/**< Total des 6 */
	int prime_35pts;	/**< +35pts si total_Sup >= 63 */

	/* Section inférieure */
	int brelan; 		/**< Total des 5 des : 3 chiffres X + 2 autres quelconques */
	int carre;			/**< Total des 5 des : 4 chiffres X + 1 chiffres Y */
	int full;			/**< 25 points : 3 chiffres X + 2 chiffres Y */
	int petite_Suite;	/**< 30 points (4 des) */
	int grande_Suite;	/**< 40 points (5 des) */
	int yahtzee;		/**< 50 points :  5 chiffres identiques */
	int chance;			/**< Total des 5 des */
	int prime_Yahtzee;	/**< 100 points */

	/* Totaux */
	int total_Sup;
	int total_Inf;
	int total_Gen;

} t_tableau;


/**
	*\struct t_joueur
	*\brief Type joueur avec sa feuille de marque et des
*/
typedef struct {
	t_tableau tab;
	int des[N];
	char nom[T];
} t_joueur;

#endif
