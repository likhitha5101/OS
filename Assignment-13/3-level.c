
//TREE_STRUCTURE DIRECTORY
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree
{
char name[25]; //name of dir/file
int df; //dir-1/file-0
struct tree *main; //main directory
struct tree *sub; //subdirectories
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
if(P->df==1 && P->main!=NULL)
display(P);
P=P->sub;
i++;
}while(P!=NULL);
}
void main()
{
int nu,nc;
int i,j,k;
struct tree *tree_dir;
tree_dir=malloc(sizeof(struct tree));
tree_dir->df=1;
tree_dir->main=NULL;
tree_dir->sub=NULL;
create(tree_dir,1);
for(in=0;in<count;in++)
{
printf("\n Enter number of child nodes for %s:",root[in]->name);
scanf("%d",&nc);
create(root[in],nc);
}
printf("\n--Tree Structure Directory--\n(1-Directory\t\t0-File)\n");
display(tree_dir);
}