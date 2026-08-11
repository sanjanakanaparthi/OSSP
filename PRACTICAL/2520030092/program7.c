#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t pid = fork();
if(pid == 0)
{
printf("Child executing ls...\n");
execl("/bin/ls","ls","-1",NULL);
}
else
{
printf("Parenting Waiting...\n");
}
return 0;
}
