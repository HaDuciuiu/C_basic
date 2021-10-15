#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
typedef phonedb elementtype;
typedef  struct node{
  elementtype element;
  struct node *next;
} node;

node *root=NULL, *cur = NULL, *prev = NULL;
node *makenewnode(elementtype element){
  node *new=(node*)malloc(sizeof(node));
  new->element=element;
  new->next=NULL;
  return new;
}
void insertathead(elementtype element){
  node  *new=makenewnode(element);
  if(root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  } else{
    new->next=root;
    root=new;
    cur=root; // cap nhat con tro cur
  } 
}
void insertaftercurrent(elementtype element){
  node *new=makenewnode(element);
  if(root == NULL){
    root=new;
    cur=root;
  } else if(cur == NULL){
    printf("Current pointer is NULL.\n");
    return ;
  }
  else{
    new->next=cur->next;
    cur->next=new;
    prev=cur;/*Update prev for use later*/
    cur=cur->next;
  }
  return ;
}
void insertbefore(elementtype element){
  node *new=makenewnode(element);
  if(root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  } else{
    new->next = cur;
    /* Neu cur o dau danh sach */
    if(cur==root){
      root=new;
    } else prev->next=new;
    cur=new;
  }
return;
}
void deletefirst(){
  node *p;
  p=root;
  root=root->next;
  cur=root;
  /*prev = NULL*/
  free(p);
  return;
}
void deletecurrent(){
  if(cur==NULL) return;
  if(cur == root) deletefirst();
  else{
    prev->next=cur->next;
    free(cur);
    cur=prev->next;
  }
  return;
}
void freelist(){
  node *freelist;
  while(root!=NULL){
    freelist=root;
    root=root->next;
    free(freelist);
  }
}
node* list_reverse(node* root){
  node *cur, *prev;
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
node* insertatposition(node *root,elementtype element, int n){
  node *p, *new=makenewnode(element);
  int count;
  for(p=root, count=1; count<n||p==NULL;count++,p=p->next);
  cur = p;
  if(root==NULL){
    root = new;
    cur = root;
  } else{
    new->next=cur->next;
    cur->next=new;
    prev= cur;
    cur=cur->next;
  }
  return new;
}
node*  deleteatposition(node *root, int n){
  int i=0;
  node* p =root;
  node *del, *prev =p;
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
node *splitlist(node *r, int n1, int n2){
  node *r1=NULL;
  node *p, *cur;
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
void printtotext(node *r, char s[]){
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
}
