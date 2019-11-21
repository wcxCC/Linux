//验证亲缘关系之间共享文件池是共享还是独立
#include "my.h"

int main()
{
	int pid1,pid2;
	FILE * fp;
	fp=fopen("out.dat","w+");
	pid1=fork();
	pid2=fork();
	if(pid1<0||pid2<0)
	{
		perror("打开失败\n");
	}
	else if(pid1==0)
	{
		fprintf(fp,"123456789 pid1:%d\n",getpid());
	}
	else if(pid2>0)
	{
		fprintf(fp,"123456789 pid2:%d\n",getpid());
	}
	
	

}
