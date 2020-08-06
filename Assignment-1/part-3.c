//file commands : 

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void main()
{
	int sz;
	int fd = open("w1.c", O_RDONLY);
	 char *c = (char *) calloc(100, sizeof(char));
	if(fd > -1)
	{
		printf("file opened\n");
		sz = read(fd, c, 100); 
		c[sz] = '\0'; 
		printf("The contents of file are : % s\n", c); 
		if(close(fd) < 0)
			printf("File is not closed properly\n");
		else
			printf("File is closed\n");
		
	}
	else
	{
		printf("file is not opened\n");
		int fc = creat("w2.c",O_RDONLY | O_WRONLY);
		if(fc > 0)
			printf("The file is created\n");
		else
			printf("The file is not created\n");
		fd = open("w2.c", O_WRONLY);
		sz = write(fd, "This is new file\n", strlen("This is new file\n")); 
  
  		printf("written % d %d %d\n", fd, strlen("This is new file\n"), sz); 
  
  		close(fd); 

	}

}