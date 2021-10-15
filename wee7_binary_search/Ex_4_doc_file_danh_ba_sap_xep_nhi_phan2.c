#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dem_dq = 0 ;
typedef struct addr
{
    char name[30];
    char phone[15];
    char email[50];
}Address;
typedef Address ElementType;
// Truoc khi ap dung thuat toan sap xep nhi phan can sap xep mang Arr theo ten tang
void SapXepTang(ElementType Arr[])
{
    int i,j;
    ElementType temp;
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(strcmp(Arr[i].name,Arr[j].name)>0)
            {
                temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }

        }
    }
}
int binarySearch_deQui(ElementType Arr[],char target[], int low , int high)
{
    if(low > high)
        return -1;
    int mid = (low + high)/2;
    if(strcmp(Arr[mid].name,target)>0)
    {
        dem_dq++;
        return binarySearch_deQui(Arr,target,low,mid-1);  
    } 
    else if(strcmp(Arr[mid].name,target)<0)
    {
        dem_dq++;
        return binarySearch_deQui(Arr,target,mid+1,high);
    }  
    else 
    {
        dem_dq++;
        return mid;
    }
    return -1;
}
int main()
{
    ElementType ADD[100];
    int i;
    FILE *fin,*fout;
    fin = fopen("address_7.txt","r");
    if(fin==NULL)
    {
        printf("Loi o buoc mo file , kiem tra lai\n");
        exit(0);
    }
    for(i=0;i<10;i++)
    {
        fscanf(fin, "%[^\n]%*c", ADD[i].name);
        fscanf(fin, "%s%*c", ADD[i].phone);
        fscanf(fin, "%s%*c", ADD[i].email);
    }
    fout = fopen("address_7ra.txt","w");
    char nameSearch[30];
    printf("Nhap vao ten can tim kiem trong mang: ");
    scanf("%[^\n]%*c", nameSearch);
    SapXepTang(ADD);
    int result = binarySearch_deQui(ADD,nameSearch,0,9);
    printf("Ket qua tim kiem la:\n");
    printf("Name\t\t\tPhone\t\tEmail\n");
    printf("%-30s%-15s%-50s\n",ADD[result].name,ADD[result].phone,ADD[result].email);
    printf("Nguoi co chi so nho nhat trong du lieu doc vao :\n");
    printf("Name\t\t\tPhone\t\tEmail\n");
    printf("%-30s%-15s%-50s\n",ADD[0].name,ADD[0].phone,ADD[0].email);
    fprintf(fout,"Ten duoc tim thay la:\n");
    fprintf(fout,"%s\n%s\n%s\n",ADD[result].name,ADD[result].phone,ADD[result].email);
    fprintf(fout,"\nNguoi co chi so nho nhat trong mang dau ra:\n");
    fprintf(fout,"%s\n%s\n%s\n",ADD[0].name,ADD[0].phone,ADD[0].email);
    printf("Hoan thanh chuong trinh! Mo file kiem tra lai\n");
    fclose(fin);
    fclose(fout);

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%s\t%s\t%s\n", ADD[i].name, ADD[i].phone, ADD[i].email);
    // }
    
    return 0;
}
