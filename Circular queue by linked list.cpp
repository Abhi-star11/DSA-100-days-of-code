#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int pos;
	struct node*next;
};
struct node *front=NULL, *rear =NULL;
void enqueue(struct node** front,struct node**rear,int size)
{
	
	int value;
	int pos;
	printf("Enter the value: ");
	scanf("%d",&value);
	if(*front!=NULL&&((*rear)->pos+1)%size==(*front)->pos)
	{
		printf("Overflow! queue if full\n");
		return;
		
	struct node *temp=*front;
	if(*front=*rear)
	{
		*front=*rear=NULL;
		
	}
	else
	{
		*front = (*front)->next;
		(*rear)->next=*front;
	}
	free(temp);
}
struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	if(newnode==NULL)
	{
		printf("Memory not available\n");
	}
	if(*front==NULL)
	{
		*front=*rear=newnode;
		newnode->pos=0;
		(*rear)->next=*front;
	}
	else
	{
		newnode->pos=((*rear)->pos+1)%size;
		(*rear)->next=newnode;
		*rear=newnode;
		(*rear)->next=*front;
	}
	printf("%d Inserted successfully!\n",value);
}
void dequeue(struct node* front,struct node*rear,int size)
{
	if(front==NULL)
	{
		printf("Queue is empty Underflow\n");
		return;
	}
	struct node *temp=front;
	if(front==rear)
	{
		front=rear=NULL;
	}
	else
	{
		front=front->next;
		rear->next=front;
	}
	printf("%d is successfully deleted\n",temp->data);
	free(temp);
}
void display(struct node* front,struct node*rear)
{
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return;
		
	}
	struct node*temp=front;
	printf("Queue elements: ");
	do
	{
		printf("%d->",temp->data);
		temp=temp->next;
		
	}while(temp!=front);
	printf("(back to front)\n");
}
int main()
{
	struct node*front=NULL,*rear=NULL;
	int size;
	printf("Enter the size: ");
	scanf("%d",&size);
	int choice;
	while(1)
	{
		printf("CIRCULAR QUEUE MENUE\n");
		printf("1. Enqueue (Insert)\n");
		printf("2. Dequeue (Delete)\n");
		printf("3. Display\n");
		printf("4. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: enqueue(&front,&rear,size);
			break;
			case 2: dequeue(front,rear,size);
			break;
			case 3: display(front,rear);
			break;
			case 4:
				printf("Exiting program....\n");
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
}
