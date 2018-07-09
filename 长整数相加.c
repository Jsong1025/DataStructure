#include <stdio.h>
#include <malloc.h>
#include <string.h>

//定义链表节点
typedef struct LongNum
{
	int Data;
	struct LongNum *Next;
} LongNum; 

//初始化长整形数
//正序建立
LongNum *InitLongNum()
{
	char Elem;

	//头指针Head ,临时节点变量TempNode
	LongNum *TempNode=NULL;
	LongNum *Head=TempNode;

	if((Elem=getchar())!='\n')
	{
		//处理第一个节点
		TempNode=(LongNum*)malloc(sizeof(LongNum));
		TempNode->Data=Elem-48;
		Head=TempNode;

		//循环开辟节点
		while((Elem=getchar())!='\n')
		{
			TempNode->Next=(LongNum*)malloc(sizeof(LongNum));
			TempNode->Next->Data=Elem-48;
			TempNode=TempNode->Next;
		}
	}

	//处理最后一个节点是指针
	TempNode->Next=NULL;

	return Head;
} //InitLongNum

//翻转链表
LongNum *RoundLongNum(LongNum *RoundLN)
{
	//头结点Head,临时节点Temp
	LongNum *Head=NULL;
	LongNum *Temp=RoundLN;
	LongNum *RoundNode;

	//判断是否为空
	if (Temp==NULL)
		return NULL;

	while(Temp!=NULL)
	{
		RoundNode=(LongNum*)malloc(sizeof(LongNum));
		RoundNode->Data=Temp->Data;

		//RoundNode的next指针指向头指针，头指针前移
		RoundNode->Next=Head;
		Head=RoundNode;
		
		Temp=Temp->Next;
	}

	return Head;
}  //RoundLongNum

//计算函数
//分别传入两个链表的节点CountNode1和CountNode2，以及进位值CountGoin
//注：CountNode1和CountNode2为指向指针的指针类型
int Count ( LongNum **CountNode1 , LongNum **CountNode2, int *CountGoin)
{
	int CountNum;

	//如果CountNode1为空
	if((*CountNode1)==NULL)
	{
		//
		CountNum=((*CountNode2)->Data+(*CountGoin))%10;
		*CountGoin=((*CountNode2)->Data+(*CountGoin))/10;
		(*CountNode2)=(*CountNode2)->Next;
	}

	//如果CountNode2为空
	else if((*CountNode2)==NULL)
	{
		CountNum=((*CountNode1)->Data+(*CountGoin))%10;
		*CountGoin=((*CountNode1)->Data+(*CountGoin))/10;
		(*CountNode1)=(*CountNode1)->Next;
	}

	else
	{
		//计算总和CountSum，以及进位符的值
		CountNum=((*CountNode1)->Data+(*CountNode2)->Data+(*CountGoin))%10;
		*CountGoin=((*CountNode1)->Data+(*CountNode2)->Data+(*CountGoin))/10;
		
		(*CountNode1)=(*CountNode1)->Next;
		(*CountNode2)=(*CountNode2)->Next;
	}
	return CountNum;
}  //Count

//长整数的相加
LongNum *LongNumAdd(LongNum *AddLN1,LongNum *AddLN2)
{
	//进位关键域
	int Goin=0;

	//长整数之和LongNumSum和两个临时节点TempLN1，TempLN2
	LongNum *LongNumSum;
	LongNum *TempLN1,*TempLN2;
	
	//分别指向LN1，LN2 翻转链表的节点TempNode1和TempNode2
	LongNum *TempNode1=RoundLongNum(AddLN1);
	LongNum *TempNode2=RoundLongNum(AddLN2);
	
	//为TempLN1开辟内存，并给Data域赋初值0
	TempLN2=TempLN1=(LongNum*)malloc(sizeof(LongNum));
	TempLN1->Data=0;
	TempLN2->Next=NULL;
	
	//头指针LongNumSum指向TempLN1
	LongNumSum=TempLN1;
	if(TempNode1==NULL && TempNode2==NULL)
		return NULL;

	//否则，为TempLN2计算赋值，并计算下一个节点
	TempLN2->Data=Count(&TempNode1,&TempNode2,&Goin);
	TempLN2=(LongNum*)malloc(sizeof(LongNum));
	TempLN2->Data=0;
	TempLN2->Next=NULL;

	while(1)
	{
		//当两个长整形数均遍历完毕后
		//即TempNode1和TempNode2同时为空
		if(TempNode1==NULL && TempNode2==NULL)
		{
			if(Goin!=0)
			{
				//如果两个链表遍历结束，但进位符仍然存在值
				TempLN2->Data=Goin;
				TempLN1->Next=TempLN2;
				TempLN1=TempLN2;
			}
			break;
		}

		//如果进位域为0，即普通计算
		TempLN2->Data=Count(&TempNode1,&TempNode2,&Goin);

		//继续开辟节点
		TempLN1->Next=TempLN2;
		TempLN1=TempLN2;

		TempLN2=(LongNum*)malloc(sizeof(LongNum));
		TempLN2->Next=NULL;
		TempLN2->Data=0;
	}
	
	//翻转Sum链表，输出
	LongNumSum=RoundLongNum(LongNumSum);
	return LongNumSum;
}  //LongNumAdd

//输出链表
void PrintLongNum (LongNum *LNPrint)
{
	//定义临时节点Temp，并令其指向LNPrint
	LongNum *Temp=LNPrint;
	
	//当指向链表的不为空时，输出链表
	while(Temp!=NULL)
	{
		printf("%d",Temp->Data);
		Temp=Temp->Next;
	}
}  //PrintLongNum

void main ()
{
	//分别定义长整形LongNum1，LongNum2和总和LNSum
	LongNum *LongNum1;
	LongNum *LongNum2;
	LongNum *LNSum;

	//初始化两个个链表
	printf("初始化长整型数：（以-1结束）\n");

	printf("L1=");
	LongNum1=InitLongNum();
	printf("L2=");
	LongNum2=InitLongNum();
	printf("\n");
	
	//计算总和
	LNSum=LongNumAdd(LongNum1,LongNum2);

	//输出结果
	printf("计算结果：\n");
	PrintLongNum(LongNum1);
	printf(" + "); 
	PrintLongNum(LongNum2);
	printf(" = ");
	PrintLongNum(LNSum);
	printf("\n");
	printf("%c",getchar());
}