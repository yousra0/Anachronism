#include <SDL/SDL.h>
#include "name.h"
#include <SDL/SDL_ttf.h>// la bibilotheque du texte 
#include <SDL/SDL_image.h>


void inText(Text *A)
{

//initialisation du position du texte
A->position.x=480;
A->position.y=80;

//chargement de la police et de la taille
A->font = TTF_OpenFont("./texte/Fortzilla-Regular.ttf",70);

// couleur noir
A->textcolor.r=0;
A->textcolor.g=0;
A->textcolor.b=0;
}


void inText1(Text *A)
{

//initialisation du position du texte
A->position.x=0;
A->position.y=570;

//chargement de la police et de la taille
A->font = TTF_OpenFont("./texte/Fortzilla-Regular.ttf",14);

// couleur noir
A->textcolor.r=28;
A->textcolor.g=0;
A->textcolor.b=0;
}



void display( Text t , SDL_Surface* screen)
{ 
//methode d'ecriture

t.surfacetexte = TTF_RenderText_Solid(t.font, "Anachronism" , t.textcolor);

// TTF_RenderText_Solid /si le texte ne change pas souvent 
SDL_BlitSurface (t.surfacetexte , NULL , screen , &t.position);
}

void display1( Text t , SDL_Surface* screen)
{ 
//methode d'ecriture

t.surfacetexte = TTF_RenderText_Solid(t.font, "@copyright Innefible Minds" , t.textcolor);

// TTF_RenderText_Solid /si le texte ne change pas souvent 
SDL_BlitSurface (t.surfacetexte , NULL , screen , &t.position);
}


void freetext(Text A)
{
SDL_FreeSurface(A.surfacetexte);
}






