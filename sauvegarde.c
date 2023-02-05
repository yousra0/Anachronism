
#include "sauvegarde.h"

void sauvegarder (Personne p,Background b) 
{
	FILE *fichier;
	save s;

	s.p=p;
	s.b=b;

	fichier=fopen("save_perso","wb");

	if (fichier != NULL)
	{
	    fwrite(&s,sizeof(save),1,fichier);
	    printf("game saved\n");

	}
	else
	{
		printf("failed");
	}


	fclose(fichier);

}

int charger (Personne *p,Background *b )
{
    FILE *fichier;
    save s;

    fichier=fopen("save_perso","rb");
    fread(&s,sizeof(save),1,fichier);
    fclose(fichier);

    p->position.x=s.p.position.x;
    p->position.y=s.p.position.y;

    b->camera.x=s.b.camera.x;
    b->camera.y=s.b.camera.y;
    
    printf("perso et background chargés\n");

}

