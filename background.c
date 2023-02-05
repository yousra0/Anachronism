#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "background.h"
//background


void initBack(Background *b)
{	
	b->backgroundImg=IMG_Load("background.png");
	b->camera.x=0;
	b->camera.y=0;
	b->camera.h=600;
	b->camera.w=1000;
	
	b->backgroundPos.x=0;
	b->backgroundPos.y=0;
	b->backgroundPos.h=600;
	b->backgroundPos.w=500;

	b->backgroundPos2.x=0;
	b->backgroundPos2.y=0;
	b->backgroundPos2.h=600;
	b->backgroundPos2.w=500;

}

void afficherBack(Background b,SDL_Surface *screen)
{
	//b->backgroundImg=IMG_Load("background.png");
	SDL_BlitSurface(b.backgroundImg,&b.camera,screen,NULL);
}

void afficherBack_partage(Background b,SDL_Surface *screen)
{       SDL_Rect pos={500,0,600,600};
	SDL_BlitSurface(b.backgroundImg,&b.backgroundPos,screen,NULL);
	SDL_BlitSurface(b.backgroundImg,&b.backgroundPos2,screen,&pos);

}

void scrolling(SDL_Rect *camera,int direction,int pasAvancement)
{
	if (direction==0)
	{
		if(camera->x < 3250) camera->x += pasAvancement;
	}
	else if (direction==1)
	{
		if (camera->x > 0) camera->x -= pasAvancement;
	}
		
}
