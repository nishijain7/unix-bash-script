#include<stdio.h>
#include<unistd.h>
#include<setjmp.h>
#include<stdlib.h>
jmp_buf buffer;
void handle_error(){
	printf("Error occured, jumping back to th eset point\n");
	longjmp(buffer,1);
}
int main(){
	const char *filename="Example.txt";
	const char *linkname="Example_link.txt";
	FILE  *file=fopen(filename,"w");
	if(!file)
	{
		perror("Error creating file");
		return 1;
	}
	fprintf(file,"This is an example file\n");
	fclose(file);
	if(link(filename,linkname)==-1)
	{
		perror("Error creating link");
		return 1;
	}
	else{
		printf("Link created:%s->%s\n",linkname,filename);
	}
	if(unlink(linkname)==-1)
	{
		perror("Error unlinking file");
		return 1;
	}
	else
	{
		printf("Link removed %s\n",linkname);
	}
	if(setjmp(buffer)==0)
	{
		printf("Setting jumpoint.\n");
		handle_error();
	}
	else{
		printf("Returned to jmp point using longjmp\n");
		}
	unlink(filename);
	return 0;
	}

	
