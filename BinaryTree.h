#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define END '#'		//������־

typedef  char ElemType;		//�ڵ���������

typedef struct BiNode			//�������ڵ�
{
	ElemType data;
	struct BiNode *lchild;	//����
	struct BiNode *rchild;	//�Һ���
	struct BiNode *parent;	//���ڵ�
}BiNode, *BiTree;

typedef struct BinaryTree
{
	BiTree root;
	int depth;
}BinaryTree;

/*
 *	��������ʼ��
 *		����һ�ÿյĶ�����
 */
void initBinaryTree(BinaryTree *t)
{
	t->depth = 0;
	t->root = NULL;
}

/*
 *	�ж��Ƿ��ǿն�����
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
 *	����������ڵ�
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
	printf("%c�����ӽڵ㣺",(*n)->data);
	createBinaryNode(&((*n)->lchild),*n);

	printf("%c���Һ��ӽڵ㣺",(*n)->data);
	createBinaryNode(&((*n)->rchild),*n);
}

void createBinaryTree(BinaryTree *t)
{
	ElemType e;
	printf("������������ڵ��ֵ��\n");
	printf("���ڵ㣺");
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
		
		printf("���ڵ�����ӽڵ㣺");
		createBinaryNode(&(t->root->lchild),t->root);

		printf("���ڵ���Һ��ӽڵ㣺");
		createBinaryNode(&(t->root->rchild),t->root);

	}
}