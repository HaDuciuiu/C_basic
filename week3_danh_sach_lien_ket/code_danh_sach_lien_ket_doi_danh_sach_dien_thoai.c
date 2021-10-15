#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Address
{
	char name[30];
	char phone[15];
	char email[30];
}A_D;
typedef struct AddressList
{
	struct AddressList *next;
	struct AddressList *prev;
	A_D addr;
}Node;

Node *head=NULL;
Node *tail=NULL;
/*Ham kiem tra danh sach lien ket co trong khong:
Bool isEmpty()
{
	return head=NULL;// them thu vien #include<stdbool.h> len phia tren nua
}*/
Node* CreatNode(A_D addr)
{
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->addr=addr;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
void AddTail(A_D addr)
{
	Node *temp;
	temp=CreatNode(addr);
	if(head==NULL)//Linked list is empty
	{
		head = temp;
		tail = temp;
		return ;
	}
	tail->next = temp;
	temp->prev = tail;
	tail = temp;
}
void Input()
{
	int n,i;
	A_D addr;
	do
	{
		printf("Nhap vao so luong phan tu trong danh sach: ");
		scanf("%d",&n);
		getchar();
	}while(n<=0);
	for(i=0;i<n;i++)
	{
		printf("Nhap vao thong tin cho thue bao thu %d:\n",i+1);
		printf("Nhap name: ");
		gets(addr.name);
		printf("Nhap phone: ");
		gets(addr.phone);
		printf("Nhap email: ");
		gets(addr.email);
		AddTail(addr);
	}	
}
void Print()
{
	printf("In danh sach theo chieu xuoi:\n");
	printf("Name\t\t\t\t\tPhone\t\t\tEmail\n");
	Node *p = head;
	while(p!=NULL)
	{
		printf("%-30s\t%-15s\t%-30s\n",p->addr.name,p->addr.phone,p->addr.email);
		p=p->next;
	}	
}
void Reverse_Print()
{
	Node *p = tail;
	if(p==NULL)//Linked list is empty
	{
		printf("Empty linked list\n");
		return ;
	}
	printf("In danh sach theo chieu nguoc:\n");
	printf("Name\t\t\tPhone\t\tEmail\n");
	while(p!=NULL)
	{
		printf("%-30s\t%-15s\t%-30s\n",p->addr.name,p->addr.phone,p->addr.email);
		p=p->prev;
	}
}

int main()
{
	printf("Tao danh sach danh ba dien thoa bang danh sach lien ket doi:\n");
	Input();
	printf("Danh sach nhap vao la:\n");
	Print();
	printf("Danh sach nhap vao theo chieu nguoc la:\n");
	Reverse_Print();
  return 0;
}

