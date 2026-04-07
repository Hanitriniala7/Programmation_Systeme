#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
/*Écrire un programme qui crée un tube, crée un processus ﬁls, puis, dans le ﬁls, lance par execv un autre programme, appelé programme ﬁls. Le programme père transmets les descripteurs de tubes au programmes ﬁls en argument, et transmet un message au ﬁls par le tube. Le programme ﬁls aﬃche le message.*/

int main()
{
    int tube[2];
    char chaine1[100];
    pipe(tube);

    pid_t pid=fork();

    if(pid==0)
    {
       close(tube[1]);
       sprintf(chaine1,"%d",tube[0]);
       char *arg[]={"./programmefils",chaine1,NULL};
       execv("./programmefils",arg);
    }
    else
    { 
        close(tube[0]);
        char *chaine="hello ici père";
        write(tube[1],chaine,strlen(chaine));
    }
}