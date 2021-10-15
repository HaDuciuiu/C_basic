#include<stdio.h>
#define MaxLength 100 
typedef int ElType ;
typedef struct {
	ElType Elements[MaxLength];
	//Store the elements
	int Front, Rear;
} Queue; 
/*Ham tao mot queue rong*/
void MakeNull_Queue(Queue *Q){
	Q->Front=-1;
	Q->Rear=-1;
}
/*Ham kiem tra mot queue rong*/
int Empty_Queue(Queue *Q){
	return Q->Front==-1;
}
/*Ham kiem tra queue day ko*/
int Full_Queue(Queue *Q){
	return (Q->Rear-Q->Front+1)==MaxLength;
}
void EnQueue(ElType X,Queue *Q){
	if (!Full_Queue(Q))
	{
		if (Empty_Queue(Q)) Q->Front=0;
	Q->Rear=Q->Rear+1;
	Q->Elements[Q->Rear]=X;
	}
	else printf("Queue day!\n");
	}
void DeQueue(Queue *Q){
	if (!Empty_Queue(Q)){
		Q->Front=Q->Front+1;
		if (Q->Front > Q->Rear)
		MakeNull_Queue(Q);
// Queue tro thanh rong
	}
	else printf("Queue bi rong!\n");
} 

