#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head,*tail;
 typedef struct Node *List;
// tạo mới một node
List CreateNewNode(int value)
{
    List newNode = (List)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
//thêm node
// thêm vào đầu
//Nếu head = NULL, ta sẽ cho cả head và tail = newNode.
//Nếu head != NULL, ta sẽ cập nhật lại head mới là newNode.
// Ta cần tạo liên kết giữa head hiện tại với newNode trước khi cho newNode làm head mới.
void Addhead(int value)
{
    List newNode = CreateNewNode(value);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return ;
    }
    head->prev =newNode;
    newNode->next=head;
    head = newNode;
}
void AddTail(int value)
{
    List p,temp;
    temp = CreateNewNode(value);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return ;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void AddAt(int value,int position)
{
    if(head == NULL)
    {
        Addhead(value);
        return;
    }
    List p = head;
    int k=1;
    while(p!= NULL && k != position)
    {
        p = p->next;
        k++;
    }
    if(k != position)
    {
        AddTail(value);
    }
    else
    {
        List temp = CreateNewNode(value);
        temp->next = p->next;
        p->next = temp;
        temp->prev=p;
        temp->next->prev=temp;
    }
    
}
// xóa phần tử
// xóa phần tử đầu
void DelHead()
{
    if(head == NULL)
    {
        printf("cos gi dau ma xoa");
        return;
    }
    head = head->next;
    head->prev = NULL;
}
// xóa cuối
void DelTail()
{
    if(head == NULL)
    DelHead();
    tail = tail->prev;
    tail->next = NULL;
}
// xóa vị trí bất kì... xóa phần tử ngay sau phần tử thứ position
void DelAt(int position)
{
    if(head == NULL)
    DelHead;
    int k=1;
    List p = head;
    while(p ->next->next != NULL && k != position)
    {
        p = p->next;
        k++;
    }
    if(k != position)
    DelTail();
    else
    {
        p->next = p->next->next;
        p->next->prev=p;
    }
    
}
void Input()
{
    int n,value;
    do
    {
        printf("nhap so luong phan tu : ");
        scanf("%d",&n);
    } while (n<=0);
    int i;
    for(i=0;i<n;i++)
    {
        printf("nhap gia tri can them :");
        scanf("%d",&value);
        Addhead(value);// thêm giá trị vào đầu
    }
}
void print()
{
    List temp;
    if(head == NULL)
    printf("danh sach trong");
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%-5d",temp->data);
            temp = temp->next;
        }
    }
}
void printN()
{
    List p;
    if(head == NULL)
    printf("danh sach trong");
    else
    {
        p=tail;
        while(p != NULL)
        {
            printf("%-5d",p->data);
            p=p->prev;
        }
    }
    
}


int main()
{
    head = NULL;
    Input();
    AddAt(54,3);
    print();
    printf("\n");
    printN();
    printf("\nxoa phan tu bat ki :\n");
    DelAt(4);
    print();
    printf("\n");
    printN();
    return 0;
}