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

/*
 *	构造二叉树
 */
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

/*
 *	前序遍历二叉树节点（递归方法）
 */
void preOrederTraverseNode(BiTree n)
{
	printf("%c\t",n->data);

	if(n->lchild != NULL)
	{
		preOrederTraverseNode(n->lchild);
	}
	
	if(n->rchild != NULL)
	{
		preOrederTraverseNode(n->rchild);
	}
}

/*
 *	前序遍历二叉树
 */
void preOrederTraverse(BinaryTree t)
{
	printf("这棵二叉树的前序遍历为：\n");
	preOrederTraverseNode(t.root);
	printf("\n");
}

/*
 *	中序遍历二叉树节点（递归方法）
 */
void inOrederTraverseNode(BiTree n)
{
	if(n->lchild != NULL)
	{
		inOrederTraverseNode(n->lchild);
	}

	printf("%c\t",n->data);
	
	if(n->rchild != NULL)
	{
		inOrederTraverseNode(n->rchild);
	}
}

/*
 *	中序遍历二叉树
 */
void inOrederTraverse(BinaryTree t)
{
	printf("这棵二叉树的中序遍历为：\n");
	inOrederTraverseNode(t.root);
	printf("\n");
}

/*
 *	后序遍历二叉树节点（递归方法）
 */
void postOrederTraverseNode(BiTree n)
{
	if(n->lchild != NULL)
	{
		postOrederTraverseNode(n->lchild);
	}
	
	if(n->rchild != NULL)
	{
		postOrederTraverseNode(n->rchild);
	}

	printf("%c\t",n->data);
}

/*
 *	后序遍历二叉树
 */
void postOrederTraverse(BinaryTree t)
{
	printf("这棵二叉树的后序遍历为：\n");
	postOrederTraverseNode(t.root);
	printf("\n");
}
