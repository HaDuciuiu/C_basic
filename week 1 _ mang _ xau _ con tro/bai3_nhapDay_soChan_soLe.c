#include<stdio.h>
void nhapMang(int arr[],int *n)
{
	int i;
	printf("Nhap vao so phan tu cua mang: ");
	scanf("%d",n);
	printf("Nhap vao cac phan tu mang:\n");
	for(i=0;i<*n;i++)
	{
		printf("arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
}
void inMang(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
void inSo_Le(int arr[],int n)
{
	int i,demL=0;
	for(i=0;i<n;i++)
	{
		if(arr[i] %2 !=0)
		{
			printf("%d\t",arr[i]);
			demL++;
		}
		
	}
	printf(",tong so le la: %d",demL);
	printf("\n");
}
void inSo_Chan(int arr[],int n)
{
	int i,demC=0;
	for(i=0;i<n;i++)
	{
		if(arr[i] %2 ==0)
		{
			printf("%d\t",arr[i]);
			demC++;
		}	
	}
	printf(",tong so chan la:%d",demC);
	printf("\n");
}
int main()
{
	int arr[100];
	int i,n;
	nhapMang(arr,&n);
	printf("Mang nhap vao ban dau la:\n");
	inMang(arr,n);
	inSo_Le(arr,n);
	inSo_Chan(arr,n);
	return 0;
}
