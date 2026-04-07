#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<semaphore.h>
#include<unistd.h>

int compteur=0;
double u;
sem_t sem1;
sem_t sem2;

void *pro1(void* arg)
{
    while(compteur<10)
    {
        sem_wait(&sem1);
        compteur++;
        sem_post(&sem1);
        sem_wait(&sem2);
        u=(1.0/4.0)*((u-1)*(u-1));
        printf("la valeur u dans T1  :%f",u);
        sem_post(&sem2);
        sleep(rand()%5+1);
    }
}
void *pro2(void *arg)
{
    while(compteur<10) //juste pour voir le resulat
    {
        sem_wait(&sem1);
        compteur++;
        sem_post(&sem1);
        sem_wait(&sem2);
        u=(1.0/6.0)*((u-2)*(u-2));
         printf("la valeur de u dans T2 :%f",u);
        sem_post(&sem2);
        sleep(rand()%5+1);
    }    
}

int main()
{
    pthread_t thread1,thread2;
    u=1;
    srand(time(NULL));
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 1);
    pthread_create(&thread1,NULL,pro1,NULL);
    pthread_create(&thread2,NULL,pro2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    sem_destroy(&sem1);
    sem_destroy(&sem2);
}

