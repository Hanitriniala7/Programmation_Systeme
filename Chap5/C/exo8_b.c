#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>

sem_t sem;
int compteur=0;

void *function_thread(void *arg)
{
      int N=*(int*)arg;
      sleep(rand()%5+1);
      pthread_mutex_lock(&mutex);
      compteur++;
      if(compteur==N) // si tous les threads ont fini on réecremente le sem ,les threads peuvent continuer
      {
        for(int i=0;i<N;i++)
        sem_post(&sem);
      }
      else
      {
        sem_wait(&sem);// sinon on attend les autres threads
      }
      pthread_mutex_unlock(&mutex);
}

int main(int argc,char *argv[])
{
    if(argc<2)
    {
        printf("erreur");
    }
    else
    {
        int N=atoi(argv[1]);
        pthread_mutex_init(&mutex, NULL);
        sem_init(&sem, 0, 0);
        pthread_t thread[N];
        for(i=0;i<N;i++)
        {
            pthread_create(&thread[i],NULL,function_thread,&N);
        }
        for(i=0;i<N;i++)
        {
            pthread_join(thread[i],NULL);
        }
    }
    return(0);
}