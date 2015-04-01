#include <iostream>
#include "Node.h"
using namespace std;

class Stack
{
private:
	LNode top;		//栈顶
	LNode bottom;	//栈底
	int length;		//栈深度

public:
	Stack();
	~Stack();

	bool isEmpty();			//判断是否空栈
	void push(ElemType e);	//压栈
	ElemType pop();			//出栈
	ElemType getTop();		//获取栈顶元素
	void  print();			//输出
};

/*
 *	构造函数
 */
Stack::Stack()
{
	this->length = 0;
	this->top = this->bottom = NULL;
}

/*
 *	析构函数
 */
Stack::~Stack()
{
}

/*
 *  判断是否是空栈
 *
 *	返回：bool
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
 *	数据压栈
 *	
 *	参数：	ElemType e	要压入的数据
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
 *	数据出栈
 *
 *	返回：ElemType  栈顶数据 
 */
ElemType Stack::pop()
{
	ElemType e = this->top->data;
	this->top = this->top->next;
	this->length--;
	return e;
}

/*
 *	获取栈顶元素
 *
 *	返回：ElemType  栈顶数据 
 */
ElemType Stack::getTop()
{
	return this->top->data;
}

/*
 *	栈遍历输出(倒序)
 */
void Stack::print()
{
	LNode p = this->top;

	printf("栈深度：");
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
