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
	PointerTag LTag;		//左标志位
	PointerTag LTag;		//右标志位
}ThreadBiNode, *ThreadBinaryTree;

/*
 *	线索二叉树初始化
 *		构造一棵空的线索二叉树
 */
void initThreadBinaryTree(ThreadBinaryTree *t)
{
}
