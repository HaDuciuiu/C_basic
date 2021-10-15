
#include<stdio.h>
#include<stdlib.h>

// khoi tao danh sach
struct list_int
{
    int val;
    struct list_int *next;
};
struct list_int *head = NULL;
typedef struct list_int *Node;
Node CreateNode(int value)
{
    Node new = (Node)malloc(sizeof(struct list_int));
    new->val = value;
    new->next = NULL;
    return new;
}
void AddTail(int value)
{
    Node temp = CreateNode(value);
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Node p = head;
        while(p->next != NULL)
        {
            p=p->next;
        }
        p->next = temp;
    }
}
void disPlay()
{
    printf("\n");
    Node p;
    for(p=head;p != NULL;p=p->next)
    {
        printf("%-5d",p->val);
    }
}
void Input()
{
    int n,value,i;
    do
    {
        printf("nhap so luong phan tu : ");
        scanf("%d",&n);
    } while (n<=0);
    for ( i = 0; i < n; i++)
    {
        printf("nhap gia tri muon them : ");
        scanf("%d",&value);
        AddTail(value);
    }
}
/*
void Reverser()
{
    if(head == NULL)
    {
        printf("danh sach trong !!!");
        return;
    }
    if(head->next == NULL)
    {
        return;
    }
    Node p=head;
    Node cur = head->next;
    head=cur->next;
    p->next = NULL;
    cur->next = p;
    if(head == NULL)
    {
        head = cur;
        return;
    }
    while(head->next != NULL)
    {
        p=cur;
        cur = head;
        head = head->next;
        cur->next = p;
    }
    head->next = cur;
}
*/
void Reverser()
{
	Node cur, prev;
	cur = prev = NULL;
	while (head != NULL) {
		cur = head;
		head = head->next;
		cur->next = prev;
		prev = cur;
	}
	head=cur;
}
int main()
{
    printf("\ntao danh sach lien ket\n");
    Input();
    disPlay();
    Reverser();
    disPlay();
    return 0;
}
