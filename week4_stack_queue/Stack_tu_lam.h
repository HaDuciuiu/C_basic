#include<stdio.h>
#include<string.h>
#define Max 50//khai bao so phan tu lon nhat cua stack
typedef struct Danhba
{
	char name[30];
	char tel[15];
	char email[50];
}Address;
typedef  Address ElType;// tu day ElType tro thanh mot kieu du lieu giong nhu kieu char
typedef ElType StackType[Max];// dinh nghia kieu StackType la mang Max co kieu cua ElType
int top;// top la chi so cua phan tu dinh stack
void Initialize(StackType stack)//ham khoi tao stack (cho top=0)
{
	int top =0;
}
int IsEmpty(StackType stack)
{
	return top==0;// neu ma stack rong thi khi do top=0;
}
int IsFull(StackType stack)
{
	return top==Max;//neu ma stack day thi top bang Max
}
void Push(ElType el,StackType stack)
{
	if(IsFull(stack))
	{
		printf("Stack overflow\n");
	}
	else
	{
		strcpy(stack[top++].name,el.name);
		strcpy(stack[top++].tel,el.tel);
		strcpy(stack[top++].email,el.email);
		//stack[top++] = el;
	}
}

ElType Pop(StackType stack)
{
	if(IsEmpty(stack))
	{
		printf("Stack is underflow\n");
	}
	else
	{
		return stack[--top];
	}
}

