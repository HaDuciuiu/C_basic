/*
• Ta thiết kế “address list”(danh sách
địa chỉ) cho các số điện thoại di động
• Phải tạo 1 cấu trúc gồm có name,
phone number và email address.
• Phải tạo 1 chương trình có thể giải
quyết với số lượng dữ liệu tuỳ ý
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char name[30];
    char phone[15];
    char email[30];
} data;
// khai bao danh sach lien ket
struct Linked
{
    data infor;
    struct Linked *next;
};
struct Linked *head;
typedef struct Linked *Node;
// CreateNode
Node CreateNode(data value)
{
    Node temp = (Node)malloc(sizeof(struct Linked));
    temp->infor = value;
    temp->next = NULL;
    return temp;
}
//them vao dau
void Addhead(data value)
{
    Node temp = CreateNode(value);
    if(head == NULL)
    {
        printf("danh sach trong ");
        return;
    }
    temp->next = head;
    head = temp;
}
//them vao cuoi
void AddTail(data value)
{
    Node temp = CreateNode(value);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    Node p=head;
    while (p->next != NULL)
    {
        p=p->next;
    }
    p->next=temp;    
}
// them vao vi tri bat ki
void AddAt(data value,int position)
{
    Node temp = CreateNode(value);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    if(position == 0)// neu position = 0 thi them vao dau
    {
        Addhead(value);
        return;
    }
    Node p=head;
    int k=1;
    while(p !=NULL && k != position)
    {
        p=p->next;
        k++;
    }
    if(k != position)
    {
        AddTail(value);// nếu không tìm thấy vị tró thì thêm vào cuối
        //printf("vi tri khong phu hop \n");
    }
    else
    {
        temp->next= p->next;
        p->next = temp;
    }
}
//xoa phan tu
// xoa cuoi
void DelTail()
{
    if(head == NULL)
    {
        printf("danh sach trong :");
        return ;
    }
    if(head->next == NULL)
    {
        head = head->next;
        return;
    }
    Node p = head;
    while(p->next->next != NULL)
        {
            p=p->next;
        }
    p->next = NULL; 
}
// xoa vi tri bat ki
void DelAt(int position)
{
    if(head == NULL)
    {
        printf("\n===danh sach trong xoa gi nua !!==\n");
        return;
    }
    if(position == 0)
    {
        head = head->next;
        return;
    }
    int k=1;
    Node p = head;
    while(p->next->next !=NULL && k != position)
    {
        p = p->next;
        k++;
    }
    if(k != position)
    {
        DelTail();// neu khong tim dc vi tri thi xoa phan tu cuoi
        printf("khong tim duoc vi tri de xoa");
    }
    else
    {
        p->next = p->next->next;
    }
}
void display()
{
    Node p = head;
    for(;p != NULL;p = p->next)
    {
        printf("\n");
        printf("%-30s%-15s%-30s",p->infor.name,p->infor.phone,p->infor.email);
    }
}
void Input()
{
    int n;
    data value;
    do
    {
        printf("nhap so luong phan tu :");
        scanf("%d",&n);
    } while (n<=0);
    getchar();
    int i;
    for(i=0;i<n;i++)
    {
        printf("nhap infor member %d\n",i+1);
        printf("name : ");
        gets(value.name);
        printf("phone : ");
        gets(value.phone);
        printf("email : ");
        gets(value.email);
        AddTail(value);
    }
}
int main()
{
    printf("===================tao mot address list ====================\n");
    Input();
    display();
    printf("\n====================================\n");
    int key;
    data value;
    int position;
    do
    {
        printf("\nnhap lua chon cua ban :\n");
        printf("0.exit\n1.them infor 1 member\n2.xoa infor 1 member\n");
        scanf("%d",&key);
        switch (key)
        {
        case 0:
        {
            printf("\nthoat chuong trinh --------\n");
            break;
        }
        case 1:
        {
            getchar();
            printf("\n=====them mot phan tu ======\n");
            printf("\nthong tin member them \n");
            printf("name : ");
                gets(value.name);
            printf("phone : ");
                gets(value.phone);
            printf("email : ");
                gets(value.email);
            printf("vi tri muon them :");
                scanf("%d",&position);
            AddAt(value,position);
            display();
            break;
        }
        case 2:
        {
            printf("\nnhap vi tri muon xoa ");
            scanf("%d",&position);
            DelAt(position);
            display();
            break;           
        }
        default:
        {
            printf("nhap key sai...... nhap lai \n");
        }
    }
    } while (key !=0);
    Node p =head;
    // giai phong du lieu
    while(p != NULL)
    {
        head = head->next;
        free(p);
        p = head;
    }
    return 0;
}