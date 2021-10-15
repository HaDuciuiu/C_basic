#include<stdio.h>
enum{
    SUCCESS,FAIL
};
typedef struct Danhba
{
    char name[30];
    char tele_num[15];
    char email_add[50];
}DB;
int main()
{
    DB Dba[100];
    FILE *fin;
    int i,num;
    fin = fopen("cautrucfile.txt","r");
    int reval = SUCCESS;
    if(fin==NULL)
    {
        printf("Loi mo file, kiem tra lai nhe\n");
        reval = FAIL;
    }
    // doc du luu tu file luu vao mang Dba
    num = fread(Dba,sizeof(DB),3,fin);
    printf("Ham fread tra ve %d\n",num);
    for(i=0;i<num;i++)
    {
        printf("%s\t",Dba[i].name);
        printf("%s\t",Dba[i].tele_num);
        printf("%s\n",Dba[i].email_add);
    }
    fclose(fin);
    return reval;
}
