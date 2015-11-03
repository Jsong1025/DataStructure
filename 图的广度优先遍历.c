#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define FALSE 0;
#define TRUE 1;

//队列节点
typedef struct QueueNode
{
	int Data;
	struct QueueNode *Next;
} QueueNode;

//队列
typedef struct Queue
{
	QueueNode *front;
	QueueNode *rear;
} Queue;

//弧节点
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *NextArc;
} ArcNode;

//顶点节点
typedef struct
{
	int Data;
	ArcNode *FristArc;
} VNode;

//图的存储结构
typedef struct
{
	VNode GraphNode[100];
	int VexNum;
} Graph;

//初始化队列
Queue InitQueue ()
{
	Queue QInit;
	QInit.front=QInit.rear=NULL;
	return QInit;
}

//队列是否为空
int QueueEmpty(Queue QEmpty)
{
	if(QEmpty.front==NULL && QEmpty.rear==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//入队
Queue EnQueue (Queue QEn,int Elem)
{
	QueueNode *temp;
	temp=(QueueNode*)malloc(sizeof(QueueNode));
	temp->Data=Elem;
	temp->Next=NULL;
	
	if(QueueEmpty(QEn))
	{
		QEn.rear=temp;
		QEn.front=temp;
	}
	else
	{
		QEn.rear->Next=temp;
		QEn.rear=temp;
	}
	
	return QEn;
}

//出队
Queue DeQueue (Queue QDe,int *Elem)
{
	*Elem=QDe.front->Data;
	if(QDe.front==QDe.rear)
		QDe.front=QDe.rear=NULL;
	else
		QDe.front=QDe.front->Next;
	return QDe;
}

//图顶点的初始化
Graph InitNode ()
{
	int i;
	Graph InNGraph;
	
	printf("请输入所要构建图的节点数：");
	scanf("%d",&InNGraph.VexNum);
	
	printf("请依次输入各个节点的数据：\n");
	for (i=1;i<=InNGraph.VexNum;i++)
	{
		printf("第%d节点：",i);
		scanf("%d",&InNGraph.GraphNode[i-1].Data);
	}
	
	return InNGraph;
}

//顶点输入函数
//Node为节点本身的编号，NodeNum为节点总数
int NodeScan(int Node,int NodeNum)
{
	int Elem;
	while(scanf("%d",&Elem))
	{
		//超出节点范围
		if(Elem>NodeNum || Elem<=0)
		{
			if(Elem==-1)
				break;
			else
			{
				printf("您输入的节点超出预定范围，请重新输入：");
				continue;
			}
		}
		else 
		{
			//节点本身
			if(Elem==Node)
			{
				printf("不可输入节点自身，请重新输入：");
				continue;
			}
			else
				break;
		}
	}
	return Elem;
}

//图的初始化
Graph InitGraph ()
{
	int i;
	int Elem;
	Graph InitGraph;
	ArcNode *TempArc;
	
	//初始化图的顶点
	InitGraph=InitNode ();
	
	printf("请输入与下列节点有关系的节点号：（以-1结束）\n");
	for (i=0;i<InitGraph.VexNum;i++)
	{
		TempArc=NULL;
		InitGraph.GraphNode[i].FristArc=TempArc;
		printf("第%d个节点：",i+1);
		
		Elem=NodeScan(i+1,InitGraph.VexNum);
		if(Elem!=-1)
		{
			//第一个节点
			TempArc=(ArcNode*)malloc(sizeof(ArcNode));
			TempArc->adjvex=Elem;
			InitGraph.GraphNode[i].FristArc=TempArc;
			
			while(1)
			{
				//输入节点编号
				Elem=NodeScan(i+1,InitGraph.VexNum);
				if(Elem==-1)
					break;
				
				//开辟节点
				TempArc->NextArc=(ArcNode*)malloc(sizeof(ArcNode));
				TempArc->NextArc->adjvex=Elem;
				TempArc=TempArc->NextArc;
			}
			//最后一个节点置空
			TempArc->NextArc=NULL;
		}
	}
	return InitGraph;
}

//在节点链表里查找特定数据
//NodeLink为指向节点链表的指针，Elem为要查找的数据
//查找成功返回TRUE，否则返回FAlSE
int SearchNode(ArcNode *NodeLink,int Elem)
{
	ArcNode *TempArc=NodeLink;

	if(TempArc==NULL)
	{
		return FALSE;
	}
	else
	{
		//循环遍历
		while(TempArc->adjvex!=Elem)
		{
			if(TempArc->NextArc==NULL)
				return FALSE;
			TempArc=TempArc->NextArc;
		}
		return TRUE;
	}
}

//输出广度遍历生成树的边集
//Gra为图，Que为广度遍历生成的队列
void PrintTree(Graph Gra,Queue Que)
{
	QueueNode *Node1,*Node2;
	ArcNode *TempArc;
	printf("该图的广度生成树的边集如下：\n");

	//Node1，Node2分别指向队列的前两个节点
	Node1=Que.front;
	Node2=Node1->Next;
	printf("根结点：%d\n",Node1->Data);
	while(Node1!=NULL)
	{
		printf("%d节点的孩子：",Node1->Data);
		if(Node2==NULL)
			printf("该节点没有孩子");
		else
		{
			//遍历Node1的弧节点链表
			TempArc=Gra.GraphNode[Node1->Data-1].FristArc;
			while(SearchNode(TempArc,Node2->Data))
			{
				//查找成功，将Node2后移
				printf(" %d节点",Node2->Data);
				Node2=Node2->Next;
				if(Node2==NULL)
					break;
			}
		}
		printf("\n");

		//查找失败，将Node1后移
		Node1=Node1->Next;
	}
}

//图的广度遍历
void BFSTraverse (Graph GTra,int nNode)
{
	int i;

	//访问标记数组
	int Visited[100];
	ArcNode *TempArc;
	Queue Que;
	Queue QuePrint;
	
	//初始化队列和标记数组
	Que=InitQueue();
	QuePrint=InitQueue();
	for(i=0;i<GTra.VexNum;i++)
		Visited[i]=FALSE;

	//访问第一个节点
	printf("从第%d个节点开始的广度遍历如下：\n",nNode);
	printf("%d",GTra.GraphNode[nNode-1].Data);
	Visited[nNode-1]=TRUE;
	Que=EnQueue(Que,nNode);
	QuePrint=EnQueue(QuePrint,nNode);
	
	while(!QueueEmpty(Que))
	{
		Que=DeQueue(Que,&nNode);
		TempArc=GTra.GraphNode[nNode-1].FristArc;
		
		//访问该节点与之所有有弧的节点
		while(TempArc!=NULL)
		{
			nNode=TempArc->adjvex;

			//如果该节点尚未访问过
			if(!Visited[nNode-1])
			{
				printf("%d",GTra.GraphNode[nNode-1].Data);
				Visited[nNode-1]=TRUE;
				Que=EnQueue(Que,nNode);

				QuePrint=EnQueue(QuePrint,nNode);
			}
			TempArc=TempArc->NextArc;
		}
		
	}
	printf("\n\n");
	PrintTree(GTra,QuePrint);
}

//输出图的所有节点和弧
void PrintGraph (Graph GPrint)
{
	int i;
	ArcNode *p;
	printf("该表如下：\n");
	printf("共有节点：%d个。\n",GPrint.VexNum);
	for (i=1;i<=GPrint.VexNum;i++)
	{
		p=GPrint.GraphNode[i-1].FristArc;
		printf("第%d个节点：\n数据域为：%d，",i,GPrint.GraphNode[i-1].Data);
		if(p==NULL)
			printf("该节点为孤立节点。\n");
		else
		{
			printf("与第");
			while(p!=NULL)
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
	Graph MainGraph;
	
	//遍历开始节点
	int num;

	//初始化图
	MainGraph=InitGraph ();
	
	printf("\n");
	printf("请输入广度遍历开始的节点：");
	num=NodeScan(0,MainGraph.VexNum);
	printf("\n");
	BFSTraverse (MainGraph,num);
	
	//输出图（节点以及弧）
	printf("\n");
	PrintGraph (MainGraph);
	printf("%c",getchar());
}
