#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdbool.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    char buffer[10];
    pid_t pid_fils=fork();
    if(pid_fils==0)
    {
        char* args[]={"./exo2_affiche",NULL};
        execv("./exo2_affiche",args);
    }
    else
    {
        int fd=open("/tmp/text.txt",O_WRONLY | O_CREAT | O_TRUNC,0644);
        int nombre;
        printf("Entrer un nombre entier ");
        scanf("%d",&nombre);
        sprintf(buffer,"%d",nombre);
        write(fd,buffer,strlen(buffer));
        close(fd);
        kill(pid_fils,SIGINT);
    }
    return(0);
}