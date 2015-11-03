#include <stdio.h>
#include <malloc.h>

typedef struct ArcNode ArcNode;
struct ArcNode
{
	int adjvex;
	ArcNode *NextArc;
};

typedef struct
{
	int Data;
	ArcNode *FristArc;
} VNode;

typedef struct
{
	VNode GraphNode[100];
	int VexNum;
} Graph;

Graph MainGraph;

void InitNode ()
{
	int i;
	printf("��������Ҫ����ͼ�Ľڵ�����");
	scanf("%d",&MainGraph.VexNum);
	printf("��������������ڵ�����ݣ�\n");
	for (i=1;i<=MainGraph.VexNum;i++)
	{
		printf("��%d�ڵ㣺",i);
		scanf("%d",&MainGraph.GraphNode[i-1].Data);
	}
}

void InitGraph ()
{
	int i;
	ArcNode *Arc1,*Arc2;
	InitNode ();
	printf("�����������нڵ��й�ϵ�Ľڵ�ţ�");
	for (i=1;i<=MainGraph.VexNum;i++)
	{
		Arc1=(ArcNode*)malloc(sizeof(ArcNode));
		MainGraph.GraphNode[i].FristArc=Arc1;
		printf("��%d���ڵ㣺",i);
		while(1)
		{
			scanf("%d",&Arc1->adjvex);
			if(Arc1->adjvex>MainGraph.VexNum)
			{
				printf("������Ľڵ㳬��Ԥ����Χ�����������룺");
				scanf("%d",&Arc1->adjvex);
			}
			if(Arc1->adjvex==-1)
				break;
			else
			{
				Arc2=(ArcNode*)malloc(sizeof(ArcNode));
				Arc1->NextArc=Arc2;
				Arc1=Arc2;
			}
		}
	}	
}

void PrintGraph ()
{
	int i;
	ArcNode *p;
	printf("�ñ����£�\n");
	printf("���нڵ㣺%d����\n",MainGraph.VexNum);
	for (i=1;i<=MainGraph.VexNum;i++)
	{
		p=MainGraph.GraphNode[i].FristArc;
		printf("��%d���ڵ㣺\n������Ϊ��%d��",i,MainGraph.GraphNode[i-1].Data);
		if(p->adjvex==-1)
			printf("�ýڵ�Ϊ�����ڵ㡣\n");
		else
		{
			printf("���");
			while(p->adjvex!=-1)
			{
					printf("%d ",p->adjvex);
					p=p->NextArc;
			}
			printf("���ڵ��л���\n");
		}
		printf("\n");
	}
}

void main()
{
	InitGraph ();
	printf("\n");
	PrintGraph ();
}