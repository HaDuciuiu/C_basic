#include<stdio.h>
#include<string.h>
typedef struct sinhVien
{
	char Name[20];
	char Sex[10];
	char Nam[5];
	float D_toan;
	float D_tin;
	float D_TB;
}SV;
void nhapDL(SV S_vien[],int *n)
{
	int i;
	printf("Nhap vao so luong sinh vien: ");
	scanf("%d",n);
	printf("Nhap vao thong tin cho cac sinh vien:\n");
	getchar();
	for(i=0;i<*n;i++)
	{
		printf("Sinh vien %d:\n",i+1);
		printf("Name: ");
		gets(S_vien[i].Name);
		printf("Sex: ");
		gets(S_vien[i].Sex);
		printf("Nam sinh: ");
		gets(S_vien[i].Nam);
		printf("Diem toan: ");
		scanf("%f",&S_vien[i].D_toan);
		printf("Diem tin: ");
		scanf("%f",&S_vien[i].D_tin);
		getchar();
	}
}
void In(SV S_vien[],int n)
{
	int i;
	printf("Thong tin sinh vien nhap vao la:\n");
	printf("Ten\t\t\tGioi tinh\tNam sinh\tDiem toan\tDiem tin\n");
	for(i=0;i<n;i++)
	{
		printf("%-20s\t%-10s\t%s\t\t%.2f\t\t%.2f\n",S_vien[i].Name,S_vien[i].Sex,S_vien[i].Nam,S_vien[i].D_toan,S_vien[i].D_tin);
	}
}
void D_TB(SV S_vien[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		S_vien[i].D_TB = (S_vien[i].D_toan+S_vien[i].D_tin)/2;
		printf("Diem trung binh cua sinh vien %s la : %.2f\n",S_vien[i].Name,S_vien[i].D_TB);
	}
}
void In_TBMax(SV S_vien[],int n)
{
	int i;
	float max = S_vien[0].D_TB;
	for(i=0;i<n;i++)
	{
		if(max<S_vien[i].D_TB)
		{
			max = S_vien[i].D_TB;
		}
	}
	for(i=0;i<n;i++)
	{
		if(S_vien[i].D_TB == max)
		{
			printf("%s co diem trung binh max la: %.2f\n",S_vien[i].Name,S_vien[i].D_TB);
		}
	}
}
void SapXep(SV S_vien[],int n)
{
	SV temp;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		
		for(j=i+1;j<n;j++)
		{
			if(S_vien[i].D_TB < S_vien[j].D_TB)
			{
				temp = S_vien[i];
				S_vien[i] = S_vien[j];
				S_vien[j] = temp;
			}
		}
	}
	printf("Danh sach sinh vien sap xep theo diem trung binh giam dan la:\n");
	for(i=0;i<n;i++)
	{
		printf("%20s\t%.2f\n",S_vien[i].Name,S_vien[i].D_TB);
	}
}
int main()
{
	SV S_vien[100];
	int n;
	nhapDL(S_vien,&n);
	In(S_vien,n);
	D_TB(S_vien,n);
	In_TBMax(S_vien,n);
	SapXep(S_vien,n);
  return 0;
}

