#include<stdio.h>
#include<unistd.h>
/*(E) crire un programme qui crée un ﬁls. Le père doit aﬃcher “je suis le père”
et le ﬁls doit aﬃcher “je suis le ﬁls”.*/

int main()
{
    pid_t pid_fils=fork();

    if(pid_fils==0)
    {
         printf("je suis le fils");
    }
    else
    {
        printf("je suis le père");
    }

    return 0;
}