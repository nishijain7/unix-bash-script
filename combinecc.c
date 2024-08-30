#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<setjmp.h>

static jmp_buf buf;
void first(){
    printf("First\n");
    longjmp(buf, 1);
}
void sec(){
    first();
    printf("Sec\n");
}

int main(int argc,char *argv[]){
    if(argc != 3){
        printf("Usage : %s OriFile DestFile",argv[0]);
        exit(0);
    }

    struct stat b1;
    stat(argv[1],&b1);
    printf("Links = %d\n",b1.st_nlink);

    int x;
    x = link(argv[1],argv[2]);
    if(x== 0){
        printf("Linking successful\n");
    }
    else{
        printf("Linking UNsuccessful\n");
    }

    struct stat b2;
    stat(argv[1],&b2);
    printf("Links = %d\n",b2.st_nlink);

    int y;
    y = unlink(argv[2]);
    if( y == 0){
        printf("Uninking successful\n");
    }
    else{
        printf("Uninking UNsuccessful\n");
    }

    struct stat b3;
    stat(argv[1],&b3);
    printf("Links = %d\n",b3.st_nlink);

    if( setjmp(buf) == 0){
        printf("Main 1\n");
        sec();
    }
    else{
        printf("Main 2\n");
    }
}
