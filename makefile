prog: enemie.o enig_fichier.o enigme.o enigme_IA.o main.o menu.o minimap.o option.o Personne.o sauvegarde.o background.o name.o xo.o load.o
	gcc enemie.o enig_fichier.o enigme.o enigme_IA.o main.o menu.o minimap.o option.o Personne.o sauvegarde.o background.o name.o xo.o  load.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer

enemie.o : enemie.c 
	gcc -c enemie.c  enemie.o

enig_fichier.o : enig_fichier.c 
	gcc -c enig_fichier.c enig_fichier.o

enigme.o : enigme.c
	gcc -c enigme.c enigme.o

enigme_IA.o : enigme_IA.c
	gcc -c enigme_IA.c enigme_IA.o

main.o : main.c
	gcc -c main.c main.o

menu.o : menu.c
	gcc -c menu.c menu.o

minimap .o: minimap.c
	gcc -c minimap.c minimap.o

option.o : option.c
	gcc -c option.c option.o

Personne.o : Personne.c
	gcc -c Personne.c Personne.o

sauvegarde.o : sauvegarde.c
	gcc -c sauvegarde.c sauvegarde.o

background.o : background.c
	gcc -c background.c background.o

name.o : name.c
	gcc -c name.c name.o

xo.o : xo.c
	gcc -c xo.c xo.o
	
load.o : load.c
	gcc -c load.c load.o




