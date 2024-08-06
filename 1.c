#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
        FILE *ip;
        char str[100];
        if(argc!=2)
        {
                puts("usage : COmmand(./a.out) filename(exp.txt)");
                exit(0);
        }
        ip = fopen(argv[1],"r");
        if(ip ==NULL)
        {
                puts("File doesn't exist:\n");
                exit(0);
        }
        while(fgets(str,100,ip)!=NULL)
        {
                printf("%s",str);
        }
        fclose(ip);
        return 0;
}
