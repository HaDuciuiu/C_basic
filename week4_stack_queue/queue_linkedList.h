#include<stdio.h>
#include<stdlib.h>
typedef int ElType;
typedef struct node{
	ElType Element;
	node* Next; //pointer to next element
}Node;
typedef Node* Position;
typedef struct{
	Position Front, Rear;
}Queue;
void MakeNullQueue(Queue *Q){
	Position Header;
	Header=(Node*)malloc(sizeof(Node));
	// Allocation Header
	Header->Next=NULL;
	Q->Front=Header;
	Q->Rear=Header;
}
int EmptyQueue(Queue Q){
	return (Q.Front==Q.Rear);
} 
void EnQueue(ElType X, Queue *Q){
	Q->Rear->Next=(Node*)malloc(sizeof(Node));
	Q->Rear=Q->Rear->Next;
	Q->Rear->Element=X;
	Q->Rear->Next=NULL;
}
Position DeQueue(Queue *Q){
	if (!EmptyQueue(*Q)){
	Position T,N;
	T=Q->Front;
	N=T;
	Q->Front=Q->Front->Next;
	free(T);
	return N;
	}
	else printf("Error: Queue is empty.");
} 

