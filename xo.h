#ifndef ENTETE_H_INCLUDED
#define ENTETE_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


typedef struct
{
	int joueur;// numero du joueur qui va jouer au premier 1: si joueur, 2 si ordinateur
	SDL_Surface * image1,*image2,*image3;
	int tabsuivi[9];// tableau representant la grille du jeu
	SDL_Rect pos;// position d'un petit carreau a calculer pour chaque case
	int tour;// initialement egale 0 au maximum nous avons 8 tours
	TTF_Font *comic;
	SDL_Color couleur;
	SDL_Rect posMSG;
}tic;

void initialisation(tic *t);

void affichage(tic t,SDL_Surface *ecran ) ;

int atilganer(int tabsuivi[]);

int minimax(int tabsuivi[],int joueur);

void calcul_coup(int tabsuivi[]);

void Resultat (tic t,SDL_Surface* ecran);

void liberationmemoire(tic t);

#endif // ENTETE_H_INCLUDED
