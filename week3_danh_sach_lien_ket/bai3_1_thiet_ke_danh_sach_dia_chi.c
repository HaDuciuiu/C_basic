#include<stdio.h>
#include<stdlib.h>
/*
+) Tao 1 danh sách liên ket don chua danh
sách phone address.
+) Viet 1 ham insert 1 phan tu vào list ngay
sau phan tu hien thoi, su dung no de them
node vao list
+) Viet 1 ham duyet toan bo list va in ra
thong tin chua trong no.
+) Viet ham xoa 1 node khoi list.
*/
typedef struct Address
{
    char name[30];
    char phone[15];
    char email[30]; 
}AD;
struct node
{
	AD data;
	struct node *next;
};
typedef struct node *Node;

Node CreatNode(AD data)
{
	Node new;// mot con tro new de cap phat bo nho cho no
	new = (Node)malloc(sizeof(struct node));
	new->next = NULL;// cho con tro cua new tro den NULL(tao mot con tro moi)
	new->data = data;
	return new; // tra ve new da duoc tao moi
}
Node AddTail(Node head,AD data)
{
	Node temp,p;/*Khai bao hai con tro , mot con tro la node can them vao , mot con tro dung de duyet 
	danh sach lien ket*/
	temp = CreatNode(data);// tao mot node temp co next tro toi NULL va gia tri la data
	if(head==NULL)
	{
		head = temp;
	} 
	else
	{
		p = head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
	return head;
}
// ham duoi day de tao danh sach lien ket 
// ham tao head (khi them mot phan tu vao dau tien thi no la head nen ta co the khoi tao no bang ham nay )
Node InItHead()
{
	Node head=NULL;
	return head;
}
// ham tao danh sach lien ket
Node Input()
{
	Node head = InItHead();
	int i,n;
	AD data;
	do
	{
		printf("Nhap so phan tu : ");
		scanf("%d",&n);
	}while(n<=0);
	getchar();// lay vao ki tu \n cua ham scanf() ben tren
	for(i=0;i<n;i++)
	{
		printf("Nhap vao dia chi can them thu %d:\n",i+1);
		printf("Name: ");
		gets(data.name);
		printf("Phone: ");
		gets(data.phone);
		printf("Address: ");
		gets(data.email);
		head = AddTail(head,data);
	}
	return head;
}
Node InsertAt(Node head,AD data,int position)
{
	Node new;
	new = CreatNode(data);// khoi tao mot node new co gia tri la data va tro den NULL
	// Bat dau tim vi tri can chen , dung bien k de dem vi tri 
	if(head == NULL)
	{
		head = AddTail(head,data);// neu linked list trong thi new them vao chinh la head luon
	}
	else
	{
		int k=1;
		Node p=head;
		while(p!=NULL&&k!=position)
		{
			p = p->next;
			++k;
		// neu chua tim duoc vi tri can chen thi tiep tuc duyet den cuoi va tang vi tri
		}
		new->next = p->next;
		p->next = new; 
	}
	return head;	
}
// ham duyet linked list va in ra dia chi trong luu trong linked list
void Traverser(Node head)
{
	Node p;
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%s\t%s\t%s\n",p->data.name,p->data.phone,p->data.email);
	}
}
// ham xoa o vi tri bat ki cua linked list
Node DelAt(Node head,int position)
{
	int k=1;
	Node p=head;
	if(head==NULL||position==0||head->next==NULL)
	{
		head = head->next;// neu chi co mot phan tu hoac xoa dau hoac chi co 1 phan tu
	}
	else
	{
		while(p->next->next!=NULL||k!=position)
		{
			p=p->next;
			++k;
		}	
	}
	if(k!=position)
	{
		printf("Vi tri xoa khong hop le\n");
	}
	else
	{
		p->next = p->next->next;// gan phan tu sau p->next vao p->next de xoa di p->next
	}
	return head;
}
int main()
{
	printf("\nDay la chuong trinh mot ham tao moi mot node cua danh sach lien ket\n");
	Node head;
	int position,n;
	head = Input();
	Traverser(head);
	printf("\nThem mot Node vao linked list:\n");
	AD data;
	printf("Nhap vao dia chi can them :\n");
	printf("Nhap name: ");
	gets(data.name);
	printf("Nhap phone: ");
	gets(data.phone);
	printf("Nhap mail: ");
	gets(data.email);
	printf("Thame mot phan tu vao linked list:\n");
	printf("nhap vao vi tri muon them: ");
	scanf("%d",&n);
	head=InsertAt(head,data,n);// them data vao vi tri chi so thu 3 cua linked list
	Traverser(head);
	printf("\nXoa mot phan tu khoi linked list:\n");
	printf("Nhap vao vi tri Node muon xoa:\n");
	scanf("%d",&position);
	head = DelAt(head,position);
	Traverser(head);
	printf("Hoan thanh suong suong roi, kiem tra lai xem nhe\n");
    return 0;
}
