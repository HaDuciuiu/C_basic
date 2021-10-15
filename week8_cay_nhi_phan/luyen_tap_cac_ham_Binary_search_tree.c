#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int KeyType;// kieu du lieu cua key la kieu int , ban co the thay doi tuy theo y thich nhe
typedef struct Node// dinh nghia kieu cua node la mot kieu cau truc co cac truong nhu duoi kia
{
	KeyType key;
	struct Node *left ;
	struct Node *right;	
}NodeType;
typedef NodeType* TreeType;// khai bao kieu TreeType la kieu con tro NodeType
// ham 1 . Tim kiem tren cay nhi phan tim kiem - Search on BST
TreeType Search(KeyType x , TreeType Root)
{
	if(Root == NULL)
		return NULL; // Not found
	else if(Root->key == x)// found x
		return Root;
	else if(Root->key < x)// search in the right sub tree
		return Search(x,Root->right);
	else// search in the left sub tree
		return Search(x,Root->left);	
}
// ham 2 . Them mot node vao cay nhi phan tim kiem - insert a node from BST
void InsertNode(KeyType x , TreeType *Root)
{
	if(*Root == NULL)
	{
		*Root = (NodeType*)malloc(sizeof(NodeType));
		(*Root)->key = x;
		(*Root)->left = NULL;
		(*Root)->right = NULL;
	}
	else if(x<(*Root)->key)
	{
		InsertNode(x,&(*Root)->left);
	}
	else if(x>(*Root)->key)
	{
		InsertNode(x,&(*Root)->right);
	}
}
// Phan xoa mot node khoi BST
// ham 3 . Tim node trai nhat cua cay con phai de xoa
KeyType DeleteMin(TreeType *Root)
{
	KeyType k;
	if((*Root)->left == NULL)
	{
		k = (*Root)->key;
		(*Root) = (*Root)->right;
		return k;
	}
	else return DeleteMin(&(*Root)->left);
}
// ham 4. Delete a node from BST - Xoa mot node tu BST
void DeleteNode(KeyType x , TreeType *Root)
{
	if(*Root != NULL)
	{
		if(x<(*Root)->key)
			DeleteNode(x,&(*Root)->left);
		else if(x>(*Root)->key)
			DeleteNode(x,&(*Root)->right);
		else if(((*Root)->left ==NULL)&&((*Root)->right==NULL))// neu la node la
			*Root = NULL;
		else if((*Root)->left==NULL)
			*Root = (*Root )->right;
		else if((*Root)->right==NULL)
			*Root = (*Root)->left;
		else 
			(*Root)->key = DeleteMin(&(*Root)->right);
	}
}
// ham 5 . ham in ra dep de mot cay nhi phan tim kiem
void prettyprint(TreeType tree,char *prefix)
{
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
// ham 6. Xoa toan bo node tren cay - Su dung o cuoi chuong trinh
void freetree(TreeType tree)
{
	if(tree != NULL)
	{
		freetree(tree->left);
		freetree(tree->right);
		free((void*)tree);
	}	
} 

int main()
{
	printf("On luyen lai cac ham co ban cai dat trong cay nhi phan tim kiem\n");
  return 0;
}

