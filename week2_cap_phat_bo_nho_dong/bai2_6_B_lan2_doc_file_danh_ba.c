#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct danhba
{
    char name[20];
    char tele[20];
    char email[100];
}DB;
int main()
{
    FILE *fin;
    DB D_ba[100];
    int i;
    fin = fopen("Cautrucfile.txt","r");
    if(fin==NULL)
    {
        printf("Khong the mo file de doc,kiem tra lai\n");
        exit(1);
    }
    fread(D_ba,sizeof(DB),10,fin);
    for(i=0;i<10;i++)
    {
        printf("%s\t%s\t%s\n",D_ba[i].name,D_ba[i].tele,D_ba[i].email);
    }
    return 0;
}