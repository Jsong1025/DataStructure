#include <iostream>
#include "Node.h"
using namespace std;

class Stack
{
private:
	LNode top;		//ջ��
	LNode bottom;	//ջ��
	int length;		//ջ���

public:
	Stack();
	~Stack();

	bool isEmpty();			//�ж��Ƿ��ջ
	void push(ElemType e);	//ѹջ
	ElemType pop();			//��ջ
	ElemType getTop();		//��ȡջ��Ԫ��
	void  print();			//���
};

/*
 *	���캯��
 */
Stack::Stack()
{
	this->length = 0;
	this->top = this->bottom = NULL;
}

/*
 *	��������
 */
Stack::~Stack()
{
}

/*
 *  �ж��Ƿ��ǿ�ջ
 *
 *	���أ�bool
 */
bool Stack::isEmpty()
{
	if(this->top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
 *	����ѹջ
 *	
 *	������	ElemType e	Ҫѹ�������
 */
void Stack::push(ElemType e)
{
	LNode n;
	if(this->isEmpty())
	{
		this->top = new Node;
		this->bottom = this->top;
		this->top->data = e;
		this->top->next = NULL;
		this->length++;
	}
	else
	{
		n = new Node;
		n->data = e;
		n->next = this->top;
		this->top = n;
		this->length++;
	}
}

/*
 *	���ݳ�ջ
 *
 *	���أ�ElemType  ջ������ 
 */
ElemType Stack::pop()
{
	ElemType e = this->top->data;
	this->top = this->top->next;
	this->length--;
	return e;
}

/*
 *	��ȡջ��Ԫ��
 *
 *	���أ�ElemType  ջ������ 
 */
ElemType Stack::getTop()
{
	return this->top->data;
}

/*
 *	ջ�������(����)
 */
void Stack::print()
{
	LNode p = this->top;

	printf("ջ��ȣ�");
	printf("%d\n",this->length);
	
	while(p != NULL)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}

void main()
{
	Stack s;
}
