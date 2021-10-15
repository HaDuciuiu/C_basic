#include<stdio.h>
void docFile(FILE *fin,FILE *fout)
{
	int c;// bien c de luu ki tu doc vao tu file
	fin = fopen("lab.txt","r");
	if(fin==NULL)
	{
		printf("Khong the mo file , vui long kiem tra lai\n");
		return;
	}
	else
	{
		fout = fopen("lab1.txt","w");
		if(fout==NULL)
		{
			printf("file loi , kiem tra lai\n");
			return;
		}
	}
	while((c=fgetc(fin))!=EOF)//ham fgetc()tra ve EOF khi doc den cuoi file
	{
		fputc(c,fout);//ghi ra file fout ki tu c vua doc duoc
		putchar(c);//ghi ra man hinh cac ki tu c vua doc duoc	
	}
}
int main()
{
	FILE *fin;
	FILE *fout;
	docFile(fin,fout);
	printf("\nCo gang moi ngay nhe!\n");
return 0;

}

