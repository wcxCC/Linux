#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
int i;
printf("PID=%d,PPID=%d\n",getpid(),getppid());
for(i=0;i<argc;i++)
{
printf("%s\n",argv[i]);
}
return 0;
}
