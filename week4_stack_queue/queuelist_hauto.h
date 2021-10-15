#include<stdio.h>
#include<stdlib.h>
typedef element eltype;
typedef struct queue_t{
  eltype e;
  struct queue_t *next,*prev;
} queue;

queue *makenew(eltype e){
  queue *new=(queue*)malloc(sizeof(queue));
  new->e=e;
  new->next=NULL;
  new->prev=NULL;
  return new;
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
  queue *new=makenew(e);
  if(*front==NULL){
    *front=new;
    *rear=new;
  } else{
    (*rear)->next=new;
    new->prev=*rear;
    *rear=new;
  }
}
eltype frontQ(queue *front, queue *rear){
  if(!empty(front)){
    return front->e;
  }
}
