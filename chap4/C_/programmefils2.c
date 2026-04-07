#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *lecture=getenv("lecture");
    if(lecture!=NULL)
    {
        int r=atoi(lecture);
        char message[100];
        read(r,message,sizeof(message)-1);
        printf("le message du père est %s ",message);
    }
    else
    {
        printf("erreur");
        return 1;
    }    
}