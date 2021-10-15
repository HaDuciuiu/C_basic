#include<stdio.h>
#include<string.h>
#include"linkedlist.h"
#include<string.h>
#include<time.h>
int dem_s=0  , dem_in=0 ;
// ham thuat toan sap xep chon 
void selection(element a[], int n)
{ 
    int i, j, min;
    element tmp;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j <= n-1 ; j++)
            if (strcmp(a[j].name,a[min].name)<0)
            {
                min = j;
                dem_s++;
            }      
        tmp = a[i];
        a[i]= a[min];
        a[min] = tmp;
    }

}
// ham thuat toan sap xep chen
void insertion_sort(element list[], int n)
{
    int i, j;
    element next;
    for (i=1; i<n; i++) 
    {
        next= list[i];
        for (j=i-1;j>=0 && strcmp(next.name,list[j].name)<0;j--)
        {
            list[j+1] = list[j];
            dem_in++;
        }
            
        list[j+1] = next;
    }
}
// ham in ra sau ki da sap xep
void print(element A[],int n)
{
    int i;
    printf("Name\t\t\t\tPhone\t\t\tEmail\n");
    for(i=0;i<n;i++)
    {
        printf("%-30s\t%-15s\t%-50s\n",A[i].name,A[i].phone,A[i].email);
    }
}
int main()
{
    int key;
    FILE *fin;
    int i,n;
    printf("Nhap vao so du lieu muon doc vao: ");
    scanf("%d",&n);
    time_t tstart , tfinish;
    float tcomp;
    fin = fopen("danhba_10.txt","r");
    if(fin==NULL)
    {
        printf("Loi o buoc mo file , kiem tra lai nhe\n");
        exit(1);
    }
    do
    {
        printf("Nhap vao lua chon cua ban :\n");
        printf("1. Su dung mang cau truc\n");
        printf("2. Su dung danh sach lien ket\n");
        printf("-1. Thoat chuong trinh\n");
        scanf("%d",&key);
        switch(key)
        {
        	
            case 1 :
            {
            	Address A[100];
                for(i=0;i<n;i++)
                {
                    fgets(A[i].name,30,fin);
                    A[i].name[strlen(A[i].name)-1] = '\0';
                    fgets(A[i].phone,15,fin);
                    A[i].phone[strlen(A[i].phone)-1] = '\0';
                    fgets(A[i].email,50,fin);
                    A[i].email[strlen(A[i].email)-1] = '\0';
                }
                printf("\nDu lieu doc vao la :\n");
                print(A,n);
                // bat dau sap xep chen tu day
                printf("\nDanh sach danh ba sau khi sap xep chen la:\n");
                tstart = clock();
                insertion_sort(A,n);
                tfinish = clock();
                tcomp = (float)(tfinish - tstart)/CLOCKS_PER_SEC;
                print(A,n);
                printf("Thoi gian tinh cua thuat toan la : %.10f\n",tcomp);
                printf("So phep so sanh can thuc hien la: %d\n",dem_in);
                dem_in =0;
                
//                // duoi day la sap xep chon
//                printf("Danh sach sau khi sap xep chon la:\n");
//                tstart = clock();
//                selection(A,n);
//                tfinish = clock();
//                tcomp = (float)(tfinish - tstart)/CLOCKS_PER_SEC;
//                printf("Thoi gian tinh cua thuat toan bubble sort la : %.100f\n",tcomp);
//                print(A,n);
//                fclose(fin);
              	break;
            }
            case 2:
            {
                node head;
                head = InitHead();
                Address B[100];
                fin = fopen("danhba_10.txt","r");
    			if(fin==NULL)
    			{
        			printf("Loi o buoc mo file , kiem tra lai nhe\n");
        			exit(1);
    			}
                for(i=0;i<n;i++)
                {
                    fgets(B[i].name,30,fin);
                    B[i].name[strlen(B[i].name)-1] = '\0';
                    fgets(B[i].phone,15,fin);
                    B[i].phone[strlen(B[i].phone)-1] = '\0';
                    fgets(B[i].email,50,fin);
                    B[i].email[strlen(B[i].email)-1] = '\0';
                    head = AddTail(head,B[i]);	
                }
                fclose(fin);
                printf("Danh sach doc vao tu file la:\n");
                Traverser(head);
                printf("Danh sach sau khi sap xep la:\n");
                element List[100];
                tstart = clock();
                insertion_sortL(head,List,&n);
                tfinish = clock();
                tcomp = (float)(tfinish - tstart)/CLOCKS_PER_SEC;
                Traverser(head);
                printf("Thoi gian tinh cua thuat toan la: %.10f\n",tcomp);
                printf("So phep so sanh can thuc hien la: %d\n",dem_i);
                break;
            }
        }
    } while (key!=-1);
    
    return 0;
}
