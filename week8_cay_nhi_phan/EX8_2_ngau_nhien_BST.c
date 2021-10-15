#include <stdio.h>
#include <stdlib.h> 
#include"BinarySearchTree.h"// create by your self
#include <time.h>
int main(){
	TreeType p;
	TreeType tree=NULL;
	//MakeNullTree(&tree);
	int n = 20;
	int i,key;
	int Arr[100];
	srand(time(NULL));
	for ( i = 0; i < n; i++ ) 
	{
		Arr[i] = rand()%100 ;
	}
	for(i=0;i<n;i++)
	{
		InsertNode(Arr[i],&tree);
	}
	printf("pretty print:\n");
	char prefix[5];
	strcpy(prefix,"    ");
	prettyprint(tree,prefix);
	printf("\n");
	do 
	{
		printf("Nhap key de tim kiem (-1 de thoat): ");
		scanf("%d",&key);
		p = Search(key,tree);
		if(p!=NULL)
			printf("Key %d duoc tim thay trong cay\n",key);
		else 
		{
			InsertNode(n,&tree);
			printf("Khong tim thay %d o trong cay\n",key);
			//prettyprint(tree,prefix);
		}
	}
	while (key!=-1);
	freetree(tree);
	return 0;
}

