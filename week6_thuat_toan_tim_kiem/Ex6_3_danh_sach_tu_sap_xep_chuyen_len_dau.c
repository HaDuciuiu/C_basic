#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkedList.h"

int main()
{
	FILE *fin,*fout;
	fin = fopen("address_6.txt","r");
	if(fin==NULL)
	{
		printf("Loi o buoc doc file, kiem tra lai nhe\n");
		exit(0);
	}
	ElementType ADD[100];// tao chuong trinh co the lam viec voi 100 phan tu
	int n,i;
	int k; // bien nay luu giu chi so cua phan tu duoc tim thay
	char nameSearch[30];
	printf("Nhap vao so luong khach hang muon doc vao tu file\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		fgets(ADD[i].name,30,fin);// doc ten vao tu file fin
		ADD[i].name[strlen(ADD[i].name)-1]='\0';
		fgets(ADD[i].phone,15,fin);// doc ten vao tu file fin
		ADD[i].phone[strlen(ADD[i].phone)-1]='\0';
		fgets(ADD[i].email,50,fin);// doc ten vao tu file fin
		ADD[i].email[strlen(ADD[i].email)-1]='\0';
		/*Tham so cua ham fread la: chuoi luu du lieu doc vao - kich thuoc cua tung phan tu mang 
		- so phan tu duoc doc - con tro file gan voi file da duoc mo de doc
		*/
		AddTail(ADD[i]);
		printf("%s\n%s\n%s\n",ADD[i].name,ADD[i].phone,ADD[i].email);
	}
	fout = fopen("address_search.txt","w");
	getchar();
	printf("Nhap vao ten khach hang can tim kiem: ");
	gets(nameSearch);
	Node *check = SearchMoveToFront(nameSearch);
	if(check==NULL)
	{
		printf("Khong co khach hang tren trong danh sach danh ba\n");
		exit(1);
	}
	else
	{
		Node *p = SearchMoveToFront(nameSearch);
		fprintf(fout,"%s\n%s\n%s",p->element.name,p->element.phone,p->element.email);
	}
	printf("Da hoan thanh chuong trinh roi nhe!!! Kiem tra file de xem ket qua thoi nao\n");
  return 0;
}

