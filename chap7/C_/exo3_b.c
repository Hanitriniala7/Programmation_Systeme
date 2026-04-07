#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdbool.h>
void send_signal(int c,pid_t pid_fils)
{
   switch (c)
   {
     case 's':
     kill(pid_fils,SIGSTOP);
     printf("fils %d endormi",pid_fils);
     break;
     case 'r':
     kill(pid_fils,SIGCONT);
     printf("fils %d redémarré",pid_fils);
     break;
     case 'q':
     kill(pid_fils,SIGTERM);
     printf("fils %d tué",pid_fils);
     break;
     default:
     printf("option invalide");
     break;
   }
    
}

void message_fils(int sig)
{
    printf("signal recu %d",sig);
}

int main()
{
    pid_t pid[5];
    struct sigaction sig;
    sig.sa_handler=message_fils;
    for(int i=0;i<5;i++)
    {
        pid[i]=fork();
        if(pid[i]==0)
        {
            sigaction(SIGCONT, &sig, NULL);   
            sigaction(SIGTERM, &sig, NULL);  
            sigaction(SIGSTOP, &sig, NULL);  
            i=0;
            while(1)
            {
                i++;
            }

        }
    
    }
    int c,numero;
    while(1)
    {
      printf("Taper:\n(s) pour endormir un fils \n(r) pour redémarrer un fils \n(q) pour tuer un fils\n");
      c=getchar();
      printf("Entrer le numéro du processus que vous voulez envoyer ce siganl :");
      scanf("%d",&numero);
      send_signal(c,pid[numero]);
      printf("\n");
    } 
}