#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

#define SIZE 1024

int main(int argc,char **argv){
    if(argc != 3){
        printf("Usage :  %s  SourceFile NewFile",argv[0]);
        return -1;
    }
    struct stat buf;
    stat(argv[1], &buf);
    printf("links %d\n",buf.st_nlink);

    int x;
    x= link(argv[1],argv[2]);
    if(x==0){
        printf("link succ\n");
    }
    else{
        printf("link unsecu\n");
    }
    struct stat buf2;
    stat(argv[1], &buf2);
    printf("links %d\n",buf2.st_nlink);

    int y;
    y= unlink(argv[2]);
    if(y==0){
        printf("unlink succ\n");
    }
    else{
        printf("unlink unsecu\n");
        
    }
    struct stat buf3;
    stat(argv[1], &buf3);
    printf("links %d\n",buf3.st_nlink);
}
