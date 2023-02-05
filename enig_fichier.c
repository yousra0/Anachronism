#include "enig_fichier.h"

void init_enig_fichier( enig_fichier* en ,SDL_Color Color)
{
    en->image_enig_fichier = IMG_Load("bg_enigme.png");
    en->position_enig_fichier.x = 0;
    en->position_enig_fichier.y = 0;
    en->resultat = 0;
    en->correct =IMG_Load("correct.png");
    en->wrong =IMG_Load("wrong.png");
    en->position_correct.x = 170;
    en->position_correct.y = 255;
    en->position_wrong.x = 240;
    en->position_wrong.y = 255;

    en->police=TTF_OpenFont("police.ttf",50 );
    en->reponse_1 = NULL;
    en->pos_reponse_1.x=200;
    en->pos_reponse_1.y=500;

    en->reponse_2 = NULL;
    en->pos_reponse_2.x=450;
    en->pos_reponse_2.y=500;

    en->reponse_3 =NULL;
    en->pos_reponse_3.x=700;
    en->pos_reponse_3.y=500;

    en->police_q=TTF_OpenFont("police.ttf",45 );
    en->question = NULL;
    en->pos_question.x=200;
    en->pos_question.y=250;

    en->alea = 0;
}


void blit_enig_fichier ( enig_fichier *en, SDL_Surface* screen)
{
	    SDL_BlitSurface(en->image_enig_fichier,NULL, screen, &en->position_enig_fichier );
	    SDL_BlitSurface(en->reponse_1,NULL,screen,&en->pos_reponse_1);
        SDL_BlitSurface(en->reponse_2,NULL,screen,&en->pos_reponse_2);
        SDL_BlitSurface(en->reponse_3,NULL,screen,&en->pos_reponse_3);
        SDL_BlitSurface(en->question,NULL,screen,&en->pos_question);
}

void free_surface_enig_fichier( enig_fichier *en )
{
    SDL_FreeSurface(en->image_enig_fichier);
    SDL_FreeSurface(en->correct);
    SDL_FreeSurface(en->wrong);
    SDL_FreeSurface(en->reponse_1);
    SDL_FreeSurface(en->reponse_2);
    SDL_FreeSurface(en->reponse_3);
    SDL_FreeSurface(en->question);
    TTF_CloseFont(en->police);
    TTF_CloseFont(en->police_q);
}

void alea_enig_fichier(enig_fichier *en ,SDL_Color Color)
{
	FILE* fichier = NULL;
	FILE* fichier_reponse = NULL;
	char ques[60] = {0};
	char rep1[20] = {0};
	char rep2[20] = {0};
	char rep3[20] = {0};
	int caracterelu_question,caracterelu_reponses,ligne =1,ligne_reponse=1;
	srand(time(0));
	do {
		en->alea = rand()%3 +1;
	}while ( en->alea <1 || en->alea > 3 );

	fichier_reponse = fopen("reponse.txt","r"); // r = read 
	fichier = fopen("question.txt","r"); // r = read 
	if ( fichier != NULL && fichier_reponse != NULL )
	{
		while ( caracterelu_question!=EOF && ligne < en->alea )
		{
			caracterelu_question = fgetc(fichier);
			if ( caracterelu_question == '\n')
				ligne++;
		}
		fgets(ques,45,fichier);
		fclose(fichier);
		while ( caracterelu_reponses!=EOF && ligne_reponse < en->alea )
		{
			caracterelu_reponses = fgetc(fichier_reponse);
			if ( caracterelu_reponses == '\n')
				ligne_reponse++;
		}
		fscanf(fichier_reponse,"%s %s %s",rep1,rep2,rep3);
		fclose(fichier_reponse);
	}
	
	

	en->question = TTF_RenderText_Blended(en->police_q,ques,Color);
	en->reponse_1 = TTF_RenderText_Blended(en->police,rep1,Color);
	en->reponse_2 = TTF_RenderText_Blended(en->police,rep2,Color);
	en->reponse_3 = TTF_RenderText_Blended(en->police,rep3,Color);

}

int quiz1(enig_fichier *en, SDL_Surface* screen )
{

    SDL_Event event;
    int continuer=1;
    SDL_Color Color = {255,255,255};
    alea_enig_fichier(en,Color);
    while(continuer == 1)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;

            break;

        case SDL_MOUSEBUTTONDOWN:
        {
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
            {
                if ( event.button.x>200 && event.button.x<350 && event.button.y>500 && event.button.y<600) //reponse1
                {
                    if ( en->alea == 1 )
                    {
                        en->resultat= 1;
                    }
                    else if ( en->alea == 2)
                    {
                        en->resultat = 2;
                    }
                    else if ( en->alea == 3)
                    {
                        en->resultat = 1;
                    }
                    
                }
                if ( event.button.x>450 && event.button.x<600 && event.button.y>500 && event.button.y<600) //reponse2
                {
                    if ( en->alea == 1 )
                    {
                        en->resultat= 2;
                    }
                    else if ( en->alea == 2)
                    {
                        en->resultat = 2;
                    }
                    else if ( en->alea == 3)
                    {
                        en->resultat = 2;
                    }
                }
                if ( event.button.x>700 && event.button.x<850 && event.button.y>500 && event.button.y<600) //reponse3
                {
                    if ( en->alea == 1 )
                    {
                        en->resultat= 2;
                    }
                    else if ( en->alea == 2)
                    {
                        en->resultat = 1;
                    }
                    else if ( en->alea == 3)
                    {
                        en->resultat = 2;
                    }
                }
            }
            break; //button left
            }
        }
        break;

        }// taskiret les events mtaa les boutons

        blit_enig_fichier ( en, screen);

        if ( en->resultat == 1 )
        {
            SDL_BlitSurface(en->correct,NULL, screen, &en->position_correct );
            SDL_Flip(screen);
            SDL_Delay(2000);
            continuer = 0;
	
	    return 1;
        }
        else if ( en->resultat == 2 )
        {
            SDL_BlitSurface(en->wrong,NULL, screen, &en->position_wrong );
            SDL_Flip(screen);
            SDL_Delay(2000);
            continuer = 0;

	    return 2;
        }
        
        SDL_Flip(screen);


    }

}



int enig_fichier_avec_fichier(){
   
   
    SDL_Surface *screen =NULL;
    SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(1000,600, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);
    SDL_WM_SetCaption("game",NULL);
    TTF_Init();
    SDL_Color Color={255,255,255};
    enig_fichier en;
    init_enig_fichier(&en,Color);

    int res = quiz1(&en,screen );
    
    free_surface_enig_fichier( &en );
    SDL_Quit();

    return EXIT_SUCCESS ;
}

