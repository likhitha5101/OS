#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <fcntl.h>

void match_pattern(char *argv[] ,int argc ,int op)
{
	char argu[argc][100];
	int flag=0;
    for (int i=1;i<argc;i++)
    {
	 	strcpy(argu[i],argv[i]);
    }
    if(argv[1][0]!='-')
    {  
		strcpy(argu[3],argu[2]);
		strcpy(argu[2],argu[1]);
		flag=0;
    }
    if(argv[1][1]=='i')
    {
		flag=1;
    }
    int fd,r,j=0,count=0,co=1,no=0;
    char temp,line[100];
    if((fd=open(argu[3],O_RDONLY)) != -1)
    {
        while((r=read(fd,&temp,sizeof(char)))!= 0)
        {
            if(temp=='\n')
                no++;
            if(temp!='\n')
            {
                line[j]=temp;
                j++;
            }
            else
            {
                if(strstr(line,argu[2])!=NULL && (op !=2 && op!=3 && op!=4))
                    {printf("%s\n",line);}
				else if(strstr(line,argu[2])!=NULL && op ==4)
                    printf("%d - %s\n",no,line);
				else if(strstr(line,argu[2])==NULL && op ==2)
                    printf("%s\n",line);
				else if(strstr(line,argu[2])!=NULL && op ==3)
                    count++;
				line[j]='\0';
                memset(line,0,sizeof(line));
                j=0;
				co++;
            }

        }
		if(op==3)
			printf("\nThe given word occured in %d line(s)\n",count);
    }   
}

int main(int argc,char *argv[])
{
    struct stat stt;
    if(argc < 3)
    {
        printf("Insufficient arguments!!!\n");
        exit(1);
    }
    else if(argc==3)
    {
        if(stat(argv[2],&stt)==0)
            match_pattern(argv,argc,1);
        else 
        {
            exit(1);
        }
    }
	else if(argc==4)
    {
        if(stat(argv[3],&stt)==0 && argv[1][0]=='-')
		{ 
        	if(argv[1][1]=='v')
            	match_pattern(argv,argc,2);
			else if(argv[1][1]=='c')
				match_pattern(argv,argc,3);
			else if(argv[1][1]=='n')
				match_pattern(argv,argc,4);
        }
        else 
        {
            exit(1);
        }
    }
    return 0;
}
