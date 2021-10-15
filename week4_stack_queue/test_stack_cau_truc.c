#include<stdio.h>
#include"stack_cau_truc.h"
int main()
{
	StackType stack;
	Initialize(&stack);
	int arr[Max];
	int n,i;
	do
	{
		printf("Nhap vao so phan tu : ");
		scanf("%d",&n);
	}while(n<=0);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		Push(arr[i],&stack);
	}
	printf("Dao nguoc mot mang su dung stack\n");
	while(!IsEmpty(stack))
	{
		printf("%d\t",Pop(&stack));
	}
  return 0;
}

