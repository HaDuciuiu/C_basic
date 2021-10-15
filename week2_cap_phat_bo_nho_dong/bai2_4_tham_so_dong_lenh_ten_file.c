#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc , char *argv[])
{
    FILE *fin;
    FILE *fout;
    int num;
    char str[100];
    if(argc>3)
    {
        printf("Qua nhieu doi so \n");
        exit(1);
    }
    else if(argc<3)
    {
        printf("Qua it doi so\n");
        exit(1);
    }
    else
    {
        fin = fopen(argv[1],"r");
        if(fin==NULL)
        {
            printf("Mo file doc that bai,kiem tra lai\n");
            exit(1);
        }
        fout = fopen(argv[2],"w");
        if(fout == NULL)
        {
            printf("Mo file doc loi , kiem tra lai\n");
            exit(1);
        }
            num = fread(str,sizeof(char),100,fin);/*Ham fread tra ve so ki tu doc duoc tu file
            nen ta gan no vao bien num de khi ghi ra file ta chi ghi vao num ki tu */
            str[num]='\0';/*gan phan tu str cuoi cung bang '\0' de no khong doc vao ki tu
            dac biet nao khac khi doc het file*/
            fwrite(str,sizeof(char),num,fout);
            puts("chuong trinh doc file tu ten ");
            printf("%s",str);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
