#include<stdio.h>

/*
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
*/
void inMang(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
}
void Max(int B[],int n)
{
	int i,max=B[0];
	for(i=0;i<n;i++)
	{
		if(max<B[i])
		max = B[i];	
	}
	printf("Gia tri lon nhat cua day so la: %d\n",max);	
}
void Min(int C[],int n)
{
	int i,min=C[0];
	for(i=0;i<n;i++)
	{
		if(min>C[i])
		min = C[i];
	}
	printf("Gia tri nho nhat cua day so la: %d\n",min);
}
void Sum(int D[],int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum += D[i];
	}
	printf("Tong cac phan tu cua day so la: %d\n",sum);
}
int main()
{
	int arr[100];
	int n,i;
	do
	{
		printf("Nhap vao so nguyen duong n>10\n");
		scanf("%d",&n);
	}while(n<10);
	for(i=0;i<n;i++)
	{
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	printf("Day so ta nhap vao la:\n");
	inMang(arr,n);
	Max(arr,n);
	Min(arr,n);
	Sum(arr,n);
return 0;

}

