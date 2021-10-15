#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct addr
{
	char name[30];
	char phone[15];
	char email[50];
}Address;
typedef Address ElementType;/*khai bao kieu du lieu cua cac phan tu trong linked list la kieu int
khi lam viec voi cac kieu du lieu khac thi ta thay doi thanh kieu du lieu do nhe*/
typedef  struct node{
  ElementType element;
  struct node *next;
} Node;
Node *root=NULL, *cur = NULL, *prev = NULL;
Node *makeNewNode(ElementType element)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->element=element;
  newNode->next=NULL;
  return newNode;
}
void AddHead(ElementType element){
  Node  *newNode=makeNewNode(element);
  if(root==NULL){
    root=newNode;
    cur=root;
    prev=NULL;
  } else{
    newNode->next=root;
    root=newNode;
    cur=root; // cap nhat con tro cur
  } 
}
void AddTail(ElementType element){
    Node *temp,*p;// Khai bao 2 node tam temp va p
    temp = makeNewNode(element);//Goi ham createNode de khoi tao node temp có next tro toi NULL và giá tri là value
    if(root == NULL){
        root = temp;     //Neu linked list dang trong thi Node temp là head luôn
        cur = root;
        prev = NULL;
    }
    else{
        p  = root;// Khoi tao p tro toi head
        while(p->next != NULL){
            p = p->next;//Duyet danh sách liên ket den cuoi. Node cuoi là node có next = NULL
        }
        p->next = temp;//Gán next cua thang cuoi = temp. Khi dó temp se là thang cuoi(temp->next = NULL mà)
        cur = temp;
    }
}
void insertAfterCurrent(ElementType element){
  Node *newNode=makeNewNode(element);
  if(root == NULL){
    root=newNode;
    cur=root;
  } else if(cur == NULL){
    printf("Current pointer is NULL.\n");
    return ;
  }
  else{
    newNode->next=cur->next;
    cur->next=newNode;
    prev=cur;/*Update prev for use later*/
    cur=cur->next;
  }
  return ;
}
void insertBeforeCurrent(ElementType element){
  Node *newNode=makeNewNode(element);
  if(root==NULL){
    root=newNode;
    cur=root;
    prev=NULL;
  } else{
    newNode->next = cur;
    /* Neu cur o dau danh sach */
    if(cur==root){
      root=newNode;
    } else prev->next=newNode;
    cur=newNode;
  }
return;
}
void DelHead(){
  Node *p;
  p=root;
  root=root->next;
  cur=root;
  /*prev = NULL*/
  free(p);
  return;
}
void DelCurrent(){
  if(cur==NULL) return;
  if(cur == root) DelHead();
  else{
    prev->next=cur->next;
    free(cur);
    cur=prev->next;
  }
  return;
}
void DelTail()
{
	if (root == NULL || root->next == NULL){
        return DelHead();
    }
    Node *p = root;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; // Cho next bang NULL
    // Hoac viet p->next = NULL cung duoc
    cur = p;
}
void freeList(){
  Node *freelist;
  while(root!=NULL){
    freelist=root;
    root=root->next;
    free(freelist);
  }
}
Node* list_reverse(Node* root){
  Node *cur, *prev;
  cur = prev = NULL;
  while(root != NULL){
    cur = root;
    root = root->next;
    cur->next = prev;
    prev = cur;
  }
  root=cur;
  return prev;
}
Node* insertAtPosition(Node *root,ElementType element, int n){
  Node *p, *newNode=makeNewNode(element);
  int count;
  for(p=root, count=1; count<n||p==NULL;count++,p=p->next);
  cur = p;
  if(root==NULL){
    root = newNode;
    cur = root;
  } else{
    newNode->next=cur->next;
    cur->next=newNode;
    prev= cur;
    cur=cur->next;
  }
  return newNode;
}
Node*  deleteAtPosition(Node *root, int n){
  int i=0;
  Node* p =root;
  Node *del, *prev =p;
  if(n==0 || root == NULL){
    del = root; root=del->next; cur = root;
    free(del); cur=root; return root;
  }
  while((i<n) && (p->next!=NULL)){
    prev=p;
    p=p->next;
    i++;
  }
  if(i<n) return root;// do nothing
  prev->next=p->next;
  free(p);
  cur=root;
  return root;
}
Node *splitlist(Node *r, int n1, int n2){
  Node *r1=NULL;
  Node *p, *cur;
  int i=0;
  if(n1<0||n2<0){
    printf("n1 and n2 must >0\n");
    return r;
  }
  if(n1==0){
    r1=r;
    p=r1;
    for(i=0;i<n2;i++){
      r=r->next;
      p=p->next;
    }
    p->next=NULL;
    return r1;
  }
  for(p=r;i<n1-1;i++){
    p=p->next;
  }
  cur=p;
  r1=p->next;
  for(i=0;i<n2+1;i++){
    cur=cur->next;
  }
  p->next=cur;
  for(p=r1,i=1;i<n2;i++){
    p=p->next;
  }
  p->next=NULL;
  
  return r1;
}
// ham tim kiem phan tu trong list qua ten
Node* Search_LinkedList(char nameSearch[])
{
	Node *p = root;
	while(strcmp(p->element.name,nameSearch)!=0 && p!=NULL)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
		return p;
	}
	return NULL;
}

// ham tim kiem chuyen len dau
Node* SearchMoveToFront(char nameSearch[])
{
	Node *p;
	Node *temp;
	for (p=root;p!=NULL;p=p->next)
	{
		if (strcmp(p->element.name,nameSearch)==0)
		{	 
			if (p!=root)
			{
				temp = p;
				AddHead(temp->element);
				p = p->next;
				free(temp);
				return root;
			}
			return p;// vi sau do node can tim se la node root
		}
	}
	return NULL;
}
/*void printToText(node *r, char s[]){
  FILE *fptr;
  node *p=r;
  if((fptr=fopen(s,"w+")) == NULL){
    printf("Cannot creat %s\n", s);
    return;
  }
  while(p!=NULL){
    fprintf(fptr,"%-20s%-10s%-10s%-10s\n",p->element.model,p->element.space,p->element.ssize,p->element.price);
    p=p->next;
  }
  return;
}*/
