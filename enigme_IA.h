#ifndef ia_H_INCLUDED
#define ia_H_INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 

typedef struct 
{
	int c;
	int l;
}Casee ;


Casee afficher_jeton(SDL_Surface *screen,SDL_Surface *rouge,SDL_Event event,int t[6][7]);
Casee IA (int t [6][7]);
void afficher_jaune (SDL_Surface *screen,SDL_Surface *jaune,Casee c);
int checkk (int t[7][7]);
int enigme_IA();
#endif
