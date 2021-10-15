#include<stdio.h>
#include<string.h>
#include"stack_linkedList.h"

int main()
{
	Stack *stack1 , *stack2 , *stack3;
	stack1 = CreatStack();
	stack2 = CreatStack();
	stack3 = CreatStack();
	char str1[Max],str2[Max];
	printf("Nhap so hang 1: ");
	scanf("%[0123456789]",str1);
	fseek(stdin,0,SEEK_END);
	printf("Nhap so hang 2: ");
	scanf("%[0123456789]",str2);
	int i;
	for(i=0;i<strlen(str1);i++)
	{
		Push(stack1,str1[i]-48);
	}
	for(i=0;i<strlen(str2);i++)
	{
		Push(stack2,str2[i]-48);
	}
	int carry = 0,local_sum =0;
	while(!StackEmpty(stack1)||!StackEmpty(stack2))
	{
		local_sum = carry;
		if(!StackEmpty(stack1))
		{
			local_sum += Pop(stack1);
		}
		if(!StackEmpty(stack2))
		{
			local_sum+=Pop(stack2);
		}
		if(local_sum>=10)
		{
			local_sum-=10;
			carry=1;
		}else 
		{
			carry =0;
		}
		Push(stack3,local_sum);
	}
	printf("Ket qua :\n");
	while(!StackEmpty(stack3))
	{
		printf("%d",Pop(stack3));
	}
  return 0;
}

