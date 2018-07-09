#include <stdio.h>
#include <malloc.h>

typedef struct StackNode StackNode;
struct StackNode
{
	int Data;
	struct StackNode *Next;
};
typedef struct ArcNode ArcNode;
struct ArcNode
{
	int adjvex;
	ArcNode *NextArc;
};

typedef struct
{
	int Vex;
	ArcNode *FristArc;
} VNode;

typedef struct
{
	VNode GraphNode[100];
	int VexNum;
} Graph;

Graph MainGraph;
StackNode *Stack;

int PopStack (StackNode *S)
{
	int d;
	StackNode *p1,*p2;
	p1=S;
	if(p1->Next==NULL)
	{
		d=p1->Data;
		S=NULL;
	}
	else
	{
		while(p1->Next!=NULL)
		{
			p2=p1;
			p1=p1->Next;
		}
		d=p1->Data;
		p2->Next=NULL;
		free(p1);
	}
	return d;
}

StackNode *PushStack (StackNode *S,int d)
{
	StackNode *p1,*p2;
	p1=S;
	if(S==NULL)
	{
		S=(StackNode*)malloc(sizeof(StackNode));
		S->Data=d;
		S->Next=NULL;
	}
	else
	{
		while(p1->Next!=NULL)
			p1=p1->Next;
		p2=(StackNode*)malloc(sizeof(StackNode));
		p2->Data=d;
		p2->Next=NULL;
		p1->Next=p2;
	}
	return S;
}

void InitGraph ()
{
	int i;
	ArcNode *Arc1,*Arc2;
	printf("请输入所要构建图的节点数：");
	scanf("%d",&MainGraph.VexNum);
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
				MainGraph.GraphNode[i-1].Vex=0;
				Arc2=(ArcNode*)malloc(sizeof(ArcNode));
				Arc1->NextArc=Arc2;
				Arc1=Arc2;
			}
		}
	}
	for (i=1;i<=MainGraph.VexNum;i++)
	{
		Arc1=MainGraph.GraphNode[i].FristArc;
		while(1)
		{
			if(Arc1->adjvex==-1)
				break;
			else
			{	
				MainGraph.GraphNode[Arc1->adjvex].Vex++;
				Arc1=Arc1->NextArc;
			}
		}
	}
}

void TopoSort ()
{
	int i,j;
	int vex;
	ArcNode *p;
	for(i=1;i<=MainGraph.VexNum;i++)
	{
		for(j=1;j<=MainGraph.VexNum;j++)
		{
			p=MainGraph.GraphNode[i].FristArc;
			if(MainGraph.GraphNode[i].Vex==0)
			{
				if(MainGraph.GraphNode[i].Vex!=-1)
				{
					Stack=PushStack(Stack,i);
					MainGraph.GraphNode[i].Vex=-1;
					while(p->adjvex!=-1)
					{
						MainGraph.GraphNode[p->adjvex].Vex--;
						p=p->NextArc;
					}
				}
			}
		}
	}
	for(i=1;i<=MainGraph.VexNum;i++)
	{
		vex=PopStack(Stack);
		printf("%d",vex);
	}
}

void main ()
{
	InitGraph ();
	printf("\n");
	TopoSort ();
}