//DAG DIRECTORY ORGANISATION
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trees
{
char from_d[20];
char file[20];
char to[20];
int flag;
}linkk;
struct tree
{
char name[25]; //name of dir/file
int df; //dir-1/file-0
struct tree *main; //main directory
struct tree *sub; //sub-directories
linkk link; //link
};
struct tree *root[20];
int in=0,count=0;
void create(struct tree *P,int N) //N is the number of child nodes
{
int i;
struct tree *Temp,*T;
Temp=P;
for(i=0;i<N;i++)
{
T=malloc(sizeof(struct tree));
printf("\nEnter name: ");
scanf("%s",T->name);
printf("\nEnter dir(1) or file(0): ");
scanf("%d",&T->df);
if(T->df==1)
{
root[count]=T;
count++;
}
T->main=NULL;
T->sub=NULL;
if(i==0)
{
Temp->main=T;
Temp=T;
}
else
{
Temp->sub=T;
Temp=T;
}
}
}
void links(struct tree *P)
{
char src[10],dest[20],f[20];
printf("Enter destination directory:");
scanf("%s",dest);
printf("Enter source directory:");
scanf("%s",src);
printf("Enter the filename:");
scanf("%s",f);
P=(P->main)->main;
while(strcmp(P->name,dest)!=0)
P=P->sub;
if(strcmp(P->name,dest)==0)
{
P->link.flag=1;
strcpy(P->link.from_d,src);
strcpy(P->link.to,dest);
strcpy(P->link.file,f);
}
}
void display(struct tree *P)
{
int i;
P=P->main;
i=0;
do{
if(P->df==1)
{
printf("\nDIR:\t");
}
printf("%s(%d)\n\t\t",P->name,P->df);
if(P->link.flag==1)
printf("\n\t\tLink:%s(0)-From dir:%s\n\t\t",P->link.file,P->link.from_d);
if(P->df==1 && P->main!=NULL)
display(P);
P=P->sub;
i++;
}while(P!=NULL);
}
void main()
{
int nc;
int i,j,k;
int ch;
struct tree *tree_dir;
tree_dir=malloc(sizeof(struct tree));
tree_dir->df=1;
tree_dir->main=NULL;
tree_dir->sub=NULL;
create(tree_dir,1);
printf("\n1.Create fil/dir\n2.Create link\n");
scanf("%d",&ch);
do{
if(ch==1)
{
for(in=0;in<count;in++)
{
printf("\n Enter number of child nodes for %s:",root[in]->name);
scanf("%d",&nc);
create(root[in],nc);
}
printf("\n--Tree Structure Directory--\n(1-Directory\t\t0-File)\n");
display(tree_dir);
}
else if(ch==2)
{
links(tree_dir);
printf("\n--Tree Structure Directory--\n(1-Directory\t\t0-File)\n");
display(tree_dir);
}
else
exit(0);
printf("\n\n1.Create fil/dir\n2.Create link\n");
scanf("%d",&ch);
}while(ch==1||ch==2);
}