#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dem_i=0;
// thao tac voi struct
typedef struct ADDR
{
    char name[30];
    char phone[15];
    char email[50];
}Address;
typedef Address element;
struct LinkedList
{
    element data;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; //Tu gio d�ng kieu du lieu LinkedList c� the thay bang node cho ngan gon
 
node CreateNode(element value){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // Cap ph�t v�ng nho d�ng malloc()
    temp->next = NULL;// Cho next tro toi NULL
    temp->data = value; // Gan gia tri cho Node
    return temp;//Tra ve node moi da co gia tri
}
 
node AddTail(node head, element value){
    node temp,p;// Khai bao 2 node tam temp va p
    temp = CreateNode(value);//Goi ham createNode de khoi tao node temp c� next tro toi NULL v� gi� tri l� value
    if(head == NULL){
        head = temp;     //Neu linked list dang trong thi Node temp l� head lu�n
    }
    else{
        p  = head;// Khoi tao p tro toi head
        while(p->next != NULL)
        {
            p = p->next;//Duyet danh s�ch li�n ket den cuoi. Node cuoi l� node c� next = NULL
        }
        p->next = temp;//G�n next cua thang cuoi = temp. Khi d� temp se l� thang cuoi(temp->next = NULL m�)
    }
    return head;
}
 
 
node AddHead(node head, element value)
{
    node temp = CreateNode(value); // Khoi tao node temp voi data = value
    if(head == NULL){
        head = temp; // //Neu linked list dang trong th� Node temp l� head lu�n
    }else{
        temp->next = head; // Tro next cua temp = head hien tai
        head = temp; // �oi head hien tai = temp(V� temp b�y gio l� head moi m�)
    }
    return head;
}
 
node AddAt(node head, element value, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, value); // Neu vi tr� ch�n l� 0, tuc l� th�m v�o dau
    }else{
        // Bat dau t�m vi tr� can ch�n. Ta se d�ng k de dem cho vi tr�
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position)
        {
            // Neu duyet het danh s�ch lk roi m� van chua den vi tr� can ch�n, ta se mac dinh ch�n cuoi
            // Neu ban kh�ng muon ch�n, h�y th�ng b�o vi tr� ch�n kh�ng hop le
            head = AddTail(head, value);
            // printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }else
        {
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
 
node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
 
node DelTail(node head){
    if (head == NULL || head->next == NULL){
         return DelHead(head);
    }
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; // Cho next bang NULL
    // Hoac viet p->next = NULL cung duoc
    return head;
}
 
node DelAt(node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = DelHead(head); // Neu vi tr� ch�n l� 0, tuc l� th�m v�o dau
    }else{
        // Bat dau t�m vi tr� can ch�n. Ta se d�ng k de dem cho vi tr�
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // Neu duyet het danh s�ch lk roi m� van chua den vi tr� can ch�n, ta se mac dinh x�a cuoi
            // Neu ban kh�ng muon x�a, h�y th�ng b�o vi tr� x�a kh�ng hop le
            head = DelTail(head);
            // printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
 
element Get(node head, int index){
    int k = 0;
    node p = head;
    while(p != NULL && k != index){
        p = p->next;
    }
    return p->data;
}
 
int Search(node head, element value)
{
    int position = 0;
    node p;
    for(p = head; p != NULL; p = p->next){
        if(strcmp(p->data.name,value.name))
        {
            return position;
        }
        ++position;
    }
    return -1;
}
 
node DelByVal(node head, element value){
    int position = Search(head, value);
    while(position != -1){
        DelAt(head, position);
        position = Search(head, value);
    }
    return head;
}
 
void Traverser(node head)
{
    printf("\n");
    node p;
    printf("Name\t\t\t\tPhone\t\t\tEmail\n");
    for(p = head; p != NULL; p = p->next)
    {
        printf("%-30s\t%-15s\t%-50s\n",p->data.name,p->data.phone,p->data.email);
    }
}
 
node InitHead()
{
    node head;
    head = NULL;
    return head;
}
 
int Length(node head){
    int length = 0;
    node p;
    for( p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
 
node Input()
{
    node head = InitHead();
    int n,i; 
    element value;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
    getchar();
    for( i = 0; i < n; ++i)
    {
        
        printf("\nNhap gia tri can them: ");
        printf("Name: ");
        gets(value.name);
        printf("Phone: ");
        gets(value.phone);
        printf("Email: ");
        gets(value.email);
        head = AddTail(head, value);
    }
    return head;
}

// Duoi day la hai ham sap xep
// ham 1. Sap xep chen
void insertion_sortL(node head, element list[], int *n)
{
    int i=0 ,j;
    element next;
    node p=head;
    while(p!=NULL)
    {
        list[i++] = p->data;
        p = p->next;
    }
    *n = i;
    for (i=1; i<*n; i++) 
    {
        next= list[i];
        for (j=i-1;j>=0 && strcmp(next.name,list[j].name)<0;j--)
        {
        	dem_i++;
        	list[j+1] = list[j];
		}
            
        list[j+1] = next;
    }
    i=0;
    p= head;
    element temp;
    while(p!=NULL)
    {
        p->data = list[i];
        p = p->next;
        i++; 
    }
}
