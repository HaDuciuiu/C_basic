#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct address
{
	char name[30];
	char phone[15];
	char email[50];
}Address;
typedef Address ElementType;
typedef struct node node;
struct node
{
  ElementType element;
  node *prev;
  node *next;
};
node *root=NULL, *cur=NULL, *tail=NULL;
node *makenewnode(ElementType el){
  node *newNode=(node*)malloc(sizeof(node));
  newNode->element=el;
  newNode->next=NULL;
  newNode->prev=NULL;
  return newNode;
}
void insertathead(ElementType el)
{
  node *newNode=makenewnode(el);
  if(root==NULL)
  {
    root=newNode;
    tail=newNode;
    cur=root;
  }
  else
  {
    newNode->next=root;
    root->prev=newNode;
    newNode->prev=NULL;
    root=newNode;
    cur=root;
  }
}
void insertatlast(ElementType el)
{
  node *newNode=makenewnode(el);
  if(root==NULL)
  {
    root=newNode;
    tail=newNode;
    cur=root;
  } 
  else
  {
    tail->next=newNode;
    newNode->prev=tail;
    newNode->next=NULL;
    tail=newNode;
  }
}
void insertatpos(ElementType el, int n)
{
  if(root==NULL)
  {
    insertathead(el);
    return;
  }
  if(n==0)
  {
    insertathead(el);
    return;
  }
  node *p;
  int i;
  node *newNode=makenewnode(el);
  for(p=root, i=1;p!=NULL&&i<n;p=p->next,i++);
  if(p==NULL)
  {
    insertatlast(el);
    return;
  }
  newNode->next=p->next;
  p->next->prev=newNode;
  p->next=newNode;
  newNode->prev=p;
  cur=p->next;
}

void insertaftercurrent(ElementType el)
{
  node *newNode=makenewnode(el);
  if(root==NULL)
  {
    root=newNode;
    tail=newNode;
    cur=root;
  }
  else
  {
    newNode->next=cur->next;
    if(cur->next!=NULL)
    cur->next->prev=newNode;
    cur->next=newNode;
    newNode->prev=cur;
    cur=cur->next;
  }
  if(newNode->next==NULL) tail=newNode;
  return;
}
void insertbeforecurrent(ElementType el)
{
  node *newNode=makenewnode(el);
  if(root==NULL)
  {
    root=newNode;
    tail=newNode;
    cur=root;
  }else{
    newNode->prev=cur->prev;
    if(cur->prev != NULL)
	{
      cur->prev->next=newNode;
    }
    newNode->next=cur;
    cur->prev=newNode;
    cur=newNode;
    if(newNode->prev==NULL) root=newNode;
  }
  
}
void deletefirst()
{
  node *p;
  p=root;
  root=root->next;
  cur=root;
  cur->prev=NULL;
  free(p);
}
void deletelast()
{
  node *p;
  p=tail;
  tail=tail->prev;
  cur=tail;
  tail->next=NULL;
  free(p);
}
void deletecurrent()
{
  node *p=cur;
  if(cur==root)
  {
    deletefirst();
    return;
  }
  if(cur==tail)
  {
    deletelast();
    return;
  }
  cur->prev->next=cur->next;
  cur->next->prev=cur->prev;
  cur=cur->next;
  free(p);
}
void deleteatpos(int n)
{
  int i;
  node *p;
  if(n==0)
  {
    deletefirst();
    return;
  }
  for(p=root,i=0;i<n&&p!=NULL;i++,p=p->next);
  if(p==NULL)
  {
    deletelast();
    return;
  }
  p->prev->next=p->next;
  p->next->prev=p->prev;
  free(p);
}
void freelist()
{
  node *del=root;
  while(del!=NULL)
  {
    root=root->next;
    free(del);
    del=root;
  }
}

void displaynode(node *p)
{
  if(p==NULL)
  {
    printf("Null pointer error\n");
    return;
  }
  for(p=root;p!=NULL;p=p->next)
  {
  	printf("%-30s%-15s%-50s\n",p->element.name,p->element.phone,p->element.email);
  }
 
}

void  reverselist()
{
  node *tmp, *cur=root;
  if(root==NULL)
  {
    printf("Root points to NULL\n");
    return ;
  }
  while(cur!=NULL)
  {
    tmp=cur->next;
    cur->next=cur->prev;
    cur->prev=tmp;
    cur=tmp;
  }
  tmp=root;
  root=tail;
  tail=tmp;
}
