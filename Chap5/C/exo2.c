#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

/*Écrire un programme qui crée un thread qui alloue un tableau d’entiers, initialise les éléments par des entiers aléatoires entre 0 et 99, et retourne le tableau d’entiers.*/
void *assignation_tab(void*arg)
{ 
    int taille1= *(int*)arg;
    int *tableau=malloc(taille1*sizeof(int));
    for(int i=0;i<taille1;i++)
    {
       tableau[i]=rand()%100;
    }
    return (void*)tableau;
}
//************************************************************ */
int main()
{
    pthread_t thread;
    int taille=5;
    int *tableau;
    srand(time(NULL));
    pthread_create(&thread,NULL,assignation_tab,&taille);
    pthread_join(thread,(void**)&tableau);

    for(int i=0;i<taille;i++)
    {
       printf("tab[%d]=%d\n",i,tableau[i]);
    }
    return(0);
}