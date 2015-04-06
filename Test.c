#include "Queue.h"

void main ()
{
	BinaryTree tree;
	initBinaryTree(&tree);
	createBinaryTree(&tree);
	preOrederTraverse(tree);
	inOrederTraverse(tree);
	postOrederTraverse(tree);
}
