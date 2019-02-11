#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree
{
	char data;
	struct BiTree *lchild;
	struct BiTree *rchild;
} BiTree;


void CreateTree(BiTree **root)
{
	char s;
	s = getchar();
//	scanf("%c", &s);
	printf("s = %d\n", s);
	if (s == ' ')
	{
		(*root) = NULL;
	}
	else
	{
		(*root) = (BiTree *)malloc(sizeof(BiTree));
		(*root)->data = s;
		CreateTree(&(*root)->lchild);
		CreateTree(&(*root)->rchild);
	}
	
	return;
}

void PrintTree(BiTree *root, int level)
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
	BiTree *T; 
	CreateTree(&T);
	PrintTree(T, 1);

	return 0;
}
