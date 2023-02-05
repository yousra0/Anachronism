#ifndef enig_fichier_H_INCLUDED
#define enig_fichier_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <math.h>
#include <time.h>

struct enig_fichier
{
	SDL_Surface* image_enig_fichier;
	SDL_Rect position_enig_fichier;
	int resultat;
	SDL_Surface *correct,*wrong;
	SDL_Rect position_correct,position_wrong;

	TTF_Font *police,*police_q;
	SDL_Surface *reponse_1,*reponse_2,*reponse_3,*question;
	SDL_Rect  pos_reponse_1,pos_reponse_2,pos_reponse_3,pos_question;
	int alea;
	
};
typedef struct enig_fichier enig_fichier;

void alea_enig_fichier(enig_fichier* en,SDL_Color Color);
void init_enig_fichier( enig_fichier* en ,SDL_Color Color);
void blit_enig_fichier ( enig_fichier *en, SDL_Surface* screen);
void free_surface_enig_fichier( enig_fichier *en );
int quiz1(enig_fichier *en, SDL_Surface* screen );
int enig_fichier_avec_fichier();



#endif // enig_fichier_H_INCLUDED
