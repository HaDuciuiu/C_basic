#include<stdio.h>
#include<stdlib.h>
 
struct LinkedList{
    int data;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; //Tu gio dùng kieu du lieu LinkedList có the thay bang node cho ngan gon
 
node CreateNode(int value){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // Cap phát vùng nho dùng malloc()
    temp->next = NULL;// Cho next tro toi NULL
    temp->data = value; // Gan gia tri cho Node
    return temp;//Tra ve node moi da co gia tri
}
 
node AddTail(node head, int value){
    node temp,p;// Khai bao 2 node tam temp va p
    temp = CreateNode(value);//Goi ham createNode de khoi tao node temp có next tro toi NULL và giá tri là value
    if(head == NULL){
        head = temp;     //Neu linked list dang trong thi Node temp là head luôn
    }
    else{
        p  = head;// Khoi tao p tro toi head
        while(p->next != NULL){
            p = p->next;//Duyet danh sách liên ket den cuoi. Node cuoi là node có next = NULL
        }
        p->next = temp;//Gán next cua thang cuoi = temp. Khi dó temp se là thang cuoi(temp->next = NULL mà)
    }
    return head;
}
 
 
node AddHead(node head, int value){
    node temp = CreateNode(value); // Khoi tao node temp voi data = value
    if(head == NULL){
        head = temp; // //Neu linked list dang trong thì Node temp là head luôn
    }else{
        temp->next = head; // Tro next cua temp = head hien tai
        head = temp; // Ðoi head hien tai = temp(Vì temp bây gio là head moi mà)
    }
    return head;
}
 
node AddAt(node head, int value, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, value); // Neu vi trí chèn là 0, tuc là thêm vào dau
    }else{
        // Bat dau tìm vi trí can chèn. Ta se dùng k de dem cho vi trí
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // Neu duyet het danh sách lk roi mà van chua den vi trí can chèn, ta se mac dinh chèn cuoi
            // Neu ban không muon chèn, hãy thông báo vi trí chèn không hop le
            head = AddTail(head, value);
            // printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }else{
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
        head = DelHead(head); // Neu vi trí chèn là 0, tuc là thêm vào dau
    }else{
        // Bat dau tìm vi trí can chèn. Ta se dùng k de dem cho vi trí
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // Neu duyet het danh sách lk roi mà van chua den vi trí can chèn, ta se mac dinh xóa cuoi
            // Neu ban không muon xóa, hãy thông báo vi trí xóa không hop le
            head = DelTail(head);
            // printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
 
int Get(node head, int index){
    int k = 0;
    node p = head;
    while(p != NULL && k != index){
        p = p->next;
    }
    return p->data;
}
 
int Search(node head, int value){
    int position = 0;
    node p;
    for(p = head; p != NULL; p = p->next){
        if(p->data == value){
            return position;
        }
        ++position;
    }
    return -1;
}
 
node DelByVal(node head, int value){
    int position = Search(head, value);
    while(position != -1){
        DelAt(head, position);
        position = Search(head, value);
    }
    return head;
}
 
void Traverser(node head){
    printf("\n");
    node p;
    for(p = head; p != NULL; p = p->next){
        printf("%5d", p->data);
    }
}
 
node InitHead(){
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
 
node Input(){
    node head = InitHead();
    int n,i, value;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for( i = 0; i < n; ++i){
        printf("\nNhap gia tri can them: ");
        scanf("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}
int main(){
    printf("\n==Tao 1 danh sach lien ket==");
    node head = Input();
    Traverser(head);
 
    printf("\n==Thu them 1 phan tu vao linked list==");
    head = AddAt(head, 100, 2);
    Traverser(head);
 
    printf("\n==Thu xoa 1 phan tu khoi linked list==");
    head = DelAt(head, 1);
    Traverser(head);
 
    printf("\n==Thu tim kiem 1 phan tu trong linked list==");
    int index = Search(head, 5);
    printf("\nTim thay tai chi so %d", index);
 
    printf("\nBan co the thu them nhe!");
 
}
 
