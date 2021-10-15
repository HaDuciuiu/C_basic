#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef int KeyType; // specify a type for the data - khai bao mot kieu cho du lieu
typedef struct Node{
	KeyType key; 
	struct Node* left, *right;
} NodeType;
typedef NodeType* TreeType; 
// ham 1 . Search on BST - tim kiem tren BST
TreeType Search(KeyType x,TreeType Root){ 
	if (Root == NULL) return NULL; // not found
	else if (Root->key == x) /* found x */ 
		return Root; 
	else if (Root->key < x)
	//continue searching in the right sub tree 	
		return Search(x,Root->right); 
	else {
  // continue searching in the left sub tree 
	return Search(x,Root->left); 
	}
}
// ham 2 . Insert a node from BST
void InsertNode(KeyType x,TreeType *Root ){
	if (*Root == NULL)
	{
	/* Create a new node for key x */
		*Root=(NodeType*)malloc(sizeof(NodeType));
		(*Root)->key = x;
		(*Root)->left = NULL;
		(*Root)->right = NULL;
	}
	else if (x < (*Root)->key) 
		InsertNode(x, &(*Root)->left);
	else if (x> (*Root)->key) 
		InsertNode(x, &(*Root)->right);
}
/* Xoa mot node khoi BST */
// ham 3 . Tim node trai nhat cua cay con phai de xoa
KeyType DeleteMin (TreeType *Root )
{ 
	KeyType k; 
	if ((*Root)->left == NULL)
	{ 
	k=(*Root)->key; 
	(*Root) = (*Root)->right; 
	return k; 
	} 
	else return DeleteMin(&(*Root)->left); 
}
// Ham 4 . Delete a node from BST - Xoa mot node tu BST
void DeleteNode(KeyType x,TreeType *Root)
{ 
	if (*Root!=NULL) 
	{
		if (x < (*Root)->key) 
			DeleteNode(x, &(*Root)->left);
		else if (x > (*Root)->key)
			DeleteNode(x, &(*Root)->right);
		else if (((*Root)->left==NULL)&&((*Root)->right==NULL))
			*Root=NULL; 
		else if ((*Root)->left == NULL)
			*Root = (*Root)->right; 
		else if ((*Root)->right==NULL) 
			*Root = (*Root)->left ;
		else (*Root)->key = DeleteMin(&(*Root)->right); 
	}
} 
// ham 5 . pretty print a BST
void prettyprint(TreeType tree,char *prefix){
	char *prefixend=prefix+strlen(prefix);
	if (tree!=NULL)
	{
		printf("%04d",tree->key);
		if (tree->left!=NULL) if (tree->right==NULL)
		{
			printf("\304");strcat(prefix,"     ");
		}
		else 
		{
			printf("\302");strcat(prefix,"\263    ");
		}
		prettyprint(tree->left,prefix);
		*prefixend='\0';
		if (tree->right!=NULL) if (tree->left!=NULL)
		{
			printf("\n%s",prefix);printf("\300");
		} 
		else printf("\304");
		strcat(prefix,"     ");
		prettyprint(tree->right,prefix);
	}
}
// ham 6 . Ham xoa toan bo node tren cay - su dung o cuoi chuong trinh
void freetree(TreeType tree)
{
	if (tree!=NULL)
	{
		freetree(tree->left);
		freetree(tree->right);
		free((void *) tree);
	}
}
int main()
{
	printf("Cai dat cac ham co ban cua cay nhi phan tim kiem - BST\n");
  return 0;
}

