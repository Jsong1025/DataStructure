#include "LinkList.h"

void main ()
{
	LinkList list;

	if (initLinkList(&list))	//测试初始化函数
		printLinkList(list);

	insertNode(&list,2,2);		//测试插入函数
	insertNode(&list,2,3);
	insertNode(&list,2,4);
	printLinkList(list);

	printf("%d\n",getNodeElem(list,2));		//测试获取节点函数
	
	deleteNode(&list,2);		//测试删除节点函数
	printLinkList(list);
}
