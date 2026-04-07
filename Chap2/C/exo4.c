#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
/*Ecrire un programme qui saisit des noms de répertoires au clavier et copie le répertoire courant dans tous ces répertoires. Le programme doit se poursuivre jusqu’à ce que l’utilisateur demande de quitter le programme.*/

int main()
{
    int fin=0;
    char repertoire[20];
    char rep_courant=getcwd(NULL,0);
    pid_t pid_fils;

    while(fin==0)
    {
        printf("Entrer le nom du répertoire : ");
        scanf("%s",repertoire);
        pid_fils=fork();
        if(pid_fils==0)
        {
            execlp("cp","cp","-r",rep_courant,repertoire,NULL);
            exit(1);//au cas ou le répertoire n'existe pas execlp echoue et fils fait ce que le père fait donc il faut l'arreter
        }
        else
        {
            wait(NULL);
        }
        printf("Voulez vous quitter/continuer (1/0)");
        scanf("%d",&fin);
    }
       return(0);
}