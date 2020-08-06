#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
void copy(int src, int dest, char * buff)
{
	int nbread;
	while((nbread=read(src,buff,10))>0)
		write(dest,buff,nbread);
	printf("FILE CONTENTS COPIED SUCCESSFULLY!!!\n");
	close(src);
	close(dest);

}

int main(int argc,char *argv[])
{
int src,dest,x,y,temp;
char op;
char * buff =(char *)calloc(100,(sizeof(char)));

if(argc<3)
{
	printf("Insufficient arguments\n");
	exit(1);
}
else if(argc>4)
{
	printf("Too many arguments\n");
	exit(1);
}
else if(argc == 3)
{
	src=open(argv[1],O_RDONLY);
	dest=creat(argv[2],O_RDWR | O_CREAT | S_IRWXU);
	if(argv[1][0]=='-')
	{
		printf("\nInsufficient arguments!!!\n");
		exit(1);
	}
	if(src == -1)
	{
	printf("\nFile not found..\n");
	exit(1);
	}
	else
	copy(src,dest,buff);
}
else
{
	x=2;y=3;

	src=open(argv[x],O_RDONLY);
	if(src==-1)
	{
		printf("\nFile does not exists...\n");
		exit(1);
	}
	temp=open(argv[y],O_RDONLY);
	if(temp==-1 && strcmp(argv[1],"-i")==0)
	{
		dest=creat(argv[y],O_RDWR | O_CREAT | S_IRWXU);
		printf("Destination File does not exist..\nCreating a new file..\n");
		copy(src,dest,buff);
	}
	else if(temp!=-1 && strcmp(argv[1],"-i")==0)
	{
		printf("\nFile already present. Do you want to overwrite? :");
		scanf("%c",&op);
		if(op=='y'||op=='Y')
		{
			dest=creat(argv[y],O_RDWR | O_CREAT | S_IRWXU);
			copy(src,dest,buff);
		}
		else
		exit(1);
	}
	if(strcmp(argv[1],"-f")==0)
	{
		dest=creat(argv[y],O_RDWR | O_CREAT | S_IRWXU);
		copy(src,dest,buff);
	}
	if(strcmp(argv[1],"-v")==0)
	{
		if(src==-1)
			printf("\nSource file doesn't exists...");
		else
		{
			dest=creat(argv[y],O_RDWR | O_CREAT | S_IRWXU);
			copy(src,dest,buff);
			printf("\"%s\" --> \"%s\"\n",argv[2],argv[3]);
		}
	}
}
return 0;
}
