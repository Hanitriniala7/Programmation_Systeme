#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

/*Ecrire un programme qui prend en argument un chemin vers un répertoire R, et copie le répertoire courant dans ce répertoire R.*/
int main(int argc ,char *argv[])
{
    if(argc<2 || argc>2)
    {
        printf("Entrer un seul chemin ");
    }
    else
    {
        
        char *chemin=getcwd(NULL,0);// recpère le repertoire courant

        pid_t   pid_fils=fork();
        if(pid_fils==0)
         {
           
             execlp("cp","cp","-r",chemin,argv[1],NULL);
    
         }
         else
         {
             wait(NULL);
         }

    }
    
    return 0;
}