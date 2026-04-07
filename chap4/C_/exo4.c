#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

/*M ) ême question qu’à l’exercice ?? mais en passant les descripteurs de tube comme variables d’environnement.*/
int main()
{
    int tube[2];
    pipe(tube);
    char chaine1[10],chaine2[10];

    sprintf(chaine2,"%d",tube[0]);
    setenv("lecture",chaine2,1);// conversion en variable d'environnement
    sprintf(chaine1,"%d",tube[1]);
    setenv("ecriture",chaine1,1);

    pid_t pid=fork();

    if(pid==0)
    {
      close(tube[1]);
      char *arg[]={"./programmefils2",NULL};
      execv("./programmefils2",arg);
    }
    else
    {
      close(tube[0]);
      char *message="hello,ici père";
      write(tube[1],message,strlen(message));
    }

    return(0);
}
