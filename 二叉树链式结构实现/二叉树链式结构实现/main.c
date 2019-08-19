#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "Queue.h"
#include "stack.h"

//���Զ���
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
	
	printf("������ǰ��ݹ����: ");
	BinaryTreePrevOrder(root);
	putchar('\n');

	printf("����������ݹ����: ");
	BinaryTreeInOrder(root);
	putchar('\n');

	printf("����������ݹ����: ");
	BinaryTreePostOrder(root);
	putchar('\n');
	
	putchar('\n');
	
	printf("�������������:	");
	BinaryTreeLevelOrder(root);
	putchar('\n');
	
	putchar('\n');

	printf("������ǰ��ǵݹ����: ");
	BinaryTreePrevOrderNonR(root);
	putchar('\n');

	printf("����������ǵݹ����: ");
	BinaryTreeInOrderNonR(root);
	putchar('\n');

	printf("����������ǵݹ����: ");
	BinaryTreePostNonR(root);
	putchar('\n');


	//putchar('\n');
	//printf("%d\n", BinaryTreeComplete(root));
	//if (BinaryTreeComplete(root)){
	//	printf("�ö���������ȫ������!\n");
	//}
	//else {
	//	printf("�ö�����������ȫ������!\n");
	//}


	BTNode* root2 = BinaryTreeCreate("ABDH##I##EJ###CF##G##");
	
	if (BinaryTreeComplete(root2)){
		printf("�ö���������ȫ������!\n");
	}
	else {
		printf("�ö�����������ȫ������!\n");
	}

	printf("��������size��СΪ%d\n", BinaryTreeSize(root));
	printf("��������Ҷ�ӽڵ����Ϊ%d\n", BinaryTreeLeafSize(root));
	system("pause");
	return 0;
}