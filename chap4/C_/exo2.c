#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
/*) eprendre les programmes de l’exercice ??. Nous allons faire un programme qui fait la même chose, mais transmet les données diﬀérement. Dans le programme père, on liera les ﬂots stdout et stdin à un tube.*/
int main()
{
    int tube[2],tube1[2],nombre;
    char mot[20],mot1[20];
    pipe(tube);
    pipe(tube1);

    FILE *fichier=fopen("test.txt","r");

    pid_t pid=fork();
    if(pid==0)
    {
        printf("Entrer le mot :");
        scanf("%s",mot);

        dup2(tube[0],STDIN_FILENO);
        dup2(tube1[1],STDOUT_FILENO);

    }
    else
    {
        scanf("%s",mot);
        nombre=0;
        while(fscanf(fichier,"%s",mot1)!=EOF)
        {
            if(strcmp(mot1,mot)==0)
            {
               nombre=1;
               break;
            }
        }
        printf("%d",nombre);
    }
}