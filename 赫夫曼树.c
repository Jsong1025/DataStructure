#include <stdio.h>
#include <malloc.h>

typedef struct
{
	unsigned int Weight;
	unsigned int Parent;
	unsigned int LChild,RChild;
}HTNode;

int List[100];
HTNode Huffman[100];

void InitList ()
{
	int i;
	int c;
	printf("���ʼ���շ���������Ȩֵ��(100���ַ����ڣ��ÿո��س��������ԡ�-1��������)��\n");
	for(i=1;c!=-1;i++)
	{
		scanf("%d",&c);
		List[i]=c;
		if(i>=100)
		{
			printf("�������������\n");
			break;
		}
	}
}

void InitHuffman ()
{
	int i;
	InitList ();
	for(i=1;i<100;i++)
		Huffman[i].Weight=List[i];
}

void Select (int T[],int n,int *s1,int *s2)
{
	int i,j;
	int k;
	for (i=1;T[i]!='\0';i++)
	{
		for (j=i+1;T[j]!='\0';j++)
		{
			if(T[j]>T[i])
			{
				k=T[j];
				T[j]=T[i];
				T[i]=k;
			}
		}
	}
	*s1=n;
	*s2=n+1;
}

HTNode *InitHuffmanTree ()
{
	int i;
	int *a1,*a2;
	int b1,b2;
	int length,HLength;
	HTNode *Head;
	a1=&b1;a2=&b2;
	InitHuffman ();
	for(i=1;Huffman[i].Weight!='\0';i++)
		length=i-1;
	HLength=2*length-1;
	for(i=1;i<=HLength;i++)
	{
		Select(Huffman,2*i-1,a1,a2);
		Huffman[length+i].LChild=b1;
		Huffman[length+i].RChild=b2;
		Huffman[length+i].Weight=Huffman[b1].Weight+Huffman[b2].Weight;
		Huffman[b1].Parent=length+i;
		Huffman[b2].Parent=length+i;
	}
	Head=&Huffman[i-1];
	Head->Parent='\0';
	Huffman[i].Weight='\0';
	return Head;
}

void HuffmanPrint (HTNode T[])
{
	int i;
	for(i=1;T[i].Weight!='\0';i++)
	{
		printf("%d�Žڵ㣬Ȩ��Ϊ%d��",i,T[i].Weight);
		if(T[i].Parent==0)
			printf("û��˫�ף�");
		else
			printf("˫��Ϊ%d�Žڵ㣬",T[i].Parent);
		if(T[i].LChild==0)
			printf("û�����ӣ�");
		else 
			printf("����Ϊ%d�Žڵ㣬",T[i].LChild);
		if(T[i].LChild==0)
			printf("û���Һ��ӡ�\n");
		else 
			printf("�Һ���Ϊ%d�Žڵ㡣\n",T[i].LChild);
	}
}

void main ()
{
	HTNode *HuffmanTree;
	HuffmanTree=InitHuffmanTree ();
	HuffmanPrint (Huffman);
}