#include<stdio.h>
int search( int key,int r[], int n )
{
	int i;
	int tempr;
	for ( i=0; i<n-1 && r[i] != key; i++ )
	{
		if ( key == r[i] )
	{ 
		if ( i>0 ) 
		{
		/*** doi cho voi phan tu dung truoc ***/
		tempr = r[i];
		r[i] = r[i-1];
		r[--i] = tempr;
		}
		return( i );
	} else return( -1 ); 	
	}
	
int main()
{
	printf("Day la ham tim kiem tu sap xep , doi cho\n");
  return 0;
}

