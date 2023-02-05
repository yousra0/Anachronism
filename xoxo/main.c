#include <stdio.h>
#include "xo.h"


int main()
{
	tic t; 
	int coup;
	SDL_Surface * ecran;
	TTF_Init();
	SDL_Event event;

    	int contin=1;

	SDL_Init(SDL_INIT_VIDEO);
    	ecran=SDL_SetVideoMode(552,541,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    	int joueur; 

    	initialisation(&t);

    	int a,bb;

    	while(contin)
    	{
		affichage(t,ecran); 
		SDL_Flip(ecran);

		if( t.tour<9 && atilganer(t.tabsuivi)==0)
		{
			if((t.tour+joueur)%2==0)//tour du PC
            		{
				calcul_coup(t.tabsuivi);
 				t.tour++;
			}
			else
			{
				SDL_WaitEvent(&event);

				switch(event.type)
				{
					case SDL_QUIT:
				    		contin=0;
				    	break;
					case SDL_MOUSEBUTTONUP:

				    		a=event.button.x/190;
				    		bb=event.button.y/190;
				    		coup=3*bb+a;
				    		t.tour++;
				    	break;
       				}

    				t.tabsuivi[coup]=-1;
			}

		}
		else
		{ 
			Resultat(t,ecran);
 			contin=0;   
			printf("%d", t.tour);
		}
	}
   	SDL_Quit();
   	TTF_Quit();
    	liberationmemoire(t);

    	return 0;
}

