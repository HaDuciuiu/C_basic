#include<stdio.h>
void nhapMang(int arr[],int *n)
{
	int i;
	printf("nhap vao kich thuoc cua mang:\n");
	scanf("%d",n);
	printf("Nhap vao cac phan tu mang:\n");
	for(i=0;i<*n;i++)
	{
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
int kiem_tra_mang_giong_nhau(int A[],int B[],int m,int n)
{
	int i,dem=1;
	if(m!=n)
	{
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(A[i]!=B[i])
		{
			dem = 0;
			return 0;	
		}
	}
	return 1;
}
int main()
{
	int A[100];
	int B[100];
	int m,n;
	printf("Nhap vao mang thu nhat\n");
	nhapMang(A,&m);
	printf("Nhap vao mang thu hai\n");
	nhapMang(B,&n);
	printf("Hai mang vua nhap vao lan luot la:\n");
	inMang(A,m);
	inMang(B,n);
	if(kiem_tra_mang_giong_nhau(A,B,m,n))
	{
		printf("Hai mang giong nhau\n");
	}
	else
	{
		printf("Hai mang khac nhau\n");
	}
	return 0;
}
