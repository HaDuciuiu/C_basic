#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct ADDR
{
	char name[30];
	char phone[15];
	char email[50];
}KeyType;
// specify a type for the data - khai bao mot kieu cho du lieu
typedef struct Node{
	KeyType key; 
	struct Node* left, *right;
}NodeType;
typedef NodeType* TreeType; 
// ham 0 . khoi tao BST rong
void MakeNullTree(TreeType *Root)
{
	(*Root)=NULL;
}
// ham 1 . Search on BST - tim kiem tren BST
TreeType Search(char x[],TreeType Root)
{ 
	if (Root == NULL) return NULL; // not found
	else if (strcmp(Root->key.email,x)==0) /* found x */ 
		return Root; 
	else if (strcmp(Root->key.email,x)<0)
	//continue searching in the right sub tree 	
		return Search(x,Root->right); 
	else 
  // continue searching in the left sub tree 
		return Search(x,Root->left); 
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
	else if (strcmp(x.email,(*Root)->key.email)<0) 
		InsertNode(x, &(*Root)->left);
	else if (strcmp(x.email,(*Root)->key.email)>0) 
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
/*
void DeleteNode(KeyType x,TreeType *Root)
{ 
	if (*Root!=NULL) 
	{
		if (x< (*Root)->key) 
			DeleteNode(x, &(*Root)->left);
		else if (x > (*Root)->key)
			DeleteNode(x, &(*Root)->right);
		else if (((*Root)->left==NULL)&&((*Root)->right==NULL))// neu la node la
			*Root=NULL; 
		else if ((*Root)->left == NULL)
			*Root = (*Root)->right; 
		else if ((*Root)->right==NULL) 
			*Root = (*Root)->left ;
		else (*Root)->key = DeleteMin(&(*Root)->right); 
	}
} 
*/
//ham 5 . pretty print a BST
/*
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
*/
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
// ham 7 . Insert a node to BST version return type
/*
TreeType InsertNode_T(KeyType x,TreeType Root )
{ 
	if (Root == NULL)
	{
	 //Create a new node for key x
	Root=(NodeType*)malloc(sizeof(NodeType)); 
	Root->key = x; 
	Root->left = NULL; 
	Root->right = NULL;
	return Root; 
	} 
	else if (x < Root->key) return InsertNode_T(x, Root->left);
	else if (x> Root->key) return InsertNode_T(x, Root->right); 
}
*/
/*3 ham duyet cay co ban mk tim hieu duoc tren mang , theo cua thay thi tim hieu sau*/
// ham1 . Duyet theo thu tu truoc preorder
void PreOrder(TreeType root){
    if(root != NULL)
    {
        printf("%s\n%s\n%s\n",root->key.name,root->key.phone,root->key.email);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
// ham 2 . Duyet theo thu tu giua inorder
void InOrder(TreeType root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%s\n%s\n%s\n",root->key.name,root->key.phone,root->key.email);
        InOrder(root->right);
    }
}
// ham 3 . Duyet theo thu tu sau postorder
void PostOrder(TreeType root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%s\n%s\n%s\n",root->key.name,root->key.phone,root->key.email);
    }
}
 


