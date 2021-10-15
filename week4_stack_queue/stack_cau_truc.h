#include<stdio.h>
#define Max 50//so phan tu Max = 50
typedef int ElType;// cac phan tu co kieu int
typedef struct StackRec
{
	ElType storage[Max];// khai bao mot mang luu tru kieu ElType co so phan tu lon nhat la Max
	int top;// truong top luu chi so cua phan tu dinh cua mang
}StackType;// tu day kieu du lieu cua stack (StackType) la kieu cau truc co cac truong nhu tren
void Initialize(StackType *stack)// ham khoi tao stack(truyen con tro de truong top con luu lai
// sau ham khoi tao
{
	(*stack).top=0;	
}
int IsEmpty(StackType stack)
{
	return stack.top==0;// neu ma stack rong thi stack.top==0	
} 
int IsFull(StackType stack)
{
	return stack.top==Max;
}
void Push(ElType el,StackType *stack)
/*Ham nay phai truyen con tro vi sau khi thuc hien ham ta muon giu su thay doi cua top*/
{
	if(IsFull(*stack))
	{
		printf("stack is overflow\n");
	}
	else
	{
		(*stack).storage[(*stack).top++]=el;
	}
}
ElType Pop(StackType *stack)
/*Ham nay cung phai su dung con tro stack vi ta can luu giu su thay doi cua top sau ham*/
{
	if(IsEmpty(*stack))
	{
		printf("Stack is underflow\n");
	}
	else
	{
		return (*stack).storage[--(*stack).top];
	}
	
}
