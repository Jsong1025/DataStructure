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
		printf("%c�����ӣ�",Head->Data);
		Head->LChild=PrInitBiTree ();
		printf("%c���Һ��ӣ�",Head->Data);
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
	printf("�������ڵ㡪���ɹ�\n");
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
	printf("�����������������ɹ�\n");
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
	printf("����������������������Ϊ:");
	InOrderPrint(T);
	printf("\n");
}

void main ()
{
	BiThrNode *Main;
	printf("����������������ĸ����ڵ㣺���ԡ�#��������\n");
	Main=PrInitBiTree ();
	printf("\n");
	InOrderTread (Main);
	printf("\n");
	Print(Main);
}