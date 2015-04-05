#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define END '#'		//结束标志

typedef  char ElemType;		//节点数据类型

typedef struct BiNode			//二叉树节点
{
	ElemType data;
	struct BiNode *lchild;	//左孩子
	struct BiNode *rchild;	//右孩子
	struct BiNode *parent;	//父节点
}BiNode, *BiTree;

typedef struct BinaryTree
{
	BiTree root;
	int depth;
}BinaryTree;

/*
 *	二叉树初始化
 *		构造一棵空的二叉树
 */
void initBinaryTree(BinaryTree *t)
{
	t->depth = 0;
	t->root = NULL;
}

/*
 *	判断是否是空二叉树
 */
int BinaryTreeEmpty(BinaryTree t)
{
	if(t.root == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*
 *	构造二叉树节点
 */
void createBinaryNode(BiTree *n,BiTree parent)
{
	ElemType e;
	scanf("%s",&e);
	if(e == END)
	{
		*n = NULL;
		return;
	}
	else
	{
		*n = (BiTree)malloc(sizeof(BiTree));
		(*n)->data = e;
		(*n)->parent = parent;
	}
	printf("%c的左孩子节点：",(*n)->data);
	createBinaryNode(&((*n)->lchild),*n);

	printf("%c的右孩子节点：",(*n)->data);
	createBinaryNode(&((*n)->rchild),*n);
}

void createBinaryTree(BinaryTree *t)
{
	ElemType e;
	printf("输入二叉树各节点的值：\n");
	printf("根节点：");
	scanf("%s",&e);
	if(e == END)
	{
		return;
	}
	else
	{
		t->root = (BiTree)malloc(sizeof(BiTree));
		t->root->parent = NULL;
		t->root->data = e;
		
		printf("根节点的左孩子节点：");
		createBinaryNode(&(t->root->lchild),t->root);

		printf("根节点的右孩子节点：");
		createBinaryNode(&(t->root->rchild),t->root);

	}
}