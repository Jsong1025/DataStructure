#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define FALSE 0;
#define TRUE 1;

//定义数字栈节点
typedef struct NumStackNode
{
	int Data;
	struct NumStackNode *Next;
} NumStack;

//定义运算符栈节点
typedef struct StrStackNode
{
	char Data;
	struct StrStackNode *Next;
} StrStack;

//返回数字栈顶元素
int NumTopStack (NumStack *S)
{
	return S->Data;
}

//返回运算符栈顶元素
char StrTopStack (StrStack *S)
{
	return S->Data;
}

//判断是否为数字空栈
int NumEmptystack(NumStack *S)
{
	//如果为空栈返回true
	if(S==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//判断是否为运算符空栈
int StrEmptystack(StrStack *S)
{
	//如果为空栈返回true
	if(S==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//数字符出栈，并返回栈顶的值
int NumPopStack (NumStack **S)
{
	int Elem=(*S)->Data;
	(*S)=(*S)->Next;
	return Elem;
}

//运算符出栈，并返回栈顶的值
char StrPopStack (StrStack **S)
{
	char Elem=(*S)->Data;
	(*S)=(*S)->Next;
	return Elem;
}

//把数据d压入数字栈顶，入栈
NumStack *NumPushStack (NumStack *S,int Elem)
{
	//临时节点Temp
	NumStack *Temp;

	//如果S为空栈
	if(S==NULL)
	{
		//重新开辟节点，并赋值
		S=(NumStack*)malloc(sizeof(NumStack));
		S->Data=Elem;
		S->Next=NULL;
	}
	else
	{
		//为栈重新开辟一个节点，并压入数值Elem
		Temp=(NumStack*)malloc(sizeof(NumStack));
		Temp->Data=Elem;
		Temp->Next=S;
		S=Temp;
	}
	return S;
}

//把数据d压入运算符栈顶，入栈
StrStack *StrPushStack (StrStack *S,char Elem)
{
	//临时节点Temp
	StrStack *Temp;

	//如果S为空栈
	if(S==NULL)
	{
		//重新开辟节点，并赋值
		S=(StrStack*)malloc(sizeof(StrStack));
		S->Data=Elem;
		S->Next=NULL;
	}
	else
	{
		//为栈重新开辟一个节点，并压入数值Elem
		Temp=(StrStack*)malloc(sizeof(StrStack));
		Temp->Data=Elem;
		Temp->Next=S;
		S=Temp;
	}
	return S;
}

//计算数值
int Operate (int Num1,int Num2,char str)
{
	switch (str)
	{
	case '+':return Num1+Num2;break;
	case '-':return Num1-Num2;break;
	case '*':return Num1*Num2;break;
	case '/':return Num1/Num2;break;
	}
}

//判断运算符优先级
//Str1低于Str2则返回true，否则返回false
int ComStr(char Str1,char Str2)
{
	//如果为+，只有*，/，）返回true
	//注意：-的优先级大于+  ！！
	//其余均为false
	if(Str1=='+')
	{
		switch(Str2)
		{
		case '-': return TRUE;
		case '*': return TRUE;
		case '/': return TRUE;
		case ')': return TRUE;
		default: return FALSE;
		}
	}

	//如果为-，只有*，/，）返回true
	//其余均为false
	if(Str1=='-')
	{
		switch(Str2)
		{
		case '*': return TRUE;
		case '/': return TRUE;
		case ')': return TRUE;
		default: return FALSE;
		}
	}

	//如果为*，只有）返回true
	//注意：/的优先级大于*  ！！
	//其余均为false
	if(Str1=='*')
	{
		switch(Str2)
		{
		case '/': return TRUE;
		case ')': return TRUE;
		default: return FALSE;
		}
	}

	//如果为\，只有）返回true
	//其余均为false
	if(Str1=='/')
	{
		switch(Str2)
		{
		case ')': return TRUE;
		default: return FALSE;
		}
	}

	// ( 低于一切运算符
	if(Str1=='(')
	{
		if(Str2=='=')
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	// ) 高于一切运算符
	if(Str1==')')
		return TRUE;
}

//演示函数
void Demo(StrStack *SStr,NumStack *SNum)
{
	StrStack *tempStr=SStr;
	NumStack *tempNum=SNum;

	//展示数字栈内所有元素
	printf("数字栈:  ");
	while(tempNum!=NULL)
	{
		printf("%d ",tempNum->Data);
		tempNum=tempNum->Next;
	}

	//运算符栈内所有元素
	printf("\t\t\t操作符栈: ");
	while(tempStr!=NULL)
	{
		printf("%c ",tempStr->Data);
		tempStr=tempStr->Next;
	}
	printf("\n");
}

//计算函数
//根据传入的运算符，对数字栈以及运算符栈进行相应操作
StrStack *Count(char str,StrStack *SStr,NumStack **SNum)
{
	int Sum=0;

	//运算符栈非空
	if(StrEmptystack(SStr) && str!='=')
		SStr=StrPushStack(SStr,str);

	else
	{
		//优先级大于栈顶元素，压栈
		if(!ComStr(str,StrTopStack(SStr)))
		{
			SStr=StrPushStack(SStr,str);
			Demo(SStr,*SNum);
		}

		//否则循环出栈并计算
		//直到栈顶元素优先级小于当前运算符，将当前运算符压栈
		//将计算结果压栈
		else
		{
			while(!StrEmptystack(SStr))
			{
				if(!ComStr(str,StrTopStack(SStr)))
					break;
				
				Demo(SStr,*SNum);
				
				//如果输入为右括号 ）运算符，消去运算符栈中的左括号（ 运算符
				if(str==')' && StrTopStack(SStr)=='(')
				{
					str=StrPopStack(&SStr);
					break;
				}

				Sum+=Operate(NumPopStack(SNum),NumPopStack(SNum),StrPopStack(&SStr));
				(*SNum)=NumPushStack((*SNum),Sum);
						
				Sum=0;
				Demo(SStr,*SNum);
			}
			//如果Elem不是（ ，既除去括号之外的运算符，把当前运算符压入栈顶
			if(str!='(')
				SStr=StrPushStack(SStr,str);
		}
	}

	Demo(SStr,*SNum);
	return SStr;
}

void main ()
{
	char Str;
	int Num=0;
	char Oper;

	//定义数字栈、运算符栈
	NumStack *NumberStack=NULL;
	StrStack *StringStack=NULL;

	printf("请输入数学表达式，以=结束：\n");
	while((Str=getchar())!='\n')
	{
		//计算输入数值
		if(Str>'0' && Str<'9')
			Num=Num*10+((int)Str-48);
		
		else
		{
			Oper=Str;

			//将数字压栈
			if(Num!=0)
			{
				NumberStack=NumPushStack(NumberStack,Num);
				Num=0;
				Demo(StringStack,NumberStack);
			}

			//对运算符进行相应操作
			StringStack=Count(Oper,StringStack,&NumberStack);
		}
	}

	printf("\n表达式结果为：%d\n",NumPopStack(&NumberStack));
	printf("%c",getchar());
}
