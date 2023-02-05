#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <ctype.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "Personne.h"



void initPerso(Personne *p)
{
    int i,j;
    char nom_image[30];
    p->acceleration=0;

    p->direction=0;
    p->nbr_frame=0;
    p->up=0;
    p->ground=0;

    p->position.x=300;
    p->position.y=0;
    p->position.w=115;
    p->position.h=140;

    p->vitesse=0;
    p->vitesse_saut=0;

 
    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 4; j++)
        {   
            sprintf(nom_image,"animation/%d/%d.png",i,j);
            p->images[i][j]=IMG_Load(nom_image);
        }
        
    }
    
}

void initPerso2(Personne *p)
{
    int i,j;
    char nom_image[30];

    p->acceleration=0;
    p->direction=0;
    p->nbr_frame=0;
    p->up=0;
    p->ground=0;

    p->position.x=800;
    p->position.y=0;
    p->position.w=115;
    p->position.h=90;

    p->vitesse=0;
    p->vitesse_saut=0;

 
    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 4; j++)
        {   
            sprintf(nom_image,"animation1/%d/%d.png",i,j);
            p->images[i][j]=IMG_Load(nom_image);
        }
        
    }
    
}


void afficherPerso(Personne p, SDL_Surface * screen)
{
    SDL_BlitSurface(p.images[p.direction][p.nbr_frame],NULL,screen,&p.position);
}



void animerPerso (Personne* p)
{
    
  p->nbr_frame++;
    if (p->nbr_frame >= 4)
 p->nbr_frame=0;
if ((p->vitesse==0) && ((p->direction == 0) || (p->direction == 1)))
{
p->nbr_frame= 0;
}
}

void deplacerPerso (Personne *p,int dt)
{

p->dx = 0.5 * p->acceleration * dt * dt + p->vitesse * dt ;
    if (p->direction==0)//mvt droite
    {
       if (p->position.x < 250) 
       p->position.x = p->position.x + p->dx ;        
    }else if (p->direction==1)
    {
        if (p->position.x > 100) 
        p->position.x = p->position.x - p->dx;
    }
    
}

void deplacerPerso2 (Personne *p,int dt)
{

p->dx = 0.5 * p->acceleration * dt * dt + p->vitesse * dt ;
    if (p->direction==0)//mvt droite
    {
       if (p->position.x < 800)
        p->position.x = p->position.x + p->dx ;        
    }else if (p->direction==1)
    {
        if (p->position.x > 600) 
        p->position.x = p->position.x - p->dx;
    }
    
}

void saut (Personne* p) 
{
    if (p->position.y == p->ground)
    {
       p->vitesse_saut=-50;
       p->up=1;
    }
    
}



void initialiser_score(vie *v)
{
    v->vie=IMG_Load("health.png");
    v->valeur_vie=100;
    v->pos.x=0;
    v->pos.y=150;
    v->pos_spr.x=0;
    v->pos_spr.y=0;
    v->pos_spr.h=50;
    v->pos_spr.w=200;
}


void update_score(vie *v)
{
    v->pos_spr.y=((100-v->valeur_vie)/25)*50;
}


void afficher_vie(vie *v,SDL_Surface *screen)
{
    SDL_BlitSurface(v->vie,&v->pos_spr,screen,&v->pos);
}




