#ifndef Texte_H
#define Texte_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>//bibilotheque du texte 
typedef struct
{
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface *surfacetexte;
	SDL_Color textcolor;
	char texte[50];
}Text;

//menu principale
	void inText(Text *t);
	void inText1(Text *t);
	void freetext (Text A);
	void display(Text t,SDL_Surface* screen);
	void display1(Text t,SDL_Surface* screen);

	
#endif

