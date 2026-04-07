#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int *remplissage(int taille)
{
    int *tab=malloc(taille*sizeof(int));
    for(int i=0;i<taille;i++)
    {
        printf("t[%d]= ",i);
        scanf("%d",&tab[i]);
    }
    return(tab);
}

void print_erreur(int sig)
{
   int nombre;
   printf("Entrer l'indice : ");
   scanf("%d",&nombre);
}

int main()
{
    int taille,nombre; 
    struct sigaction sig;
    sig.sa_handler = print_erreur;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;
    sigaction(SIGSEGV,&sig,NULL);

    printf("Entrer le nombre d'élément du tableau");
    scanf("%d",&taille);
    int *tab=remplissage(taille);
   
    printf("Entrer l'indice de l'élément que vous vouliez voir ");
    scanf("%d",&nombre);
    printf("tab[%d]=%d",nombre,tab[nombre]);
    
}