#include <stdio.h>
#include <malloc.h>
#include <string.h>

//��������ڵ�
typedef struct LongNum
{
	int Data;
	struct LongNum *Next;
} LongNum; 

//��ʼ����������
//������
LongNum *InitLongNum()
{
	char Elem;

	//ͷָ��Head ,��ʱ�ڵ����TempNode
	LongNum *TempNode=NULL;
	LongNum *Head=TempNode;

	if((Elem=getchar())!='\n')
	{
		//�����һ���ڵ�
		TempNode=(LongNum*)malloc(sizeof(LongNum));
		TempNode->Data=Elem-48;
		Head=TempNode;

		//ѭ�����ٽڵ�
		while((Elem=getchar())!='\n')
		{
			TempNode->Next=(LongNum*)malloc(sizeof(LongNum));
			TempNode->Next->Data=Elem-48;
			TempNode=TempNode->Next;
		}
	}

	//�������һ���ڵ���ָ��
	TempNode->Next=NULL;

	return Head;
} //InitLongNum

//��ת����
LongNum *RoundLongNum(LongNum *RoundLN)
{
	//ͷ���Head,��ʱ�ڵ�Temp
	LongNum *Head=NULL;
	LongNum *Temp=RoundLN;
	LongNum *RoundNode;

	//�ж��Ƿ�Ϊ��
	if (Temp==NULL)
		return NULL;

	while(Temp!=NULL)
	{
		RoundNode=(LongNum*)malloc(sizeof(LongNum));
		RoundNode->Data=Temp->Data;

		//RoundNode��nextָ��ָ��ͷָ�룬ͷָ��ǰ��
		RoundNode->Next=Head;
		Head=RoundNode;
		
		Temp=Temp->Next;
	}

	return Head;
}  //RoundLongNum

//���㺯��
//�ֱ�����������Ľڵ�CountNode1��CountNode2���Լ���λֵCountGoin
//ע��CountNode1��CountNode2Ϊָ��ָ���ָ������
int Count ( LongNum **CountNode1 , LongNum **CountNode2, int *CountGoin)
{
	int CountNum;

	//���CountNode1Ϊ��
	if((*CountNode1)==NULL)
	{
		//
		CountNum=((*CountNode2)->Data+(*CountGoin))%10;
		*CountGoin=((*CountNode2)->Data+(*CountGoin))/10;
		(*CountNode2)=(*CountNode2)->Next;
	}

	//���CountNode2Ϊ��
	else if((*CountNode2)==NULL)
	{
		CountNum=((*CountNode1)->Data+(*CountGoin))%10;
		*CountGoin=((*CountNode1)->Data+(*CountGoin))/10;
		(*CountNode1)=(*CountNode1)->Next;
	}

	else
	{
		//�����ܺ�CountSum���Լ���λ����ֵ
		CountNum=((*CountNode1)->Data+(*CountNode2)->Data+(*CountGoin))%10;
		*CountGoin=((*CountNode1)->Data+(*CountNode2)->Data+(*CountGoin))/10;
		
		(*CountNode1)=(*CountNode1)->Next;
		(*CountNode2)=(*CountNode2)->Next;
	}
	return CountNum;
}  //Count

//�����������
LongNum *LongNumAdd(LongNum *AddLN1,LongNum *AddLN2)
{
	//��λ�ؼ���
	int Goin=0;

	//������֮��LongNumSum��������ʱ�ڵ�TempLN1��TempLN2
	LongNum *LongNumSum;
	LongNum *TempLN1,*TempLN2;
	
	//�ֱ�ָ��LN1��LN2 ��ת����Ľڵ�TempNode1��TempNode2
	LongNum *TempNode1=RoundLongNum(AddLN1);
	LongNum *TempNode2=RoundLongNum(AddLN2);
	
	//ΪTempLN1�����ڴ棬����Data�򸳳�ֵ0
	TempLN2=TempLN1=(LongNum*)malloc(sizeof(LongNum));
	TempLN1->Data=0;
	TempLN2->Next=NULL;
	
	//ͷָ��LongNumSumָ��TempLN1
	LongNumSum=TempLN1;
	if(TempNode1==NULL && TempNode2==NULL)
		return NULL;

	//����ΪTempLN2���㸳ֵ����������һ���ڵ�
	TempLN2->Data=Count(&TempNode1,&TempNode2,&Goin);
	TempLN2=(LongNum*)malloc(sizeof(LongNum));
	TempLN2->Data=0;
	TempLN2->Next=NULL;

	while(1)
	{
		//����������������������Ϻ�
		//��TempNode1��TempNode2ͬʱΪ��
		if(TempNode1==NULL && TempNode2==NULL)
		{
			if(Goin!=0)
			{
				//������������������������λ����Ȼ����ֵ
				TempLN2->Data=Goin;
				TempLN1->Next=TempLN2;
				TempLN1=TempLN2;
			}
			break;
		}

		//�����λ��Ϊ0������ͨ����
		TempLN2->Data=Count(&TempNode1,&TempNode2,&Goin);

		//�������ٽڵ�
		TempLN1->Next=TempLN2;
		TempLN1=TempLN2;

		TempLN2=(LongNum*)malloc(sizeof(LongNum));
		TempLN2->Next=NULL;
		TempLN2->Data=0;
	}
	
	//��תSum�������
	LongNumSum=RoundLongNum(LongNumSum);
	return LongNumSum;
}  //LongNumAdd

//�������
void PrintLongNum (LongNum *LNPrint)
{
	//������ʱ�ڵ�Temp��������ָ��LNPrint
	LongNum *Temp=LNPrint;
	
	//��ָ������Ĳ�Ϊ��ʱ���������
	while(Temp!=NULL)
	{
		printf("%d",Temp->Data);
		Temp=Temp->Next;
	}
}  //PrintLongNum

void main ()
{
	//�ֱ��峤����LongNum1��LongNum2���ܺ�LNSum
	LongNum *LongNum1;
	LongNum *LongNum2;
	LongNum *LNSum;

	//��ʼ������������
	printf("��ʼ����������������-1������\n");

	printf("L1=");
	LongNum1=InitLongNum();
	printf("L2=");
	LongNum2=InitLongNum();
	printf("\n");
	
	//�����ܺ�
	LNSum=LongNumAdd(LongNum1,LongNum2);

	//������
	printf("��������\n");
	PrintLongNum(LongNum1);
	printf(" + "); 
	PrintLongNum(LongNum2);
	printf(" = ");
	PrintLongNum(LNSum);
	printf("\n");
	printf("%c",getchar());
}