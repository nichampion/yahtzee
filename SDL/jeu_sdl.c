#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

int main(int argc, char** argv)
{
		int i = 0;
		//score J1
		char score_j1[17] = {0};
		char score_j2[17];
		//grille des possibilités du joueur	après lancement
	char possible_j1[17];
	char possible_j2[17];
    //Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;
	//Le pointeur vers la surface incluse dans la fenetre
    SDL_Surface *texte=NULL, *image=NULL, *de1=NULL, *de2=NULL, *de3=NULL, *de4=NULL, *de5=NULL, *de6=NULL, *case1=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect txtDestRect,imgDestRect, caseDestRect;

	// Le pointeur vers notre police
	TTF_Font *police = NULL;
	// Une variable de couleur noire
	SDL_Color couleurNoire = {0, 0, 0};

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
	pWindow = SDL_CreateWindow("Yahtzee",SDL_WINDOWPOS_UNDEFINED,
												  SDL_WINDOWPOS_UNDEFINED,
												  1000,
												  750,
												  SDL_WINDOW_SHOWN);

	if(!pWindow){
		fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}


	if( (police = TTF_OpenFont("ChowFun.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}

	texte = TTF_RenderUTF8_Blended(police, "Partie :", couleurNoire);
	if(!texte){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	case1 = TTF_RenderUTF8_Blended(police, "0", couleurNoire);
	if(!case1){
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

	SDL_FreeSurface(case1);
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






	if( pWindow )
	{
		int running = 1;
		while(running) {
			SDL_Event e;
			while(SDL_PollEvent(&e)) {
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

								imgDestRect.x = 300;
 								imgDestRect.y = 300;
 								SDL_QueryTexture(image_texde1, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
 								SDL_RenderCopy(renderer, image_texde1, NULL, &imgDestRect);

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

								//SDL_Delay(1000);



                                /* On fait le rendu ! */


                                SDL_RenderPresent(renderer);

							break;
						}
						break;
						case SDL_MOUSEBUTTONDOWN:
						//	running = 0;
							if(e.motion.x > 300 && e.motion.x < 350 && e.motion.y > 300 && e.motion.y < 350){

								fprintf(stdout, "Un appui sur le dé :\n");


								SDL_Texture *image_texde1 = SDL_CreateTextureFromSurface(renderer, de2);
								if(!image_texde1){
									fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
									exit(EXIT_FAILURE);
								}

								imgDestRect.x = 300;
 								imgDestRect.y = 300;

								SDL_QueryTexture(image_texde1, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, image_texde1, NULL, &imgDestRect);

								SDL_RenderPresent(renderer);

								}
									break;
						}
				}
			}
	} else {
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
