//SINGLE LEVEL DIRECTORY
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct filee
{
char fname[10];
int loc;
}file;
typedef struct directory
{
char dname[10];
int count;
file f[10];
}direc;
void main()
{
int i,ch;
int copy;
char f[30];
direc dir;
dir.count = 0;
printf("\nEnter name of directory : ");
scanf("%s", dir.dname);
while(1)
{
printf("\n\n 1. Create File\t2. Delete File\t3. Search File \n 4. Display Files\t5. Exit\nEnter your choice :
");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\n Enter the name of the file : ");
int fcount=dir.count;
copy=0;
if(dir.count==0)
{
scanf("%s",dir.f[dir.count].fname);
dir.f[dir.count].loc=10;
dir.count++;
}
else
{
scanf("%s",f);
for(i=0;i<dir.count;i++)
{
if(strcmp(f,dir.f[i].fname)==0)
{
copy=1;
printf("FILE ALREADY EXISTS!");
break;
}
}
if(copy!=1)
{
strcpy(dir.f[fcount].fname,f);
dir.f[fcount].loc=dir.f[fcount-1].loc + 15;
dir.count++;
break;
}
}
break;
case 2: printf("\n Enter the name of the file : ");
scanf("%s",f);
for(i=0;i<dir.count;i++)
{
if(strcmp(f, dir.f[i].fname)==0)
{
printf("File %s is deleted ",f);
strcpy(dir.f[i].fname,dir.f[dir.count-1].fname);
break;
}
}
if(i==dir.count)
printf("File %s not found",f);
else
dir.count--;
break;
case 3: printf("\n Enter the name of the file : ");
scanf("%s",f);
for(i=0;i<dir.count;i++)
{
if(strcmp(f, dir.f[i].fname)==0)
{
printf("File %s is found ", f);
break;
}
}
if(i==dir.count)
printf("File %s not found",f);
break;
case 4: if(dir.count==0)
printf("\n Directory Empty");
else
{
printf("\n The Files are : ");
printf("\nFile\tLocation");
for(i=0;i<dir.count;i++)
printf("\n%s\t%d",dir.f[i].fname,dir.f[i].loc);
}
break;
default: exit(0);
}
}
}