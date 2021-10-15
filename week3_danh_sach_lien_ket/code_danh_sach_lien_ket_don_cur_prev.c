#include<stdio.h>
#include<stdlib.h>
typedef struct address
{
	char name[20];
	char tell[15];
	char email[25];
}Address;
typedef struct LinkedList
{
	Address addr;
	struct LinkedList *next; 
}Node;
Node *head;
Node *cur;
// in case you use the pointer prev
Node *prev;
/*Ham 1.Khoi tao mot node moi*/
Node* CreatNode(Address addr)
{
	Node *new=(Node*)malloc(sizeof(Node));
	new->addr = addr;
	new->next = NULL;
	return new;
}
/*Duoi ham chinh sau khi tao node , ta phai thay doi gia tri cho cur la node 
moi tao , nhu sau:
	head = CreatNode(addr)
	cur = head*/
	
/*Ham 2.Ham insert phan tu vao dau danh sach lien ket*/
Node* AddHead(Address addr)
{
	Node *new;
	new = CreatNode(addr);
	new->next=head;
	head = new;
	cur = head;
	return head;
}

/*Ham 3.Ham insert phan tu vao ngay sau vi tri hien thoi*/
Node* InsertAfterCurrent(Node *head,Address addr)
{
	Node *new;
	new = (Node*)malloc(sizeof(Node));
	if(head==NULL)
	{
		/*There is no element in linked list*/
		head = new;
		cur = head;
	}
	else
	{
		new->next = cur->next;
		cur->next = new;
		/*neu khong dung prev thi xoa cau lenh nay:
		prev = cur;*/
		prev = cur;
		cur = cur->next;
	}
	return head;
}
/*Ham 4 . Ham insert vao ngay truoc phan tu hien thoi*/
Node *InsertBeforeCurrent(Node *head,Address addr)
{
	Node *new;
	new = CreatNode(addr);
	if(head==NULL)
	{
		//there is no element
		head = new;
		cur = head;
		prev = NULL;
	}
	else
	{
		new->next = cur;
		if(cur==head)
		{
			head = new;
		}else
		{
			prev->next = new;
		}
		cur = new;
	}
}
/*Ham 5.Them vao cuoi danh sach lien ket*/
void AddTail(Address addr)
{
	Node *new;
	new = CreatNode(addr);
	if(head==NULL)
	{
		printf("Empty linked list\n");
		return ;
	}
	else
	{
		Node *p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next = new;
	}
}
/*Ham 6 : Ham nhap vao danh sach lien ket*/
void Input()
{
	int n,i;
	Address addr;
	do
	{
		printf("Nhap vao so phan tu cua danh sach lien ket: ");
		scanf("%d",&n);
	}while(n<=0);
	getchar();
	for(i=0;i<n;i++)
	{
		printf("Nhap name: ");
		gets(addr.name);
		printf("Nhap tell: ");
		gets(addr.tell);
		printf("Nhap mail: ");
		gets(addr.email);
		AddTail(addr);
	}
}
/*Ham 7. Ham in ra danh sach lien ket*/
void Traverse()
{
	Node *p;
	printf("Name\t\t\tTell\t\tEmail\n");
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%-20s\t%-15s\t%-30s\n",p->addr.name,p->addr.tell,p->addr.email);
	}
}
/*Ham 8: Ham them phan tu vao vi tri bat ki*/
void AddAt(Address addr,int pos)
{
	Node *newNode = makeNewNode(addr);
	cur = root;
  	for (int i = 0; i < pos; i++)
  	{
    	prev = cur;
    	cur = cur->next;
  	}
  	newNode->next = cur->next;
  	cur->next = newNode;
  	if (root == NULL)
    	root = cur;
  	if (n == 0)
    	AddHead(addr);
 	prev = cur;
  	cur = cur->next;
  	return new;
}
int main()
{
	Node *to_free = head;
	while(to_free!=NULL)
	{
		head = head->next;
		free(to_free);
		to_free = head;
	}
  return 0;
}

