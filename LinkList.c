#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define END '#'		//结束标志

typedef  int ElemType;		//节点数据类型

typedef struct Node			//节点结构体
{
	ElemType data;
	struct Node *next;
}Node, *LNode;

typedef struct LinkNode		//链表结构体
{
	LNode head;		//头结点
	LNode tail;		//尾节点
	int length;		//长度
}LinkList;

/*
 *	向链表中插入数据
 *	
 *	参数：	LinkList *  list（要初始化的链表）
 *			ElemType	要插入的数据
 *	返回：	伪布尔类型(int)
 */
void insertElem(LinkList *list , ElemType e)
{
	if(list->tail != NULL)
	{
		list->tail->next = (LNode)malloc(sizeof(LNode));
		list->tail=list->tail->next;
		list->tail->data = e;
		list->tail->next = NULL;
		list->length++;
	}
	else
	{
		list->tail = (LNode)malloc(sizeof(LNode));
		list->head = list->tail;
		list->tail->data = e;
		list->tail->next = NULL;
		list->length++;
	}
}
/*
 *	插入链表指定位置
 *	
 *	参数：	LinkList	list
 *			ElemType	e	  要插入的数据
 *			int			n	  节点位置 (从0开始) 
 */
void insertNode(LinkList *list ,int n , ElemType e)
{
	int i = 0;
	LNode p = list->head;
	LNode q;
	while(i < n-1)	//找到要插入的前一个节点
	{
		p = p->next;
		i++;
	}
	q = p->next;
	p->next = (LNode)malloc(sizeof(LNode));
	p->next->data = e;
	p->next->next = q;
	list->length++;
}

/*
 *	获取链表指定位置的数据
 *	
 *	参数：	LinkList	list
 *			int			n	  节点位置(从0开始) 
 *	返回：	ElemType	此节点的数据  
 */
ElemType getNodeElem(LinkList list,int n)
{
	int i = 0;
	LNode p = list.head;
	while(i < n)		//找到要插入的节点
	{
		p = p->next;
		i++;
	}
	return p->data;
}

/*
 *	删除链表指定节点
 *	
 *	参数：	LinkList	list
 *			int			n	  节点位置(从0开始) 
 */
void deleteNode(LinkList *list,int n)
{
	int i = 0;
	LNode p = list->head;
	LNode q;
	while(i < n-1)	//找到要插入的前一个节点
	{
		p = p->next;
		i++;
	}
	q = p->next;
	p->next = q->next;
	list->length--;
}

/*
 *	链表输出
 *	
 *	参数：	LinkList   list（要输出的链表）
 */
void printLinkList(LinkList list)
{
	LNode p = list.head;

	printf("链表长度：");
	printf("%d\n",list.length);
	
	while(p != NULL)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}


/*
 *	链表初始化
 *		循环扫描输入数据，直到输入指定结束符为止
 *	
 *	参数：	LinkList * 	list（要初始化的链表）
 *	返回：	伪布尔类型(int)
 */
int initLinkList(LinkList *list)
{
	char c;

	list->length = 0;
	list->head = list->tail = NULL;

	printf("请输入初始化数据：\n");
	while(1)
	{
		scanf("%s",&c);
		if(c == END)
		{
			return TRUE;
		}
		else
		{
			insertElem(list,c-48);
		}
	}
}

void main ()
{
	LinkList list;

	if (initLinkList(&list))	//测试初始化函数
		printLinkList(list);

	insertNode(&list,2,2);		//测试插入函数
	insertNode(&list,2,3);
	insertNode(&list,2,4);
	printLinkList(list);

	printf("%d\n",getNodeElem(list,2));		//测试获取节点函数
	
	deleteNode(&list,2);		//测试删除节点函数
	printLinkList(list);
}
