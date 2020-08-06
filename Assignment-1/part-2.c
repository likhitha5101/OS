//getpid(),getppid(),exec() and sleep() commands:

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	int pid;
	printf("hello\n");
	pid = fork();
	if(pid == 0)
	{
		printf("%d\n",j);
		printf("child process\n");
		printf("%d\n%d\n",getpid(),getppid());
	}
	else if(pid > 0)
	{
		wait(&pid);
		scanf("%d",&j);
		printf("parent process\n");
		sleep(1);
		printf("%d\n%d\n",getpid(),getppid());
	}
	else if(pid < 0)
		printf("Failure\n");
	execl("/bin/ls","/bin/ls",NULL);
	printf("%d\n",j);
	

}