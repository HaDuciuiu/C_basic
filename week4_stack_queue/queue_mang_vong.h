#include<stdio.h>
#define Max 100
typedef int ElType;// khai bao kieu du lieu cua cac phan tu trong queue la kieu int
typedef struct 
{
	ElType Elements[Max];// truong de chua gia tri cac phan tu
	int Front,Rear;
}Queue;
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
	return (Q->Rear-Q->Front+1)% Max==0;
}
/*Ham them phan tu queue*/
void EnQueue(ElType x , Queue *Q)
{
	if(!Full_Queue(Q))
	{
		if(Empty_Queue)
		{
			Q->Front = 0;
		}
		Q->Rear = (Q->Rear+1) % Max;
		Q->Elements[Q->Rear]=x;
	}
	else
	{
		printf("Queue da day\n");
	}
}
/*Ham xoa phan tu khoi queue*/
ElType DeQueue(Queue *Q)
{
	ElType data;
	if (!Empty_Queue(Q))
	{
		//Neu queue chi chua mot phan tu
		if (Q->Front==Q->Rear)
		{
			data = Q->Elements[Q->Front];
			MakeNull_Queue(Q);
			return data;
		}
		
		else 
		{
			data = Q->Elements[Q->Front];
			Q->Front=(Q->Front+1) % Max;
			return data;
		}
	}
	else printf("Queue rong!\n");
} 





