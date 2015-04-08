#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define END '#'		//������־

typedef  char ElemType;		//�ڵ���������

typedef enum PointerTag
{
	Link,Thread				//Link==0:ָ��  Thread==1:����
};

typedef struct ThreadBiNode			//�����������ڵ�
{
	ElemType data;
	struct ThreadBiNode *lchild;	//����
	struct ThreadBiNode *rchild;	//�Һ���
	enum PointerTag LTag;		//���־λ
	enum PointerTag RTag;		//�ұ�־λ
}ThreadBiNode, *ThreadBinaryTree;

/*
 *	������������ʼ��
 *		����һ�ÿյ�����������
 */
void initThreadBinaryTree(ThreadBinaryTree *t)
{
	t = NULL;
}

/*
 *	�ж��Ƿ��ǿն�����
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
 *	����������ڵ�
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
	printf("%c�����ӽڵ㣺",(*n)->data);
	createThreadBiNode(&((*n)->lchild));

	printf("%c���Һ��ӽڵ㣺",(*n)->data);
	createThreadBiNode(&((*n)->rchild));

}

/*
 *	��ǰ�򣩹��������
 */
void createThreadBinaryTree(ThreadBinaryTree *t)
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
		(*t) = (ThreadBinaryTree)malloc(sizeof(ThreadBinaryTree));
		(*t)->data = e;
		
		printf("���ڵ�����ӽڵ㣺");
		createThreadBiNode(&((*t)->lchild));

		printf("���ڵ���Һ��ӽڵ㣺");
		createThreadBiNode(&((*t)->rchild));

	}
}
