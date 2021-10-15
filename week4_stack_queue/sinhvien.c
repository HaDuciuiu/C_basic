#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 20
typedef struct
{
    char name[30];
    char phone[15];
    char email[30];
} sinhvien;
int top = 0;
int IsEmpty(sinhvien stack[Max])
{
    return top == 0;
}
int IsFull(sinhvien stack[Max])
{
    return top == Max;
}
void Push(sinhvien el,sinhvien stack[Max])
{
    if(IsFull(stack))
        printf("stack Overflow !!");
    else
        {

            strcpy(stack[top].email,el.email);
            strcpy(stack[top].name,el.name);
            strcpy(stack[top].phone,el.phone);
            top++;
        }
}
sinhvien Pop(sinhvien stack[Max])
{
    if(IsEmpty(stack))
        printf("stack underflow");
    else
        return stack[--top];
}
void docfile(char *fname,sinhvien el,sinhvien stack[])
{
    FILE *fp;
    fp = fopen(fname,"r");
    if(fp == NULL)
    {
        printf("file khong ton tai !!");
        return;
    }
    int i;
    while(fgets(el.name,30,fp)&&fgets(el.phone,15,fp)&&fgets(el.email,30,fp))
    {
        
        el.name[strlen(el.name)-1] = '\0';
        
        el.phone[strlen(el.phone)-1] = '\0';
        
        el.email[strlen(el.email)-1] = '\0';
        Push(el,stack);
    }
    fclose(fp);
    
}
void ghifile(char *ffname,sinhvien stack[Max])
{
    FILE *fpt;
    fpt = fopen(ffname,"w");
    if(fpt == NULL)
    {
        printf("khong the tao file !!");
        return;
    }
    sinhvien temp;
    while(!IsEmpty(stack))
    {
        temp = Pop(stack);
        fprintf(fpt,"%s\n%s\n%s\n",temp.name,temp.phone,temp.email);
    }
    fclose(fpt);
}
int main()
{
    sinhvien stack[Max];
    sinhvien arr[Max];
    sinhvien el;
    docfile("address.txt",el,stack);
    ghifile("addresscp.txt",stack);


    return 0;
}
