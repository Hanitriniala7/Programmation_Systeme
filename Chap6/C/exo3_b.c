#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int *chargement_en_memoire(char *name,int *taille)
{
    int fd=open(name,O_RDONLY);
    int *tab=NULL;
    int *temp;
    int nombre,i=0;
    while(read(fd,&nombre,sizeof(int))!=0)//lire tant que le fichier est vide mais par int 
    {
        temp = realloc(tab, (i + 1) * sizeof(int));
        if (temp == NULL)
        {
            free(tab);
            return NULL;
        }

        tab = temp;
        tab[i] = nombre;
        i++;
    }
    *taille=i-1;
    return(tab);
}
int main()
{
    char fichier[100];
    int taille=0;
    printf("Entrer le nom du fichier ");
    scanf("%s",fichier);
    int *tab=chargement_en_memoire(fichier,&taille);
    int i;
    for(i=0;i<taille;i++)
    {
        printf("%d\n",tab[i]);
    
    }
}