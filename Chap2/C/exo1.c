#include<stdio.h>
#include<stdlib.h>
/*Écrire un programme qui prend deux arguments en ligne de commande en supposant qu ce sont des nombres entiers, et qui aﬃche l’addition de ces deux nombres.*/

int main( int argc , char *argv[])
{
    if(argc<3 || argc>3)
    {
        printf("erreur vous devez entrer deux entiers ");
        exit(1);
    }
    else
    {
        printf("%s + %s = %d",argv[1],argv[2],atoi(argv[1])+atoi(argv[2]));
        return(0);
    }
}