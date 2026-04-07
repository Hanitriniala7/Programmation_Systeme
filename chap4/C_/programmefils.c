#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    if(argc<2)
    {
        printf("erreur");
        return 1;
    }

    else
    {
        char message[100];
        int tube=atoi(argv[1]);
        int nombre=read(tube,message,sizeof(message)-1);
        message[nombre]='\0';
        printf("le message venant du père est :%s ",message);
    }
    return(0);
}