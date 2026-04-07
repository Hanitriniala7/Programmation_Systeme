#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>

int tableau[10];
int indice=0;
sem_t sem1,sem2;

void *pro(void *arg)
{
    while(1)
    {
        sem_wait(&sem1);
        pthread_mutex_lock(&mutex); 
        tableau[indice]=rand()%256;
        indice++ ;
        pthread_mutex_unlock(&mutex); 
        sem_post(&sem2);
        sleep(rand()%3+1);
    }    
}

void *cons(void *arg)
{
    while(1)
    {
        sem_wait(&sem2);
        pthread_mutex_lock(&mutex); 
        int prend=tableau[indice];
        indice--;
        pthread_mutex_unlock(&mutex); 
        sem_post(&sem1);
        sleep(rand()%3+1);
    }    
}

int main()
{
    int N,M;
    printf("Entrer le nombre de producteurs :");
    scanf("%d",&N);
    printf("Entrer le nombre de consommateurs :");
    scanf("%d",&M);

    pthread_t producteurs[N],consommateurs[M];
    sem_init(&sem1,0,10);
    sem_init(&sem2,0,0);
    pthread_mutex_init(&mutex, NULL);
    for(int i=0;i<N;i++)
    {
        pthread_create(&producteurs[i],NULL,pro,NULL);
    }
    for(int i=0;i<M;i++)
    {
        pthread_create(&consommateurs[i],NULL,cons,NULL);
    }

    for(int i=0;i<N;i++)
    {
        pthread_join(producteurs[i],NULL);
        
    }
    for(int i=0;i<M;i++)
    {
        pthread_join(consommateurs[i],NULL);
    }
    return(0);
}