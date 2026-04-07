#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
/*Ecrire un programme qui saisit un nom de ﬁchier texte au clavier et ouvre ce ﬁchier dans l’éditeur emacs, dont le ﬁchier exécutable se trouve à l’emplacement /usr/bin/emacs.*/

int main()
{
    char fichier[30];
    printf("Entrer le nom du fichier  à editer sur emacs:");
    scanf("%s",fichier);

    pid_t  pid_fils=fork();
    if(pid_fils==0)
    {
        execl("/usr/bin/emacs","emacs",fichier,NULL);
    }
    else
    {
        wait(NULL);
    }
}