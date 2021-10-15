#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fin;
    FILE *fout;
    int num;// bien dem so ki tu doc vao dc tu file qua ham fread
    char str[1000];
    fin = fopen("laba.txt","r");
    if(fin==NULL)
    {
        printf("Mo file bi loi\n");
        exit(1);//chua trong thu vien stdlib.h
    }
    fout = fopen("labcp.txt","w");
    while(!feof(fin))// phu dinh cua den cuoi file la chua den cuoi file
    {
        num = fread(str,sizeof(char),1000,fin);
        str[num] = '\0';//khoi tao phan tu xau thu num = NULL de ko bi nhan ki tu rac
        fwrite(str,sizeof(char),num,fout);//chi ghi ra file fout num phan tu thoi
    }
    puts("Da hoan thanh chuong trinh\n");
    fclose(fin);
    fclose(fout);
    return 0;
}