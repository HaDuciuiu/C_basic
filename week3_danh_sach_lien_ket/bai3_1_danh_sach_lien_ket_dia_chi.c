#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Address
{
	char name[30];
	char phone[15];
	char email[30];
}AD;
struct LinkedList
{
	AD data;
	struct LinkedList *next;
};
typedef struct LinkedList *Node;//dinh nghia mot bien kieu con tro co cau truc giong LikedList
/*Ham khoi tao head*/
/*ham 1 . tao mot Node moi*/
Node CreatNode(AD data)
{
	Node temp;// khai bao mot Node moi
	temp = (Node)malloc(sizeof(struct LinkedList));
	/*Khai bao cau truc*/
	temp->next=NULL;
	temp->data=data;
	/*Tao mot Node moi co gia tri la data va co con tro den NULL, khi muon them Node
	nay vao linked List thi ta moi can cho no tro den dia chi phu hop*/
	return temp;// tra ve Node moi duoc tao ra
}
/*Ham 2. ham xac dinh Node nao duoc them dau se dong vai tro la head(head tro den
dia chi cua Node nay)*/
Node InItHead()
{
	Node head;
	head=NULL;/*phan tu them vao dau tien vua lm head luon va tro den NULL
	vi chua co phan tu nao sau no*/ 
	return head;
}
/*Ham 3. Them vao cuoi linked list*/
Node AddTail(Node head,AD data)
{
	Node temp,p;// temp de them , p de duyet linked list
	temp = CreatNode(data);// tao Node temp
	if(head==NULL)
	{
		head = temp;// Neu empty linked list thi Node them vao lm head luon
	}
	else
	{
		p = head;
		while(p->next!=NULL)// duyet den Node cuoi cung
		{
			p=p->next;
		}
		p->next = temp;/*Cho p->next= temp , khi do temp se la thang cuoi
		vi temp->next =NULL ma*/
	}
	return head;
}
/*Ham 4 . Nhap danh sach lien ket*/
Node Input()
{
	Node head = InItHead();/*Khoi tao phan tu them vao dau tien la head theo nhu ham
	InItHead da giai thich*/
	int n,i;
	AD data;
	do
	{
		printf("Nhap vao so luong cac phan tu: ");
		scanf("%d",&n);
	}while(n<=0);
	getchar();//lay vao ki tu \n sau ham scanf()
	for(i=0;i<n;i++)
	{
		printf("Nhap vao dia chi can them\n");
		printf("Name: ");
		gets(data.name);
		printf("Phone: ");
		gets(data.phone);
		printf("Email: ");
		gets(data.email);
		head = AddTail(head,data);
	}
	return head;	
}
/*Ham 5.Them vao dau linked list*/
Node AddHead(Node head,AD data)
{
	Node temp;
	temp=CreatNode(data);// tao mot Node temp de them vao linked list
	if(head==NULL)
	{
		head = temp;// neu empty linked list thi temp them vao chinh la head luon
	}
	else
	{
		temp->next=head;// cho temp tro den dia chi cua thang dau tien hien tai(head)
		head = temp;// head tro den di chi thang temp khi nay la head moi
	}
	return head;
}
/*Ham 6.Them Node vao vi tri bat ki*/
Node AddAt(Node head,AD data,int position)
{
	Node temp;
	temp = CreatNode(data);
	if(head==NULL)
	{
		head = AddHead(head,data);
	}// neu chi so chen la 0 hoac empty linkedlist thi chen dau
	else
	{
		int k=0;// k=1;
		Node p=head;
		while(p!=NULL&&k!=position)
		{
			p=p->next;
			++k;
		}
		if(k!=position)
		{
			printf("Vi tri chen vuot qua vi tri cuoi cung\n");
		}
		else
		{
			temp->next = p->next;
			temp->next=temp;
		}
	}
	return head;
}
/*Ham 7. Ham duyet toan bo list va in ra thong tin chua trong no*/
void Traverse(Node head)
{
	printf("\n");
	Node p;
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%30s\t%15s\t%30s\n",p->data.name,p->data.phone,p->data.email);
	}
}
/*Ham 8 . Ham xoa mot Node khoi list*/
Node DelAt(Node head,int position)
{
	if(head==NULL||head->next==NULL)
	{
		head = head->next;
	}
	else
	{
		Node p=head;
		while(p->next->next!=NULL)
		{
			p=p->next;
		}
		p->next=p->next->next;
	}
	return head;
}
int main()
{
	int n,m;
	AD data;
	printf("\nTao mot danh sach lien ket\n");
	Node head;
	head = Input();
	Traverse(head);
	printf("\nThem Node vao danh sach lien ket\n");
	printf("Nhap vao dia chi muon them:\n");
	printf("Nhap Name: ");
	gets(data.name);
	printf("Nhap phone:");
	gets(data.phone);
	printf("Nhap email:");
	gets(data.email);
	printf("Nhap vao vi tri muon them:");
	scanf("%d",&n);
	head=AddAt(head,data,n);
	Traverse(head);
	printf("\nXoa Node khoi linked list\n");
	printf("Nhap chi so can xoa: ");
	scanf("%d",&m);
	head = DelAt(head,m);
	Traverse(head);
	// giai phong Linkedlist
	Node to_free = head;
	while(to_free!=NULL)
	{
		head = head->next;
		free(to_free);
		to_free = head;
	}
  return 0;
}

