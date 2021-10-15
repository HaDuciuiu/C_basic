#include<stdio.h>
#include<stdlib.h>

typedef int element;
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
    printf("Thuat toan sap xep vun dong - heapsort\n");
    return 0;
}