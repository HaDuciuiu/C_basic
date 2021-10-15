#include<stdio.h>
#include<stdlib.h>
//ham1. khoi tao cay
typedef int ElementType;// muon thay kieu du lieu thi ta thay the int thanh kieu du lieu phu hop hon
typedef struct nodeType
{
	ElementType element;
	struct nodeType *left,*right;
}node_type;
typedef struct nodeType *TreeType;
// ham2. Khoi tao cay rong
void MakeNullTree(TreeType *T)
{
	(*T)=NULL;
}
// ham3. kiem tra cay co rong khong
int EmptyTree(TreeType T)
{
	return T==NULL;
}
// ham 4. Truy cap vao con trai
TreeType LeftChild(TreeType n)
{
	if (n!=NULL) return n->left;
	else return NULL;
}
// ham 5. Truy cap vao con phai
TreeType RightChild(TreeType n)
{
	if (n!=NULL) return n->right;
	else return NULL;
}
// ham 6 . Tao node moi
node_type *create_node(ElementType NewData)
{
	node_type *N = (node_type*)malloc(sizeof(node_type));
	if (N != NULL)
	{
	N->left = NULL;
	N->right = NULL;
	N->element = NewData;
}
	return N;
}
// ham 7 . Kiem tra mot node co phai la la khong
int IsLeaf(TreeType n)
{
	if(n!=NULL)
	return(LeftChild(n)==NULL)&&(RightChild(n)==NULL);
	else return -1;
}
// ham 8 .Xu li de quy , tim so node tren cay
int nb_nodes(TreeType T)
{
	if(EmptyTree(T)) return 0;
	else return 1+nb_nodes(LeftChild(T))+nb_nodes(RightChild(T));
}
// ham 9 . Tao mot cay tu hai cay con
TreeType createfrom2(ElementType v,TreeType l, TreeType r){
	TreeType N;
	N=(node_type*)malloc(sizeof(node_type));
	N->element=v;
	N->left=l;
	N->right=r;
	return N;
}
// ham 10 . Them mot node vao vi tri trai nhat tren cay
TreeType Add_Left(TreeType *Tree, ElementType NewData)
{
	node_type *NewNode = create_node(NewData);
	if (NewNode == NULL) 
	return (NewNode);
	if (*Tree == NULL)
		*Tree = NewNode;
	else
	{
		node_type *Lnode = *Tree;
		while (Lnode->left != NULL)
			Lnode = Lnode->left;
		Lnode->left = NewNode;
	}
	return (NewNode);
}
// ham 11 . Them mot node vao vi tri phai nhat tren cay
TreeType Add_Right(TreeType *Tree, ElementType NewData)
{
	node_type *NewNode = create_node(NewData);
	if (NewNode == NULL) 
	return (NewNode);
	if (*Tree == NULL)
	*Tree = NewNode;
	else
	{
		node_type *Rnode = *Tree;
		while (Rnode->right != NULL)
			Rnode = Rnode->right;
		Rnode->right = NewNode;
	}
	return (NewNode);
}
// ham 12. Ham dem so node la cua cay
int countLeafNode(TreeType Tree)
{
	if (Tree == NULL) return 0;
	if (IsLeaf(Tree)) return 1;
	return countLeafNode(Tree->left) + countLeafNode(Tree->right);
}
// ham 13 . Tinh chieu cao cua cay
int ChieuCao(TreeType Tree)
{
	if(Tree==NULL)
	return 0;
	int a = ChieuCao(Tree->left);
    int b = ChieuCao(Tree->right);
	if(a>b)
	return a+1;
	else
	return b+1;
}


