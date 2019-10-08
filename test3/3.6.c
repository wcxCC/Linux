#include "apue.h"
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    if((fd=open("lseek",O_RDWR | O_APPEND)) < 0)
    {
        err_sys("open file error!");
        exit(-1);
    }

    int offt;
    if((offt=lseek(fd, 0, SEEK_END)) == -1)
    {
        err_sys("lseek error!");
        exit(-1);
    }


    int wb;
    if((wb=write(fd,"test\n", 5)) < 0)
    {
        err_sys("write error!");
        exit(-1);
    }
    int rb;
    char *rd;
    if((rb=read(fd,rd,wb)) < 0)
    {
        err_sys("read error");
        exit(-1);
    }

    if(write(STDOUT_FILENO, rd, rb) != rb){
        err_sys("ouput result error!");
        exit(-1);
    }

/*
    int n;
    char *rd;
    int wd;
    while ((n=read(fd,rd,1024)) > 0)
        if (write(STDOUT_FILENO,rd,wd) != wd)
            err_sys("write error!");
    if (n < 0)
        err_sys("write error");
*/
    exit(0);
}
