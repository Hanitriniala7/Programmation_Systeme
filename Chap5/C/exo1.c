#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
/*Écrire un programme qui crée un thread qui prend en paramètre un tableau d’entiers et l’aﬃche dans la console.*/
void *print_tab(void*arg) //fonction qui affiche le tableau
{
    int *tableau=(int*)arg; // caste de arg en int * 
    for(int i=0;i<5;i++)
    {
        printf("%d\n",tableau[i]);
    }
    return(0);
}
int main()
{
   pthread_t thread;
   int tableau[]={1,2,3,4,5};
   pthread_create(&thread,NULL,print_tab,(void*)tableau);//crée le thread
   pthread_join(thread,NULL);//thread principale(main) attend que thread a fini
   return(0);
}