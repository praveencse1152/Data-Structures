#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head=NULL;
node *getnode()
{
	node *temp=(node *)malloc(sizeof(node));
	printf("\nEnter the data to insert : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	return temp;
}
void insertBack()
{
	printf("\n***Inserting at Back****\n");
	node *temp=getnode();
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		node *a=head;
		while(a->link)
		{
			a=a->link;
		}
		a->link=temp;
	}
}
void insertFront()
{
	printf("\n****Inserting at Front****\n");
	node *temp=getnode();
	if(head==NULL)
		head=temp;
	else
	{
		temp->link=head;
		head=temp;
	}
}
void deleteFront()
{
	printf("\n****Deleting at Front****\n");
	if(head==NULL)
		printf("\nList is Empty\n");
	else if(head->link==NULL)
	{
		printf("\nThe Deleted Value is : %d\n",head->data);
		head=NULL;
	}
	else
	{
		node *temp=head;
		head=head->link;
		printf("\nThe Deleted Value is : %d\n",temp->data);
		free(temp);
	}
}
void deleteBack()
{
	printf("\n****Deleting at Back****\n");
	if(head==NULL)
		printf("\nList is Empty\n");
	else if(head->link==NULL)
	{
		printf("\nThe Deleted Value is : %d\n",head->data);
		head=NULL;
	}
	else
	{
		node *temp=head;
		while(temp->link->link)
		{
			temp=temp->link;
		}
		node *ptr=temp->link;
		temp->link=NULL;
		printf("\nThe Deleted Value is : %d\n",ptr->data);
		free(ptr);
	}
}
void display()
{
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	node *temp=head;
	printf("\n****The List****\n");
	while(temp)
	{
		printf("%d < - ",temp->data);
		temp=temp->link;
	}
}
void reversePrint(node *temp)
{
	if(temp==NULL)
		return;
	reversePrint(temp->link);
	printf("%d < - ",temp->data);
}
void reverseValue(node *temp)
{
	node *a=NULL,*b=NULL;
	while(temp)
	{
		a=temp->link;
		temp->link=b;
		b=temp;
		temp=a;
	}
	head=b;
}
int main()
{
	int ch;
	printf("Enter\n1->Insert at Front\n2->Insert at Back\n3->Delete at Front\n4->Delete at Back\n5->Display\n6->Print in Reverse\n7->Change in reverse\n8->Exit\n");
	while(1)
	{
		printf("\nEnter your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertFront();
				break;
			case 2:
				insertBack();
				break;
			case 3:
				deleteFront();
				break;
			case 4:
				deleteBack();
				break;
			case 5:
				display();
				break;
			case 6:
				reversePrint(head);
				break;
			case 7:
				reverseValue(head);
				break;
			case 8:
				exit(0);
			default : printf("\nEntered keyword is not Correct...Please try to Enter the correct keyword\n");
		}
	}
	return 0;
}
