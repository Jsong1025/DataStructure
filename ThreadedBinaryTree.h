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
	PointerTag LTag;		//���־λ
	PointerTag LTag;		//�ұ�־λ
}ThreadBiNode, *ThreadBinaryTree;

/*
 *	������������ʼ��
 *		����һ�ÿյ�����������
 */
void initThreadBinaryTree(ThreadBinaryTree *t)
{
}
