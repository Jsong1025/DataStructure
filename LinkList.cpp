#include <iostream>
#include "Node.h"
using namespace std;

#define END '#'		//������־

class LinkList
{
private:
	LNode head;		//ͷ���
	LNode tail;		//β�ڵ�
	int length;		//����

public:
	LinkList();
	~LinkList();

	void insert(ElemType e);		//�������� 
	void insert(ElemType e, int n);
	ElemType getNode(int n);		//��ȡָ��λ�õ�����
	void deleteNode(int n);			//ɾ������ָ���ڵ�
	void init();					//��ʼ��
	void print();					//���
};

/*
 *	���캯��
 */
LinkList::LinkList()
{
	this->head = this->tail = NULL;
	this->length = 0;
}

/*
 *	��������
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
 *	��������
 *	
 *	������	ElemType	Ҫ���������
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
 *	���뵽ָ��λ��
 *	
 *	������	ElemType	e	  Ҫ���������
 *			int			n	  �ڵ�λ�� (��0��ʼ) 
 */
void LinkList::insert(ElemType e,int n)
{
	int i = 0;
	LNode p = this->head;
	LNode q;
	while(i < n-1)	//�ҵ�Ҫ�����ǰһ���ڵ�
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
 *	��ȡָ��λ�õ�����
 *	
 *	������	int			n	  �ڵ�λ��(��0��ʼ) 
 *	���أ�	ElemType	�˽ڵ������  
 */
ElemType LinkList::getNode(int n)
{
	int i = 0;
	LNode p = this->head;
	while(i < n)		//�ҵ�Ҫ����Ľڵ�
	{
		p = p->next;
		i++;
	}
	return p->data;
}

/*
 *	ɾ��ָ���ڵ�
 *	
 *	������	int			n	  �ڵ�λ��(��0��ʼ) 
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
 *	�������
 */
void LinkList::print()
{
	LNode p = this->head;

	cout<<"�����ȣ�";
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
 *	��ʼ��
 *		ѭ��ɨ���������ݣ�ֱ������ָ��������Ϊֹ
 */
void  LinkList::init()
{
	char c;
	printf("�������ʼ�����ݣ�\n");
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
