#include<stdio.h>
#define MaxLength 100 
typedef struct ADDR
{
	char name[30];
	char phone[15];
	char email[50];
}KeyType;
// specify a type for the data - khai bao mot kieu cho du lieu
typedef struct Node{
	KeyType key; 
	struct Node *left, *right;
}NodeType;
typedef NodeType* TreeType; 
typedef  TreeType ElType;
typedef struct {
	ElType Elements[MaxLength];
	//Store the elements
	int Front, Rear;
} Queue; 
void MakeNull_Queue(Queue *Q){
	Q->Front=-1;
	Q->Rear=-1;
}
int Empty_Queue(Queue Q){
	return Q.Front==-1;
}
int Full_Queue(Queue Q){
	return (Q.Rear-Q.Front+1)==MaxLength;
}
void EnQueue(ElType X,Queue *Q){
	if (!Full_Queue(*Q))
	{
		if (Empty_Queue(*Q)) Q->Front=0;
	Q->Rear=Q->Rear+1;
	Q->Elements[Q->Rear]=X;
	}
	else printf("Queue day!\n");
	}
ElType DeQueue(Queue *Q){
	if (!Empty_Queue(*Q))
	{
	int result = Q->Front;
	Q->Front=Q->Front+1;
	return Q->Elements[result];
	if (Q->Front > Q->Rear)
	MakeNull_Queue(Q);
// Queue tro th�nh rong
	}
	else printf("Queue bi rong!\n");
} 

