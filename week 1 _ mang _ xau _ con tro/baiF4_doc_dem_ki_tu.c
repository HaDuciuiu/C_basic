#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void doc_dem(FILE *fin,FILE *fout)
{
	char str[100];
	int len;
	fin = fopen("laba.txt","r");
	if(fin==NULL)
	{
		printf("Mo file loi, thu lai nhe\n");
		return;
	}
	else
	{
		fout = fopen("laba1.txt","w");
		while(fgets(str,100,fin)!=NULL)
		{
			len = strlen(str)-1;// vi ham strlen tinh ca NULL nen phai tru di ptu nay
			fprintf(fout,"%d %s",len,str);// in ra file bang lenh fprintf()
			printf("%d %s\n",len,str);// in ra man hinh 	
		}
	}
}
int main()
{
	FILE *fin;
	FILE *fout;
	printf("Chuong trinh doc vao mot dong va dem so ki tu cua dong do\n");
	doc_dem(fin,fout);

return 0;

}

