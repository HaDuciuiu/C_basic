#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int  eltype;
typedef struct stacktype{
  eltype e;
  struct stacktype *link;
} stacktype;
int empty(stacktype *p){
  return p==NULL;
}
void push(stacktype **p, eltype e){
  stacktype *new=(stacktype*)malloc(sizeof(stacktype));
  new->e=e;
  new->link=*p;
  *p=new;
  return;
}
eltype pop(stacktype **p){
  if(empty(*p)){
    printf("stack undeflow\n");
    exit(0);
  }
  stacktype *temp=*p;
  eltype poped=temp->e;
  *p=(*p)->link;
  free(temp);
  return poped;
}
void freestack(stacktype **p){
  while(!empty(*p)){
    pop(p);
  }
}
eltype peek(stacktype *p){
  if(empty(p)){
    printf("stack undeflow\n");
    exit(0);
  }
  return p->e;
}
