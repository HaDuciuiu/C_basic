#include<stdio.h>
#include<stdlib.h>
#define Max 100
typedef int/*muon thay doi kieu cua data thi thay doi kieu int nay di*/ ElType;
/*Khai bao cau truc cua mot node cua Stack*/
typedef struct Node
{
	ElType item;
	struct Node *next;
}StackNode;
/*Khai bao cau truc Stack co kieu StackNode va luu giu phan tu dau tien*/
typedef struct stack
{
	StackNode *top;
}Stack;
/*Ham 1.Khoi tao Stack*/
Stack *CreatStack()
{
	Stack *s;
	s=(Stack*)malloc(sizeof(Stack));
	if(s==NULL)
	{
		return 0;
	}
	s->top=NULL;
	return s;
}
/*Ham2.kiem tra stack rong*/
int StackEmpty(Stack *s)
{
	return (s->top==NULL);
}

/*Ham 3.Push phan tu vao ngan xep*/
void Push(Stack *s,ElType value)
{
	StackNode *temp;
	temp = (StackNode*)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("Khong con bo nho\n");
		return ;
	}
	temp->item = value;
	temp->next = s->top;
	s->top = temp;
}
/*Ham 4. Pop phan tu khoi ngan xep*/
ElType Pop(Stack *s)
{
	ElType item;
	StackNode *node;
	if(StackEmpty(s))
	{
		printf("Ngan xep rong \n");
		return 0;
	}
	node = s->top;
	item = node->item;
	s->top = node->next;
	free(node);
	return item;
}
/*Ham 5 . Hien thi stack */
void disPlay(Stack *s)
{
	StackNode *node;
	ElType m;
	printf("\nDANH SACH CAC PHAN TU CUA NGAN XEP LA:\n");
	if(StackEmpty(s))
	{
		printf("\nNgan xep rong\n");
	}
	else
	{
		node = s->top;
		do
		{
			m = node->item;
			printf("%d",m);
			node = node->next;
		}while(node==NULL);
	}
}
/*Ham 6. Huy ngan xep*/
void StackDestroy(Stack *s)
{
	while(!StackEmpty(s))
	{
		Pop(s);
	}
	free(s);
}

