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
     break;
     case 'r':
     kill(pid_fils,SIGCONT);
     break;
     case 'q':
     kill(pid_fils,SIGTERM);
     break;
     default:
     printf("option invalide");
     break;
   }
    
}

int main()
{
    pid_t pid[5];
    for(int i=0;i<5;i++)
    {
        pid[i]=fork();
        if(pid[i]==0)
        {
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
    } 
}