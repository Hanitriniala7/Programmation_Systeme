#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>

int variable;
sem_t sem1,sem2;

void *emetteur(void *arg)
{
    sleep(rand()%3+1);
    sem_wait(&sem1);
    pthread_mutex_lock(&mutex);  
    variable=rand()%256;
    pthread_mutex_unlock(&mutex);  
    sem_post(&sem2);
}

void *recepteur(void *arg)
{
    sleep(rand()%3+1);
    sem_wait(&sem2);
    pthread_mutex_lock(&mutex);  
    printf("la variable est %d",variable);
    pthread_mutex_unlock(&mutex);  
    sem_post(&sem1);
}

int main()
{
    pthread_t thread1,thread2;
    sem_init(&sem1,0,1);// surveille que la valeur a été bien lu avant de générer un autre
    sem_init(&sem2,0,0);//surveille que la valeur a été bien générer avant de l'afficher
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread1,NULL,emetteur,NULL);
    pthread_create(&thread1,NULL,recepteur,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return(0);
}