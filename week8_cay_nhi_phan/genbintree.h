#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct doibong{
  char name[10];
  int score;
}team;
typedef team element;
typedef struct nodetree_t{
  element A;
  struct nodetree_t *left,*right;
}treetype;
int compare(element a,element b){
  if(strcmp(a.name,b.name)==0){
    return 0;
  }
  if(strcmp(a.name,b.name)>0){
    return 1;
  }
  if(strcmp(a.name,b.name)<0){
    return -1;
  }
}
int compare2(element a,element b){
  if(a.score==b.score){
    return 0;
  }
  if(a.score>b.score){
    return 1;
  }
  if(a.score<b.score){
    return -1;
  }
}
void displayelement(element A){
  printf("%-15s %d\n",A.name,A.score);
}
int max(int a, int b){
  if(a>=b){                    
    return a;
  }
  return b;
}
void initialize(treetype **t){
  *t=NULL;
  return;
}
int isleaf(treetype *t){
  if(t==NULL){
    return -1;
  }
  return t->left==NULL&&t->right==NULL;
}
int isempty(treetype *t){
  return t==NULL;
}
void makenulltree(treetype **t){
  if(isempty(*t)){
    return;
  }
  if(isleaf(*t)){
    free(*t);
    return;
  }
  makenulltree(&(*t)->left);
  makenulltree(&(*t)->right);
  free(*t);
  return;
}
treetype *createnode(element A){
  treetype *p;
  p=(treetype*)malloc(sizeof(treetype));
  if(p!=NULL){
    p->left=NULL;
    p->right=NULL;
    p->A=A;
  }
  return p;
}
int numnode(treetype *t){
  if(isempty(t)){
    return 0;
  }
  return 1+numnode(t->left)+numnode(t->right);
}
/*treetype *createfrom2(element v,treetype *l,treetype *r){
  treetype *n;
  n=(treetype*)malloc(sizeof(treetype));
  n->A=v;
  n->left=l;
  n->right=r;
  return *n;
  }*/
void input(element v, treetype **t){
  if(*t==NULL){
    *t=createnode(v);
    printf("Address of new node: %d\n",*t);
    return;
  }
  if(compare((*t)->A,v)>=0){
    input(v,&(*t)->left);
    return;
  }else{
    input(v,&(*t)->right);
    return;
  }
}
int hight(treetype *t){
  if(t==NULL){
    return 0;
  }
  return 1+max(hight(t->left),hight(t->right));
}
int numleaf(treetype *t){
  if(t==NULL){
    return 0;
  }
  if(isleaf(t)){
    return 1;
  }
  return numleaf(t->left)+numleaf(t->right);
}
int numinode(treetype *t){
  if(t==NULL){
    return 0;
  }
  if(isleaf(t)){
    return 0;
  }
  return 1+numinode(t->left)+numinode(t->right);
}
int numrchildren(treetype *t){
  if(t==NULL){
    return 0;
  }
  if(t->right==NULL){
    return numrchildren(t->left);
  }
  return 1+numrchildren(t->left)+numrchildren(t->right);
}
void inorderprint(treetype *t){
  if(t!=NULL){
    inorderprint(t->left);
    displayelement(t->A);
    inorderprint(t->right);
  }
  return;
}
void postorderprint(treetype *t){
  if(t!=NULL){
    postorderprint(t->left);
    postorderprint(t->right);
    displayelement(t->A);
  }
}
void preorderprint(treetype *t){
  if(t!=NULL){
    displayelement(t->A);
    preorderprint(t->left);
    preorderprint(t->right);
  }
}
element deletemin(treetype **t){
  element k;
  if((*t)->left==NULL){
    k=(*t)->A;
    (*t)=(*t)->right;
    return k;
  }else{
    return deletemin(&(*t)->left);
  }
}
void deletenode(element k,treetype **t){
  if(*t!=NULL){
    if(compare2(k,(*t)->A)==-1){
      deletenode(k,&(*t)->left);
    }else if(compare2(k,(*t)->A)==1){
      deletenode(k,&(*t)->right);
    }else if(((*t)->left==NULL)&&((*t)->right==NULL)){
      *t=NULL;
    }else if((*t)->left==NULL){
      *t=(*t)->right;
    }else if((*t)->right==NULL){
      *t=(*t)->left;
    }else{
      (*t)->A=deletemin(&(*t)->right);
    }
  }
}
int lowerthankey(element A,treetype *t){
  if(t!=NULL){
    if(compare(A,t->A)>0){
      displayelement(t->A);
      return 1+lowerthankey(A,t->left)+lowerthankey(A,t->right);
    }else{
      return lowerthankey(A,t->left)+lowerthankey(A,t->right);
    }
  }
  return 0;
}
int higherthankey(element A,treetype *t){
  if(t!=NULL){
    if(compare(A,t->A)<0){
      displayelement(t->A);
      return 1+higherthankey(A,t->left)+higherthankey(A,t->right);
    }else{
      return higherthankey(A,t->left)+higherthankey(A,t->right);
    }
  }
  return 0;
}
void inordersearch(int *n,element A,treetype *t){
  if(t!=NULL){
    inordersearch(n,A,t->left);
    if(compare(A,t->A)==0){
      *n=1;
    }
    inordersearch(n,A,t->right);
  }
  return;
}
//bai kiem tra
void inorderupdate(element B,treetype **t){
  if((*t)!=NULL){
    inorderupdate(B,&(*t)->left);
    if(compare(B,(*t)->A)==0){
      (*t)->A.score=(*t)->A.score+B.score;
    }
    inorderupdate(B,&(*t)->right);
  }
  return;
}
void inordersearch2(int *n,element A,treetype *t){
  if(t!=NULL){
    inordersearch2(n,A,t->left);
    if(compare(A,t->A)==0){
      *n=1;
      displayelement(t->A);
    }
    inordersearch2(n,A,t->right);
  }
  return;
}
void xuonghang(element A,treetype **t){
  if((*t)!=NULL){
    xuonghang(A,&(*t)->left);
    xuonghang(A,&(*t)->right);
    if((*t)->A.score<A.score){
      printf("%s\n",(*t)->A.name);
      deletenode((*t)->A,t);
    }
  }
  return;
}
void xuatfile(FILE *ptr,treetype *t){
  if(t!=NULL){
    xuatfile(ptr,t->left);
    fprintf(ptr,"%s\t%d\n",t->A.name,t->A.score);
    xuatfile(ptr,t->right);
  }
  return;
}
