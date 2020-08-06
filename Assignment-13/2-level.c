//TWO LEVEL DIRECTORIES
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct
{
char dname[10],fname[10][10];
int fcount;
}dir[10];
void main()
{
int i,ch,dcount,k;
char f[30], d[30];
dcount=0;
while(1)
{
printf("\n\n 1. Create Directory\n 2. Create File\n 3. Delete File");
printf("\n 4. Search File \n 5. Display \n 6. Exit \n Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\n Enter name of directory:");
scanf("%s", dir[dcount].dname);
dir[dcount].fcount=0;
dcount++;
printf("\nDirectory created");
break;
case 2: printf("\n Enter name of the directory:");
scanf("%s",d);
for(i=0;i<dcount;i++)
if(strcmp(d,dir[i].dname)==0)
{
printf("Enter name of the file:");
scanf("%s",dir[i].fname[dir[i].fcount]);
dir[i].fcount++;
printf("\nFile created");
break;
}
if(i==dcount)
printf("\nDirectory %s not found",d);
break;
case 3: printf("\nEnter name of the directory:");
scanf("%s",d);
for(i=0;i<dcount;i++)
{
if(strcmp(d,dir[i].dname)==0)
{
printf("\nEnter name of the file:");
scanf("%s",f);
for(k=0;k<dir[i].fcount;k++)
{
if(strcmp(f, dir[i].fname[k])==0)
{
printf("\nFile %s is deleted ",f);
dir[i].fcount--;
strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcount]);
goto jmp;
}
}
printf("\nFile %s not found",f);
goto jmp;
}
}
printf("Directory %s not found",d);
jmp : break;
case 4: printf("\nEnter name of the directory:");
scanf("%s",d);
for(i=0;i<dcount;i++)
{
if(strcmp(d,dir[i].dname)==0)
{
printf("Enter the name of the file:");
scanf("%s",f);
for(k=0;k<dir[i].fcount;k++)
{
if(strcmp(f, dir[i].fname[k])==0)
{
printf("\nFile %s is found ",f);
goto jmp1;
}
}
printf("\nFile %s not found",f);
goto jmp1;
}
}
printf("\nDirectory %s not found",d);
jmp1: break;
case 5: if(dcount==0)
printf("\nNo Directory's ");
else
{
printf("\nDirectory\tFiles");
for(i=0;i<dcount;i++)
{
printf("\n%s\t",dir[i].dname);
for(k=0;k<dir[i].fcount;k++)
printf("\t%s",dir[i].fname[k]);
}
}
break;
default:exit(0);
}
}
}