#include<stdio.h>
#include<stdlib.h>
/*
#include<string.h>
#include<ctype.h>
#include<math.h>
*/

int main()
{
	int i,n,*p;//con tro *p dung de luu tru mot mang so nguyen
	printf("How many numbers do you want to enter ?\n");
	scanf("%d",&n);
	/*Phan phoi mang du lieu kieu int voi kich co thich hop*/
	p = (int *)malloc(n * sizeof(int));
	if(p==NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}
	// Get the numbers from the user
	printf("Please enter the numbers now\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	// Display them in reverse
	printf("The numbers in reverse order are :\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\t",p[i]);
	}
	free(p);
return 0;

}

