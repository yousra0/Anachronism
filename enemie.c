#include "enemie.h"



void initennemi(enemie*e) {
    e->spritesheet=IMG_Load("ennemi_spr.png");
    e->frame=0;
    e->direction=0; 
    e->pos.x=2000;
    e->pos.y=450;
    e->posframe.x=0;
    e->posframe.y=0;
    e->posframe.h=100;
    e->posframe.w=100;
    e->posmax.x=2200;
    e->posmin.x=1900;

}


void afficherennemi(enemie *e, SDL_Surface * screen) {
   if (e->pos.x>0) SDL_BlitSurface(e->spritesheet,&e->posframe,screen,&e->pos);
}

void animerennemi( enemie * e) {
    e->posframe.y = e->direction * 100 ; // e->posframe.y = e->direction * e->posframe.h
    e->posframe.x = e->posframe.x + 100;// e->posframe.x = e->posframe.x + e->posframe.w
    if (e->posframe.x==400)
    {
        e->posframe.x=0;
    }
    
} 


void deplacer( enemie * e)  {
    if (e->direction==0)
    {
        e->pos.x += 5;
    }else if (e->direction==1)
    {
        e->pos.x -= 5;
    }

    if (e->pos.x > e->posmax.x)
    {
        e->direction=1;
    }
    if (e->pos.x < e->posmin.x)
    {
        e->direction=0;
    }   
}


int collision(SDL_Rect E, SDL_Rect p) {
  int collision,px,py;
  px=p.x+100;
  py=p.y+120;
  if (((px + p.w) < E.x) || (px > (E.x + E.w)) || ((py + p.h) < E.y) || (py > (E.y + E.h))) {
    collision = 0;
  } else {
    collision = 1;
  }

  return collision;
}


void deplacerIA(enemie * E, SDL_Rect posPerso) {
  if (((E -> pos.x - posPerso.x) < 200) && ((E -> pos.x - posPerso.x) > 80))  
   {
    E -> direction = 1; 
    E -> pos.x -= 8;
  } 
  else if (((E -> pos.x - posPerso.x) < -80) && ((E -> pos.x - posPerso.x) > -400))
   {
    E -> direction = 0; 
    E -> pos.x += 8;
  } 
  else if (((E -> pos.x - posPerso.x) <= 80) && ((E -> pos.x - posPerso.x) >= 0)) 
  {
    E -> direction = 3;
  } 
  else if (((E -> pos.x - posPerso.x) <= 0) && ((E -> pos.x - posPerso.x) >= -80)) 
  {
    E -> direction = 2;
  }
  else deplacer(E);

}

void scrolling_enemie(enemie *E,int direction,int pasAvancement){
  if (direction==1)
	{
		 E->pos.x += pasAvancement;
     E->posmin.x += pasAvancement;
     E->posmax.x += pasAvancement;
	}else if (direction==0)
	{
		E->pos.x -= pasAvancement;
    E->posmin.x -= pasAvancement;
    E->posmax.x -= pasAvancement;
	}
}
