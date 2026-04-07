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
     printf("fils endormi");
     break;
     case 'r':
     kill(pid_fils,SIGCONT);
     printf("fils redémarré");
     break;
     case 'q':
     kill(pid_fils,SIGTERM);
     printf("fils tué");
     break;
     default:
     printf("option invalide");
     break;
   }
    
}
int main()
{
    pid_t pid_fils=fork();
    int c;
    if(pid_fils==0)
    {
       int i=0;
       while(true)
       {
         i++;
         
       }
    }
    else
    {
        printf("Taper:\n(s) pour endormir\n(r) pour redémarrer\n(q) pour tuer\n");
        c=getchar();
        send_signal(c,pid_fils);
    }
}