#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct thisinh
{
    char mssv[11];
    char name[31];
    float grade;
}TS;
int main()
{
    FILE *fin,*fout;
    int numSV;// bien dung de luu vao so luong sinh vien dc doc vao o dong dau file
    char s[100];// doc vao dong dau tien
    int i;// bien de luu vao so luong thi sinh co trong file thisinh.dat
    fin = fopen("thisinh.dat","rb");
    if(fin==NULL)
    {
        printf("Loi o buoc mo file , kiem tra lai\n");
        exit(0);
    }
    fscanf(fin, "%d%*c", &numSV);// lenh doc ca so va doc luon ki tu xuong dong o cuoi
    TS S[numSV];
    for (i = 0; i < numSV; i++)
    {
        /*if(i==0)
        {
            fscanf(fin, "%d%*c", &numSV);
        }*/
        fscanf(fin, "%[^,],%[^,],%f%*c", S[i].mssv,S[i].name,&S[i].grade);
    }
    
    printf("Danh sach sinh vien doc vao tu file la:\n");
    printf("STT\tMSSV\t\tName\t\t\t\tDiem\n");
    for(i=0;i < numSV;i++)
    {
        printf("%-3d\t%-10s\t%-30s\t%-5.2f\n",i+1,S[i].mssv,S[i].name,S[i].grade);
    }
    fclose(fin);
    fout = fopen("thisinh2.dat","wb");
    for(i=0;i<numSV;i++)
    {
        if(S[i].grade>=5)
        {
            fprintf(fout,"%10s,%30s,%2.1f\n",S[i].mssv,S[i].name,S[i].grade);
        }
    }
    printf("Da hoan thanh chuong trinh , kiem tra lai nhe!\n");
    fclose(fout);
    return 0;
}
