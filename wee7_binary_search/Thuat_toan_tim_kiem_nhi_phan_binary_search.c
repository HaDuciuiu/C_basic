#include<stdio.h>
int binSearch(int List[], int Target, int Size) 
{
// target la so can tim, size la kich thuoc list
	int Mid;
	int Low = 0;
	int High = Size-1;
	while ( Low <= High ) 
	{
		Mid = (Low+High)/2;
		if ( List[Mid] == Target )
			return Mid;
		else if ( Target < List[Mid] )
			High = Mid - 1;
		else
			Low = Mid + 1;
}
	return -1;
}
int main()
{
	printf("Ham mo ta thuat toan binary search - tim kiem nhi phan\n");
  return 0;
}

