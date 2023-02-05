#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include "enigme_IA.h"   

//puissance


Casee afficher_jeton(SDL_Surface *screen,SDL_Surface *rouge,SDL_Event event,int t[6][7])
{
int i=5;
Casee c;
SDL_Rect pos;
if ((event.motion.x>175)&&(event.motion.x<276))
{pos.x=175-10;
c.c=0;}
if ((event.motion.x>306)&&(event.motion.x<399))
{pos.x=306-8;
c.c=1;}
if ((event.motion.x>439)&&(event.motion.x<533))
{pos.x=439-8;
c.c=2;}
if ((event.motion.x>571)&&(event.motion.x<667))
{c.c=3;
pos.x=571-8;}
if ((event.motion.x>706)&&(event.motion.x<800))
{c.c=4;
pos.x=706-8;}
if ((event.motion.x>838)&&(event.motion.x<934))
{c.c=5;
pos.x=838-8;}
if ((event.motion.x>972)&&(event.motion.x<1068))
{c.c=6;
pos.x=972-8;}
while ((t[i][c.c]!=0)&&(i>0))
i--;
if (i==0)
{c.l=0;
pos.y=22-5;//22-5
}
if (i==1)
{pos.y=154-5;//154-5
c.l=1;
}
if (i==2)
{pos.y=287-5;//287-5
c.l=2;}
if (i==3)
{c.l=3;
pos.y=422-5;}//422-5
if (i==4)
{c.l=4;
pos.y=554-5;}//554-5
if (i==5)
{c.l=5;
pos.y=686-5;}//686-5
SDL_BlitSurface(rouge,NULL,screen,&pos);
SDL_Flip(screen);
return c;
}
Casee IA (int t [6][7])
{
Casee c;
int i,j=0,test=0,test_i=0;
while ((j<7)&&(test==0))
{i=5;
while ((i>2)&&(test==0))
{
if (((t[i][j]==2)&&(t[i-1][j]==2)&&(t[i-2][j]==2))&&((t[i-3][j]==0)))
{test=1;
c.l=i-3;								//jaune gagne v
c.c=j;}
i--;}
j++;}
i=5;
while ((i>0)&&(test==0))
{j=0;
while ((j<4)&&(test==0))
{
if (((t[i][j]==2)&&(t[i][j+1]==2)&&(t[i][j+2]==2))&&((t[i][j-1]==0)||(t[i][j+3]==0))&&((t[i-1][j+3]!=0)||(t[i-1][j-1]!=0)))
{
if ((t[i][j-1]==0)&&(j!=0)&&(t[i-1][j-1]!=0))
{c.l=i;								//jaune gagne h
c.c=j-1;
test=1;}
if ((t[i][j+3]==0)&&(t[i-1][j+3]!=0))
{c.l=i;
c.c=j+3;
test=1;}}
j++;}
i--;}
j=0;
while ((j<7)&&(test==0))
{i=5;
while ((i>2)&&(test==0))
{
if (((t[i][j]==1)&&(t[i-1][j]==1)&&(t[i-2][j]==1))&&((t[i-3][j]==0)))
{test=1;
c.l=i-3;
c.c=j;}									//bloc rouge 3
i--;}
j++;}
i=5;
while ((i>0)&&(test==0))
{j=0;
while ((j<5)&&(test==0))
{
if (((t[i][j]==1)&&(t[i][j+1]==1)&&(t[i][j+2]==1))&&((t[i][j-1]==0)||(t[i][j+3]==0)))
{
if ((t[i][j+3]==0)&&((t[i-1][j+3]!=0)||(i==5)))
{test=1;
c.l=i;
c.c=j+3;}
if ((t[i][j-1]==0)&&(j!=0)&&((t[i-1][j-1]!=0)||(i==5)))							//bloc rouge 3 h
{test=1;
c.l=i;
c.c=j-1;}}
j++;}
i--;}
j=0;
while ((j<7)&&(test==0))
{i=5;
while ((i>1)&&(test==0))
{
if (((t[i][j]==2)&&(t[i-1][j]==2))&&((t[i-2][j]==0)))
{test=1;
c.l=i-2;
c.c=j;}
i--;}
j++;}
i=5;
while ((i>0)&&(test==0))
{j=0;
while ((j<5)&&(test==0))
{
if (((t[i][j]==2)&&(t[i][j+1]==2))&&((t[i][j-1]==0)||(t[i][j+2]==0)))
{
if ((t[i][j-1]==0)&&(j!=0)&&((t[i-1][j-1]!=0)||(i==5)))
{test=1;
c.l=i;
c.c=j-1;}
if ((t[i][j+2]==0)&&((t[i-1][j+2]!=0)||(i==5)))
{test=1;
c.l=i;
c.c=j+2;}}
j++;}
i--;}
j=0;
while ((j<7)&&(test==0))
{i=5;
while ((i>0)&&(test==0))
{
if (((t[i][j]==2))&&((t[i-1][j]==0)))
{test=1;
c.l=i-1;
c.c=j;}
i--;}
j++;}
i=5;
while ((i>0)&&(test==0))
{j=0;
while ((j<6)&&(test==0))
{
if ((t[i][j]==2)&&(((t[i][j-1]==0)||(t[i][j+1]==0))))
{

if ((t[i][j-1]==0)&&(j!=0)&&((t[i-1][j-1]!=0)||(i==5)))
{test=1;
c.l=i;
c.c=j-1;}
if ((t[i][j+1]==0)&&((t[i-1][j+1]!=0)||(i==5)))
{test=1;
c.l=i;
c.c=j+1;}}
j++;}
i--;}
j=rand()%7;
while ((test==0))
{i=5;
while ((i>0)&&(test==0))
{
if (t[i][j]==0)
{test=1;
c.c=j;
c.l=i;}
i--;}
j++;}
return c;
}
void afficher_jaune (SDL_Surface *screen,SDL_Surface *jaune,Casee c)
{
SDL_Rect pos;
if (c.c==0)
{pos.x=175-10;
}
if (c.c==1)
{pos.x=306-8;
}
if (c.c==2)
{pos.x=439-8;
}
if (c.c==3)
{
pos.x=571-8;}
if (c.c==4)
{
pos.x=706-8;}
if (c.c==5)
{
pos.x=838-8;}
if (c.c==6)
{
pos.x=972-8;}
if (c.l==0)
{
pos.y=22-5;}
if (c.l==1)
{pos.y=154-5;

}
if (c.l==2)
{pos.y=287-5;
}
if (c.l==3)
{
pos.y=422-5;}
if (c.l==4)
{
pos.y=554-5;}
if (c.l==5)
{
pos.y=686-5;}
SDL_BlitSurface(jaune,NULL,screen,&pos);
SDL_Flip(screen);
}
int checkk (int t[7][7])
{
int j_g=0,pc_g=0,test=0,j=0,i;
while ((j_g==0)&&(pc_g==0)&&(j<7))
{i=5;
while((i>2)&&(j_g==0)&&(pc_g==0))
{
if ((t[i][j]==1)&&(t[i-1][j]==1)&&(t[i-2][j]==1)&&(t[i-3][j]==1))
j_g=1;
if ((t[i][j]==2)&&(t[i-1][j]==2)&&(t[i-2][j]==2)&&(t[i-3][j]==2))
pc_g=1;
i--;}
j++;}
i=5;
while ((j_g==0)&&(pc_g==0)&&(i>0))
{j=0;
while((j<4)&&(j_g==0)&&(pc_g==0))
{
if ((t[i][j]==1)&&(t[i][j+1]==1)&&(t[i][j+2]==1)&&(t[i][j+3]==1))
j_g=1;
if ((t[i][j]==2)&&(t[i][j+1]==2)&&(t[i][j+2]==2)&&(t[i][j+3]==2))
pc_g=1;
j++;}
i--;}
j=0;
while ((j_g==0)&&(pc_g==0)&&(j<4))
{i=5;
while((i>2)&&(j_g==0)&&(pc_g==0))
{
if ((t[i][j]==1)&&(t[i-1][j+1]==1)&&(t[i-2][j+2]==1)&&(t[i-3][j+3]==1))
j_g=1;
if ((t[i][j]==2)&&(t[i-1][j+1]==2)&&(t[i-2][j+2]==2)&&(t[i-3][j+3]==2))
pc_g=1;
i--;}
j++;}
j=3;
while ((j_g==0)&&(pc_g==0)&&(j<7))
{i=5;
while((i>2)&&(j_g==0)&&(pc_g==0))
{
if ((t[i][j]==1)&&(t[i-1][j-1]==1)&&(t[i-2][j-2]==1)&&(t[i-3][j-3]==1))
j_g=1;
if ((t[i][j]==2)&&(t[i-1][j-1]==2)&&(t[i-2][j-2]==2)&&(t[i-3][j-3]==2))
pc_g=1;
i--;}
j++;}
if (j_g==1)
test=1;
if (pc_g==1)
test=2;
return test;
}


int enigme_IA()
{


TTF_Init();
TTF_Font *police = NULL;
police = TTF_OpenFont("alger.TTF",90);
SDL_Color couleur = {52,201,36};
SDL_Color couleur_r= {187,11,11};
SDL_Color couleur_n = {0,0,0};
SDL_Surface *fond_n;
SDL_Rect pos_n;
pos_n.x=480;
pos_n.y=400;
int check=0;
Casee c,c_o;
int T[6][7];
int done=1,j,i,nb_coups=0;
SDL_Surface *screen;
SDL_Surface *fond;
SDL_Surface *jaune;
SDL_Surface *rouge;
SDL_Rect pos_ecran;
SDL_Rect pos_rouge;
SDL_Rect pos;
SDL_Surface *j_g;
SDL_Surface *pc_g;
SDL_Surface *gameover;
j_g= TTF_RenderText_Blended(police,"YOU WON",couleur);
pc_g= TTF_RenderText_Blended(police,"YOU LOST",couleur_r);
gameover= TTF_RenderText_Blended(police,"Game Over",couleur_n);
pos.x=500;
pos.y=400;
SDL_Event event;
fond=IMG_Load("puissance.png");
fond_n=IMG_Load("fond.png");
jaune=IMG_Load("jaune.png");
rouge=IMG_Load("rouge.png");
pos_ecran.x=150;
pos_ecran.y=0;
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER); 
screen=SDL_SetVideoMode(1250,800,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_BlitSurface(fond,NULL,screen,&pos_ecran);
SDL_Flip(screen);
for (i=0;i<6;i++)
{
for (j=0;j<7;j++)
T[i][j]=0;
}
while (done==1)
{
while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_MOUSEBUTTONUP:
if ((check==0)&&(nb_coups<21))
{c=afficher_jeton(screen,rouge,event,T);
T[c.l][c.c]=1;
nb_coups++;
check=checkk(T);
if (nb_coups==21)
{SDL_BlitSurface(fond_n,NULL,screen,&pos_n);
SDL_Flip(screen);
SDL_BlitSurface(gameover,NULL,screen,&pos);
SDL_Flip(screen);
}
if (check==1)
{SDL_BlitSurface(fond_n,NULL,screen,&pos_n);
SDL_Flip(screen);
SDL_BlitSurface(j_g,NULL,screen,&pos);
SDL_Flip(screen);
SDL_Delay(2000);
return 1;
}
if (check==2)
{SDL_BlitSurface(fond_n,NULL,screen,&pos_n);
SDL_Flip(screen);
SDL_BlitSurface(pc_g,NULL,screen,&pos);
SDL_Flip(screen);
SDL_Delay(2000);
return 2;
}
if ((nb_coups<22)&&(check==0))
{c_o=IA(T);
T[c_o.l][c_o.c]=2;
afficher_jaune (screen,jaune,c_o);
check=checkk(T);
if (nb_coups==21)
{SDL_BlitSurface(fond_n,NULL,screen,&pos_n);
SDL_Flip(screen);
SDL_BlitSurface(gameover,NULL,screen,&pos);
SDL_Flip(screen);
}
if (check==1)
{SDL_BlitSurface(fond_n,NULL,screen,&pos_n);
SDL_Flip(screen);
SDL_BlitSurface(j_g,NULL,screen,&pos);
SDL_Flip(screen);
SDL_Delay(2000);
return check;
}
if (check==2)
{SDL_BlitSurface(fond_n,NULL,screen,&pos_n);
SDL_Flip(screen);
SDL_BlitSurface(pc_g,NULL,screen,&pos);
SDL_Flip(screen);
SDL_Delay(2000);
return check;
}}}
break;
case SDL_QUIT :
done=0;

case SDL_KEYDOWN :
if (event.key.keysym.sym==SDLK_r)
{
done=0;}
break;
break;
}}}
return 0;}
