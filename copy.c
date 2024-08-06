#include<stdio.h>
#include<stdlib.h>
#define SIZE 1024

int main(int argc,char** argv)
{
        if(argc!=3)
        {
                printf("Usage : COMMAND SourceFILENAME DestFILENAME \n");
                return -1;
        }

        FILE *sfptr , *dfptr;

        sfptr = fopen(argv[1],"r");
        if(sfptr == NULL)
        {
                printf("SOURCE FILE '%s' does not exist\n",argv[1]);
                return -2;
        }

        dfptr = fopen(argv[2],"w");
        if(dfptr == NULL)
        {
                printf("Destinatin FILE '%s' does not exist\n",argv[2]);
                return -3;
        }

        char buffer[SIZE];
        int bytesRead;
        while( (bytesRead = fread(buffer,1,SIZE,sfptr)) > 0 )
           {
                fwrite(buffer,1,bytesRead,dfptr);
        }

        fclose(sfptr);
        fclose(dfptr);

        printf("Succesfully copied file contents from %s to %s\n",argv[1],argv[2]);
        return 0;
}

