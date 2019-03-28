#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

int main(int argc, char** argv)
{
	SDL_Window *pWindow = NULL;
	SDL_Surface *pScreen = NULL;

  SDL_Surface *logo = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Rect logoDestRect;


	SDL_Texture *logo_tex;


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

	// load sample.png into image
	SDL_RWops *rwoplogo=SDL_RWFromFile("img/logo.png", "rb");
	logo=IMG_LoadPNG_RW(rwoplogo);
	if(!logo) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	logo_tex = SDL_CreateTextureFromSurface(renderer,logo);
	if(!logo_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(logo); /* on a la texture, plus besoin de l'image */



	if(pWindow){
		int running = 1;
		while(running){
			SDL_Event e;
			while(SDL_PollEvent(&e)){
				switch(e.type) {
					case SDL_QUIT:
						running = 0;
					break;

					case SDL_WINDOWEVENT:
						switch(e.window.event){
				  			case SDL_WINDOWEVENT_SHOWN:
								/* Le fond de la fenêtre sera vert */
		            SDL_SetRenderDrawColor(renderer, 55, 99, 78, 255);
							  SDL_RenderClear(renderer);

                logoDestRect.x = 200;
                logoDestRect.y = 10;


                SDL_QueryTexture(logo_tex, NULL, NULL, &(logoDestRect.w), &(logoDestRect.h));
                SDL_RenderCopy(renderer, logo_tex, NULL, &logoDestRect);


								SDL_RenderPresent(renderer);

							break;
						}

					case SDL_MOUSEBUTTONDOWN:

						if(e.motion.x > 575 && e.motion.x < 675 && e.motion.y > 500 && e.motion.y < 550){

            }

						else if(e.motion.x > 575 && e.motion.x < 675 && e.motion.y > 500 && e.motion.y < 550){

            }
					break;
				}
			}
		}
	}
	else {
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

	/* Destruction de la fenetre */
	SDL_DestroyWindow(pWindow);
  SDL_Quit();

  return 0;
}
