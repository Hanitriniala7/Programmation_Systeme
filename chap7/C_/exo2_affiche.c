#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdbool.h>
#include<stdlib.h>
#include<fcntl.h>

void print_int(int sig)
{
    int fd=open("/tmp/text.txt",O_RDONLY);
    char nombre[10];
    int t=read(fd,nombre,sizeof(nombre)-1);
    nombre[t]='\0';
    int nombre1=atoi(nombre);
    printf("le nombre tapé est %d",nombre1);
    exit(0);
}
int main()
{
    struct sigaction sig;
    sig.sa_handler=print_int;
    sigaction(SIGINT,&sig,NULL);
    while(1)
    {
        sleep(2);
    }
}  