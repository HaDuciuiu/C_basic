#include"stack.h"
#include<stdio.h>
Initialize(StackType stack)
{
    top = 0;
}
empty(StackType stack)
{
    return top == 0;
}
full(StackType stack)
{
    return top == Max;
}
push(Eltype el, StackType stack)
{
    if (full(stack))
        printf("stack overflow");
    else stack[top++] = el;
}
Eltype pop(StackType stack)
{
    if (empty(stack))
        printf("stack underflow");
    else return stack[--top];
}