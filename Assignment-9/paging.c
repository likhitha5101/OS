#include<stdio.h>
#include<stdlib.h>

int pagesize;
int no_of_frames;
int free_frames_avail;
int physical_memory_size;
typedef struct pagetable
{
	int pageno;
	int frameno;
	int process;
	struct pagetable* next;
}pt;
typedef struct freeframes
{
	int frame;
	int avail;
	struct freeframes* next;
}ff;
pt* create_p()
{
	pt* newTable = (pt*)malloc(sizeof(pt));
	newTable->next = NULL;
	return newTable;
}
ff* create_f()
{
	ff* FrameList = malloc(sizeof(ff));
	FrameList->next = NULL;
	return FrameList;
}
pt* newMap(int process,int pageno,int frameno)
{
	pt* link = malloc(sizeof(pt));
	link->pageno = pageno;
	link->frameno = frameno;
	link->process = process;
	link->next = NULL;
	return link;
}
ff* newFrame(int frame, int avail)
{
	ff* newFrame = malloc(sizeof(ff));
	newFrame->frame = frame;
	newFrame->avail = avail;
	newFrame->next = NULL;
	return newFrame;
}
void insertLast_frame(ff* head, ff* newNode)
{
	ff* temp = head;
	while(temp->next!=NULL)
		temp = temp->next;
	newNode->next = temp->next;
	temp->next = newNode;
}
void insertLast_table(pt* head, pt* newNode)
{
	pt* temp = head;
	while(temp->next!=NULL)
		temp = temp->next;
	newNode->next = temp->next;
	temp->next = newNode;
}
void display_table(pt* table)
{
	pt * temp_table = table->next;
	while(temp_table!=NULL)
	{
		printf("Process : %d\t Page: %d\t Frameno : %d \n",temp_table->process, temp_table->pageno,temp_table->frameno);
		temp_table = temp_table->next;
	}
}
void display_frames(ff* framelist)
{
	ff* temp_frame = framelist->next;
        	while(temp_frame!=NULL)
        	{
        		printf("Frame : %d\t avail:%d \n",temp_frame->frame,temp_frame->avail);
		temp_frame = temp_frame->next;
	}
}
void delete_frame(ff* framelist, ff* delNode)
{
	ff* temp = framelist;
	while(temp->next != NULL)
	{
		if(temp->next->avail == delNode->avail)		
			break;
		temp = temp->next;
	}
	temp->next = temp->next->next;
}
void delete_link(pt* framelist, pt* delNode)
{
	pt* temp = framelist;
	while(temp->next != NULL)
	{
		if(temp->next->process == delNode->process)		
			break;
		temp = temp->next;
	}
	temp->next = temp->next->next;
}
void request(int process_id, int process_size, pt* table, ff* framelist)
{
	int reqd_frames = process_size / pagesize;
	ff* temp;
	pt* link;
	if(reqd_frames  > free_frames_avail)
	{
		printf("Request Denied : Not enough memory \n");
		return;
	}	
	else
	{
		for(int i = 0;i < reqd_frames;i++)
		{
			temp = framelist->next;
			while(temp->avail != 1)
				temp = temp->next;
			temp->avail = 0;
			link = newMap(process_id,i,temp->frame);
			delete_frame(framelist, temp);
			insertLast_table(table, link);
			free_frames_avail--;
		}
	}			
}
void delc(int process_id, pt* table, ff* framelist)
{
	pt* temp = table->next;
	ff* fram;
	while(temp!=NULL)
	{
		if(temp->process == process_id)
		{
			int frameno = temp->frameno;
			int avail = 1;
			fram = newFrame(frameno,avail);
			delete_link(table,temp);
			insertLast_frame(framelist,fram);
			free_frames_avail++;
		}
		temp = temp->next;
	}
}
int fno=0;
void addressmap()
{
	int pid, logical, offset, physical,pageno;
	printf("Enter PID: ");
	scanf("%d", &pid);
	printf("Enter Logical address: ");
	scanf("%d", &logical);
	pageno = logical / (pagesize * 1024);
	offset = logical % (pagesize * 1024);
	physical = fno * pagesize * 1024 + offset;
	printf("Page no : %d\t Offset : %d\t Frameno : %d \n",pageno,offset,fno);	
	printf("Physical address: %d\n", physical);
	fno++;
}

void main()
{
	int process_id;
	int process_size;
	int choice;
	pt* table = create_p();
	ff* framelist = create_f();
	ff* temp_frame;
	pt* temp_table;

	printf("Enter the physical memory size \n");
	scanf("%d",&physical_memory_size);
	printf("Enter page size");
	scanf("%d",&pagesize);
	int no_of_frames = physical_memory_size / pagesize;
	printf("\tPhysical memory is divided into %d frames \n",no_of_frames);
	printf("Initializing physical memory and frame list\n");
	// Generating random numbers 
	for (int i = 0; i < no_of_frames; i++) 
	{ 
        		int avail = (rand() % (2)); // generates values between 0 and 1 - 0 implies unavailable;
        		temp_frame = newFrame(i,avail);
        		if(avail == 1)
        			{
        				insertLast_frame(framelist,temp_frame);
        				free_frames_avail++;
        			}
        		else	
        		{
        			int random_pid = (rand() % (11));
        			int random_page = (rand() & no_of_frames + 1);
        			temp_table = newMap(random_pid,random_page,i);
        			insertLast_table(table,temp_table);
        		}
        	}
	do 
	{
		printf("\t\t\t PAGING IMPLEMENTATION\n");
		printf("1.Process Request \n");
		printf("2.Dealloation \n");
		printf("3.Display Page table \n");
		printf("4.Display free frames\n");
		printf("5.Display logical to physical memory conversion\n");
		printf("6.Exit \n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("\n\nEnter Process ID\n");
				scanf("%d",&process_id);
				printf("Enter size of the process \n");
				scanf("%d",&process_size);
				request(process_id,process_size,table,framelist);
				break;
			case 2:
				printf("\n\nEnter Process ID to deallocated\n");
				scanf("%d",&process_id);
				delc(process_id,table,framelist);
				break;
			case 3:
				display_table(table);
				break;
			case 4:	
				display_frames(framelist);
				break;
			case 5:   addressmap();
				break;
		}
	}while(choice!=6);
}
			