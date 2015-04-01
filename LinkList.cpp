#include <iostream>
#include "Node.h"
using namespace std;

#define END '#'		//结束标志

class LinkList
{
private:
	LNode head;		//头结点
	LNode tail;		//尾节点
	int length;		//长度

public:
	LinkList();
	~LinkList();

	void insert(ElemType e);		//插入数据 
	void insert(ElemType e, int n);
	ElemType getNode(int n);		//获取指定位置的数据
	void deleteNode(int n);			//删除链表指定节点
	void init();					//初始化
	void print();					//输出
};

/*
 *	构造函数
 */
LinkList::LinkList()
{
	this->head = this->tail = NULL;
	this->length = 0;
}

/*
 *	析构函数
 */
LinkList::~LinkList()
{
	LNode p = this->head;
	while(p != NULL)
	{
		LNode n = p;
		p = p->next;
		delete n;
	}

	this->length = 0;
}


/*
 *	插入数据
 *	
 *	参数：	ElemType	要插入的数据
 */
void LinkList::insert(ElemType e)
{
	if(this->tail != NULL)
	{
		this->tail->next = new Node;
		this->tail = this->tail->next;
		this->tail->data = e;
		this->tail->next = NULL;
		this->length++;
	}
	else
	{
		this->tail = new Node;
		this->head = this->tail;
		this->tail->data = e;
		this->tail->next = NULL;
		this->length++;
	}
}
/*
 *	插入到指定位置
 *	
 *	参数：	ElemType	e	  要插入的数据
 *			int			n	  节点位置 (从0开始) 
 */
void LinkList::insert(ElemType e,int n)
{
	int i = 0;
	LNode p = this->head;
	LNode q;
	while(i < n-1)	//找到要插入的前一个节点
	{
		p = p->next;
		i++;
	}
	q = p->next;
	p->next = new Node;
	p->next->data = e;
	p->next->next = q;
	this->length++;
}

/*
 *	获取指定位置的数据
 *	
 *	参数：	int			n	  节点位置(从0开始) 
 *	返回：	ElemType	此节点的数据  
 */
ElemType LinkList::getNode(int n)
{
	int i = 0;
	LNode p = this->head;
	while(i < n)		//找到要插入的节点
	{
		p = p->next;
		i++;
	}
	return p->data;
}

/*
 *	删除指定节点
 *	
 *	参数：	int			n	  节点位置(从0开始) 
 */
void LinkList::deleteNode(int n)
{
	int i = 0;
	LNode p = this->head;
	LNode q;
	while(i < n-1)
	{
		p = p->next;
		i++;
	}
	q = p->next;
	p->next = q->next;
	delete q;
	this->length--;
}

/*
 *	链表输出
 */
void LinkList::print()
{
	LNode p = this->head;

	cout<<"链表长度：";
	cout<<this->length<<endl;
	
	while(p != NULL)
	{
		cout<<p->data;
		cout<<"\t";
		p = p->next;
	}
	cout<<"\n";
}


/*
 *	初始化
 *		循环扫描输入数据，直到输入指定结束符为止
 */
void  LinkList::init()
{
	char c;
	printf("请输入初始化数据：\n");
	while(1)
	{
		cin>>c;
		if(c == END)
		{
			return;
		}
		else
		{
			insert(c-48);
		}
	}
}
