#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
#include <string.h>
#define MAXWORD 100
struct tnode 
{     
 	char *word; /* points to the text */
 	int count;     /* number of occurrences */
 	struct tnode *left;   /* left child */
 	struct tnode *right;  /* right child */
};

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}
int getword(FILE *fp,char *word, int lim) 
{
	int c;
   	char *w = word;

	while (isspace(c = fgetc(fp)))	;
	if (c != EOF) *w++ = c;
	if (!isalpha(c)) 
	{
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = fgetc(fp))) 
		{
			ungetc(*w,fp);
			break;
		}
	*w = '\0';
	return word[0];
}
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(FILE *,char *, int);
struct tnode *talloc(void);
char* strd_up(char *);
int main()
{
	FILE *fp; 
	fp = fopen("demtu.txt","r");
	if(fp==NULL)
	{
		printf("Loi o buoc doc file\n");
	}
	struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(fp,word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
	return 0;
}
/* treeprint:  in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) 
	{
           treeprint(p->left);
           printf("%4d %s\n", p->count, p->word);
           treeprint(p->right);
    }
}
/* addtree:  add a node with w, at or below p */
struct tnode* addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) 
	{     
		/* a new word has arrived */
        p = talloc();    /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } 
	else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;      /* repeated word */
    else if (cond < 0)   /* less than into left subtree */
        p->left = addtree(p->left, w);
    else             /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}
// ham nhap mot xau vao
char* str_dup(char str[])
{
	return str;
}



