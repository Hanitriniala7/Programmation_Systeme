#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

/*Exercice 2.3 (E) crire un programme qui crée 5 ﬁls en utilisant une boucle for. On remar-
quera que pour que le ﬁls ne crée pas lui-même plusieurs ﬁls, il faut interompre la boucle par
un break dans le ﬁls.*/

int main()
{
    pid_t pid_fils;

    for(int i=0;i<5;i++)
    {
       pid_fils=fork();
       if(pid_fils==0)
       {
        printf("Le processus fils numéro %d\n",i);
        break;
       }
       else
       {
         waitpid(pid_fils,NULL,0);
       }    
    }
    return 0;
}
