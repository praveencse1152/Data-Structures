#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top=-1;
void push(int stack[],int n)
{
	if(top==MAX-1)
	{
		printf("\nStack is Full/OverFlow\n");
		return;
	}
	stack[++top]=n;
}
int pop(int stack[])
{
	if(top==-1)
	{
		printf("\nStack is Empty / Underflow\n");
		return 0;
	}
	return stack[top--];
}
int topValue(int stack[])
{
	if(top==-1)
	{
		printf("\nStack is Empty / Underflow\n");
		return;
	}
	return stack[top];
}
void display(int s[])
{
	int i;
	printf("\n****The Stack****\n\n"); 
	for(i=0;i<=top;i++)
		printf("%d <- ",s[i]);
	printf("\n");
}
int main()
{
	int stack[MAX],ch,n;
	printf("Enter\n1->Push\n2->Pop\n3->Top\n4->Exit\n");
	while(1)
	{
		printf("\nEnter your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the data to insert : ");
				scanf("%d",&n);
				push(stack,n);
				display(stack);
				break;
			case 2:
				if(top!=-1)
				{
				printf("\nThe Popped Element is : %d\n",pop(stack));
				display(stack);
				}
				else
				printf("\nPop() is unsuccessful\n");
				break;
			case 3:
				if(top!=-1)
				printf("\nThe value of the top of the Stack is : %d\n",topValue(stack));
				else
				printf("\nStack is Empty\n"); 
				break;
			case 4:
				exit(0);
			default : printf("\nYou Entered a Wrong Keyword...Please enter the correct keyword\n");
		}
	}
	return 0;
}
