
typedef  int ElemType;		//节点数据类型

typedef struct Node			//节点结构体
{
	ElemType data;
	struct Node *next;
}Node, *LNode;