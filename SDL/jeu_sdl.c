#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

int main(int argc, char** argv)
{
	int i = 0;
		//score J1
	char * score_j1[17] = {"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"};
	char * score_j2[17] = {"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"};
		//grille des possibilités du joueur	après lancement
	char * possible_j1[17] = {"x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x"} ;
	char * possible_j2[17] = {"x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x"} ;
    //Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;
	//Le pointeur vers la surface incluse dans la fenetre
  SDL_Surface *texte=NULL, *image=NULL, *de1=NULL, *de2=NULL, *de3=NULL, *de4=NULL, *de5=NULL, *de6=NULL, *img_btn_lancer=NULL, *case1=NULL, *case2=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect txtDestRect,imgDestRect, caseDestRect;

	// Le pointeur vers notre police
	TTF_Font *police = NULL;
	// Une variable de couleur noire
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurRouge = {255, 0, 0};

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


	if( (police = TTF_OpenFont("Bebas-Regular.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}

	texte = TTF_RenderUTF8_Blended(police, "Partie :", couleurNoire);
	if(!texte){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	case1 = TTF_RenderUTF8_Blended(police, score_j1[0], couleurNoire);
	if(!case1){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	case2 = TTF_RenderUTF8_Blended(police, score_j2[0], couleurNoire);
	if(!case2){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte);
	if(!texte_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Texture *case1_tex = SDL_CreateTextureFromSurface(renderer, case1);
	if(!case1_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Texture *case2_tex = SDL_CreateTextureFromSurface(renderer, case2);
	if(!case2_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(case1);
	SDL_FreeSurface(case2);
	SDL_FreeSurface(texte); /* on a la texture, plus besoin du texte */
	/* Position ou sera mis le texte dans la fenêtre */
  txtDestRect.x = txtDestRect.y = 10;
	SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

	// load sample.png into image
	SDL_RWops *rwop=SDL_RWFromFile("img/score.png", "rb");
	image=IMG_LoadPNG_RW(rwop);
	if(!image) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_Texture *image_tex = SDL_CreateTextureFromSurface(renderer, image);
	if(!image_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(image); /* on a la texture, plus besoin de l'image */

	SDL_RWops *rwopde1=SDL_RWFromFile("img/de1.png", "rb");
	de1=IMG_LoadPNG_RW(rwopde1);
	if(!de1) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde2=SDL_RWFromFile("img/de2.png", "rb");
	de2=IMG_LoadPNG_RW(rwopde2);
	if(!de2) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde3=SDL_RWFromFile("img/de3.png", "rb");
	de3=IMG_LoadPNG_RW(rwopde3);
	if(!de3) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde4=SDL_RWFromFile("img/de4.png", "rb");
	de4=IMG_LoadPNG_RW(rwopde4);
	if(!de4) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde5=SDL_RWFromFile("img/de5.png", "rb");
	de5=IMG_LoadPNG_RW(rwopde5);
	if(!de5) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	SDL_RWops *rwopde6=SDL_RWFromFile("img/de6.png", "rb");
	de6=IMG_LoadPNG_RW(rwopde6);
	if(!de6) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}


	SDL_Texture *image_texde1 = SDL_CreateTextureFromSurface(renderer, de1);
	if(!image_texde1){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Texture *image_texde2 = SDL_CreateTextureFromSurface(renderer, de1);
	if(!image_texde2){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Texture *image_texde3 = SDL_CreateTextureFromSurface(renderer, de1);
	if(!image_texde3){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Texture *image_texde4 = SDL_CreateTextureFromSurface(renderer, de1);
	if(!image_texde4){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Texture *image_texde5 = SDL_CreateTextureFromSurface(renderer, de1);
	if(!image_texde5){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_RWops *rwop_btn=SDL_RWFromFile("img/btn_lancer.png", "rb");
	img_btn_lancer=IMG_LoadPNG_RW(rwop_btn);
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
		while(running){
		SDL_Event e;
		while(SDL_PollEvent(&e)){
			switch(e.type) {
				case SDL_QUIT: running = 0;
				break;

				case SDL_WINDOWEVENT:
					switch(e.window.event){
						case SDL_WINDOWEVENT_EXPOSED:
						case SDL_WINDOWEVENT_SHOWN:
								/* Le fond de la fenêtre sera vert */
              SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
							SDL_RenderClear(renderer);

              	/* Ajout du texte en noir */
              SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
							txtDestRect.x = txtDestRect.y = 10;
              SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);


                /* Ajout de l'image à une certaine position */
      				imgDestRect.x = 10;
							imgDestRect.y = 50;
							SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
							SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);

							imgDestRect.x = 400;
 							imgDestRect.y = 300;
 							SDL_QueryTexture(image_texde1, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
 							SDL_RenderCopy(renderer, image_texde1, NULL, &imgDestRect);

							imgDestRect.x = 500;
 							imgDestRect.y = 300;
 							SDL_QueryTexture(image_texde2, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
 							SDL_RenderCopy(renderer, image_texde2, NULL, &imgDestRect);

							imgDestRect.x = 600;
 							imgDestRect.y = 300;
 							SDL_QueryTexture(image_texde3, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
 							SDL_RenderCopy(renderer, image_texde3, NULL, &imgDestRect);

							imgDestRect.x = 700;
 							imgDestRect.y = 300;
 							SDL_QueryTexture(image_texde4, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
 							SDL_RenderCopy(renderer, image_texde4, NULL, &imgDestRect);

							imgDestRect.x = 800;
 							imgDestRect.y = 300;
 							SDL_QueryTexture(image_texde5, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
 							SDL_RenderCopy(renderer, image_texde5, NULL, &imgDestRect);

							caseDestRect.x = 200;
						 	caseDestRect.y = 78;
							for(i = 0; i <=7; i++){
								SDL_QueryTexture(case1_tex, NULL, NULL, &(caseDestRect.w), &(caseDestRect.h));
								SDL_RenderCopy(renderer, case1_tex, NULL, &(caseDestRect));
								caseDestRect.y += 29;
								}

								caseDestRect.y += 19;
								for(i = 0; i <=7; i++){
									SDL_QueryTexture(case1_tex, NULL, NULL, &(caseDestRect.w), &(caseDestRect.h));
									SDL_RenderCopy(renderer, case1_tex, NULL, &(caseDestRect));
									caseDestRect.y += 29;
								}

								caseDestRect.y += 19;
								SDL_QueryTexture(case1_tex, NULL, NULL, &(caseDestRect.w), &(caseDestRect.h));
								SDL_RenderCopy(renderer, case1_tex, NULL, &(caseDestRect));

								/* POUR JOUEUR 2 */
								caseDestRect.x = 250;
							 	caseDestRect.y = 78;
								for(i = 0; i <=7; i++){
									SDL_QueryTexture(case2_tex, NULL, NULL, &(caseDestRect.w), &(caseDestRect.h));
									SDL_RenderCopy(renderer, case2_tex, NULL, &(caseDestRect));
									caseDestRect.y += 29;
								}

								caseDestRect.y += 19;
								for(i = 0; i <=7; i++){
									SDL_QueryTexture(case2_tex, NULL, NULL, &(caseDestRect.w), &(caseDestRect.h));
									SDL_RenderCopy(renderer, case2_tex, NULL, &(caseDestRect));
									caseDestRect.y += 29;
								}

								caseDestRect.y += 19;
								SDL_QueryTexture(case2_tex, NULL, NULL, &(caseDestRect.w), &(caseDestRect.h));
								SDL_RenderCopy(renderer, case2_tex, NULL, &(caseDestRect));


								imgDestRect.x = 575;
								imgDestRect.y = 500;
								SDL_QueryTexture(btn_lancer_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, btn_lancer_tex, NULL, &imgDestRect);
								//SDL_Delay(1000);

              /* On fait le rendu ! */
              	SDL_RenderPresent(renderer);
								break;
						}

						break;

						case SDL_MOUSEBUTTONDOWN:
						//	running = 0;
							if(e.motion.x > 400 && e.motion.x < 450 && e.motion.y > 300 && e.motion.y < 350){

								SDL_Texture *image_texde1 = SDL_CreateTextureFromSurface(renderer, de2);
								if(!image_texde1){
									fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								imgDestRect.x = 400;
 								imgDestRect.y = 300;

								SDL_QueryTexture(image_texde1, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, image_texde1, NULL, &imgDestRect);

								SDL_RenderPresent(renderer);

							}
			break;
			}
		}
	}
	}
	else {
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

	SDL_FreeSurface(de1); /* on a la texture, plus besoin de l'image */
	SDL_FreeSurface(de2); /* on a la texture, plus besoin de l'image */
	SDL_FreeSurface(de3); /* on a la texture, plus besoin de l'image */
	SDL_FreeSurface(de4); /* on a la texture, plus besoin de l'image */
	SDL_FreeSurface(de5); /* on a la texture, plus besoin de l'image */
	SDL_FreeSurface(de6); /* on a la texture, plus besoin de l'image */

	//Destruction de la fenetre
	SDL_DestroyWindow(pWindow);

	TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
	TTF_Quit();
    SDL_Quit();

    return 0;
}
