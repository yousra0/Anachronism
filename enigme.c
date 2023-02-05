#include "enigme.h"

//enigme mathematique

enigme generer()
{
    enigme e;
    int sol,ajout;
    int i;

    int coeffQ[4];
    srand( time( NULL ) );
    coeffQ[0]=rand() % 30;
    coeffQ[1]=coeffQ[0]+12;
    coeffQ[2]=coeffQ[1]-5;
    coeffQ[3]=coeffQ[0]+coeffQ[2];


//affichage de la question
    sprintf(e.question,"(%d * %d)+ %d - %d =?",coeffQ[0],coeffQ[1],coeffQ[2],coeffQ[3]);
//affichage de la solution
    sol=(coeffQ[0]*coeffQ[1])+coeffQ[2]-coeffQ[3];//calculer la sol
    

	

//initialisation de la musique du background
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);  
        Mix_Music *music ;
        music=Mix_LoadMUS("game1.mp3");
        Mix_PlayMusic(music,-1);
	for(int i=1;i<5;i++)
	{
		char str[30];
		sprintf(str,"%d.png",i);
		//e.boutons[i]=IMG_Load(str);
	}


//les 3 solutions
    srand( time( NULL ) );
    e.sol =1 + rand() % 3;
    if (e.sol==1)
    {
        sprintf(e.rep1,"%d",sol);
        srand( time( NULL ) );
        ajout =rand() % 15;
        sprintf(e.rep2,"%d",sol+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.rep3,"%d",sol+ajout);
    }
    if (e.sol==2)
    {
        sprintf(e.rep2,"%d",sol);
        srand( time( NULL ) );
        ajout =rand() % 15;
        sprintf(e.rep1,"%d",sol+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.rep3,"%d",sol+ajout);
    }
    if (e.sol==3)
    {
        sprintf(e.rep3,"%d",sol);
        srand( time( NULL ) );
        ajout =rand() % 15;
        sprintf(e.rep1,"%d",sol+ajout);
        srand( time( NULL ) );
        ajout =(rand() % 15)-20;
        sprintf(e.rep2,"%d",sol+ajout);
    }
    return e;
    
    

}

//affichage de l'enigme
void afficherEnigme(enigme *e, SDL_Surface * screen)
{    
	SDL_Surface *texte,*R1,*R2,*R3,*back,*bouton;
	SDL_Rect posQ,pos1,pos2,pos3,posbouton1,posbouton2,posbouton3;
	SDL_Color blanc = {255, 255, 255};
	TTF_Font *police = NULL,*police2 = NULL;

	bouton=IMG_Load("bouton.png");//ou on affiche la solution
	back=IMG_Load("backenig.png");


	TTF_Init();
       
	police = TTF_OpenFont("clerk.ttf", 90);
	police2 = TTF_OpenFont("pepsi.ttf", 90);


    	texte = TTF_RenderText_Blended(police, e->question, blanc);
	//les 3 réponses
    	R1 = TTF_RenderText_Blended(police2, e->rep1, blanc);
    	R2 = TTF_RenderText_Blended(police2, e->rep2, blanc);
    	R3 = TTF_RenderText_Blended(police2, e->rep3, blanc);



    posQ.x=170;
    posQ.y=80;
    pos1.x=100;
    pos1.y=420;
    posbouton1.x=30;
    posbouton1.y=400;

    pos2.x=520;
    pos2.y=420;
    posbouton2.x=450;
    posbouton2.y=400;

    pos3.x=980;
    pos3.y=420;
    posbouton3.x=870;
    posbouton3.y=400;

    SDL_BlitSurface(back, NULL, screen, NULL); 
    SDL_BlitSurface(texte, NULL, screen, &posQ);

    SDL_BlitSurface(bouton,NULL,screen,&posbouton1);
    SDL_BlitSurface(bouton,NULL,screen,&posbouton2);
    SDL_BlitSurface(bouton,NULL,screen,&posbouton3);

    SDL_BlitSurface(R1, NULL, screen, &pos1); 
    SDL_BlitSurface(R2, NULL, screen, &pos2); 
    SDL_BlitSurface(R3, NULL, screen, &pos3); 
}


int enigme_alea()
{
	int resultat;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *screen=NULL;
	SDL_Surface *back=NULL;
	SDL_Surface *winning=NULL;
	SDL_Surface *losing=NULL;

	winning=IMG_Load("winning.png");
	losing=IMG_Load("losing.png");

	screen=SDL_SetVideoMode (1200,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	SDL_Event event;
	SDL_WM_SetCaption("Enigme Yousra\t1",NULL);

	bool execute=true;
	int reponse=-1;

	enigme e;
	e=generer();

while (execute)
{
    afficherEnigme(&e,screen);
    SDL_Flip(screen);

    while(SDL_PollEvent(&event))
    {
		switch(event.type)
		{
			case SDL_QUIT:

				execute=false;
			break;
        		case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_a :
						if (e.sol==1)
                				{
						    	reponse=1;
						    	printf("vrai");
						    	SDL_BlitSurface(winning, NULL, screen, NULL);
						    	SDL_Flip(screen);
						    	SDL_Delay(6000);
						    	resultat=1;
						    	execute=0;
                				}
                				else
						{
                    					reponse=0;
						    	printf("faux");
						    	SDL_BlitSurface(losing, NULL, screen, NULL);
						    	SDL_Flip(screen);
						    	SDL_Delay(4000);
						    	resultat=0;
						    	execute=0;
                				}
                
      					break;
            				case SDLK_z :
                				if (e.sol==2)
						{
						    	printf("vrai");
						    	reponse=1;
						    	SDL_BlitSurface(winning, NULL, screen, NULL);
						    	SDL_Flip(screen);
						    	SDL_Delay(4000);
						    	resultat=1;
						    	execute=0;
						}
						else 
						{
						    	printf("faux");
						    	reponse=0;
						    	SDL_BlitSurface(losing, NULL, screen, NULL);
						    	SDL_Flip(screen);
						    	SDL_Delay(4000);
						    	resultat=0;
						    	execute=0;
						}
            				break;
           				case SDLK_e :
						if (e.sol==3)
						{
						    	printf("vrai");
						    	reponse=1;
						    	SDL_BlitSurface(winning, NULL, screen, NULL);
						    	SDL_Flip(screen);
						    	SDL_Delay(4000);
						    	resultat=1;
						   	execute=0;
						}
						else
						{
						   	reponse=0;
						    	printf("faux");
						    	SDL_BlitSurface(losing, NULL, screen, NULL);
						    	SDL_Flip(screen);
						    	SDL_Delay(4000);
						    	resultat=0;
						    	execute=0;
						}
            				break;
            			}
        		break;
        		case SDL_MOUSEBUTTONDOWN:
		    		if (event.motion.x >= 30 && event.motion.x <= 303 && event.motion.y >= 420 && event.motion.y <= 558)
		    		{
					if (e.sol==1)
					{
					    printf("vrai");
					    reponse=1;
					    printf("vrai");
					    SDL_BlitSurface(winning, NULL, screen, NULL);
					    SDL_Flip(screen);
					    SDL_Delay(6000);
					    resultat=1;
					    execute=0;
			      
					}
					else
					{
					    printf("faux");
					    reponse=0;
					    SDL_BlitSurface(losing, NULL, screen, NULL);
					    SDL_Flip(screen);
					    SDL_Delay(4000);
					    resultat=0;
					    execute=0;
					}
            			}
			    	if (event.motion.x >= 450 && event.motion.x <= 723 && event.motion.y >= 400 && event.motion.y <= 573)
			    	{
					if (e.sol==2)
					{
					    printf("vrai");
					    reponse=1;
					    printf("vrai");
					    SDL_BlitSurface(winning, NULL, screen, NULL);
					    SDL_Flip(screen);
					    SDL_Delay(6000);
					    resultat=1;
					    execute=0;
					}
					else
					{
					    printf("faux");
					    reponse=0;
					    SDL_BlitSurface(losing, NULL, screen, NULL);
					    SDL_Flip(screen);
					    SDL_Delay(4000);
					    resultat=0;
					    execute=0;
					}
            			}
			    	if (event.motion.x >= 980 && event.motion.x <= 1253 && event.motion.y >= 400 && event.motion.y <= 573)
			    	{
					if (e.sol==3)
					{
					    printf("vrai");
					    reponse=1;
					    printf("vrai");
					    SDL_BlitSurface(winning, NULL, screen, NULL);
					    SDL_Flip(screen);
					    SDL_Delay(6000);
					    resultat=1;
					    execute=0;
					}
					else
					{
					    printf("faux");
					    reponse=0;
					    SDL_BlitSurface(losing, NULL, screen, NULL);
					    SDL_Flip(screen);
					    SDL_Delay(4000);
					    resultat=0;
					    execute=0;
					}
            			}
            			break;
       			}
		}
	}
	return resultat;

SDL_FreeSurface(winning);
SDL_FreeSurface(losing);
}



