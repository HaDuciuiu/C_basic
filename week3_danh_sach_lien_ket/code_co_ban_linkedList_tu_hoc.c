#include<stdio.h>
#include<stdlib.h>
/*Ham 1.Khai bao linked list
*/
struct LinkedList{
	int data;
	struct LinkedList *next;
};
typedef struct LinkedList *Node;// sau day co mot kieu du lieu con tro Node co cau truc nhu LinkedList
// dung typedef de dinh nghia kieu du lieu Node la mot kieu du lieu moi
/*Ham 2.Tao moi mot danh sach lien ket*/
Node CreatNode(int value)
{
	Node temp;//declare a node
	temp = (Node*)malloc(sizeof(struct LinkedList));// cap phat bo nho dong cho con tro temp
	temp->next = NULL;// cho con tro cua temp tro den NULL
	temp->data = value;// gan gia tri value cho temp
	return temp;// tra ve con tro da duoc tao moi
}
/*Ham 3. Them node vao dau Linked list*/
Node AddHead(Node head,int value)
{
	Node temp = CreatNode(value);// khoi tao node temp voi data = value
	if(head==NULL)
	{
		head = temp;//Neu linked list dang trong thi temp = head luon
	}
	else
	{
		temp->next = head;//Tro next cua temp tro toi head hien tai
		head = temp;// Doi head hien tai = temp (vi temp bay gio la head moi ma)
	}
	return head;
}
/*Ham 4. them node vao cuoi cua linked list*/
Node AddTail(Node head,int value)
{
	Node temp,p;// khai bao 2 node : temp , p . p dung de duyet qua cac node cua linked list
	temp = CreatNode(value);/*Goi ham CreatNode de tao moi mot Node temp co next tro toi NULL va gia
	tri la value*/
	if(head==NULL)
	{
		head = temp;//neu linked list dang trong thi node temp lam head luon
	}
	else
	{
		p = head;//khoi tao p tro toi head
		while(p->next!=NULL)
		{
			p = p->next;// duyet dan danh sach lien ket den cuoi
		}
		p->next = temp;//Gan next cua thang cuoi = temp , khi do temp se la thang cuoi(temp -> next==NULL ma)
		
	}
	return head;
}
/*Ham 4. Them node vao vi tri bat ki*/
Node AddAt(Node head,int value,int position)
{
	if(position==0||head==NULL)// neu chen vao dau hoac la linked list dang trong
	{
		head = AddHead(head,value);// neu vi tri chen la 0 tuc la them vao dau
	}
	else
	{
		// Bat dau tim vi tri can chen , ta se dung k de dem vi tri
		int k=1;
		Node p = head;// khoi tao gia tri cho p tro toi head
		while(p!=NULL&&k!=position)
		{
			p = p->next;
			++k;
		}
		if(k!=position)
		{
			/*Neu duyet het linked list roi ma van chua tim thay vi tri can chen thi ta mac dinh 
			chen cuoi.Neu khong muon chen cuoi thi hay dua ra thong bao vi tri chen khong hop le*/
			head = AddTail(head,value);
			//printf("vi tri can chen vuot qua vi tri cuoi cung\n");
		}
		else
		{
			Node temp = CreatNode(value);//khoi tao mot node temp co con tro tro toi NULL va gtri value
			temp->next = p->next;/*gan vi tri con tro p dang tro (phan tu ngay sau p) vao con tro 
			cua temp de temp tro den phan tu ngay sau p do*/
			p->next = temp;/*cho con tro cua p tro den temp*/
		}	
	}
	return head;
}
/*Ham 5. Xoa node khoi danh sach lien ket:Xoa dau*/
Node DelHead(Node head)
{
	if(head==NULL)
	{
		printf("Cha co gi de xoa het\n");
	}
	else
	{
		head = head->next;/*Xoa dau rat don gian , chi can cho thang ke tiep cua head lam head la dc*/
	}
	return head;
}
/*Ham 6. Xoa cuoi : Xoa cuoi hoi met vi phai duyet den thang cuoi tru 1 sau do tro next cua thang cuoi
tru 1 do bang NULL*/
Node DelTail(Node head)
{
	if(head==NULL||head->next==NULL)
	{
		return DelHead(head);
	}
	Node p = head;
	while(p->next->next!=NULL)
	{
		p = p->next;
		p->next = p->next->next;// cho next bang NULL
		// hoac viet la p->next=NULL cx dc
	}
	return head;
}
/*Ham 7 . Xoa o vi tri bat ki*/
Node DelAt(Node head,int position)
{
	int k=1;
	Node p = head ;
	if(position==0||head==NULL||head->next==NULL)
	{
		head = DelHead(head);//Neu vi tri xoa la 0 thi tuc la xoa dau
	}
	else
	{
		// Bat dau tim vi tri can xoa,ta se dung bien k de dem vi tri can xoa
		while(p->next->next!=NULL&&k!=position)
		{
			p=p->next;
			++k;
		}
	}
	if(k!=position)
	{
		/*Neu duyet den cuoi danh sach lien ket roi ma van chua tim thay vi tri can xoa , ta mac dinh
		se xoa cuoi.Neu ban khong muon xoa cuoi , hay thong bao vi tri xoa khong hop le*/
		head = DelTail(head);
		//printf("Vi tri xoa vuot qua vi tri cuoi cung\n");
	}
	else
	{
		p->next=p->next->next;// gan dia chi cua con tro p->next->next vao p->next
	}
	return head;
}
/*Ham 8. Lay gia tri o vi tri bat ki*/
int Get(Node head,int index)
{
	int k=0;
	Node p = head;
	while(p->next!=NULL&&k!=index)
	{
		++k;
		p=p->next;
	}
	return p->data;
}
/*Ham 9.Tim kiem trong danh sach lien ket*/
int Search(Node head,int value)
{
	int position=0;
	Node p;
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->data==value)
		{
			return position;
		}
		++position;
	}
	return -1;
}
/*Chung ta co the dung ham9 de xoa tat ca cac Node trong danh sach lien ket co gia tri chi dinh nhu sau:*/
Node DelByVal(Node head,int value)
{
	int position = Search(head,value);
	while(position!=-1)
	{
		DelAt(head,position);
		position = Search(head,value);
	}
	return head;
}
/*Ham 10.Duyet danh sach lien ket*/
Node Tranverser(Node head)
{
	printf("\n");
	Node p;// mot bien p de duyet danh sach lien ket
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%5d",p->data);
	}
}
/*Ham 11. Ham khoi tao Node head*/
Node InItHead()
{
	Node head;
	head = NULL;
	return head;
}
/*Ham 12. Ham lay so phan tu cua DSLK*/
int Length(Node head)
{
	int length =0;
	Node p;
	for(p=head;p!=NULL;p=p->next)
	{
		++length;
	}
	return length;
}
/*Ham 13. Ham nhap danh sach lien ket*/
Node Input()
{
	Node head = InItHead();
	int n,i,value;
	do
	{
		printf("Nhap vao so phan tu :\n");
		scanf("%d",&n);
	}while(n<=0);
	for(i=0;i<n;i++)
	{
		printf("Nhap vao gia tri can them: ");
		scanf("%d",&value);
		head = AddTail(head,value);
	}
	return head;
}
int main()
{
	printf("Cac ham co ban cua danh sach lien ket don\n");
	

  return 0;
}

