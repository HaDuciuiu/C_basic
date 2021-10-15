#include<stdio.h>
#include<stdlib.h>
typedef struct ADDR
{
	char name[30];
	char phone[15];
	char email[50];
}KeyType;
// specify a type for the data - khai bao mot kieu cho du lieu
typedef struct Node
{
	KeyType key; 
	struct Node* left, *right;
}NodeType;
typedef NodeType* TreeType; 
typedef TreeType ElementType;
typedef struct Q_Node
{ 
	ElementType Element;
	struct Q_Node* Next; //pointer to next element
}QNode;
typedef QNode* Position; // Tu day moi con tro node se thay the bang kieu position
typedef struct
{ 
	Position Front, Rear;
}Queue;

// ham khoi tao mot queue rong 
void MakeNullQueue(Queue *Q)
{ 
	Position Header; 
	Header=(QNode*)malloc(sizeof(QNode)); //Allocation	Header 
	Header->Next=NULL; 
	Q->Front=Header; 
	Q->Rear=Header;
}

// ham kiem tra xem queue co rong hay khong
int EmptyQueue(Queue *Q)
{ 
	return (Q->Front==Q->Rear); 
}

// Ham them mot node vao Queue
void EnQueue(ElementType X, Queue *Q)
{ 
	Q->Rear->Next=(QNode*)malloc(sizeof(QNode));
 	Q->Rear=Q->Rear->Next; 
	Q->Rear->Element=X; 
	Q->Rear->Next=NULL;
}
 
// Ham xoa mot node khoi queue
ElementType DeQueue(Queue *Q)
{ 
	Position T;
	if (!EmptyQueue(Q))
	{ 
		T=Q->Front; 
		Q->Front=Q->Front->Next;
		if(Q->Front==NULL)// la nut du lieu cuoi cung
		{
			Q->Rear = NULL;	
		}
		T->Next = NULL;// ko tro ke tiep vao front nua
	} 
	else printf("Error: Queue is empty.\n");
	return T->Element; 
} 

