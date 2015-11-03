#include <stdio.h>
#include <malloc.h> 
#define Link 0;
#define Thread 1;


typedef char ElemType;
typedef struct BiThrNode BiThrNode;
typedef struct BiThrNode
{
	BiThrNode *LChild;
	BiThrNode *RChild;
	int LTag;
	int RTag;
	ElemType Data;
};

BiThrNode *PrInitBiTree ()
{
	BiThrNode *Head;
	char ch;
	scanf("%s",&ch);
	if(ch=='#')
	{
		Head=NULL;
		return Head;
	}
	else
	{
		Head=(BiThrNode*)malloc(sizeof(BiThrNode));
		Head->Data=ch;
		printf("%c的左孩子：",Head->Data);
		Head->LChild=PrInitBiTree ();
		printf("%c的右孩子：",Head->Data);
		Head->RChild=PrInitBiTree ();
	}
	return Head;
}

void InThreading (BiThrNode *T,BiThrNode *p)
{
	if(T!=NULL)
	{
		T->LTag=Link;
		T->RTag=Link;
		InThreading (T->LChild,p);
		if(T->LChild==NULL)
		{
			T->LTag=Thread;
			T->LChild=p;
		}
		if(p->RChild==NULL)
		{
			p->RTag=Thread;
			p->RChild=T;
		}
		p=T;
		InThreading (T->RChild,p);
	}
	printf("线索化节点——成功\n");
}

BiThrNode *InOrderTread (BiThrNode *T)
{
	BiThrNode *Head;
	BiThrNode *p;
	Head=(BiThrNode*)malloc(sizeof(BiThrNode));
	Head->LTag=Link;
	Head->RTag=Thread;
	Head->RChild=Head;
	if(T==NULL)
	{
		Head->LTag=Thread;
		Head->LChild=Head;
	}
	else
	{
		Head->LChild=T;
		p=Head;
		InThreading (T,p);
		p->RChild=Head;
		p->RTag=Thread;
		Head->RChild=p;
	}
	printf("二叉树线索化——成功\n");
	return Head;
}

void InOrderPrint(BiThrNode *T)
{
	if(T->LTag==0)
	{
		InOrderPrint (T->LChild);
		printf("%c",T->Data);
		if(T->RTag==0)
			InOrderPrint (T->RChild);
	}
	else 
	{
		printf("%c",T->Data);
		if(T->RTag==1)
			InOrderPrint (T->RChild);
	}
}

void Print (BiThrNode *T)
{
	printf("线索二叉树的中序遍历输出为:");
	InOrderPrint(T);
	printf("\n");
}

void main ()
{
	BiThrNode *Main;
	printf("请依次输入二叉树的各个节点：（以“#”结束）\n");
	Main=PrInitBiTree ();
	printf("\n");
	InOrderTread (Main);
	printf("\n");
	Print(Main);
}