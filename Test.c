#include "Queue.h"

void main ()
{
	Queue q;
	initQueue(&q);
	enQueue(&q,1);
	enQueue(&q,2);
	enQueue(&q,3);
	printf("%d\n",deQueue(&q));
	printf("%d\n",getHead(q));
	printf("%d\n",getTail(q));
	printQueue(q);
}
