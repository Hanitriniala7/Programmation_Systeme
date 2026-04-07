#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

void select_fic(char *name)
{
    struct stat fic;// contient les informations du fichier
    stat(name, &fic);

    float taille=fic.st_size;// taille en octets
    if(taille>1048576)//plus de 1Mo
    {
        printf("->%s appartenant %d \n",name,fic.st_uid);
    }

}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("erreur");
        return(1);
    }
    else
    {
        DIR *rep;
        char *chaine;
        struct dirent *p;
        for(int i=1;i<argc;i++)
        {
            rep=opendir(argv[i]);//ouvre le dossier
            while((p=readdir(rep))!=NULL)//lit les fichiers de chaque dossier
            {
               chaine=malloc(strlen(argv[i]) + strlen(p->d_name) + 2);         
               sprintf(chaine,"%s/%s",argv[i],p->d_name);//donne le chemin complet pour donner au stat  
               select_fic(chaine);
            }  
        }
        closedir(rep);
    }
    return(0);
}