#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>
sem_t sem;

void *T1(void *arg)
{
    for(int i=0;i<10;i++)
    {
        sleep(2);
        sem_wait(&sem); //essaie d'entrer mais ne réussie pas car sem=0
    }
}
void *T2(void *arg)
{
    int t;
    for(int i=0;i<10;i++)
    {
        t = rand() % 6 + 4;
        sleep(t);
        sem_post(&sem);//une fois itération de T2 fini sem est incrémenté et T1 peut continuer
    }
}
int main()
{
    pthread_t thread1,thread2;
    sem_init(&sem, 0, 0);
    srand(time(NULL));
    pthread_create(&thread1,NULL,T1,NULL);
    pthread_create(&thread2,NULL,T2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    sem_destroy(&sem);
    
  return(0);
}