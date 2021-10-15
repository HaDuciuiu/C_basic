#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dem_dq =0 ;
typedef struct addr
{
    char name[30];
    char phone[15];
    char email[50];
}Address;
typedef Address ElementType;
// Truoc khi ap dung thuat toan sap xep nhi phan can sap xep mang Arr theo ten tang
void SapXepTang(ElementType Arr[],int n)
{
    int i,j;
    ElementType temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
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
    int n,i;
    FILE *fin,*fout;
    fin = fopen("address_7.txt","r");
    if(fin==NULL)
    {
        printf("Loi o buoc mo file , kiem tra lai\n");
        exit(0);
    }
    printf("Nhap vao so luong sinh vien muon doc: ");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        fgets(ADD[i].name,30,fin);
        ADD[i].name[strlen(ADD[i].name)-1]='\0';
        fgets(ADD[i].phone,15,fin);
        ADD[i].phone[strlen(ADD[i].phone)-1]='\0';
        fgets(ADD[i].email,50,fin);
        ADD[i].email[strlen(ADD[i].email)-1]='\0';
    }
    fout = fopen("address_7ra.txt","w");
    char nameSearch[30];
    printf("Nhap vao ten can tim kiem trong mang: ");
    gets(nameSearch);
    SapXepTang(ADD,n);
    int result = binarySearch_deQui(ADD,nameSearch,0,n);
    if(result>=0)
    {
    	printf("Ket qua tim kiem la:\n");
    	printf("Name\t\t\t\tPhone\t\t\tEmail\n");
    	printf("%-30s%\t%-15s\t%-50s\n",ADD[result].name,ADD[result].phone,ADD[result].email);
    	
    	fprintf(fout,"Ten duoc tim thay la:\n");
    	fprintf(fout,"%s\n%s\n%s\n",ADD[result].name,ADD[result].phone,ADD[result].email);
    	fprintf(fout,"\nNguoi co chi so nho nhat trong mang dau ra:\n");
    	fprintf(fout,"%s\n%s\n%s\n",ADD[0].name,ADD[0].phone,ADD[0].email);
	}
    
    printf("Nguoi co chi so nho nhat trong du lieu doc vao :\n");
    printf("Name\t\t\t\tPhone\t\t\tEmail\n");
    printf("%-30s\t%-15s\t%-50s\n",ADD[0].name,ADD[0].phone,ADD[0].email);

    printf("Hoan thanh chuong trinh! Mo file kiem tra lai\n");
    fclose(fin);
    fclose(fout);
    return 0;
}
