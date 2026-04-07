#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
/*Écrire un programme qui crée deux processus. Le processus père ouvre un ﬁchier texte en lecture. On suppose que le ﬁchier est composé de mots formés de
caractères alphabétiques séparés par des espaces. Le processus ﬁls saisit un mot au clavier. Le
processus père recherche le mot dans le ﬁchier, et transmet au ﬁls la valeur 1 si le mot est dans
le ﬁchier, et 0 sinon. Le ﬁls aﬃche le résultat.*/

int main()
{
    int tube1[2],tube2[2]; //tube 1 fils->père, tube2 père->fils
    char *fichier1="test.txt";
    char buffer[100],mot[100];
    int resultat=0,nombre,nombre2;
    FILE *fichier=fopen(fichier1, "r+");
    pipe(tube1);
    pipe(tube2);

    pid_t pid_fils=fork();

    if(pid_fils==0)
    {
        close(tube1[0]); //ne lit pas
        close(tube2[1]);//n'écrit pas
        printf("Entrer le mot que vous voulez tester si il est dans le fichier :");
        scanf("%s",mot);
        write(tube1[1],&mot,sizeof(mot));
        nombre=read(tube2[0],&resultat,sizeof(resultat));
        if(nombre>0)
        {
          printf(" résultat %d",resultat);
        }
        
    }
    else
    {
        close(tube1[1]); //n'écrit pas
        close(tube2[0]); //ne lit pas
        read(tube1[0],buffer,sizeof(buffer));
        nombre2=0;
        while(fscanf(fichier,"%s ",mot)!=EOF)
        {
            if(strcmp(mot,buffer)==0)
            {
                nombre2=1;
                break;
            }
           
        }
        write(tube2[1],&nombre2,sizeof(nombre2));

    }
   
}