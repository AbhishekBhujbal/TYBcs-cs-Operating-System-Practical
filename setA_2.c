#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
int pid = fork();
if (pid == 0)
{
printf("I am child process, id=%d\n",getpid());
printf("Priority :%d,id=%d\n",nice (-7),getpid());
}
else
{
printf("I am parent process, id=%d\n",getpid());
nice(1);
printf("Priority :%d,id=%d\n",nice (15),getpid());
}
}
