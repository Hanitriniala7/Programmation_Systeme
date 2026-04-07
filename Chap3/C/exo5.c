#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
#include<stdlib.h>
/*(E) crire un programme qui crée deux ﬁls appelés ﬁls 1 et ﬁls 2. Chaque ﬁls
doit attendre un nombre de secondes aléatoire entre 1 et 10, en utilisant la fonction sleep.
Le programme attend que le ﬁls le plus long se termine et aﬃche la durée totale. On pourra
utiliser la fonction time de la bibliothèque time.h, qui retourne le nombre de secondes depuis
le premier janvier 1970 à 0h (en temps universel).*/

int main()
{
    srand(time(NULL));
    time_t debut=time(NULL); // donne le temps en sec du commencement du programme référence  premier janvier 1970 à 0h 
    pid_t pid_fils1=fork();
    
    if(pid_fils1==0)
    {
        sleep(rand()%10+1);
        return(0);
    }
    pid_t pid_fils2=fork();
    if(pid_fils2==0)
    {
    
      sleep(rand()%10+1);
      return(0);
    }
    wait(NULL);
    wait(NULL);
    time_t fin=time(NULL);//donne le temps en sec de la fin du programme référence  premier janvier 1970 à 0h 
    printf("la durée totale est %ld",fin-debut);
    return(0);
}