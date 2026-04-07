#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
/*(E) crire un programme avec un processus père qui engendre 5 ﬁls dans une
bouble for. Les ﬁls sont nommés ﬁls 1 à ﬁls 5. Le ﬁls 1 doit aﬃcher “je suis le ﬁls 1” et le ﬁls 2
doit aﬃcher je suis le ﬁls 2, et ainsi de suite.
Indication. on pourra utiliser une variable globale.*/
int main()
{
    pid_t pid_fils;

    for(int i=0;i<5;i++)
    {
       pid_fils=fork();
       if(pid_fils==0)
       {
        printf("je suis le fils  %d\n",i+1);
        return 0;
       }
       else
       {
         waitpid(pid_fils,NULL,0);
       }    
    }
    return 0;
}