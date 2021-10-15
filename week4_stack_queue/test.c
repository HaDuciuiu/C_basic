#include<stdio.h>
#include<string.h>
#include"stack.h"
int main()
{
    StackType stack;
    char str[50];
    printf("Nhap vao mot xau ki tu :\n");
    gets(str);
    int i;
    Initialize(stack);
    for(i=0;i<strlen(str);i++)
    {
        push(str[i],stack);
    }
    while(empty(stack)==0)
    {
        printf("%c\t",pop(stack));
    }
    return 0;
}