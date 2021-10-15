#include<stdio.h>
#include"queue_list.h"
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fin,*fout;
    fin = fopen("danhba4.txt","r");
    if(fin==NULL)
    {
        printf("Loi o buoc doc file , kiem tra lai\n");
        exit(0);
    }
    ElementType A;
    Queue Q;
    MakeNullQueue(&Q);
    fout = fopen("danhba4cp2.txt","w");
    while(!feof(fin))
    {
        fgets(A.name,30,fin); 
        //A.name[strlen(A.name)-1] = '\0';
        fgets(A.phone,15,fin); 
        //A.phone[strlen(A.phone)-1] = '\0';
        fgets(A.email,50,fin);
        //A.email[strlen(A.email)-1] = '\0';
        EnQueue(A,&Q);
    }
    while(!isEmptyQueue(Q))
    {
        fprintf(fout,"%s\n%s\n%s\n",DeQueue(&Q).name,DeQueue(&Q).phone,DeQueue(&Q).email);
    }
    printf("Da hoan thanh chuong trinh , kiem tra file danhba4cp2.txt nhe\n");
    fclose(fin);
    fclose(fout);
    return 0;
}
