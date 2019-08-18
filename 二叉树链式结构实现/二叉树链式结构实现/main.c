#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "Queue.h"
#include "stack.h"

//≤‚ ‘∂”¡–
//void testQueue(){
//	Queue qu;
//	QueueInit(&qu);
//	QueuePush(&qu, 1);
//	QueuePush(&qu, 2);
//	QueuePush(&qu, 3);
//	printf("%d ", QueueTop(&qu));
//	QueuePop(&qu);
//	printf("%d ", QueueTop(&qu));
//	QueuePop(&qu);
//	QueuePush(&qu, 4);
//	QueuePush(&qu, 5);
//	printf("%d ", QueueTop(&qu));
//	QueuePop(&qu);
//	printf("%d ", QueueTop(&qu));
//	QueuePop(&qu);
//	QueuePush(&qu, 6);
//	printf("%d ", QueueTop(&qu));
//	QueuePop(&qu);
//	printf("%d ", QueueTop(&qu));
//	QueuePop(&qu);
//	QueuePop(&qu);
//	QueuePush(&qu, 6);
//	printf("%d ", QueueTop(&qu));
//	QueuePop(&qu);
//
//
//	QueueDestroy(&qu);
//}

int main(){
	BTNode* root = BinaryTreeCreate("ABD#GI##J###CE#HK###F##");
	BinaryTreePrevOrder(root);
	putchar('\n');

	BinaryTreeInOrder(root);
	putchar('\n');

	BinaryTreePostOrder(root);
	putchar('\n');

	BinaryTreeLevelOrder(root);
	putchar('\n');
	
	BinaryTreePrevOrderNonR(root);
	putchar('\n');
	system("pause");
	return 0;
}