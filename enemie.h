#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct enemie
	{ 
            SDL_Surface *spritesheet;  
            SDL_Rect pos,posframe;
            int direction; /*!< Direction*/ 
            SDL_Rect posmin,posmax;
            int frame; /*!< Frame*/ 
     }enemie;


void initennemi(enemie*e)  ;
void afficherennemi(enemie *e, SDL_Surface * screen) ;
void animerennemi( enemie * e)  ;   
void deplacer( enemie * e)  ;  
int collision(SDL_Rect E, SDL_Rect p);
void deplacerIA(enemie * E, SDL_Rect posPerso);


void scrolling_enemie(enemie *E,int direction,int pasAvancement);

#endif 


