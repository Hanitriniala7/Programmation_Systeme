#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

//********************************************** */
int *remplissage(int taille)
{
    int *tab=malloc(taille*sizeof(int));

    for(int i=0;i<taille;i++)
    {
        printf("t[%d]=",i);
        scanf("%d",&tab[i]);
    }
    return(tab);
}
//******************************************** */
void sauvegarde_tab(int *tab,int taille)
{
    int fd=open("sauvegarde_tab",O_WRONLY | O_CREAT | O_TRUNC,0624); //0624 permission du fichier 
    for (int i=0;i<taille;i++)
    {
        write(fd,&tab[i],sizeof(int));
    }
    close(fd);
}
//******************************************* */
int main(int argc,char*argv[])
{
   int taille;
   printf("Entrer la taille du tableau");
   scanf("%d",&taille);
   int *tab=remplissage(taille);
   sauvegarde_tab(tab,taille);
   return(0);

}