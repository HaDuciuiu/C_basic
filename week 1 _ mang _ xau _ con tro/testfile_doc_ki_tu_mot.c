#include<stdio.h>
int main()
{
    FILE *fin;
    FILE *fout;
    int c;
    printf("Chuong trinh doc tung ki tu va ghi ra file\n");
    fin = fopen("labtest.txt","r");
    if(fin==NULL)
    {
        printf("Loi mo file , kiem tra lai\n");
        return 0;
    }
    fout = fopen("labtest1.txt","w");
    while(1)
    {
        c = fgetc(fin);
        if(feof(fin))
        {
            break;
        }
        fprintf(fout,"%c",c);//ghi ki tu c ra file
        printf("%c",c);//in ra man hinh stdout
    }
    return 0;
}