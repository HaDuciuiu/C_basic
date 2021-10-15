#include<stdio.h>
#include<stdlib.h>
int dem=0;
int binSearch(int List[], int Target, int Size) 
{
// target la so can tim, size la kich thuoc list
	int Mid;
	int Low = 0;
	int High = Size-1;
	while ( Low <= High ) 
	{
		Mid = (Low+High)/2;
		if ( List[Mid] == Target )
		{
			dem ++;
			return Mid;
		}
			
		else if ( Target < List[Mid] )
		{
			High = Mid - 1;
			dem++;
		}
			
		else
		{
			Low = Mid + 1;
			dem++;	
		}		
	}
	return -1;
}
int main()
{
	int A[100];
	FILE *fin;
	int i;
	fin = fopen("mangSo.txt","r");
	if(fin==NULL)
	{
		printf("Loi o buoc doc file , kiem tra lai \n");
		exit(1);
	}
	for(i=0;i<100;i++)
	{
		fscanf(fin,"%d",&A[i]);
	}
	printf("Cac phan tu doc vao tu file la :\n");
	for(i=0;i<100;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	int n;// bien luu gia tri can tim kiem
	printf("Nhap vao gia tri can tim kiem:\n");
	scanf("%d",&n);
	int k = binSearch(A,n,100);
	if(k>=0)
	{
		printf("ket qua tim thay %d tai chi so %d ",n,k);
		printf("So phep toan thuc hien la: %d\n",dem);	
	}
	else
	{
		printf("NOT FOUND\n");
	}
	fclose(fin);
  return 0;
}

