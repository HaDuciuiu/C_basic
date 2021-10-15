#include<stdio.h>
#define Max 30
typedef char Eltype;// khai bao kieu du lieu cua cac phan tu trong stack
typedef Eltype StackType[Max];// //định nghĩa kiểu StackType là mảng Max phần tử có kiểu Eltype.
int top;
void Initialize(StackType stack)
{
    top = 0;
}
int IsEmpty(StackType stack)
{
    return top == 0;
}
int IsFull(StackType stack)
{
    return top == Max;
}
void Push(Eltype el,StackType stack)
{
    if (IsFull(stack))
        printf("stack overflow\n");
    else stack[top++] = el;
}
Eltype Pop(StackType stack)
{
    if(IsEmpty(stack))
        printf("stack underflow\n");
    else return stack[--top];
}
