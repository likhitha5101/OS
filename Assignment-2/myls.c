#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
void ls_a(struct dirent **name,int n)
{
	if(n<=0)
	{
		printf("Directory not found..\n");
		exit(0);
	}
	while(n--)
	{
		printf("%s \t\t\t",name[n]->d_name);
		free(name[n]);
		if(n%2)
		printf("\n");
	}
}
void ls_1(struct dirent **name,int n)
{
	if(n<=0)
	{
		printf("Directory not found..\n");
		exit(0);
	}
	while(n--)
	{
		if(name[n]->d_name[0]!='.')
			printf("%s \n",name[n]->d_name);
		free(name[n]);
	}
}
void ls_r(struct dirent **name,int n)
{
	if(n<=0)
	{
		printf("Directory not found..\n");
		exit(0);
	}
	for(int i=1;i<n;++i)
	{
		if(name[i]->d_name[0]!='.')
			printf("%s \n",name[i]->d_name);
		free(name[i]);
	}
}
void ls_i(struct dirent **name,int n)
{
	if(n<=0)
	{
		printf("Directory not found..\n");
		exit(0);
	}
	for(int i=1;i<n;++i)
	{
		if(name[i]->d_name[0]!='.')
			printf("%ld \t %s \n",name[i]->d_ino,name[i]->d_name);
		free(name[i]);
	}
}
int main(int argc,char *argv[])
{
	struct dirent **name;
	int n;
	if(argc==1 || (argc <= 2 && argv[1][0]!='-'))
	{
		
		if(argc==1)
			n=scandir(".",&name,NULL,alphasort);
		else
			n=scandir(argv[1],&name,NULL,alphasort);
	
		if(n<=0)
		{
			printf("Directory not found..\n");
			exit(0);
		}
		while(n--)
		{
			if(name[n]->d_name[0]!='.')
				printf("%s \t\t\t",name[n]->d_name);
			free(name[n]);
			if(n%2)
			printf("\n");
		}
	}
	else if (argv[1][1]=='a')
	{
	if(argc==2)
		n=scandir(".",&name,NULL,alphasort);
	else		
		n=scandir(argv[2],&name,NULL,alphasort);
	ls_a(name,n);
	}
	else if (argv[1][1]=='1')
	{
	if(argc==2)
		n=scandir(".",&name,NULL,alphasort);
	else		
		n=scandir(argv[2],&name,NULL,alphasort);
	ls_1(name,n);
	}
	else if (argv[1][1]=='r')
	{
	if(argc==2)
		n=scandir(".",&name,NULL,alphasort);
	else		
		n=scandir(argv[2],&name,NULL,alphasort);
	ls_r(name,n);
	}
	else if (argv[1][1]=='i')
	{
	if(argc==2)
		n=scandir(".",&name,NULL,alphasort);
	else		
		n=scandir(argv[2],&name,NULL,alphasort);
	ls_i(name,n);
	}
	else
	{
		printf("\n Invalid Option...\n");
		exit(1);
	}
	printf("\n");
	free(name);
	return 0;
}
