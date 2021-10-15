#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stacklib.h"
int do_uu_tien(char c)
{
    if(c == '*' || c == '/')
        return 1;
    if(c == '+' || c == '-')
        return 0;
    if(c == '(' || c == ')')
        return -1;
}
void Input(char str[])
{
    printf("nhap chuoi : ");
    gets(str);
}
void thuattoan(char kq[],StackType stack,char str[])
{
    int i;
    int dem = -1;
    char s;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            dem ++;
            kq[dem] = str[i];
        }
        if(str[i] == '(')
        {
            Push(str[i],stack);
        }
        if(str[i] == '+' ||str[i] == '-' ||str[i] == '*' ||str[i] == '/')
        {
                
                if(IsEmpty(stack))
                    {
                        Push(str[i],stack);
                    }
                else
                    {
                        if(do_uu_tien(str[i]) <= do_uu_tien(stack[--top]))
                        {
                            dem++;
                            top++;
                            kq[dem] = Pop(stack);
                        }
                        else
                            top++;
                    
                        Push(str[i],stack);   
                    }      
        }
        if(str[i] == ')')
        {
                    while(1)
                    {
                        s= Pop(stack);
                        if(s == '(')
                            break;
                        else
                        {
                            dem++;
                            kq[dem] = s;
                        }
                    }
                    
        }
    }
  while(!IsEmpty(stack))
        {
            s= Pop(stack);
            dem++;
            kq[dem] = s;
        }
        kq[dem+1] = '\0';
}
float Value_postfix(char Postfix[])
{
	StackType stack1;
	float op1, op2, result;
	int i=0;
	Initialize(stack1);
	while (Postfix[i]!= '\0')
	{
		while (Postfix[i]== ' ' || Postfix[i] == '\t')
		{
			i++;
		}
		if (isdigit(Postfix[i]))
		{
			int num = 0;
			while (isdigit(Postfix[i]))
			{
				num = (int)(Postfix[i])-48;
				Push(num,stack1);
				i++;
			}	
		}
		else
		{
			op1 = Pop(stack1);
			op2 = Pop(stack1);
			switch (Postfix[i])
			{
			case '+':
				result = op2 + op1;
				break;
			case '-':
				result = op2 - op1;
				break;
			case '/':
				result = op2 / op1;
				break;
			case '*':
				result = op2 * op1;
				break;
			default:
				printf("\nInvalid Operator");
				return 0;
			}
			Push(result,stack1);
			i++;
		}	
	}
	result = Pop(stack1);
	return result;
}
int main()
{
    char str[10];
    char kq[10];
    Input(str);
    StackType stack;
    Initialize(stack);
    thuattoan(kq,stack,str);
    printf("\nket qua : %s",kq);
    printf("\nGia tri cua bieu thuc hau to : %.2f\n",Value_postfix(kq));
}
