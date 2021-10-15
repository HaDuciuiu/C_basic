#include<stdio.h>
enum {SUCCESS,FAIL,MAX_LEN=81
};//ham khai bao cac hang so duoc su dung trong toan chuong trinh
void Line_read_write(FILE *fin,FILE *fout)
{
	char str[MAX_LEN];//mang de doc va luu tru ki tu
	fin = fopen("lab.txt","r");
	if(fin==NULL)
	{
		printf("Khong the mo file, kiem tra lai nhe\n");
		return ;
	}
	else
	{
		fout = fopen("lab3.txt","w");//mo file de ghi vao file
		while(fgets(str,MAX_LEN,fin) != NULL)
		{
			fputs(str,fout);//ghi chuoi str dc doc vao file fout
			puts(str);//in chuoi str ra man hinh
		}
	}
}

int main()
{
	FILE *fin;
	FILE *fout;
	printf("chuong trinh doc vao mot dong tu file va ghi ra file khac\n");
	Line_read_write(fin,fout);                                                                                                                                
return 0;

}

