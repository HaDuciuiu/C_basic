#include<stdio.h>

/*
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
*/
void nhapMang(int A[],int *n)
{
	int i;
	printf("Nhap vao so phan tu cua mang: ");
	scanf("%d",n);// n la con tro nen ko dung toan tu &
	printf("Nhap gia tri cua cac phan tu mang:\n");
	for(i=0;i<*n;i++)
	{
		printf("arr[%d] = ",i);
		scanf("%d",&A[i]);
	}
}
void inMang(int B[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",B[i]);
	}
	printf("\n");
}
void daoMang(int C[],int n)
{
	int i,j;
	int temp;//bien trung gian dung de dao nguoc mang
	for(i=0,j=n-1;i<=j;i++,j--)
	{
		temp = C[i];
		C[i] = C[j];
		C[j] = temp;	
	}
}
int main()
{
	int arr[100];
	int n;
	nhapMang(arr,&n);
	printf("Mang ban dau la:\n");
	inMang(arr,n);
	daoMang(arr,n);
	printf("Mang sau khi dao nguoc la:\n");
	inMang(arr,n);
return 0;

}

