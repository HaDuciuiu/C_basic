#include<stdio.h>
#include"binaryTree.h"
#include<string.h>
int main()
{
	TreeType Tree;
	MakeNullTree(&Tree);
	int m,n;
	printf("Nhap m = ");
	scanf("%d",&m);
	printf("Nhap n = ");
	scanf("%d",&n);
	int *A;
	int *B;
	int i,j;
	A = (int*)malloc(m*sizeof(int));
	B = (int*)malloc(n*sizeof(int));
	printf("Them %d nut trai nhat vao cay:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		Add_Left(&Tree,A[i]);
	}
	printf("Them %d nut phai nhat vao cay:\n",m);
	for(j=0;j<m;j++)
	{
		scanf("%d",&B[j]);
		Add_Right(&Tree,B[j]);
	}
	int Num_node = nb_nodes(Tree);// bien Num_node de nhan vao so node cua cay
	printf("So node cua cay la: %d\n",Num_node);
	int nodeLeaf = countLeafNode(Tree);
	printf("So node la cua cay la: %d\n",nodeLeaf);
	printf("Do cao cua cay la: %d\n",ChieuCao(Tree));
  return 0;
}

