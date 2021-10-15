#include<stdio.h>
#include<stdlib.h>
typedef int eltype;
typedef struct queue_t{
  eltype e;
  struct queue_t *next,*prev;
} queue;

queue *makenew(eltype e){
  queue *newNode=(queue*)malloc(sizeof(queue));
  newNode->e=e;
  newNode->next=NULL;
  newNode->prev=NULL;
  return newNode;
}

int empty(queue *front){
  return front==NULL;
}

eltype deQ(queue **front, queue **rear){
  if(!empty(*front)){
    queue *del=*front;
    eltype el=(*front)->e;
    *front=(*front)->next;
    free(del);
    return el;
  } else {
    printf("Queue is empty\n");
  }
}


void enQ(queue **front, queue **rear, eltype e){
  queue *newNode=makenew(e);
  if(*front==NULL){
    *front=newNode;
    *rear=newNode;
  } else{
    (*rear)->next=newNode;
    newNode->prev=*rear;
    *rear=newNode;
  }
}
eltype frontQ(queue *front, queue *rear){
  if(!empty(front)){
    return front->e;
  }
}
