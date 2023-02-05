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
#include "background.h"
#include "enemie.h"
#include "minimap.h"
#include "enigme_IA.h" //puissance
#include "enigme.h"//aleatoire sans fichier
#include "menu.h"
#include "option.h"
#include "enig_fichier.h"
#include "sauvegarde.h"
#include "xo.h"
#include "load.h"




#define mono_joueur 1
#define multijoueur 2
#define returnn 3
#define new_game 0
#define save_game 3




int main()
{
	
	vie  v;    
	minimap m;
	enemie e;
	Background b;  
	Personne p,p1; 	
	tic t;

	SDL_Surface *screen;
	SDL_Surface *back;
	SDL_Surface * ecran;

	int continuer=1,up=0;
	int contin=1;;
	int coup;
	int joueur;
    	int a,bb;

	SDL_Event event;

	//mouvement du 1er joueur
	int acceleration=0;
	int deceleration=0;

	int up1=0;

	//mouvement du 2eme joueur
	int acceleration1=0;
	int deceleration1=0;

	TTF_Font *police=NULL;
	Uint32 t_prev,t_fin , dt ,temps;

	SDL_Surface *mask;

	int resultat_ia,resultat_alea,stage=1;

	SDL_Color Color={255,255,255};
	enig_fichier en;

	int resultat_fichier;

	SDL_Surface *sous_menu_1[3],  //mono et multi joueurs et back
		    *menu[2];  //save game
		 

	int mode=new_game;

	//initialisation de la fenetre
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	screen=SDL_SetVideoMode (1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


	//initialisation des joueurs, enemie, background, map, score, enigme fichier
	initPerso(&p);
	initPerso2(&p1);
	initBack(&b);
	initennemi(&e);
	initmap(&m);
	initialiser_score(&v);
	init_enig_fichier(&en,Color);
	initialisation(&t);

	

	back=IMG_Load("background.png");
	police=TTF_OpenFont("DS-DIGI.TTF",70);
	mask=IMG_Load("mask.png");


	int choix=1;

	//les boutons mono et multi joueurs et mono et back
	sous_menu_1[0]=IMG_Load("im21.png");
	sous_menu_1[1]=IMG_Load("im22.png");
	sous_menu_1[2]=IMG_Load("im23.png");

	//les boutons save game
	menu[0]=IMG_Load("im11.png");
	menu[1]=IMG_Load("im12.png");
	
	
	

///////////////////////////////////////////////////////////////////////////////////////////////////menu
	int Menu=-1;
do{
		Menu=afficher_menu(screen);  //affichage du menu

		if (Menu==3) 
		{
			afficher_option( screen);
			
		}
		else if (Menu==2) 
		{
			afficher_load( screen);
			
		}
	

	
}while ((Menu == 3) || (Menu == 2) );
	
	if (Menu ==0)
	{
		return 0;
	}
	

	while (continuer)
	{
		t_prev = SDL_GetTicks();

		while(SDL_PollEvent(&event))  //début d'events
		{
		    if (mode==new_game)  //mode new game
		    {
			switch (event.type)
		      	{
		   		case SDL_QUIT:  //pour quitter le program

					continuer=0;
			  	break;
		       
		     		case SDL_KEYDOWN:  //lorsqu'on clique sur le bouton play
		    			if (event.key.keysym.sym== SDLK_RETURN) 
		   			{
				        	printf("%d",choix);

			  		 	switch (choix)
				   		{
			   				case 0:
								mode=multijoueur;
			      		 		break;
			   			 	case 1:
			   		     			mode=mono_joueur;
			  			  	break;
							case 2:
								mode=returnn;
			      		 		break;              
			 			 }
			 			 SDL_Delay(1000);
			  	
		    			 }
		      			 else
		       			 	choix=(choix+2)%3;//si choix =1 , devient 0 ,,, si choix =0 ,, devient 1
		       		break;
		      
		       	  }
		     }   
		    if (mode==mono_joueur)  //mode mono joueur
		    {
		     		switch (event.type)
				{
					case SDL_QUIT:
				    		continuer=0;
				    	break;

					case SDL_KEYDOWN:
				    		switch (event.key.keysym.sym)
				    		{
					    		case  SDLK_RIGHT:
								p.direction=0;
								p.vitesse=5;
							break;
					    		case  SDLK_LEFT:
								p.direction=1;
								p.vitesse=5;
							break; 
					   		case SDLK_UP:
								up=1;
							break;  
					    		case SDLK_p:  //lettre P pour accelerer
								acceleration=1;
					    		break;
					    		case SDLK_o:  //lettre O pour decelerer
								deceleration=1;
							break;
					    		case SDLK_ESCAPE://espace pour enregistrer le jeu
					    			mode=save_game;
					    		break;    	

			    			}
					break;

					case SDL_KEYUP:
						switch (event.key.keysym.sym)//lbouton appuyé?
				    		{
				   	 		case  SDLK_RIGHT:
					      			p.vitesse=0;
							break;

				    			case  SDLK_LEFT:        
								p.vitesse=0;
							break; 

				    			case SDLK_UP:
								up=0;
							break; 

				    			case SDLK_p:
				       	 			acceleration=0;
				    			break;

				    			case SDLK_o:
								deceleration=0;
							break; 	
				    		 }

					break;
				}	

		    	 }
	    		if (mode==multijoueur)  //mode multi joueur
	   		{
		       		switch (event.type)
				{
					case SDL_QUIT:
		    				continuer=0;
		    			break;

					case SDL_KEYDOWN:
		    				switch (event.key.keysym.sym)
						{
							case  SDLK_RIGHT:
								p.direction=0;
								p.vitesse=5;
							break;
		    					case  SDLK_LEFT:
								p.direction=1;
								p.vitesse=5;
		       					break; 
		    					case SDLK_UP:
								up=1;
							break;  
		    					case SDLK_p:
								acceleration=1;
		    					break;
		    					case SDLK_o:
								deceleration=1;
							break;

			
		    					case  SDLK_d:
								p1.direction=0;
								p1.vitesse=5;
							break;
							case  SDLK_q:
								p1.direction=1;
								p1.vitesse=5;
							break; 
		    					case SDLK_z:
		       						up1=1;
							break;  
		    					case SDLK_f:
								acceleration1=1;
		    					break;
		    					case SDLK_g:
								deceleration1=1;
		       					break;
		    
		    				}
					break;

					case SDL_KEYUP:
						switch (event.key.keysym.sym)//lbouton appuyé?
		    				{
		    					case  SDLK_RIGHT:
			      					p.vitesse=0;
		       					break;

		    					case  SDLK_LEFT:        
								p.vitesse=0;
							break; 

		    					case SDLK_UP:
								up=0;
							break; 

						    	case SDLK_p:
								acceleration=0;
						    	break;

						    	case SDLK_o:
								deceleration=0;
							break; 

							case  SDLK_d:
							      p1.vitesse=0;
							break;

						    	case  SDLK_q:        
								p1.vitesse=0;
							break; 

						    	case SDLK_z:
								up1=0;
							break; 

						    	case SDLK_f:
								acceleration1=0;
						    	break;

						    	case SDLK_g:
								deceleration1=0;
							break;             
		    
		   				 }
			
					break;
				}
	    		}


		    	if (mode==save_game)  //mode save game
			{
				switch (event.type)
		      		{
		   			case SDL_QUIT://pour quitter le program
				   		continuer=0;
			  	 	break;
		       
		     		  	case SDL_KEYDOWN:
		    				if (event.key.keysym.sym== SDLK_RETURN) 
		   			    	{
				  			 switch (choix)
					   		 {
				   				case 0:
									sauvegarder(p,b);
									continuer=0;
				      		 		break;
					   			case 1:
					   		     		charger(&p,&b);
					   			     	printf("\nperso %d -- %d\n",p.position.x,p.position.y);
					    				printf("\nback %d -- %d\n",b.camera.x,b.camera.y);
					    				
					  			break;              
				 			  }
			 			  	  SDL_Delay(1000);
							  mode=mono_joueur;
		    			   	}
		       				else
		      					choix=(choix+1)%2;//si choix =1 , devient 0 ,,, si choix =0 ,, devient 1
		       			break;
		       		}
			}
	}

/////////////////////////////////////////////////////////////////////////////////////////////partie update
if (mode==mono_joueur)  //mode mono joueur
{
	if (acceleration==1) 
		p.acceleration = p.acceleration + 0.005 ;
	if (deceleration==1)
		p.acceleration = p.acceleration - 0.01;

		p.acceleration = p.acceleration - 0.001;
	if (p.acceleration<0)
		p.acceleration =0;


	SDL_Delay(3);

	t_fin=SDL_GetTicks();
	dt=t_fin - t_prev ;

	switch (p.direction)
	{
		case 0:    //collisition droite
	    	if (collisionPP_droite(p.position,mask,b.camera)==0)
		{
	    		scrolling(&b.camera,p.direction,p.dx);
	    		scrolling_enemie(&e,p.direction,p.dx);
	    		deplacerPerso(&p,dt);
	    	}
	    	break;

		case 1:    //collisition gauche
	    	if (collisionPP_gauche(p.position,mask,b.camera)==0)
		{
	    		scrolling(&b.camera,p.direction,p.dx);
	    		scrolling_enemie(&e,p.direction,p.dx);
	    		deplacerPerso(&p,dt);
	    	}
	    	break;
	}


	update_score(&v);
	deplacerIA(&e,p.position);

	m.pos_joueur=MAJMinimap(p.position,20,b.camera);

	animerennemi(&e);
	animerPerso(&p);

	if (p.up==0 && collisionPP_down(p.position,mask,b.camera)==0)
	{
	   // p.vitesse_saut+=15;
	    p.ground+=15;
	}

	if (collisionPP_down(p.position,mask,b.camera)==1)
	{
	    p.ground=p.position.y;
	  //  printf("co\n");
	} 


	if (up==1) 
		saut(&p);
	//printf("%f\n",p.vitesse_saut);
	p.position.y = p.position.y   + p.vitesse_saut ;
	p.vitesse_saut = p.vitesse_saut + 10 ;

	if (p.position.y>=p.ground)
	{   
		p.position.y=p.ground;
		p.vitesse_saut=0;
		p.up=0;
	}

/////////////////////////////////////////////////////////////////jeu xoxo quand le perso atteint la fin

	if (b.camera.x>b.backgroundImg->w - screen->w)
	{
	switch (stage)
		{
			case 1:
	
	SDL_Init(SDL_INIT_VIDEO);
    	ecran=SDL_SetVideoMode(552,541,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

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

		initialiser_score(&v);
		SDL_Quit();
		TTF_Quit();
    		liberationmemoire(t);
	}}}


//	printf("you winn \n");
					//stage=3;
   	
    	//break;
    	
    	
    	

	/*case 2:
		    		
		    	if (resultat_ia==1)
		    	{
					initPerso(&p);
					initBack(&b);
					initialiser_score(&v);
					//continuer=0;
					printf("you winn \n");
					stage=3;
		    		}
	
				else
		    		{
					printf("you lostt \n");
					continuer=0;
		    		}
		    	break;
			case 3:
		    		resultat_fichier=quiz1(&en,screen);
		    		if (resultat_fichier==1)
		    		{
					initPerso(&p);
					initBack(&b);
					initialiser_score(&v);
					//continuer=0;
					printf("you winn \n");
					stage=1;
		    		}
				else
				{
					printf("you lostt \n");
					continuer=0;
				}
			break;
			}		*/
		
	
//////////////////////////////////////////////////////////////cas de collision bb
	if (collision(e.pos,p.position)==1)
	{
		if (v.valeur_vie>0)
			v.valeur_vie--;
		else if (v.valeur_vie==0)
		{
			resultat_alea=enigme_alea();
			if (resultat_alea==1)
			{
			    printf("revived\n");
			    p.position.x+=500;
			    p.dx=0;
			    b.backgroundPos.x+=500;
			    v.valeur_vie=100;
			}
			else
			{
			    printf("dead\n");
			    continuer=0;
			}   
		}
	    
	}
}

if (mode==multijoueur)
{
    if (acceleration==1) p.acceleration = p.acceleration + 0.005 ;
if (deceleration==1) p.acceleration = p.acceleration - 0.01;

if (acceleration1==1) p1.acceleration = p1.acceleration + 0.005 ;
if (deceleration1==1) p1.acceleration = p1.acceleration - 0.01;

p.acceleration = p.acceleration - 0.001;
if (p.acceleration<0) p.acceleration =0;


p1.acceleration = p1.acceleration - 0.001;
if (p1.acceleration<0) p1.acceleration =0;


SDL_Delay(3);
t_fin=SDL_GetTicks();
dt=t_fin - t_prev ;

switch (p.direction)
{
	case 0:
	   if (collisionPP_droite(p.position,mask,b.backgroundPos)==0)
	   {
		    scrolling(&b.backgroundPos,p.direction,p.dx);
		    scrolling_enemie(&e,p.direction,p.dx);
		    deplacerPerso(&p,dt);  
    	   }
    	break;

	case 1:
	    if (collisionPP_gauche(p.position,mask,b.backgroundPos)==0)
	    {
		    scrolling(&b.backgroundPos,p.direction,p.dx);
		    scrolling_enemie(&e,p.direction,p.dx);
		    deplacerPerso(&p,dt);
	    }
	break;
}


switch (p1.direction)
{
	case 0:
	    if (collisionPP_droite(p1.position,mask,b.backgroundPos2)==0)
	    {
		    scrolling(&b.backgroundPos2,p1.direction,p1.dx);
		    scrolling_enemie(&e,p.direction,p.dx);
		    deplacerPerso2(&p1,dt);
	    }
    	break;

	case 1:
	    if (collisionPP_gauche(p1.position,mask,b.backgroundPos2)==0)
	    {
		    scrolling(&b.backgroundPos2,p1.direction,p1.dx);
		    scrolling_enemie(&e,p.direction,p.dx);
		    deplacerPerso2(&p1,dt);
	    }
	    break;
}

update_score(&v);
deplacerIA(&e,p.position);
m.pos_joueur=MAJMinimap(p.position,20,b.backgroundPos);
animerennemi(&e);
animerPerso(&p);
animerPerso(&p1);

if (p.up==0 && collisionPP_down(p.position,mask,b.backgroundPos)==0)
{
   p.vitesse_saut+=15;
    p.ground+=15;
}
if (collisionPP_down(p.position,mask,b.backgroundPos)==1){
    p.ground=p.position.y;
  //  printf("co\n");
} 

if (p1.up==0 && collisionPP_down(p1.position,mask,b.backgroundPos2)==0)
{
    p.vitesse_saut+=15;
    p1.ground+=15;
}
if (collisionPP_down(p1.position,mask,b.backgroundPos2)==1)
{
    p1.ground=p1.position.y;
    printf("co\n");
} 

if (up1==1) saut(&p1);

if (up==1) saut(&p);
printf("%f\n",p.vitesse_saut);
p.position.y = p.position.y   + p.vitesse_saut ;
p.vitesse_saut = p.vitesse_saut + 10 ;

if (p.position.y>=p.ground)
{   
    p.position.y=p.ground;
    p.vitesse_saut=0;
    p.up=0;
}

p1.position.y = p1.position.y   + p1.vitesse_saut ;
p1.vitesse_saut = p1.vitesse_saut + 10 ;

if (p1.position.y>=p1.ground)
{   
    p1.position.y=p1.ground;
    p1.vitesse_saut=0;
    p1.up=0;
}

}



/*----------partie affichage---------*/


/////////////////////////////////////////////
SDL_BlitSurface(back,NULL,screen,NULL);
if (mode==mono_joueur)
{
    afficherBack(b,screen);
    afficherPerso(p,screen);
    afficherennemi(&e,screen);
    affichertemp(&temps,screen,police);
    afficherminimap(m,screen);
    afficher_vie(&v,screen);
}

if (mode==new_game)
{
	SDL_BlitSurface(sous_menu_1[choix],NULL,screen,NULL);
}
	
if (mode==multijoueur)
{
    afficherBack_partage(b,screen);
    afficherPerso(p,screen);
    afficherPerso(p1,screen);
}

if (mode==save_game)
{
	SDL_BlitSurface(menu[choix],NULL,screen,NULL);
}

SDL_Flip(screen);

SDL_Delay(30);

//afficher le texte
//display(t,screen);
   	

}
	

    return 0;
}





