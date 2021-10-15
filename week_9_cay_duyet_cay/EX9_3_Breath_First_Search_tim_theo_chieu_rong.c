#include<stdio.h>
#include"BinarySearchTreeWithStruct_2_name.h"
int main()
{
	
	TreeType Tree = NULL;
	TreeType check;
	KeyType ADDR[10];
	FILE *fin , *fout , *fout2;
	int i;
	char nameS[30];
	fin = fopen("danhba_9.txt","r");
	if(fin==NULL)
	{
		printf("Loi o buoc doc file , kiem tra lai nhe\n");
		exit(0);
	}
	for(i=0;i<10;i++)
	{
		fgets(ADDR[i].name,30,fin);
		ADDR[i].name[strlen(ADDR[i].name)-1]='\0';
		fgets(ADDR[i].phone,15,fin);
		ADDR[i].phone[strlen(ADDR[i].phone)-1]='\0';
		fgets(ADDR[i].email,50,fin);
		ADDR[i].email[strlen(ADDR[i].email)-1] = '\0';
		InsertNode(ADDR[i],&Tree);
	}
	// Bay gio in ra nhung du lieu mk vu doc vao xem co sai sot j ko
	printf("Danh sach doc vao la:\n");
	printf("Name\t\t\tPhone Number\t\tEmail\n");
	for(i=0;i<10;i++)
	{
		printf("%-30s%-15s%-50s\n",ADDR[i].name,ADDR[i].phone,ADDR[i].email);
	}
	printf("Nhap vao mot name can tim kiem trong cay: \n");
	gets(nameS);
	check = Search(nameS,Tree);
	if(check != NULL)
	{
		printf("\nTim thay dia chi email tren trong danh sach nhu sau:\n");
		printf("Name\t\t\t\tPhone\t\t\tEmai\n");
		printf("%-30s%-15s%-50s\n",check->key.name,check->key.phone,check->key.email);
		fout = fopen("danhba_9ra.txt","w");
		fprintf(fout,"%s\n%s\n%s\n",check->key.name,check->key.phone,check->key.email);
	}
	// in ra cac node cua cay theo thu tu tang dan cua dia chi email- du doan la ham duyet theo thu tu giua
	printf("\nIn ra danh sach danh ba theo thu tu name tang dan nhu sau:\n");
	InOrder(Tree);
    printf("Du lieu da duoc ghi ra file danhba_9.txt, vui long kiem tra file \n");
    fout2 = fopen("danhba_9ra2.txt","w");
    InOrder_file(Tree,fout2);
    printf("\nIn ra danh sach danh ba su dung ham duyet BFS\n");
    breadth_first(Tree);
    fclose(fin);
    fclose(fout);
    fclose(fout2);
    return 0;
}
