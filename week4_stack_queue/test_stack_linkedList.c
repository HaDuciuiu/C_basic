#include<stdio.h>
#include<stdlib.h>
#include"stack_linkedList.h"
int main()
{
	StackType *top = NULL;
	int n,value;
	do
	{
	do
	{
	printf("Enter the element to be pushed\n");
	scanf("%d",&value);
	top = Push(top,value);
	printf("Enter 1 to continue\n");
	scanf("%d",&n);
	} while(n == 1);
	printf("Enter 1 to pop an element\n");
	scanf("%d",&n);
	while( n == 1)
	{
	top = Pop(top,&value);
	printf("The value poped is %d\n",value);
	printf("Enter 1 to pop an element\n");
	scanf("%d",&n);
	}
	printf("Enter 1 to continue\n");
	scanf("%d",&n);
	} while(n == 1);
}
