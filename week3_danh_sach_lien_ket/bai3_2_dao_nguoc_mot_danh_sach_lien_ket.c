#include<stdio.h>
#include<stdlib.h>
typedef struct list_int
{
	int val;
	struct list_int *next;
}List;
List *head=NULL;
List *CreatNode(int val)
{
	List *temp;
	temp = (List*)malloc(sizeof(List));
	temp->next=NULL;
	temp->val=val;
	return temp;
}
void AddTail(int value)
{
	List *temp=CreatNode(value);
	if(head==NULL)
	{
		head = temp;
		return;
	}
	else
	{
		List *p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
}
void Traverse()
{
	List *p;
	printf("\n");
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%5d",p->val);
	}	
}
void CreatList()
{
	int n,i,val;
	do
	{
		printf("Nhap vao so luong cac phan tu cua danh sach lien ket: ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("phan tu thu %d : ",i+1);
			scanf("%d",&val);
			AddTail(val);	
		}
	}while(n<=0);
}
void Reverse()
{
	List *cur , *prev;
	cur = prev = NULL;
	while(head!=NULL)
	{
		cur = head;
		head = head->next;
		cur->next=prev;
		prev = cur;
	}
	head = cur;  
}
int main()
{
	printf("========Tao mot danh sach lien ket\n");
	CreatList();
	Traverse();
	printf("\nDao nguoc danh sach lien ket\n");
	Reverse();
	Traverse();
	List *to_free;
	while(to_free!=NULL)
	{
		head = head->next;
		free(to_free);
		to_free = head;
	}
  return 0;
}
