#include<stdio.h>
#include "stacklib.h"
#include<string.h>

int main()
{
    char so1[Max];
    char so2[Max];
    StackType stack1,stack2,stackSum;
    printf("nhap so thu nhat : ");
    gets(so1);
    printf("nhap so thu hai : ");
    gets(so2);
    int i;
    for(i=0;i<strlen(so1);i++)
        Push(so1[i],stack1);  
    int top1 = top;
    top = 0;
    for(i=0;i<strlen(so2);i++)
        Push(so2[i],stack2);
    int top2 = top;
    char s1,s2,sum='0',s3;
    int top3 =0;
    while(top1 != 0 || top2 != 0)
    {
        top = top2;
        if(!IsEmpty(stack2))
        {
            s2 = Pop(stack2);
            top2 = top;
        }
        else
            s2 = '0';
        top = top1;
        if(!IsEmpty(stack1))
        {
            s1 = Pop(stack1);
            top1 = top;
        }
        else
            s1 = '0';
        s3 = s1+s2-48+sum-48;
        top = top3;
        if(s3 > '9')
        {
            s3 = s3-10;
            Push(s3,stackSum);
            sum = '1';
        }
        else
        {
            Push(s3,stackSum);
            sum = '0';
        }
        top3 = top;
    }
    if(sum == '1')
     Push(sum,stackSum);
    printf("\n");
    while(!IsEmpty(stackSum))
        {
            printf("%c",Pop(stackSum));
        }
    
    return 0;
}
