#include<stdio.h>
#define Max 50// so phan tu toi da
typedef char Eltype;// kieu cua phan tu cua mang la int
typedef Eltype StackType[Max]; //định nghĩa kiểu StackType là mảng Max phần tử có kiểu Eltype.
int top;
void Initialize(StackType stack);
int empty(StackType stack);
int full(StackType stack);
void push(Eltype el, StackType stack);
Eltype pop(StackType stack);