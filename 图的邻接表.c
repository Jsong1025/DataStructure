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
	printf("请输入所要构建图的节点数：");
	scanf("%d",&MainGraph.VexNum);
	printf("请依次输入各个节点的数据：\n");
	for (i=1;i<=MainGraph.VexNum;i++)
	{
		printf("第%d节点：",i);
		scanf("%d",&MainGraph.GraphNode[i-1].Data);
	}
}

void InitGraph ()
{
	int i;
	ArcNode *Arc1,*Arc2;
	InitNode ();
	printf("请输入与下列节点有关系的节点号：");
	for (i=1;i<=MainGraph.VexNum;i++)
	{
		Arc1=(ArcNode*)malloc(sizeof(ArcNode));
		MainGraph.GraphNode[i].FristArc=Arc1;
		printf("第%d个节点：",i);
		while(1)
		{
			scanf("%d",&Arc1->adjvex);
			if(Arc1->adjvex>MainGraph.VexNum)
			{
				printf("您输入的节点超出预定范围，请重新输入：");
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
	printf("该表如下：\n");
	printf("共有节点：%d个。\n",MainGraph.VexNum);
	for (i=1;i<=MainGraph.VexNum;i++)
	{
		p=MainGraph.GraphNode[i].FristArc;
		printf("第%d个节点：\n数据域为：%d，",i,MainGraph.GraphNode[i-1].Data);
		if(p->adjvex==-1)
			printf("该节点为孤立节点。\n");
		else
		{
			printf("与第");
			while(p->adjvex!=-1)
			{
					printf("%d ",p->adjvex);
					p=p->NextArc;
			}
			printf("个节点有弧。\n");
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