#ifndef menu_H_INCLUDED
#define menu_H_INCLUDED

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
	SDL_Surface *crow ; // nsob feha taswira
	SDL_Rect crow_pos; // pos du curseur dans fenetre
	SDL_Rect animation[8];
	int frame; // pour parcourir tab animation : taswira 1 / 2 / 3 ....
	int show;

}curseur ;




void init_tab_anim(SDL_Rect* clip); //t3abi tab animation
void initialiser (curseur *p, int xmouse, int ymouse) ;
void afficher_curseur(curseur  * p , SDL_Surface *screen);
void animation(curseur  *p);
void mvt_curseur_x(curseur *p, int xmouse);
void mvt_curseur_y(curseur *p, int ymouse);

int afficher_menu(SDL_Surface *screen);







  #endif //
