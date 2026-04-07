#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
/*Ecrire un programme qui saisit des nom de ﬁchiers texte au clavier et ouvre tous ces ﬁchiers dans l’éditeur emacs. Le programme doit se poursuivre jusqu’à ce que l’utilisateur demande de quitter.*/

int main()
{
    int fin=0;
    char fichier[20];
    pid_t pid_fils;

    while(fin==0)
    {
        printf("Entrer le nom du fichier à ouvrir sur emacs : ");
        scanf("%s",fichier);
        pid_fils=fork();
        if(pid_fils==0)
        {
            execlp("emacs","emacs",fichier,NULL);
            exit(1);//au cas ou le répertoire n'existe pas execlp echoue et fils fait ce que le père fait donc il faut l'arreter
        }
        else
        {
            wait(NULL);
        }
        printf("Voulez vous quitter(1)/continuer(0)");
        scanf("%d",&fin);
    }
    return(0);
}