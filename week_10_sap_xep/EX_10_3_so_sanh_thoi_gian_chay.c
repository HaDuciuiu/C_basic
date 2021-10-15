#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
typedef int element;
void swap(element *x, element *y)
{
    element temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(element arr[], int n)
{
    int i,j;
    bool haveSwap = false;
    for (i = 0; i < n-1; i++){
    // i phần tử cuối cùng đã được sắp xếp
        haveSwap = false;
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                haveSwap = true; // Kiểm tra lần lặp này có swap không
            }
        }
        // Nếu không có swap nào được thực hiện => mảng đã sắp xếp. Không cần lặp thêm
        if(haveSwap == false)
        {
            break;
        }
    }
}
void insertion_sort(element list[], int n)
{
    int i, j;
    element next;
    for (i=1; i<n; i++) 
    {
        next = list[i];
        for (j=i-1;j>=0 && next< list[j];j--)
            list[j+1] = list[j];
        list[j+1] = next;
    }
}

void selection_sort(element a[], int n)
{ 
    int i, j, min, tmp;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j <=n-1 ; j++)
            if ( a[j]< a[min])
                min = j;
        tmp= a[i];
        a[i]= a[min];
        a[min] = tmp;
    }
}
void print(element A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}

// ham sap xep vun dong

void SWAP(element *x , element *y , element temp)
{
    temp = *x;
    *x = *y;
    *y = temp;
}
void adjust(element list[], int root, int n)
{
    int child, rootkey;
    element temp;
    temp = list[root];     
    rootkey= list[root];
    child=2*root;
    while (child <= n) 
    {
        if ((child < n) && (list[child] < list[child+1]))
           child++;
        if (rootkey > list[child]) break;
        else 
        {
            list[child/2] = list[child];
            child *= 2;
        }
    }
    list[child/2] = temp;
}
void heapsort(element list[], int n)
{
    int i, j;
    element temp;
    for (i=n/2; i>0; i--) adjust(list, i, n);
    for (i=n-1; i>0; i--) 
    {

        SWAP(&list[1], &list[i+1], temp);
        adjust(list, 1, i);
    }
} 

int main()
{
    int *A;
    int n = 100000;
    A = (int*)malloc(n*sizeof(int));
    srand(time(NULL));
    int i;
    int key;
    clock_t tstart, tfinish;
    float tcomp;
    do
    {
        printf("\n===================Nhap vao lua chon cua ban:=======================\n");
        printf("1. Khoi tao mang\n");
        printf("2. Sap xep chen\n");
        printf("3. Sap xep chon\n");
        printf("4. Bubble sort\n");
        printf("5. Sap xep vun dong\n");
        printf("-1 . Exit\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            {
                srand(time(NULL));
                for(i=0;i<n;i++)
                {
                    A[i] = rand();
                }
                printf("Mang khoi tao la:\n");
                print(A,n);
                break;
            }
        case 2:
            {
            	int *B;
            	(int*)malloc(n*sizeof(int));
                tstart = clock();
                insertion_sort(A,n);
                tfinish = clock();
                tcomp = (float)(tfinish - tstart)/CLOCKS_PER_SEC;
                printf("Mang sau khi sap xep la:\n");
                print(A,n);
                printf("Thoi gian tinh cua thuat toan sap xep chen la : %.10f\n",tcomp);
                break;
            }
        case 3:
            {
                tstart = clock();
                selection_sort(A,n);
                tfinish = clock();
                tcomp = (float)(tfinish - tstart)/CLOCKS_PER_SEC;
                printf("Mang sau khi sap xep la:\n");
                print(A,n);
                printf("Thoi gian tinh cua thuat toan sap xep chon la : %.10f\n",tcomp);
                break;
            }
        case 4:
            {
                tstart = clock();
                bubbleSort(A,n);
                tfinish = clock();
                tcomp = (float)(tfinish - tstart)/CLOCKS_PER_SEC;
                printf("Mang sau khi sap xep la:\n");
                print(A,n);
                printf("Thoi gian tinh cua thuat toan bubble sort la : %.10f\n",tcomp);
                break;
            }  
        case 5:
            {
                tstart = clock();
                heapsort(A,n);
                tfinish = clock();
                tcomp = (float)(tfinish - tstart)/CLOCKS_PER_SEC;
                printf("Mang sau khi sap xep la:\n");
                print(A,n);
                printf("Thoi gian tinh cua thuat toan bubble sort la : %.10f\n",tcomp);
                break;
            } 
        default:
            printf("EXIT\n");
            break;
        }
        
    } while (key!=-1);
    return 0;
}
