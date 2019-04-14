#ifndef affichage_h
#define affichage_h

  /* Librairies standards */
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <time.h>

  /* Librairies SDL */
  #include "SDL2/SDL.h"
  #include "SDL2/SDL_ttf.h"
  #include "SDL2/SDL_image.h"

  /* Librairies du jeu */
  #include "commun.h"
  #include "fonctions_jeu.h"
  #include "fonctions_joueur.h"
  #include "mains.h"
  #include "ordinateur.h"

  int aff1_joueur();
  int aff2_joueurs();

#endif
