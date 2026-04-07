#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

struct tab
{
    int *tab1;
    int *tab2;
    int taille1;
    int taille2;
};
typedef struct tab tab;

void *assignation_tab(void*arg)
{ 
    int taille1= *(int*)arg;
    int *tableau=malloc(taille1*sizeof(int));
    for(int i=0;i<taille1;i++)
    {
       sleep(1);
       tableau[i]=rand()%100;
    }
    return (void*)tableau;
}

void *test_inclusion(void *arg)
{
    int compteur=0,i;
    tab t=*(tab*) arg;
    for(i=0;i<t.taille1;i++)
    {
        for(i=0;i<t.taille2;i++)
        {
            if(t.tab1[i]==t.tab2[i])
            {
                compteur++;
            }
        }
    }
    if(compteur==t.taille1)
    {
        printf("le tableau T1 est inclus dans T2");
    }
}

void* wait(void *arg)
{
   int c=getchar();
   if(c=='A')
   {
    printf("Programme annulé");
    exit(0);
   }
   
}

int main()
{
    pthread_t thread1,thread2,thread3,thread4;
    int taille1=5,taille2=6;
    int *tab1,*tab2;
    tab t;
    srand(time(NULL));
    pthread_create(&thread1,NULL,assignation_tab,&taille1);
    pthread_create(&thread2,NULL,assignation_tab,&taille2);
    pthread_create(&thread3,NULL,wait,NULL);
    pthread_join(thread1,(void**)&tab1);
    pthread_join(thread2,(void**)&tab2);
    t.tab1=tab1;
    t.tab2=tab2;
    t.taille1=taille1;
    t.taille2=taille2;
    pthread_create(&thread3,NULL,test_inclusion,&t);
    pthread_join(thread3,NULL);
    
}