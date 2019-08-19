#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "Queue.h"
#include "stack.h"

//测试队列
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
	
	printf("二叉树前序递归遍历: ");
	BinaryTreePrevOrder(root);
	putchar('\n');

	printf("二叉树中序递归遍历: ");
	BinaryTreeInOrder(root);
	putchar('\n');

	printf("二叉树后序递归遍历: ");
	BinaryTreePostOrder(root);
	putchar('\n');
	
	putchar('\n');
	
	printf("二叉树层序遍历:	");
	BinaryTreeLevelOrder(root);
	putchar('\n');
	
	putchar('\n');

	printf("二叉树前序非递归遍历: ");
	BinaryTreePrevOrderNonR(root);
	putchar('\n');

	printf("二叉树中序非递归遍历: ");
	BinaryTreeInOrderNonR(root);
	putchar('\n');

	printf("二叉树后序非递归遍历: ");
	BinaryTreePostNonR(root);
	putchar('\n');


	//putchar('\n');
	//printf("%d\n", BinaryTreeComplete(root));
	//if (BinaryTreeComplete(root)){
	//	printf("该二叉树是完全二叉树!\n");
	//}
	//else {
	//	printf("该二叉树不是完全二叉树!\n");
	//}


	BTNode* root2 = BinaryTreeCreate("ABDH##I##EJ###CF##G##");
	
	if (BinaryTreeComplete(root2)){
		printf("该二叉树是完全二叉树!\n");
	}
	else {
		printf("该二叉树不是完全二叉树!\n");
	}

	printf("二叉树的size大小为%d\n", BinaryTreeSize(root));
	printf("二叉树的叶子节点个数为%d\n", BinaryTreeLeafSize(root));
	system("pause");
	return 0;
}