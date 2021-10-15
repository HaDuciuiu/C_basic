#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10];
	int n;
	printf("Nhap vao day 11 so nguyen :\n");
	int i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if(arr[i]==n)
		{
			printf("vi tri - chi so cua phan tu tim thay trong mang : %d\n",i);
			exit(0);
		}
	}
	printf("khong tim thay phan tu trong mang :%d\n",0);
  return 0;
}

