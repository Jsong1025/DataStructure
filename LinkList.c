#include "LinkList.h"

void main ()
{
	LinkList list;

	if (initLinkList(&list))	//���Գ�ʼ������
		printLinkList(list);

	insertNode(&list,2,2);		//���Բ��뺯��
	insertNode(&list,2,3);
	insertNode(&list,2,4);
	printLinkList(list);

	printf("%d\n",getNodeElem(list,2));		//���Ի�ȡ�ڵ㺯��
	
	deleteNode(&list,2);		//����ɾ���ڵ㺯��
	printLinkList(list);
}
