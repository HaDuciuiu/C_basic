#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay doi kieu int thanh kieu du lieu mong muon
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;
/*Khoi tao 3 con tro quan trong de thao tac voi danh sach lien ket don hieu qua hon*/
Node *makeNewNode(ElementType element)
{
	Node *newNode = (*Node)malloc(sizeof(struct node));
	newNode->element = element;
	newNode->next = NULL;
	return newNode;
}
int main()
{
	printf("Ham khoi tao mot node moi trong danh sach lien ket don\n");
  return 0;
}

