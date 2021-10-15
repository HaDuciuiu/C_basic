#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{
    FAIL , SUCCESS
};
typedef struct danhba
{
    char name[20];
    char tele_num[15];
    char email_add[100];
}Dba;
int main()
{
    FILE *fin;
    FILE *fout;
    Dba DB[100];
    int i,n,num;// bien num de dem so lan doc vao
    printf("Nhap du lieu vao nhe\n");
    printf("Nhap so khach hang ban muon nhap :");
    scanf("%d",&n);
    getchar();
    int reval = SUCCESS;// reval : danh gia lai
    for(i=0;i<n;i++)
    {
        printf("Khach hang so %d:\n",i+1);
        printf("Nhap ten :");
        gets(DB[i].name);
        printf("Nhap so dien thoai :");
        gets(DB[i].tele_num);
        printf("Nhap dia chi email:");
        gets(DB[i].email_add);
    }
    fout = fopen("phonebook.dat","w+b");
    if(fout==NULL)
    {
        printf("Loi mo file , kiem tra lai\n");
        reval = FAIL;
    }
    // write the entire array into the file
    num = fwrite(DB,sizeof(Dba),n,fout);
    printf("fwrite tra ve %d\n",num);
    fclose(fout);
    return 0;
}