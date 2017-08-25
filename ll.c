#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node *getnode(int v)
{
	node *temp=(node *)malloc(sizeof(node));
	/*printf("\nEnter the data to insert : ");
	  scanf("%d",&temp->data);*/
	temp->data=v;
	temp->link=NULL;
	return temp;
}
node *insertBack(node *head,int v)
{
	printf("\n***Inserting at Back****\n");
	node *temp=getnode(v);
	if(head==NULL)
	{
		return temp;
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
void display(node *head)
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
node *merge(node *ptr1,node *ptr2)
{
        if(ptr1==NULL&&ptr2==NULL)
        {
		 printf("Err : Both the list is empty \n");
		 exit(0);
	}
	struct node *temp=NULL,*head=NULL,*tail=NULL;
	while(1)
	{
		if(ptr1==NULL)
		{
			tail->link=ptr2;
			break;
		}
		if(ptr2==NULL)
		{
			tail->link=ptr1;
			break;
		}
		if(ptr1->data>ptr2->data)
		{		
			temp=ptr2;
			ptr2=ptr2->link;
		}
		else if(ptr1->data<ptr2->data)
		{
        		temp=ptr1;                
			ptr1=ptr1->link;
		}
		else
		{
			temp=ptr1;
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		if(head==NULL)
			head=tail=temp;
		else
		{
			tail->link=temp;
			tail=temp;
		}

	}	
	return head;
}
int main()
{
	node *head1=NULL,*head2=NULL,*head3=NULL;
	/*int n1,n2;
	  printf("\nEnter the no of elements insert to list-1 : ");
	  scanf("%d",&n1);
	  printf("\n\t*****Enter the values of List-1****\n");*/
	head1=insertBack(head1,1);
	insertBack(head1,5);
	insertBack(head1,9);
	/*for(int i=1;i<n1;i++)
	  insertBack(head1);*/
	printf("\n-----The List-1-----\n");
	display(head1);
	printf("\n");
	/*printf("\nEnter the no of elements insert to list-2 : ");
	  scanf("%d",&n2);
	  printf("\n\tEnter the values of List-2****\n");*/
	head2=insertBack(head2,2);
	insertBack(head2,4);
	insertBack(head2,7);
	/*for(int i=1;i<n2;i++)
	  insertBack(head2);*/
	printf("\n-----The List-2-----\n");
	display(head2);
	printf("\n");
	head3=merge(head1,head2);
	printf("\n\t*****The Merged List******\n");
	display(head3);
	printf("\n");
	return 0;
}
