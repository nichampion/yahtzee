#ifndef commun_h
#define commun_h

	/**
		*\file commun.h
		*\brief Contient les structures et constantes du jeu
		*\version 2
	*/


	#define N 5 	/* Nombre de des */
	#define T 12	/* Taille nom joueur */


	/* ****************************** Constantes pour le tableau ****************************** */

	#define TAILLE_TAB 17
	#define VAL_INIT -1 /* Valeur par défaut pour la feuille de marque */

	/* ***** Section supérieure ***** */
	#define AS 0 						/**< Total des 1 */
	#define DEUX 1 					/**< Total des 2 */
	#define TROIS 2 				/**< Total des 3 */
	#define QUATRE 3 				/**< Total des 4 */
	#define CINQ 4 					/**< Total des 5 */
	#define SIX 5						/**< Total des 6 */
	#define PRIME_35 6 			/**< +35pts si total_Sup >= 63 */

	/* ***** Section inférieure ***** */
	#define BRELAN 7 				/**< Total des 5 des : 3 chiffres X + 2 autres quelconques */
	#define CARRE 8 				/**< Total des 5 des : 4 chiffres X + 1 chiffres Y */
	#define FULL 9 					/**< 25 points : 3 chiffres X + 2 chiffres Y */
	#define PETITE_SUITE 10 /**< 30 points (4 des) */
	#define GRANDE_SUITE 11 /**< 40 points (5 des) */
	#define YAHTZEE 12 			/**< 50 points :  5 chiffres identiques */
	#define CHANCE 13 			/**< Total des 5 des */

	/* ***** Totaux ***** */
	#define TOTAL_SUP 14		/**< Total de la section superieur (de AS à SIX) */
	#define TOTAL_INF 15		/**< Total de la section inferieur (de BRELAN à CHANCE) */
	#define TOTAL_GEN 16		/**< Totaux superieur + inferieur + prime(s) */

	/* **************************************************************************************** */


	/**
		*\struct t_joueur
		*\brief Type joueur avec sa feuille de marque et des
	*/
	typedef struct {
		int tab[TAILLE_TAB]; 	/**< Feuille de marque Yahtzee */
		int des[N]; 					/**< Les 5 dès (la main) du joueur */
		char nom[T]; 					/**< Nom du joueur */
	} t_joueur;

#endif
