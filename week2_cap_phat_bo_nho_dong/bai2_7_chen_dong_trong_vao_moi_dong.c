#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fin;
    FILE *fout;
    char c;
    fin = fopen("class1EF.txt","r");
    if(fin == NULL)
    {
        printf("Loi o buoc mo file doc, check lai\n");
        return 0;
    }
    fout = fopen("class1EF1.txt","w");
    while((c=fgetc(fin)) != EOF)
    {
        fputc(c,fout);
        if(c=='\n')
        {
            fputc('\n',fout);/*neu doc den phan tu '\n' o cuoi moi dong thi ta in them mot 
            ki tu '\n' nua*/
        }
    }
    fclose(fin);
    fclose(fout);
    fin = fopen("class1EF1.txt","r");
    if(fin == NULL)
    {
    	printf("loi mo file , kiem tra lai\n");
    	exit(1);
	}
    fout = fopen("class1EF.txt","w");
    while((c=fgetc(fin))!= EOF)
    {
    	fputc(c,fout);
	}
    printf("Hoan thanh xong chuong trinh , kiem tra lai nhe\n");
    return 0;
}
