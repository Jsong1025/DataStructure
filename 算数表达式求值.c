#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define FALSE 0;
#define TRUE 1;

//��������ջ�ڵ�
typedef struct NumStackNode
{
	int Data;
	struct NumStackNode *Next;
} NumStack;

//���������ջ�ڵ�
typedef struct StrStackNode
{
	char Data;
	struct StrStackNode *Next;
} StrStack;

//��������ջ��Ԫ��
int NumTopStack (NumStack *S)
{
	return S->Data;
}

//���������ջ��Ԫ��
char StrTopStack (StrStack *S)
{
	return S->Data;
}

//�ж��Ƿ�Ϊ���ֿ�ջ
int NumEmptystack(NumStack *S)
{
	//���Ϊ��ջ����true
	if(S==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//�ж��Ƿ�Ϊ�������ջ
int StrEmptystack(StrStack *S)
{
	//���Ϊ��ջ����true
	if(S==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//���ַ���ջ��������ջ����ֵ
int NumPopStack (NumStack **S)
{
	int Elem=(*S)->Data;
	(*S)=(*S)->Next;
	return Elem;
}

//�������ջ��������ջ����ֵ
char StrPopStack (StrStack **S)
{
	char Elem=(*S)->Data;
	(*S)=(*S)->Next;
	return Elem;
}

//������dѹ������ջ������ջ
NumStack *NumPushStack (NumStack *S,int Elem)
{
	//��ʱ�ڵ�Temp
	NumStack *Temp;

	//���SΪ��ջ
	if(S==NULL)
	{
		//���¿��ٽڵ㣬����ֵ
		S=(NumStack*)malloc(sizeof(NumStack));
		S->Data=Elem;
		S->Next=NULL;
	}
	else
	{
		//Ϊջ���¿���һ���ڵ㣬��ѹ����ֵElem
		Temp=(NumStack*)malloc(sizeof(NumStack));
		Temp->Data=Elem;
		Temp->Next=S;
		S=Temp;
	}
	return S;
}

//������dѹ�������ջ������ջ
StrStack *StrPushStack (StrStack *S,char Elem)
{
	//��ʱ�ڵ�Temp
	StrStack *Temp;

	//���SΪ��ջ
	if(S==NULL)
	{
		//���¿��ٽڵ㣬����ֵ
		S=(StrStack*)malloc(sizeof(StrStack));
		S->Data=Elem;
		S->Next=NULL;
	}
	else
	{
		//Ϊջ���¿���һ���ڵ㣬��ѹ����ֵElem
		Temp=(StrStack*)malloc(sizeof(StrStack));
		Temp->Data=Elem;
		Temp->Next=S;
		S=Temp;
	}
	return S;
}

//������ֵ
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

//�ж���������ȼ�
//Str1����Str2�򷵻�true�����򷵻�false
int ComStr(char Str1,char Str2)
{
	//���Ϊ+��ֻ��*��/��������true
	//ע�⣺-�����ȼ�����+  ����
	//�����Ϊfalse
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

	//���Ϊ-��ֻ��*��/��������true
	//�����Ϊfalse
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

	//���Ϊ*��ֻ�У�����true
	//ע�⣺/�����ȼ�����*  ����
	//�����Ϊfalse
	if(Str1=='*')
	{
		switch(Str2)
		{
		case '/': return TRUE;
		case ')': return TRUE;
		default: return FALSE;
		}
	}

	//���Ϊ\��ֻ�У�����true
	//�����Ϊfalse
	if(Str1=='/')
	{
		switch(Str2)
		{
		case ')': return TRUE;
		default: return FALSE;
		}
	}

	// ( ����һ�������
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

	// ) ����һ�������
	if(Str1==')')
		return TRUE;
}

//��ʾ����
void Demo(StrStack *SStr,NumStack *SNum)
{
	StrStack *tempStr=SStr;
	NumStack *tempNum=SNum;

	//չʾ����ջ������Ԫ��
	printf("����ջ:  ");
	while(tempNum!=NULL)
	{
		printf("%d ",tempNum->Data);
		tempNum=tempNum->Next;
	}

	//�����ջ������Ԫ��
	printf("\t\t\t������ջ: ");
	while(tempStr!=NULL)
	{
		printf("%c ",tempStr->Data);
		tempStr=tempStr->Next;
	}
	printf("\n");
}

//���㺯��
//���ݴ�����������������ջ�Լ������ջ������Ӧ����
StrStack *Count(char str,StrStack *SStr,NumStack **SNum)
{
	int Sum=0;

	//�����ջ�ǿ�
	if(StrEmptystack(SStr) && str!='=')
		SStr=StrPushStack(SStr,str);

	else
	{
		//���ȼ�����ջ��Ԫ�أ�ѹջ
		if(!ComStr(str,StrTopStack(SStr)))
		{
			SStr=StrPushStack(SStr,str);
			Demo(SStr,*SNum);
		}

		//����ѭ����ջ������
		//ֱ��ջ��Ԫ�����ȼ�С�ڵ�ǰ�����������ǰ�����ѹջ
		//��������ѹջ
		else
		{
			while(!StrEmptystack(SStr))
			{
				if(!ComStr(str,StrTopStack(SStr)))
					break;
				
				Demo(SStr,*SNum);
				
				//�������Ϊ������ �����������ȥ�����ջ�е������ţ� �����
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
			//���Elem���ǣ� ���ȳ�ȥ����֮�����������ѵ�ǰ�����ѹ��ջ��
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

	//��������ջ�������ջ
	NumStack *NumberStack=NULL;
	StrStack *StringStack=NULL;

	printf("��������ѧ���ʽ����=������\n");
	while((Str=getchar())!='\n')
	{
		//����������ֵ
		if(Str>'0' && Str<'9')
			Num=Num*10+((int)Str-48);
		
		else
		{
			Oper=Str;

			//������ѹջ
			if(Num!=0)
			{
				NumberStack=NumPushStack(NumberStack,Num);
				Num=0;
				Demo(StringStack,NumberStack);
			}

			//�������������Ӧ����
			StringStack=Count(Oper,StringStack,&NumberStack);
		}
	}

	printf("\n���ʽ���Ϊ��%d\n",NumPopStack(&NumberStack));
	printf("%c",getchar());
}
