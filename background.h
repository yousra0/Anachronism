#ifndef JEUX_H_INCLUDED
#define JEUX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct 
{
	SDL_Surface *backgroundImg;
        SDL_Rect camera,backgroundPos,backgroundPos2;
    
}Background;

void initBack(Background *b);
void afficherBack(Background b,SDL_Surface *screen);
void afficherBack_partage(Background b,SDL_Surface *screen);
void scrolling(SDL_Rect *camera,int direction,int pasAvancement);


#endif // JEUX_H_INCLUDED
