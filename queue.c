#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int rear=-1,front=-1;
void enQueue(int queue[],int n)
{
	if(rear==MAX-1)
	{
		printf("\nQueue is Full/OverFlow\n");
		return;
	}
	if(front==-1)
		front=0;
	queue[++rear]=n;
}
int deQueue(int queue[])
{
	if(front==-1||front>rear)
	{
		printf("\nQueue is Empty / Underflow\n");
		return 0;
	}
	return queue[front++];
}
int topValue(int queue[])
{
	if(front==-1||front>rear)
	{
		printf("\nQueue is Empty / Underflow\n");
		return;
	}
	return queue[front];
}
void display(int s[])
{
	int i;
	printf("\n****The Queue****\n\n"); 
	for(i=rear;i>=front;i--)
		printf("%d <- ",s[i]);
	printf("\n");
}
int main()
{
	int queue[MAX],ch,n;
	printf("Enter\n1->Enqueue\n2->Dequeue\n3->Top\n4->Exit\n");
	while(1)
	{
		printf("\nEnter your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the data to insert : ");
				scanf("%d",&n);
				enQueue(queue,n);
				display(queue);
				break;
			case 2:
				if(!(front==-1||front>rear))
				{
				printf("\nThe Popped Element is : %d\n",deQueue(queue));
				display(queue);
				}
				else
				printf("\nDequeue() is unsuccessful\n");
				break;
			case 3:
				if(!(front==-1||front>rear))
				printf("\nThe value of the top of the Queue is : %d\n",topValue(queue));
				else
				printf("\nQueue is Empty\n"); 
				break;
			case 4:
				exit(0);
			default : printf("\nYou Entered a Wrong Keyword...Please enter the correct keyword\n");
		}
	}
	return 0;
}
