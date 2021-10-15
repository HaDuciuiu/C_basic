#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int agrc, char *argv[])
{
    FILE *fout;
    fout = fopen("filecat.txt","w");
    char str1[100];
    char str2[100];
    printf("Nhap vao xau 1:");
    gets(str1);
    printf("Nhap vao xau 2:");
    gets(str2);
    int len1,len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    char *result;//con tro mang duoc cap phat bo nho
    result = (char*)malloc((len1+len2+1)*sizeof(char));// cong 1 de co 1 vi tri chu '\0'
    strcpy(result,str1);
    strcpy(result+len1,str2);
    int n= len1 +len2 +1;
    fwrite(result,sizeof(char),n,fout);
    printf("Xau sau khi ta noi la:\n");
    printf("%s",result);
    free(result);
    fclose(fout);
    return 0;
}