#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<semaphore.h>
#include<unistd.h>

int N=100;
sem_t sem;
int print;
int indice=0;

void *affect_valeur(void *arg)
{
    double *tab=(double*)arg;   
    for(int i=1;i<N-1;i++)
    {
        sem_wait(&sem);
        tab[i]=(tab[i-1]+tab[i]+tab[i+1])/3;
        sem_post(&sem);
        print=i;
        sleep(rand()%3+1);
    }
    
}

void *affiche(void *arg)
{
    int i;
    double *tab=(double*)arg;
    while(print<N)
    {
      sleep(4);
      for(i=indice;i<print;i++)
      {
        sem_wait(&sem);
        printf("tab[%d]=%f\n",i,tab[i]);
        sem_post(&sem);
      }
      indice=i;
    }  
    printf("\n");
}


int main()
{
  pthread_t thread1,thread2;
  double *tab=malloc(N*sizeof(double));
  tab[0]=0;
  tab[99]=0;

  srand(time(NULL));
  for(int i=1;i<N-1;i++)
  {
    tab[i]=rand()%101;
  }
    sem_init(&sem, 0, 1);//
    pthread_create(&thread1,NULL,affect_valeur,tab);
    pthread_create(&thread2,NULL,affiche,tab);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    sem_destroy(&sem);
}