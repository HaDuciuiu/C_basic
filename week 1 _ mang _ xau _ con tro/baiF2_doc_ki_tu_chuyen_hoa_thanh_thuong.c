#include<stdio.h>
void doc_ghi_File(FILE *fin,FILE *fout)
{
	char c;//ki tu de luu vao tung ki tu doc duoc
	fin = fopen("lab2.txt","r");//mo file duoi chuc nang doc
	if(fin == NULL)
	{
		printf("Khong mo duoc file , kiem tra lai \n");
		return;
	}
	else
	{
		fout = fopen("lab2ra.txt","w");
		while((c=fgetc(fin))!=EOF)//ham fgetc() se tra ve gia tri EOF khi doc den cuoi file
		{
			if(islower(c))//kiem tra xem c co phai 1 ki tu chu cai thuong ko?
			{
				c=toupper(c);//ham viet hoa 1 ki tu
				fputc(c,fout);/*sau khi viet hoa ki tu c xong thi ta ghi no ra file*/
				putchar(c);//in ra man hinh ki tu c
			}
			else if(isupper(c))//kiem tra xem c co phai mot ki tu chu cai hoa ko?
			{
				c=tolower(c);//ham viet thuong 1 ki tu
				fputc(c,fout);/*sau khi viet thuong ki tu c xong thi ta ghi no ra file*/
				putchar(c);//in ra man hinh ki tu c
			}
			else
			{
				fputc(c,fout);//cac ki tu khac thi in ra file mot cach y nguyen
				putchar(c);
			}	
		}
	}
}

int main()
{
	FILE *fin ;
	FILE *fout;
	doc_ghi_File(fin,fout);
 	return 0;

}

