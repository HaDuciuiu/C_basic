#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct danhba
{
    char name[30];
    char tele[15];
    char email[50];
}DB;
int main()
{
    FILE *fin;
    FILE *fout;
    DB D_ba[100];// khai bao mot con tro D_ba de luu vao mot mang thong tin , cap phat bo nho sau
    DB Dba[100];
    int n,i;
    int num ;
    printf("Nhap vao so luong khach hang:");
    scanf("%d",&n);
    getchar();//lenh lay vao ki tu xuong dong
    printf("Nhap vao du lieu khach hang:\n");
    for(i=0;i<n;i++)
    {
        printf("Khach hang thu %d:\n",i+1);
        printf("Name:");
        gets(D_ba[i].name);
        printf("Telephone number:");
        gets(D_ba[i].tele);
        printf("Email address:");
        gets(D_ba[i].email);
    }
    fout = fopen("Cautrucfile.txt","w");
    num = fwrite(D_ba,sizeof(DB),n,fout);
    printf("Ham fwrite tra ve %d\n",num);
    fclose(fout);
    //free(D_ba);
    fin = fopen("cautrucfile.txt","r");
    if(fin==NULL)
    {
        printf("Loi mo file, kiem tra lai nhe\n");
        exit(0);
    }
    // doc du luu tu file luu vao mang Dba
    num = fread(Dba,sizeof(DB),n,fin);
    printf("\nDoc lai du lieu tu file :\n")
    printf("Ham fread tra ve %d\n",num);
    for(i=0;i<num;i++)
    {
        printf("%s\t",Dba[i].name);
        printf("%s\t",Dba[i].tele);
        printf("%s\n",Dba[i].email);
    }
    fclose(fin);
    return 0;
}
