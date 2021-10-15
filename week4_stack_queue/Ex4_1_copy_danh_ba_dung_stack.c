#include<stdio.h>
#include<string.h>
#include"Stack_tu_lam.h"
int main()
{
	StackType stack1;
	ElType data;
	Initialize(stack1);
	FILE *fin,*fout;
	fin = fopen("address.txt","r");
	if(fin==NULL)
	{
		printf("Loi o buoc mo file , kiem tra lai\n");
		return 0;
	}
	fout = fopen("addresscp.txt","w");
	printf("Du lieu doc vao duoc tu file danh ba la:\n");
	while(!feof(fin))
	{
		fgets(data.name,30,fin);
		data.name[strlen(data.name)-1]='\0';// bo di ki tu \n cuoi dong
		fgets(data.tel,15,fin);
		data.tel[strlen(data.tel)-1]='\0';
		fgets(data.email,50,fin);
		data.email[strlen(data.email)-1]='\0';
		printf("%s\n%s\n%s\n",data.name,data.tel,data.email);
		Push(data,stack1);
	}
	
	while(!IsEmpty(stack1))
	{
		fprintf(fout,"%s\n%s\n%s\n",Pop(stack1).name,Pop(stack1).tel,Pop(stack1).email);		
	}
	printf("chuong trinh copy thong tin danh ba sang file khac su dung stack\n");
	fclose(fin);
	fclose(fout);
  return 0;
}

