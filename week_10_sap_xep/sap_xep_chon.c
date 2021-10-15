#include<stdio.h>
typedef int element;
void selection(element a[], int n)
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
int main()
{
    printf("Thuat toan sap xep chon:\n");
    return 0;
}
