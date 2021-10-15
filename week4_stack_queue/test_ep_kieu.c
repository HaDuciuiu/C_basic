#include<stdio.h>
#include"stacklib.h"
int main()
{
	StackType stack;
	Initialize(stack);
	float n = (int)'7'-48;
	printf("%d\n",n);
	Push(n,stack);
	//printf("%d\n",Pop(stack));
	n= Pop(stack)/3;
	printf("n= %.2f\n",n);
	Push(n,stack);
	printf("Sau khi tinh toan : %.2f\n",Pop(stack));
  return 0;
}

