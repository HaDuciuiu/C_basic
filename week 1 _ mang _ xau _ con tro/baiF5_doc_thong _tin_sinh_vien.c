#include<stdio.h>
#include<string.h>
typedef struct sinhvien
{
	int stt;
	int Msssv;
	char hoTen[20];
	int diem;
	int Sdt;
}SV;
void docFile(FILE *fin)
{
	int i;
	SV sinhvien[5];
	fin = fopen("sinhvien.txt","r");
	if(fin==NULL)
	{
		printf("Khong tho mo file , kiem tra lai\n");
		return;//ket thuc chuong trinh luon
	}
	else
	{
		for(i=0;i<4;i++)
		{
			fscanf(fin,"%d %d %s %d",&sinhvien[i].stt,&sinhvien[i].Msssv,&sinhvien[i].hoTen,&sinhvien[i].stt);
			if(feof(fin))//ket thuc file
			{
				break;
			}
		}
	}
	fclose(fin);
}
void nhap_diem_in_file(FILE *fout)
{
	int i;
	SV sinhvien[5];
	printf("Nhap diem cho cac sinh vien nha \n");
	for(i=0;i<4;i++)
	{
		printf("Sinh vien thu %d:\n",i+1);
		scanf("%d",&sinhvien[i].diem);
	}
	fout = fopen("sinhvien1.txt","w");
	for(i=0;i<4;i++)
	{
		fprintf(fout,"%d% d% s %d %d\n",sinhvien[i].stt,sinhvien[i].Msssv,sinhvien[i].hoTen,sinhvien[i].Sdt,sinhvien[i].diem);
	}
	fclose(fout);
	
}
/*
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
*/
int main()
{
	FILE *fin;
	FILE *fout;
	printf("Chuong trinh doc thong tin sinh vien luu vao cau truc va in ra mot file khac\n");
	docFile(fin);
	nhap_diem_in_file(fout);
return 0;

}

