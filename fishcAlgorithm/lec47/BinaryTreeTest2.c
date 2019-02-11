#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;


void CreateTree(BiTree *root)
{
	char s;
	scanf("%c", &s);
	printf("s = %d\n", s);
	if (s == ' ')
	{
		*root = NULL;
	}
	else
	{
		*root = (BiTNode *)malloc(sizeof(BiTNode));
		(*root)->data = s;
		CreateTree(&(*root)->lchild);
		CreateTree(&(*root)->rchild);
	}
	
}

void PrintTree(BiTree root, int level)
{
	if (root != NULL)
	{
		printf("level = %d, root->s = %c\n", level, root->data);
		PrintTree(root->lchild, level + 1);
		PrintTree(root->rchild, level + 1);
	}
	else
	{
		return;
	}
}

int main()
{
	int level = 1;
	BiTree T = NULL; 
	CreateTree(&T);
	PrintTree(T, level);

	return 0;
}
