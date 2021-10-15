#include<stdio.h>
#include<stdlib.h>

int MaxSum_AG1(int arr[],int n)//Thuat toan truc tiep
{ 
 	int i,j,k;
 	int maxSum =0 ;//khoi tao mot bien maxSum de luu tong lon nhat cua day so
 	for(i=0;i<n;i++)
 	{
 		for(j=i;j<n;j++)
 		{
 			int sum=0;
			/*Phai khoi tao bien sum=0 o day de ket thuc vong lap for cua con chay k
			thi sum lai phai quay tro ve gia tri sum de tiep tuc luu vao mot tong moi*/
			for(k=i;k<=j;k++)
			{
				sum += arr[k];
				if(maxSum<sum)
				maxSum = sum;
			}
		}
	}
	return maxSum; 
}

int MaxSum_AG2(int arr[],int n)
{
	int i,j;
	int maxSum = 0;
	for(i=0;i<n;i++)
	{
		int sum =0 ;
		for(j=i;j<n;j++)
		{
			sum += arr[j];
			if(sum>maxSum)
			{
				maxSum = sum;
			}
		}
	}
	return maxSum;
}
int main()
{
	int n,i,j;
	int *arr;// dung de cap phat bo nho dong
	printf("Nhap vao so phan tu cua day so: ");
	scanf("%d",&n);
	arr = (int *)malloc(n*sizeof(int));
	printf("Nhap vao cac phan tu cua day so: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	//printf("Day con lon nhat la: %d\n",MaxSum_AG1(arr,n));
	printf("Day con lon nhat la: %d\n",MaxSum_AG2(arr,n));
	
  return 0;
}

