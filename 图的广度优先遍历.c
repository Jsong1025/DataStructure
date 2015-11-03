#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define FALSE 0;
#define TRUE 1;

//���нڵ�
typedef struct QueueNode
{
	int Data;
	struct QueueNode *Next;
} QueueNode;

//����
typedef struct Queue
{
	QueueNode *front;
	QueueNode *rear;
} Queue;

//���ڵ�
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *NextArc;
} ArcNode;

//����ڵ�
typedef struct
{
	int Data;
	ArcNode *FristArc;
} VNode;

//ͼ�Ĵ洢�ṹ
typedef struct
{
	VNode GraphNode[100];
	int VexNum;
} Graph;

//��ʼ������
Queue InitQueue ()
{
	Queue QInit;
	QInit.front=QInit.rear=NULL;
	return QInit;
}

//�����Ƿ�Ϊ��
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

//���
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

//����
Queue DeQueue (Queue QDe,int *Elem)
{
	*Elem=QDe.front->Data;
	if(QDe.front==QDe.rear)
		QDe.front=QDe.rear=NULL;
	else
		QDe.front=QDe.front->Next;
	return QDe;
}

//ͼ����ĳ�ʼ��
Graph InitNode ()
{
	int i;
	Graph InNGraph;
	
	printf("��������Ҫ����ͼ�Ľڵ�����");
	scanf("%d",&InNGraph.VexNum);
	
	printf("��������������ڵ�����ݣ�\n");
	for (i=1;i<=InNGraph.VexNum;i++)
	{
		printf("��%d�ڵ㣺",i);
		scanf("%d",&InNGraph.GraphNode[i-1].Data);
	}
	
	return InNGraph;
}

//�������뺯��
//NodeΪ�ڵ㱾��ı�ţ�NodeNumΪ�ڵ�����
int NodeScan(int Node,int NodeNum)
{
	int Elem;
	while(scanf("%d",&Elem))
	{
		//�����ڵ㷶Χ
		if(Elem>NodeNum || Elem<=0)
		{
			if(Elem==-1)
				break;
			else
			{
				printf("������Ľڵ㳬��Ԥ����Χ�����������룺");
				continue;
			}
		}
		else 
		{
			//�ڵ㱾��
			if(Elem==Node)
			{
				printf("��������ڵ��������������룺");
				continue;
			}
			else
				break;
		}
	}
	return Elem;
}

//ͼ�ĳ�ʼ��
Graph InitGraph ()
{
	int i;
	int Elem;
	Graph InitGraph;
	ArcNode *TempArc;
	
	//��ʼ��ͼ�Ķ���
	InitGraph=InitNode ();
	
	printf("�����������нڵ��й�ϵ�Ľڵ�ţ�����-1������\n");
	for (i=0;i<InitGraph.VexNum;i++)
	{
		TempArc=NULL;
		InitGraph.GraphNode[i].FristArc=TempArc;
		printf("��%d���ڵ㣺",i+1);
		
		Elem=NodeScan(i+1,InitGraph.VexNum);
		if(Elem!=-1)
		{
			//��һ���ڵ�
			TempArc=(ArcNode*)malloc(sizeof(ArcNode));
			TempArc->adjvex=Elem;
			InitGraph.GraphNode[i].FristArc=TempArc;
			
			while(1)
			{
				//����ڵ���
				Elem=NodeScan(i+1,InitGraph.VexNum);
				if(Elem==-1)
					break;
				
				//���ٽڵ�
				TempArc->NextArc=(ArcNode*)malloc(sizeof(ArcNode));
				TempArc->NextArc->adjvex=Elem;
				TempArc=TempArc->NextArc;
			}
			//���һ���ڵ��ÿ�
			TempArc->NextArc=NULL;
		}
	}
	return InitGraph;
}

//�ڽڵ�����������ض�����
//NodeLinkΪָ��ڵ������ָ�룬ElemΪҪ���ҵ�����
//���ҳɹ�����TRUE�����򷵻�FAlSE
int SearchNode(ArcNode *NodeLink,int Elem)
{
	ArcNode *TempArc=NodeLink;

	if(TempArc==NULL)
	{
		return FALSE;
	}
	else
	{
		//ѭ������
		while(TempArc->adjvex!=Elem)
		{
			if(TempArc->NextArc==NULL)
				return FALSE;
			TempArc=TempArc->NextArc;
		}
		return TRUE;
	}
}

//�����ȱ����������ı߼�
//GraΪͼ��QueΪ��ȱ������ɵĶ���
void PrintTree(Graph Gra,Queue Que)
{
	QueueNode *Node1,*Node2;
	ArcNode *TempArc;
	printf("��ͼ�Ĺ���������ı߼����£�\n");

	//Node1��Node2�ֱ�ָ����е�ǰ�����ڵ�
	Node1=Que.front;
	Node2=Node1->Next;
	printf("����㣺%d\n",Node1->Data);
	while(Node1!=NULL)
	{
		printf("%d�ڵ�ĺ��ӣ�",Node1->Data);
		if(Node2==NULL)
			printf("�ýڵ�û�к���");
		else
		{
			//����Node1�Ļ��ڵ�����
			TempArc=Gra.GraphNode[Node1->Data-1].FristArc;
			while(SearchNode(TempArc,Node2->Data))
			{
				//���ҳɹ�����Node2����
				printf(" %d�ڵ�",Node2->Data);
				Node2=Node2->Next;
				if(Node2==NULL)
					break;
			}
		}
		printf("\n");

		//����ʧ�ܣ���Node1����
		Node1=Node1->Next;
	}
}

//ͼ�Ĺ�ȱ���
void BFSTraverse (Graph GTra,int nNode)
{
	int i;

	//���ʱ������
	int Visited[100];
	ArcNode *TempArc;
	Queue Que;
	Queue QuePrint;
	
	//��ʼ�����кͱ������
	Que=InitQueue();
	QuePrint=InitQueue();
	for(i=0;i<GTra.VexNum;i++)
		Visited[i]=FALSE;

	//���ʵ�һ���ڵ�
	printf("�ӵ�%d���ڵ㿪ʼ�Ĺ�ȱ������£�\n",nNode);
	printf("%d",GTra.GraphNode[nNode-1].Data);
	Visited[nNode-1]=TRUE;
	Que=EnQueue(Que,nNode);
	QuePrint=EnQueue(QuePrint,nNode);
	
	while(!QueueEmpty(Que))
	{
		Que=DeQueue(Que,&nNode);
		TempArc=GTra.GraphNode[nNode-1].FristArc;
		
		//���ʸýڵ���֮�����л��Ľڵ�
		while(TempArc!=NULL)
		{
			nNode=TempArc->adjvex;

			//����ýڵ���δ���ʹ�
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

//���ͼ�����нڵ�ͻ�
void PrintGraph (Graph GPrint)
{
	int i;
	ArcNode *p;
	printf("�ñ����£�\n");
	printf("���нڵ㣺%d����\n",GPrint.VexNum);
	for (i=1;i<=GPrint.VexNum;i++)
	{
		p=GPrint.GraphNode[i-1].FristArc;
		printf("��%d���ڵ㣺\n������Ϊ��%d��",i,GPrint.GraphNode[i-1].Data);
		if(p==NULL)
			printf("�ýڵ�Ϊ�����ڵ㡣\n");
		else
		{
			printf("���");
			while(p!=NULL)
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
	Graph MainGraph;
	
	//������ʼ�ڵ�
	int num;

	//��ʼ��ͼ
	MainGraph=InitGraph ();
	
	printf("\n");
	printf("�������ȱ�����ʼ�Ľڵ㣺");
	num=NodeScan(0,MainGraph.VexNum);
	printf("\n");
	BFSTraverse (MainGraph,num);
	
	//���ͼ���ڵ��Լ�����
	printf("\n");
	PrintGraph (MainGraph);
	printf("%c",getchar());
}
