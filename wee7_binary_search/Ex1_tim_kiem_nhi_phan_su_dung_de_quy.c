#include<stdio.h>
#define NotFound -1
typedef int ElementType;

int  BinarySearch(ElementType A[ ], ElementType X, int Low, int High )  
{
	if (Low > High) return NotFound; 
	int Mid = ( Low + High ) / 2;
	if  (A[ Mid ] < X ) return BinarySearch(A, X, Mid+1, High);
	else if ( A[ Mid ] > X )
		return BinarySearch(A, X, Low, Mid-1);
    else
		return Mid;  /* Found */
	return NotFound;     /* NotFound is defined as -1 */
}

// loi goi ham Usage: BinarySearch(A, X, 0, size -1);
int main()
{
	printf("Mo ta thuat toan tim kiem nhi phan su dung de quy\n");
	return 0;
}


