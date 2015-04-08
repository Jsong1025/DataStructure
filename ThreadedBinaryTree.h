#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define END '#'		//结束标志

typedef  char ElemType;		//节点数据类型

typedef enum PointerTag
{
	Link,Thread				//Link==0:指针  Thread==1:线索
};

typedef struct ThreadBiNode			//线索二叉树节点
{
	ElemType data;
	struct ThreadBiNode *lchild;	//左孩子
	struct ThreadBiNode *rchild;	//右孩子
	enum PointerTag LTag;		//左标志位
	enum PointerTag RTag;		//右标志位
}ThreadBiNode, *ThreadBinaryTree;

/*
 *	线索二叉树初始化
 *		构造一棵空的线索二叉树
 */
void initThreadBinaryTree(ThreadBinaryTree *t)
{
	t = NULL;
}

/*
 *	判断是否是空二叉树
 */
int BinaryTreeEmpty(ThreadBinaryTree t)
{
	if(t == NULL)
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
void createThreadBiNode(ThreadBinaryTree *n)
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
		*n = (ThreadBinaryTree)malloc(sizeof(ThreadBinaryTree));
		(*n)->data = e;
	}
	printf("%c的左孩子节点：",(*n)->data);
	createThreadBiNode(&((*n)->lchild));

	printf("%c的右孩子节点：",(*n)->data);
	createThreadBiNode(&((*n)->rchild));

}

/*
 *	（前序）构造二叉树
 */
void createThreadBinaryTree(ThreadBinaryTree *t)
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
		(*t) = (ThreadBinaryTree)malloc(sizeof(ThreadBinaryTree));
		(*t)->data = e;
		
		printf("根节点的左孩子节点：");
		createThreadBiNode(&((*t)->lchild));

		printf("根节点的右孩子节点：");
		createThreadBiNode(&((*t)->rchild));

	}
}
