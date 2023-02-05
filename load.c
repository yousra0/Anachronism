#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "Personne.h"
#include "background.h"
#include "load.h"

int afficher_load(SDL_Surface *screen)
{
Personne p,p1; 
	//mouvement du 1er joueur
	int acceleration=0;
	int deceleration=0;

	int up1=0 , up=0 , continuer=1;

	//mouvement du 2eme joueur
	int acceleration1=0;
	int deceleration1=0;
  //creation background
    SDL_Surface *background = NULL;
    background = IMG_Load("graphic/zom.jpg");
    // detreminerr pos de back
    SDL_Rect background_pos;
    background_pos.x = 0;
    background_pos.y = 0;
    
    //bouton exit 
    SDL_Surface *exit[2];
    exit[0]=IMG_Load("graphic/x.png");
     exit[1]=IMG_Load("graphic/x1.png");
     int ex=0;
     SDL_Rect exit_pos;
     exit_pos.x = 700;
     exit_pos.y = 0;
    
     
    //les boutons resume & new game
     SDL_Surface *load[2];
	load[0]=IMG_Load("newgame.png");
	load[1]=IMG_Load("resume.png");
	int lo=0;
	
	

    
     int t = 0;
    SDL_Event event;
    int done = 1;
    while (done)
    {
        t = 0;
        if (SDL_PollEvent(&event)) // ki ninzel ala ay haja
        {
            switch (event.type) //tal9a type el 7aja
            {
            	case SDL_QUIT: //nenzel 3al (X) el 7amra
                	done = 0;
                break;

            	//avec clavier
            	case SDL_KEYDOWN:                 // ay haja fil clav
                	switch (event.key.keysym.sym) // taref type l haja l nzalt alaha fil clav
                	{
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
				case SDLK_UP: //flech fou9ani
				
				   if (lo==0)
					    {
						lo = 1;
					    }
					    else if (lo==1 && t==0)
					    {
	
						lo = 0;
						t = 1;
					    }
					    
					    break;
					       ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
				case SDLK_DOWN: //flech loutani
				  if (lo==0)
					    {
						lo = 1;
					    }
					    else if (lo==1 && t==0)
					    {
	
						lo = 0;
						t = 1;
					    }
					    
					    break;
					     ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
				  
					    }
					    }
					    }
					     SDL_BlitSurface(background, NULL, screen, &background_pos);
					      SDL_BlitSurface(load[lo], NULL, screen, NULL);
					       SDL_Flip(screen);
}
 SDL_FreeSurface(background);
}
