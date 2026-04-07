#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<semaphore.h>

int compteur=0;
int fini=0;
sem_t sem;

void *pro1(void*arg)
{
    int nombre=*(int*)arg;
    while(1)
    {
       sem_wait(&sem);
       compteur++;
        if(compteur==nombre)
        {
            printf("nombre atteint ");
            fini=1;
            exit(0);
        }
        sem_post(&sem);
        sleep(rand()%5+1);
    }
}

void *pro2(void *arg)
{

    while(1)
    {
      sleep(2);
      sem_wait(&sem);
      if(fini==1)
      {
        break;
      }
      else
      {
       printf("le compteur est %d\n",compteur);
       sem_post(&sem);
      }
    }   

}

int main(int argc,char *argv[])
{
    if(argc<2)
    {
        printf("Erreur");
        return(1);

    }
    else
    {
        int nombre=atoi(argv[1]);  
        srand(time(NULL));
        pthread_t thread1,thread2;
        sem_init(&sem, 0, 1);//un processus peut avoir accès au section critique (la variable compteur)
        pthread_create(&thread1,NULL,pro1,&nombre);
        pthread_create(&thread2,NULL,pro2,NULL);
        pthread_join(thread1,NULL);
        pthread_join(thread2,NULL);
        sem_destroy(&sem);    
    } 

}    