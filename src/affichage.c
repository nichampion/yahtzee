#include "affichage.h"

/* Librairies SDL */
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

/**
	*\file affichage.c
	*\brief Fonctions de jeu en SDL
	*\version 2
  *\author Sunny Biard
*/


/**
	*\fn int aff1_joueur(int dflag)
	*\param Un flag transmis a tour_ordinateur
	*\brief Fonction permettant l'affichage du jeu avec 1 humain (vs PC)
  *\author Sunny Biard
*/
int aff1_joueur(int dflag) {
	t_joueur * j1 = creer_joueur("J1");
	t_joueur * j2 = creer_joueur("Ordinateur");
	t_joueur * j_choix = creer_joueur("Choix"); /* Joueur temporaire permettant de stocker les combinaisons possibles du joueur pour chaque tour */
	t_joueur ** ptj = &j1;

	int cpt_lancer = 0, de_pos[5] = {0,0,0,0,0}, clic_borneG_x, clic_borneD_x, clic_borneS_y, clic_borneI_y, coup, i, p;
	char  score[20], msg_fin[50];

	SDL_Window *pWindow = NULL;

  	SDL_Surface *j_courant=NULL, *msg=NULL, *tab_score=NULL, *de_courant=NULL, *de1=NULL, *de2=NULL, *de3=NULL, *de4=NULL, *de5=NULL, *de6=NULL, *img_btn_lancer=NULL, *caseJ=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect clearDestRect, j_courantDestRect, msgDestRect, imgDestRect, img2DestRect, scoreDestRect, caseDestRect;

	caseDestRect.w = 49;
	caseDestRect.h = 27;

	img2DestRect.w = 50;
	img2DestRect.h = 50;

	j_courantDestRect.x = 620;
	j_courantDestRect.y = 50;
	j_courantDestRect.w = 100;
	j_courantDestRect.h = 100;

	clearDestRect.x = 300;
	clearDestRect.y = 0;
	clearDestRect.w = 700;
	clearDestRect.h = 700;

	SDL_Texture *image_texde1, *image_texde2, *image_texde3, *image_texde4, *image_texde5, *caseJ_tex;
	SDL_Texture **pt_image_texde[5] = {&image_texde1,&image_texde2,&image_texde3,&image_texde4,&image_texde5};

	TTF_Font *police_jeu = NULL, *police_score = NULL;

	SDL_Color blanc = {255, 255, 255};
	SDL_Color noir = {0, 0, 0};
	SDL_Color rouge = {255, 0, 0};

 	/* Initialisation simple */
  	if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
  		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
    	return -1;
  	}

	/* Initialisation TTF */
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}


	/* Création de la fenêtre */
	pWindow = SDL_CreateWindow("Yahtzee",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 750, SDL_WINDOW_SHOWN);

	if(!pWindow){
		fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}

	/* Initialisation des polices */
	if( (police_score = TTF_OpenFont("../src/coolvetica rg.ttf", 20)) == NULL){
		fprintf(stderr, "Erreur au chargement de la police\n");
		exit(EXIT_FAILURE);
	}

	if( (police_jeu = TTF_OpenFont("../src/coolvetica rg.ttf", 35)) == NULL){
		fprintf(stderr, "Erreur au chargement de la police\n");
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// load sample.png into image
	SDL_RWops *rwopscore=SDL_RWFromFile("../src/img/score.png", "rb");
	tab_score=IMG_LoadPNG_RW(rwopscore);
	if(!tab_score) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_Texture *tab_score_tex = SDL_CreateTextureFromSurface(renderer, tab_score);
	if(!tab_score_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(tab_score); /* on a la texture, plus besoin de l'image */

	SDL_RWops *rwopde1=SDL_RWFromFile("../src/img/de1.png", "rb");
	de1=IMG_LoadPNG_RW(rwopde1);
	if(!de1) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde2=SDL_RWFromFile("../src/img/de2.png", "rb");
	de2=IMG_LoadPNG_RW(rwopde2);
	if(!de2) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde3=SDL_RWFromFile("../src/img/de3.png", "rb");
	de3=IMG_LoadPNG_RW(rwopde3);
	if(!de3) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde4=SDL_RWFromFile("../src/img/de4.png", "rb");
	de4=IMG_LoadPNG_RW(rwopde4);
	if(!de4) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde5=SDL_RWFromFile("../src/img/de5.png", "rb");
	de5=IMG_LoadPNG_RW(rwopde5);
	if(!de5) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde6=SDL_RWFromFile("../src/img/de6.png", "rb");
	de6=IMG_LoadPNG_RW(rwopde6);
	if(!de6) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwop_btn_lancer=SDL_RWFromFile("../src/img/btn_lancer.png", "rb");
	img_btn_lancer=IMG_LoadPNG_RW(rwop_btn_lancer);
	if(!img_btn_lancer) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_Texture *btn_lancer_tex = SDL_CreateTextureFromSurface(renderer, img_btn_lancer);
	if(!btn_lancer_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(img_btn_lancer); /* on a la texture, plus besoin de l'image */

	if(pWindow){
		int running = 1;
		/* Boucle de jeu */
		while(running){
			SDL_Event e;
			while(SDL_PollEvent(&e)){
				switch(e.type) {
					/* Fermeture de la fenêtre */
					case SDL_QUIT:
						running = 0;
					break;

					/* Ouverture de la fenêtre */
					case SDL_WINDOWEVENT:
						switch(e.window.event){
							case SDL_WINDOWEVENT_SHOWN:
								/* Le fond de la fenêtre sera vert */
			        			SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
								SDL_RenderClear(renderer);

			        			/* Ajout du texte en noir */
			        			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

			      				imgDestRect.x = 10;
								imgDestRect.y = 50;

								SDL_QueryTexture(tab_score_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, tab_score_tex, NULL, &imgDestRect);

								imgDestRect.x = 575;
								imgDestRect.y = 500;

								SDL_QueryTexture(btn_lancer_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, btn_lancer_tex, NULL, &imgDestRect);

								/* Rendu */
								SDL_RenderPresent(renderer);

							break;
						}
					break;

					/* Relachement de souris */
					case SDL_MOUSEBUTTONUP:

						/* Tour de jeu de l'ordinateur */
						if(ptj == &j2){
							if(tour_ordinateur(*ptj, dflag) >= 0){

								/* Nettoyage de la partie droite de la fenêtre */
								SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
								SDL_RenderFillRect(renderer,&clearDestRect);

								j_courantDestRect.x = 520;

								/* Affichage nom du joueur courant */
								sprintf(score,"%s",(*ptj)->nom);
								j_courant = TTF_RenderUTF8_Blended(police_jeu, score, blanc);
								if(!j_courant){
									fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								SDL_Texture *j_courant_tex = SDL_CreateTextureFromSurface(renderer, j_courant);
								if(!j_courant_tex){
									fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								SDL_QueryTexture(j_courant_tex, NULL, NULL, &(j_courantDestRect.w), &(j_courantDestRect.h));
								SDL_RenderCopy(renderer, j_courant_tex, NULL, &j_courantDestRect);

								SDL_RenderPresent(renderer);

								sleep(1);

								scoreDestRect.x = 252;
								caseDestRect.x = 234;
								caseDestRect.y = scoreDestRect.y = 80;

								/* Affichage du score joué par l'ordinateur ainsi que ses scores précédents dans la grille */
								for(i = 0; i < 14; i++){

									if(i == 6){
										caseDestRect.y = (scoreDestRect.y += 48);
									}

									else{

										SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
										SDL_RenderFillRect(renderer,&caseDestRect);
										if((*ptj)->tab[i] != VAL_INIT){

											sprintf(score,"%d",(*ptj)->tab[i]);
											caseJ = TTF_RenderUTF8_Blended(police_score, score, noir);
											if(!caseJ){
												fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
												exit(EXIT_FAILURE);
											}

											caseJ_tex = SDL_CreateTextureFromSurface(renderer, caseJ);
											if(!caseJ_tex){
												fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
												exit(EXIT_FAILURE);
											}

											SDL_QueryTexture(caseJ_tex, NULL, NULL, &(scoreDestRect.w), &(scoreDestRect.h));
											SDL_RenderCopy(renderer, caseJ_tex, NULL, &(scoreDestRect));
										}
									}
									caseDestRect.y = (scoreDestRect.y += 29);

								}

								imgDestRect.x = 575;
								imgDestRect.y = 500;

								SDL_QueryTexture(btn_lancer_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, btn_lancer_tex, NULL, &imgDestRect);

								SDL_RenderPresent(renderer);

								/* Changement de joueur courant */
								ptj = &j1;

							}
						}

						/* Fin de partie */
						if(fin_de_partie(j1) && fin_de_partie(j2)){

							scoreDestRect.x = 202;
							caseDestRect.x = 184;
							caseDestRect.y = scoreDestRect.y = 254;
							i = 6;

							/* Affichage des totaux dans la grille du joueur 1 */
							while(i < 17){

								SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
								SDL_RenderFillRect(renderer,&caseDestRect);
								sprintf(score,"%d",j1->tab[i]);
								caseJ = TTF_RenderUTF8_Blended(police_score, score, noir);
								if(!caseJ){
									fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								caseJ_tex = SDL_CreateTextureFromSurface(renderer, caseJ);
								if(!caseJ_tex){
									fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								SDL_QueryTexture(caseJ_tex, NULL, NULL, &(scoreDestRect.w), &(scoreDestRect.h));
								SDL_RenderCopy(renderer, caseJ_tex, NULL, &(scoreDestRect));

								caseDestRect.y = (scoreDestRect.y += 29);

								if(i == 14){
									caseDestRect.y = (scoreDestRect.y += 222);
								}

								if(i == 6)
									i = 14;
								else
									i++;
							}

							scoreDestRect.x = 252;
							caseDestRect.x = 234;
							caseDestRect.y = scoreDestRect.y = 254;
							i = 6;

							/* Affichage des totaux dans la grille de l'ordinateur */
							while(i < 17){

								SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
								SDL_RenderFillRect(renderer,&caseDestRect);
								sprintf(score,"%d",j2->tab[i]);
								caseJ = TTF_RenderUTF8_Blended(police_score, score, noir);
								if(!caseJ){
									fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								caseJ_tex = SDL_CreateTextureFromSurface(renderer, caseJ);
								if(!caseJ_tex){
									fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								SDL_QueryTexture(caseJ_tex, NULL, NULL, &(scoreDestRect.w), &(scoreDestRect.h));
								SDL_RenderCopy(renderer, caseJ_tex, NULL, &(scoreDestRect));

								caseDestRect.y = (scoreDestRect.y += 29);

								if(i == 14){
									caseDestRect.y = (scoreDestRect.y += 222);
								}

								if(i == 6)
									i = 14;
								else
									i++;
							}

							SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
							SDL_RenderFillRect(renderer,&clearDestRect);

							msgDestRect.x = 310;
							msgDestRect.y = 300;

							/* Affichage message de fin de partie */
							if(j1->tab[16] > j2->tab[16])
								sprintf(msg_fin,"Le joueur %s a gagné avec %d points !",j1->nom,j1->tab[16]);
							else if(j1->tab[16] < j2->tab[16])
								sprintf(msg_fin,"Le joueur %s a gagné avec %d points !",j2->nom,j2->tab[16]);
							else
								sprintf(msg_fin,"Egalité !");

							msg = TTF_RenderUTF8_Blended(police_jeu, msg_fin, blanc);
							if(!msg){
								fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
								exit(EXIT_FAILURE);
							}

							SDL_Texture *msg_tex = SDL_CreateTextureFromSurface(renderer, msg);
							if(!msg_tex){
								fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
								exit(EXIT_FAILURE);
							}

							SDL_QueryTexture(msg_tex, NULL, NULL, &(msgDestRect.w), &(msgDestRect.h));
							SDL_RenderCopy(renderer, msg_tex, NULL, &msgDestRect);

							SDL_RenderPresent(renderer);
						}
					break;

					/* Clic de souris */
					case SDL_MOUSEBUTTONDOWN:

						if(!fin_de_partie(j1) || !fin_de_partie(j2)){

							if(ptj == &j1){

								/* Clic sur le bouton lancer en ayant fait au maximum 2 lancers auparavant */
								if(e.motion.x > 575 && e.motion.x < 675 && e.motion.y > 500 && e.motion.y < 550 && cpt_lancer < 3){

									/* Affichage joueur courant */
									SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
									SDL_RenderFillRect(renderer,&j_courantDestRect);

									j_courantDestRect.x = 620;

									sprintf(score,"%s",(*ptj)->nom);
									j_courant = TTF_RenderUTF8_Blended(police_jeu, score, blanc);
									if(!j_courant){
										fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
										exit(EXIT_FAILURE);
									}

									SDL_Texture *j_courant_tex = SDL_CreateTextureFromSurface(renderer, j_courant);
									if(!j_courant_tex){
										fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
										exit(EXIT_FAILURE);
									}

									SDL_QueryTexture(j_courant_tex, NULL, NULL, &(j_courantDestRect.w), &(j_courantDestRect.h));
									SDL_RenderCopy(renderer, j_courant_tex, NULL, &j_courantDestRect);

									imgDestRect.x = img2DestRect.x = 400;
					 				imgDestRect.y = 300;
									img2DestRect.y = 600;

									/* Boucle de lancer des dés */
									for(i = 0; i < 5; i++){
										if(de_pos[i] == 0 || cpt_lancer == 0){
											lancer(*ptj,i);
											/* Récupération de la valeur du dé courant (entre 1 et 6) */
											switch((*ptj)->des[i]){
												case 1:
													de_courant = de1;
												break;
												case 2:
													de_courant = de2;
												break;
												case 3:
													de_courant = de3;
												break;
												case 4:
													de_courant = de4;
												break;
												case 5:
													de_courant = de5;
												break;
												case 6:
													de_courant = de6;
												break;
											}
											/* Affichage de l'image du dé courant */
											switch(i){
												case 0:
													SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
													SDL_RenderFillRect(renderer,&img2DestRect);
								 					image_texde1 = SDL_CreateTextureFromSurface(renderer, de_courant);
													if(!image_texde1){
														fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
														exit(EXIT_FAILURE);
													}
								 					SDL_QueryTexture(image_texde1, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								 					SDL_RenderCopy(renderer, image_texde1, NULL, &imgDestRect);
													de_pos[i] = 0;
												break;
												case 1:
													SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
													SDL_RenderFillRect(renderer,&img2DestRect);
								 					image_texde2 = SDL_CreateTextureFromSurface(renderer, de_courant);
													if(!image_texde2){
														fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
														exit(EXIT_FAILURE);
													}
													SDL_QueryTexture(image_texde2, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								 					SDL_RenderCopy(renderer, image_texde2, NULL, &imgDestRect);
													de_pos[i] = 0;
												break;
												case 2:
													SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
													SDL_RenderFillRect(renderer,&img2DestRect);
								 					image_texde3 = SDL_CreateTextureFromSurface(renderer, de_courant);
													if(!image_texde3){
														fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
														exit(EXIT_FAILURE);
													}
													SDL_QueryTexture(image_texde3, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								 					SDL_RenderCopy(renderer, image_texde3, NULL, &imgDestRect);
													de_pos[i] = 0;
												break;
												case 3:
													SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
													SDL_RenderFillRect(renderer,&img2DestRect);
								 					image_texde4 = SDL_CreateTextureFromSurface(renderer, de_courant);
													if(!image_texde4){
														fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
														exit(EXIT_FAILURE);
													}
								 					SDL_QueryTexture(image_texde4, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								 					SDL_RenderCopy(renderer, image_texde4, NULL, &imgDestRect);
													de_pos[i] = 0;
												break;
												case 4:
													SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
													SDL_RenderFillRect(renderer,&img2DestRect);
								 					image_texde5 = SDL_CreateTextureFromSurface(renderer, de_courant);
													if(!image_texde5){
														fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
														exit(EXIT_FAILURE);
													}
													SDL_QueryTexture(image_texde5, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								 					SDL_RenderCopy(renderer, image_texde5, NULL, &imgDestRect);
													de_pos[i] = 0;
												break;
											}
										}
										imgDestRect.x += 100;
										img2DestRect.x += 100;
									}
									msgDestRect.x = 375;
									msgDestRect.y = 200;

									/* Affichage message de relancer */
									msg = TTF_RenderUTF8_Blended(police_score, "Veuillez choisir une case a remplir ou selectionner les des a garder", blanc);
									if(!msg){
										fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
										exit(EXIT_FAILURE);
									}

									SDL_Texture *msg_tex = SDL_CreateTextureFromSurface(renderer, msg);
									if(!msg_tex){
										fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
										exit(EXIT_FAILURE);
									}

									SDL_QueryTexture(msg_tex, NULL, NULL, &(msgDestRect.w), &(msgDestRect.h));
									SDL_RenderCopy(renderer, msg_tex, NULL, &msgDestRect);

									/* Test des combinaisons possibles avec la main courante */
									j_choix = test_mains(*ptj,j_choix);

									scoreDestRect.x = 202;
									caseDestRect.x = 184;
									caseDestRect.y = scoreDestRect.y = 80;

									/* Affichage des scores possibles en rouge dans la grille */
									for(i = 0; i < 14; i++){

										if(i == 6){
											caseDestRect.y = (scoreDestRect.y += 48);
										}

										else{

											if((*ptj)->tab[i] == VAL_INIT){
												SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
												SDL_RenderFillRect(renderer,&caseDestRect);
												if(j_choix->tab[i] != VAL_INIT){

													sprintf(score,"%d",j_choix->tab[i]);
													caseJ = TTF_RenderUTF8_Blended(police_score, score, rouge);
													if(!caseJ){
													fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
														exit(EXIT_FAILURE);
													}

													caseJ_tex = SDL_CreateTextureFromSurface(renderer, caseJ);
													if(!caseJ_tex){
														fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
														exit(EXIT_FAILURE);
													}

													SDL_QueryTexture(caseJ_tex, NULL, NULL, &(scoreDestRect.w), &(scoreDestRect.h));
													SDL_RenderCopy(renderer, caseJ_tex, NULL, &(scoreDestRect));
												}
											}
										}
										caseDestRect.y = (scoreDestRect.y += 29);
									}

									SDL_RenderPresent(renderer);
									cpt_lancer++;


								}

								clic_borneG_x = 400;
								clic_borneD_x = 450;

								/* Boucle permettant de mettre des dés de côté et inversement pour le relancement (si de_pos[i] = 0 : le dé n'est pas mis de côté, si de_pos[i] = 1 : le dé est mis de côté) */
								for(i = 0; i < 5; i++){

									/* Clic sur un dé qui n'est pas mis de côté */
									if(e.motion.x > clic_borneG_x && e.motion.x < clic_borneD_x && e.motion.y > 300 && e.motion.y < 350 && de_pos[i] == 0){

										imgDestRect.x = clic_borneG_x;
										imgDestRect.y = 300;

				          				SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
										SDL_RenderFillRect(renderer,&imgDestRect);

				 						imgDestRect.y = 600;

										SDL_QueryTexture(*pt_image_texde[i], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
										SDL_RenderCopy(renderer, *pt_image_texde[i], NULL, &imgDestRect);
										SDL_RenderPresent(renderer);

										/* Le dé est mis de côté */
										de_pos[i] = 1;
									}

									/* Clic sur un dé qui est mis de côté */
									else if(e.motion.x > clic_borneG_x && e.motion.x < clic_borneD_x && e.motion.y > 600 && e.motion.y < 650 && de_pos[i] == 1){

										imgDestRect.x = clic_borneG_x;
										imgDestRect.y = 600;

				            			SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
										SDL_RenderFillRect(renderer,&imgDestRect);

				 						imgDestRect.y = 300;

										SDL_QueryTexture(*pt_image_texde[i], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
										SDL_RenderCopy(renderer, *pt_image_texde[i], NULL, &imgDestRect);
										SDL_RenderPresent(renderer);

										/* Le dé n'est plus mis de côté */
										de_pos[i] = 0;
									}

									clic_borneG_x += 100;
									clic_borneD_x += 100;
								}

								scoreDestRect.x = 202;
								caseDestRect.x = 184;
								caseDestRect.y = scoreDestRect.y = 80;

								clic_borneG_x = caseDestRect.x;
								clic_borneD_x = 233;
								clic_borneS_y = 80;
								clic_borneI_y = 107;

								coup = 0;
								p = 0;

								/* Boucle permettant de jouer le tour actuel (remplir une case de la grille) */
								while(p < 14 && coup == 0){

									if(p == 6){
										clic_borneS_y += 48;
										clic_borneI_y += 48;
										scoreDestRect.y += 48;
									}
									else{

										/* Clic sur une des cases de la grille */
										if(e.motion.x > clic_borneG_x && e.motion.x < clic_borneD_x && e.motion.y > clic_borneS_y && e.motion.y < clic_borneI_y && cpt_lancer != 0 && j1->des[0] != 0 && (*ptj)->tab[p] == VAL_INIT){

											/* La case vaudra 0 s'il n'y a pas de combinaison possible */
											if(j_choix->tab[p] == VAL_INIT)
												(*ptj)->tab[p] = 0;
											else
												(*ptj)->tab[p] = j_choix->tab[p];

											/* Nettoyage des cases qui n'ont pas été remplies */
											for(i = 0; i < 14; i++){
												if(i == 7)
													caseDestRect.y += 48;

												if((*ptj)->tab[i] == VAL_INIT){
													SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
													SDL_RenderFillRect(renderer,&caseDestRect);
												}

												caseDestRect.y += 29;
											}

											/* Remplissage de la case sur laquelle le joueur a cliqué avec le score correspondant */
											sprintf(score,"%d",(*ptj)->tab[p]);
											caseJ = TTF_RenderUTF8_Blended(police_score, score, noir);
											if(!caseJ){
											fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
												exit(EXIT_FAILURE);
											}

											caseJ_tex = SDL_CreateTextureFromSurface(renderer, caseJ);
											if(!caseJ_tex){
												fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
												exit(EXIT_FAILURE);
											}

											SDL_QueryTexture(caseJ_tex, NULL, NULL, &(scoreDestRect.w), &(scoreDestRect.h));
											SDL_RenderCopy(renderer, caseJ_tex, NULL, &(scoreDestRect));

											SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
											SDL_RenderFillRect(renderer,&clearDestRect);

											SDL_RenderPresent(renderer);

											cpt_lancer = 0;
											coup = 1;

											/* Changement de joueur courant */
											if(ptj == &j1)
												ptj = &j2;

										}
									}

									scoreDestRect.y += 29;
									clic_borneS_y += 29;
									clic_borneI_y += 29;
									p++;

								}
							}
						}

					break;

				}
			}
		}
	}
	else {
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

	/* Destruction des joueurs */
	detruire_joueur(&j1);
	detruire_joueur(&j2);
	detruire_joueur(&j_choix);

	/* Libération des surfaces */
	SDL_FreeSurface(caseJ);
	SDL_FreeSurface(de1);
	SDL_FreeSurface(de2);
	SDL_FreeSurface(de3);
	SDL_FreeSurface(de4);
	SDL_FreeSurface(de5);
	SDL_FreeSurface(de6);

	/* Destruction de la fenetre */
	SDL_DestroyWindow(pWindow);

	TTF_CloseFont(police_score); /* Doit être avant TTF_Quit() */
	TTF_CloseFont(police_jeu);
	TTF_Quit();
  	SDL_Quit();

    return 0;
}


/**
	*\fn int aff2_joueurs()
	*\brief Fonction permettant l'affichage du jeu avec 2 humains
  *\author Sunny Biard
*/
int aff2_joueurs() {
 	t_joueur * j1 = creer_joueur("J1");
	t_joueur * j2 = creer_joueur("J2");
	t_joueur * j_choix = creer_joueur("Choix"); /* Joueur temporaire permettant de stocker les combinaisons possibles du joueur pour chaque tour */
	t_joueur ** ptj = &j1;

	int cpt_lancer = 0, de_pos[5] = {0,0,0,0,0}, clic_borneG_x, clic_borneD_x, clic_borneS_y, clic_borneI_y, coup, i, p;
	char  score[20], msg_fin[50];

	SDL_Window *pWindow = NULL;

  	SDL_Surface *j_courant=NULL, *msg=NULL, *tab_score=NULL, *de_courant=NULL, *de1=NULL, *de2=NULL, *de3=NULL, *de4=NULL, *de5=NULL, *de6=NULL, *img_btn_lancer=NULL, *caseJ=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect clearDestRect, j_courantDestRect, msgDestRect, imgDestRect, img2DestRect, scoreDestRect, caseDestRect;

	caseDestRect.w = 49;
	caseDestRect.h = 27;

	img2DestRect.w = 50;
	img2DestRect.h = 50;

	j_courantDestRect.x = 620;
	j_courantDestRect.y = 50;
	j_courantDestRect.w = 100;
	j_courantDestRect.h = 100;

	clearDestRect.x = 300;
	clearDestRect.y = 0;
	clearDestRect.w = 700;
	clearDestRect.h = 700;

	SDL_Texture *image_texde1, *image_texde2, *image_texde3, *image_texde4, *image_texde5, *caseJ_tex;
	SDL_Texture **pt_image_texde[5] = {&image_texde1,&image_texde2,&image_texde3,&image_texde4,&image_texde5};

	TTF_Font *police_jeu = NULL, *police_score = NULL;

	SDL_Color blanc = {255, 255, 255};
	SDL_Color noir = {0, 0, 0};
	SDL_Color rouge = {255, 0, 0};

 	/* Initialisation simple */
  if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
  	fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
    return -1;
  }

	/* Initialisation TTF */
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}


	/* Création de la fenêtre */
	pWindow = SDL_CreateWindow("Yahtzee",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 750, SDL_WINDOW_SHOWN);

	if(!pWindow){
		fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}

	/* Initialisation des polices */
	if( (police_score = TTF_OpenFont("../src/coolvetica rg.ttf", 20)) == NULL){
		fprintf(stderr, "Erreur au chargement de la police\n");
		exit(EXIT_FAILURE);
	}

	if( (police_jeu = TTF_OpenFont("../src/coolvetica rg.ttf", 35)) == NULL){
		fprintf(stderr, "Erreur au chargement de la police\n");
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// load sample.png into image
	SDL_RWops *rwopscore=SDL_RWFromFile("../src/img/score.png", "rb");
	tab_score=IMG_LoadPNG_RW(rwopscore);
	if(!tab_score) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_Texture *tab_score_tex = SDL_CreateTextureFromSurface(renderer, tab_score);
	if(!tab_score_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(tab_score); /* on a la texture, plus besoin de l'image */

	SDL_RWops *rwopde1=SDL_RWFromFile("../src/img/de1.png", "rb");
	de1=IMG_LoadPNG_RW(rwopde1);
	if(!de1) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde2=SDL_RWFromFile("../src/img/de2.png", "rb");
	de2=IMG_LoadPNG_RW(rwopde2);
	if(!de2) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde3=SDL_RWFromFile("../src/img/de3.png", "rb");
	de3=IMG_LoadPNG_RW(rwopde3);
	if(!de3) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde4=SDL_RWFromFile("../src/img/de4.png", "rb");
	de4=IMG_LoadPNG_RW(rwopde4);
	if(!de4) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde5=SDL_RWFromFile("../src/img/de5.png", "rb");
	de5=IMG_LoadPNG_RW(rwopde5);
	if(!de5) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde6=SDL_RWFromFile("../src/img/de6.png", "rb");
	de6=IMG_LoadPNG_RW(rwopde6);
	if(!de6) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwop_btn_lancer=SDL_RWFromFile("../src/img/btn_lancer.png", "rb");
	img_btn_lancer=IMG_LoadPNG_RW(rwop_btn_lancer);
	if(!img_btn_lancer) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_Texture *btn_lancer_tex = SDL_CreateTextureFromSurface(renderer, img_btn_lancer);
	if(!btn_lancer_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(img_btn_lancer); /* on a la texture, plus besoin de l'image */

	if(pWindow){
		int running = 1;
		/* Boucle de jeu */
		while(running){
			SDL_Event e;
			while(SDL_PollEvent(&e)){
				switch(e.type) {
					/* Fermeture de la fenêtre */
					case SDL_QUIT:
						running = 0;
					break;

					/* Ouverture de la fenêtre */
					case SDL_WINDOWEVENT:
						switch(e.window.event){
							case SDL_WINDOWEVENT_SHOWN:
								/* Le fond de la fenêtre sera vert */
			        			SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
								SDL_RenderClear(renderer);

			        			/* Ajout du texte en noir */
			        			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

			      				imgDestRect.x = 10;
								imgDestRect.y = 50;

								SDL_QueryTexture(tab_score_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, tab_score_tex, NULL, &imgDestRect);

								imgDestRect.x = 575;
								imgDestRect.y = 500;

								SDL_QueryTexture(btn_lancer_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, btn_lancer_tex, NULL, &imgDestRect);

								/* Rendu */
								SDL_RenderPresent(renderer);

							break;
						}
					break;

					/* Relachement de souris */
					case SDL_MOUSEBUTTONUP:

						/* Fin de partie */
						if(fin_de_partie(j1) && fin_de_partie(j2)){

							scoreDestRect.x = 202;
							caseDestRect.x = 184;
							caseDestRect.y = scoreDestRect.y = 254;
							i = 6;

							/* Affichage des totaux dans la grille du joueur 1 */
							while(i < 17){

								SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
								SDL_RenderFillRect(renderer,&caseDestRect);
								sprintf(score,"%d",j1->tab[i]);
								caseJ = TTF_RenderUTF8_Blended(police_score, score, noir);
								if(!caseJ){
									fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								caseJ_tex = SDL_CreateTextureFromSurface(renderer, caseJ);
								if(!caseJ_tex){
									fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								SDL_QueryTexture(caseJ_tex, NULL, NULL, &(scoreDestRect.w), &(scoreDestRect.h));
								SDL_RenderCopy(renderer, caseJ_tex, NULL, &(scoreDestRect));

								caseDestRect.y = (scoreDestRect.y += 29);

								if(i == 14){
									caseDestRect.y = (scoreDestRect.y += 222);
								}

								if(i == 6)
									i = 14;
								else
									i++;
							}

							scoreDestRect.x = 252;
							caseDestRect.x = 234;
							caseDestRect.y = scoreDestRect.y = 254;
							i = 6;

							/* Affichage des totaux dans la grille du joueur 2 */
							while(i < 17){

								SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
								SDL_RenderFillRect(renderer,&caseDestRect);
								sprintf(score,"%d",j2->tab[i]);
								caseJ = TTF_RenderUTF8_Blended(police_score, score, noir);
								if(!caseJ){
									fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								caseJ_tex = SDL_CreateTextureFromSurface(renderer, caseJ);
								if(!caseJ_tex){
									fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								SDL_QueryTexture(caseJ_tex, NULL, NULL, &(scoreDestRect.w), &(scoreDestRect.h));
								SDL_RenderCopy(renderer, caseJ_tex, NULL, &(scoreDestRect));

								caseDestRect.y = (scoreDestRect.y += 29);

								if(i == 14){
									caseDestRect.y = (scoreDestRect.y += 222);
								}

								if(i == 6)
									i = 14;
								else
									i++;
							}

							SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
							SDL_RenderFillRect(renderer,&clearDestRect);

							msgDestRect.x = 310;
							msgDestRect.y = 300;

							/* Affichage message de fin de partie */
							if(j1->tab[16] > j2->tab[16])
								sprintf(msg_fin,"Le joueur %s a gagné avec %d points !",j1->nom,j1->tab[16]);
							else if(j1->tab[16] < j2->tab[16])
								sprintf(msg_fin,"Le joueur %s a gagné avec %d points !",j2->nom,j2->tab[16]);
							else
								sprintf(msg_fin,"Egalité !");

							msg = TTF_RenderUTF8_Blended(police_jeu, msg_fin, blanc);
							if(!msg){
								fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
								exit(EXIT_FAILURE);
							}

							SDL_Texture *msg_tex = SDL_CreateTextureFromSurface(renderer, msg);
							if(!msg_tex){
								fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
								exit(EXIT_FAILURE);
							}

							SDL_QueryTexture(msg_tex, NULL, NULL, &(msgDestRect.w), &(msgDestRect.h));
							SDL_RenderCopy(renderer, msg_tex, NULL, &msgDestRect);

							SDL_RenderPresent(renderer);
						}
					break;

					/* Clic de souris */
					case SDL_MOUSEBUTTONDOWN:

						if(!fin_de_partie(j1) || !fin_de_partie(j2)){

							/* Clic sur le bouton lancer en ayant fait au maximum 2 lancers auparavant */
							if(e.motion.x > 575 && e.motion.x < 675 && e.motion.y > 500 && e.motion.y < 550 && cpt_lancer < 3){

								/* Affichage joueur courant */
								SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
								SDL_RenderFillRect(renderer,&j_courantDestRect);

								sprintf(score,"%s",(*ptj)->nom);
								j_courant = TTF_RenderUTF8_Blended(police_jeu, score, blanc);
								if(!j_courant){
									fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								SDL_Texture *j_courant_tex = SDL_CreateTextureFromSurface(renderer, j_courant);
								if(!j_courant_tex){
									fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								SDL_QueryTexture(j_courant_tex, NULL, NULL, &(j_courantDestRect.w), &(j_courantDestRect.h));
								SDL_RenderCopy(renderer, j_courant_tex, NULL, &j_courantDestRect);

								imgDestRect.x = img2DestRect.x = 400;
				 				imgDestRect.y = 300;
								img2DestRect.y = 600;

								/* Boucle de lancer des dés */
								for(int i = 0; i < 5; i++){
									if(de_pos[i] == 0 || cpt_lancer == 0){
										lancer(*ptj,i);
										/* Récupération de la valeur du dé courant (entre 1 et 6) */
										switch((*ptj)->des[i]){
											case 1:
												de_courant = de1;
											break;
											case 2:
												de_courant = de2;
											break;
											case 3:
												de_courant = de3;
											break;
											case 4:
												de_courant = de4;
											break;
											case 5:
												de_courant = de5;
											break;
											case 6:
												de_courant = de6;
											break;
										}
										/* Affichage de l'image du dé courant */
										switch(i){
											case 0:
												SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
												SDL_RenderFillRect(renderer,&img2DestRect);
							 					image_texde1 = SDL_CreateTextureFromSurface(renderer, de_courant);
												if(!image_texde1){
													fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
													exit(EXIT_FAILURE);
												}
							 					SDL_QueryTexture(image_texde1, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
							 					SDL_RenderCopy(renderer, image_texde1, NULL, &imgDestRect);
												de_pos[i] = 0;
											break;
											case 1:
												SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
												SDL_RenderFillRect(renderer,&img2DestRect);
							 					image_texde2 = SDL_CreateTextureFromSurface(renderer, de_courant);
												if(!image_texde2){
													fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
													exit(EXIT_FAILURE);
												}
												SDL_QueryTexture(image_texde2, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
							 					SDL_RenderCopy(renderer, image_texde2, NULL, &imgDestRect);
												de_pos[i] = 0;
											break;
											case 2:
												SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
												SDL_RenderFillRect(renderer,&img2DestRect);
							 					image_texde3 = SDL_CreateTextureFromSurface(renderer, de_courant);
												if(!image_texde3){
													fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
													exit(EXIT_FAILURE);
												}
												SDL_QueryTexture(image_texde3, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
							 					SDL_RenderCopy(renderer, image_texde3, NULL, &imgDestRect);
												de_pos[i] = 0;
											break;
											case 3:
												SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
												SDL_RenderFillRect(renderer,&img2DestRect);
							 					image_texde4 = SDL_CreateTextureFromSurface(renderer, de_courant);
												if(!image_texde4){
													fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
													exit(EXIT_FAILURE);
												}
							 					SDL_QueryTexture(image_texde4, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
							 					SDL_RenderCopy(renderer, image_texde4, NULL, &imgDestRect);
												de_pos[i] = 0;
											break;
											case 4:
												SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
												SDL_RenderFillRect(renderer,&img2DestRect);
							 					image_texde5 = SDL_CreateTextureFromSurface(renderer, de_courant);
												if(!image_texde5){
													fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
													exit(EXIT_FAILURE);
												}
												SDL_QueryTexture(image_texde5, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
							 					SDL_RenderCopy(renderer, image_texde5, NULL, &imgDestRect);
												de_pos[i] = 0;
											break;
										}
									}
									imgDestRect.x += 100;
									img2DestRect.x += 100;
								}
								msgDestRect.x = 375;
								msgDestRect.y = 200;

								/* Affichage message de relancer */
								msg = TTF_RenderUTF8_Blended(police_score, "Veuillez choisir une case a remplir ou selectionner les des a garder", blanc);
								if(!msg){
									fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								SDL_Texture *msg_tex = SDL_CreateTextureFromSurface(renderer, msg);
								if(!msg_tex){
									fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								SDL_QueryTexture(msg_tex, NULL, NULL, &(msgDestRect.w), &(msgDestRect.h));
								SDL_RenderCopy(renderer, msg_tex, NULL, &msgDestRect);

								/* Test des combinaisons possibles avec la main courante */
								j_choix = test_mains(*ptj,j_choix);

								if(ptj == &j1){
									scoreDestRect.x = 202;
									caseDestRect.x = 184;
								}
								else{
									scoreDestRect.x = 252;
									caseDestRect.x = 234;
								}
								caseDestRect.y = scoreDestRect.y = 80;

								/* Affichage des scores possibles en rouge dans la grille */
								for(i = 0; i < 14; i++){

									if(i == 6){
										caseDestRect.y = (scoreDestRect.y += 48);
									}

									else{

										if((*ptj)->tab[i] == VAL_INIT){
											SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
											SDL_RenderFillRect(renderer,&caseDestRect);
											if(j_choix->tab[i] != VAL_INIT){

												sprintf(score,"%d",j_choix->tab[i]);
												caseJ = TTF_RenderUTF8_Blended(police_score, score, rouge);
												if(!caseJ){
												fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
													exit(EXIT_FAILURE);
												}

												caseJ_tex = SDL_CreateTextureFromSurface(renderer, caseJ);
												if(!caseJ_tex){
													fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
													exit(EXIT_FAILURE);
												}

												SDL_QueryTexture(caseJ_tex, NULL, NULL, &(scoreDestRect.w), &(scoreDestRect.h));
												SDL_RenderCopy(renderer, caseJ_tex, NULL, &(scoreDestRect));
											}
										}
									}
									caseDestRect.y = (scoreDestRect.y += 29);
								}

								SDL_RenderPresent(renderer);
								cpt_lancer++;


							}

							clic_borneG_x = 400;
							clic_borneD_x = 450;

							/* Boucle permettant de mettre des dés de côté et inversement pour le relancement (si de_pos[i] = 0 : le dé n'est pas mis de côté, si de_pos[i] = 1 : le dé est mis de côté) */
							for(i = 0; i < 5; i++){

								/* Clic sur un dé qui n'est pas mis de côté */
								if(e.motion.x > clic_borneG_x && e.motion.x < clic_borneD_x && e.motion.y > 300 && e.motion.y < 350 && de_pos[i] == 0){

									imgDestRect.x = clic_borneG_x;
									imgDestRect.y = 300;

				          			SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
									SDL_RenderFillRect(renderer,&imgDestRect);

				 					imgDestRect.y = 600;

									SDL_QueryTexture(*pt_image_texde[i], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
									SDL_RenderCopy(renderer, *pt_image_texde[i], NULL, &imgDestRect);
									SDL_RenderPresent(renderer);

									/* Le dé est mis de côté */
									de_pos[i] = 1;
								}

								/* Clic sur un dé qui est mis de côté */
								else if(e.motion.x > clic_borneG_x && e.motion.x < clic_borneD_x && e.motion.y > 600 && e.motion.y < 650 && de_pos[i] == 1){

									imgDestRect.x = clic_borneG_x;
									imgDestRect.y = 600;

				            		SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
									SDL_RenderFillRect(renderer,&imgDestRect);

				 					imgDestRect.y = 300;

									SDL_QueryTexture(*pt_image_texde[i], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
									SDL_RenderCopy(renderer, *pt_image_texde[i], NULL, &imgDestRect);
									SDL_RenderPresent(renderer);

									/* Le dé n'est plus mis de côté */
									de_pos[i] = 0;
								}

								clic_borneG_x += 100;
								clic_borneD_x += 100;
							}

							if(ptj == &j1){
								scoreDestRect.x = 202;
								caseDestRect.x = 184;
								clic_borneD_x = 233;
							}
							else{
								scoreDestRect.x = 252;
								caseDestRect.x = 234;
								clic_borneD_x = 283;
							}

							clic_borneG_x = caseDestRect.x;

							caseDestRect.y = scoreDestRect.y = 80;
							clic_borneS_y = 80;
							clic_borneI_y = 107;
							coup = 0;
							p = 0;

							/* Boucle permettant de jouer le tour actuel (remplir une case de la grille) */
							while(p < 14 && coup == 0){

								if(p == 6){
									clic_borneS_y += 48;
									clic_borneI_y += 48;
									scoreDestRect.y += 48;
								}
								else{

									/* Clic sur une des cases de la grille */
									if(e.motion.x > clic_borneG_x && e.motion.x < clic_borneD_x && e.motion.y > clic_borneS_y && e.motion.y < clic_borneI_y && cpt_lancer != 0 && j1->des[0] != 0 && (*ptj)->tab[p] == VAL_INIT){

										/* La case vaudra 0 s'il n'y a pas de combinaison possible */
										if(j_choix->tab[p] == VAL_INIT)
											(*ptj)->tab[p] = 0;
										else
											(*ptj)->tab[p] = j_choix->tab[p];

										/* Nettoyage des cases qui n'ont pas été remplies */
										for(i = 0; i < 14; i++){
											if(i == 7)
												caseDestRect.y += 48;

											if((*ptj)->tab[i] == VAL_INIT){
												SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
												SDL_RenderFillRect(renderer,&caseDestRect);
											}
											caseDestRect.y += 29;
										}

										/* Remplissage de la case sur laquelle le joueur a cliqué avec le score correspondant */
										sprintf(score,"%d",(*ptj)->tab[p]);
										caseJ = TTF_RenderUTF8_Blended(police_score, score, noir);
										if(!caseJ){
										fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
											exit(EXIT_FAILURE);
										}

										caseJ_tex = SDL_CreateTextureFromSurface(renderer, caseJ);
										if(!caseJ_tex){
											fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
											exit(EXIT_FAILURE);
										}

										SDL_QueryTexture(caseJ_tex, NULL, NULL, &(scoreDestRect.w), &(scoreDestRect.h));
										SDL_RenderCopy(renderer, caseJ_tex, NULL, &(scoreDestRect));

										SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
										SDL_RenderFillRect(renderer,&clearDestRect);

										imgDestRect.x = 575;
										imgDestRect.y = 500;

										SDL_QueryTexture(btn_lancer_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
										SDL_RenderCopy(renderer, btn_lancer_tex, NULL, &imgDestRect);

										SDL_RenderPresent(renderer);

										cpt_lancer = 0;
										coup = 1;

										/* Changement de joueur courant */
										if(ptj == &j1)
											ptj = &j2;
										else
											ptj = &j1;
									}
								}

								scoreDestRect.y += 29;
								clic_borneS_y += 29;
								clic_borneI_y += 29;
								p++;

							}
						}

					break;

				}
			}
		}
	}
	else {
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

	/* Destruction des joueurs */
	detruire_joueur(&j1);
	detruire_joueur(&j2);
	detruire_joueur(&j_choix);

	/* Libération des surfaces */
	SDL_FreeSurface(caseJ);
	SDL_FreeSurface(de1);
	SDL_FreeSurface(de2);
	SDL_FreeSurface(de3);
	SDL_FreeSurface(de4);
	SDL_FreeSurface(de5);
	SDL_FreeSurface(de6);

	/* Destruction de la fenetre */
	SDL_DestroyWindow(pWindow);

	TTF_CloseFont(police_score); /* Doit être avant TTF_Quit() */
	TTF_CloseFont(police_jeu);
	TTF_Quit();
  	SDL_Quit();

    return 0;
}
