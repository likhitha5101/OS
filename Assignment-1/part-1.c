//fork() and exit() commands : 

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
	int pid;
	printf("hello\n");
	pid = fork();
	if(pid == 0)
	{
		exit(1);
		printf("child process\n");
		printf("%d\n",j);
	}
	else if(pid > 0)
	{		
		printf("parent process\n");
	}
	else if(pid < 0)
		printf("Failure\n");
	

}