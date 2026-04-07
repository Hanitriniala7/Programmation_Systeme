#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

/*(E) crire un programme qui crée deux ﬁls appelés ﬁls 1 et ﬁls 2. Le père doit
aﬃcher “je suis le père” et le ﬁls 1 doit aﬃcher “je suis le ﬁls 1”, et le ﬁls 2 doit aﬃcher “je
suis le ﬁls 2”.*/

int main()
{
    pid_t pid_fils1=fork();

    if(pid_fils1==0)
    {
        printf("je suis le fils 1\n");
        return(0);
    }
    else
    {
        printf("je suis le père\n");
        waitpid(pid_fils1,NULL,0);
    }

    pid_t pid_fils2=fork();

    if(pid_fils2==0)
    {
        printf("je suis le fils 2\n");
        return(0);
      
    }
    else
    {
        printf("je suis le père\n");
        waitpid(pid_fils2,NULL,0);
    }

    return 0;
}