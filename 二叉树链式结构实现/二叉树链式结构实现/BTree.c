#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "Queue.h"
#include "stack.h"

static int s_n = 0;

//通过前序遍历的数组"ABD##GI##J###CE#HK###F##"构建二叉树
BTNode* BinaryTreeCreateExe(BTDataType* src){

	if (src[s_n] == '#'){
		s_n++;
		return NULL;
	}
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	s_n++;

	cur->lchild = BinaryTreeCreateExe(src);
	cur->rchild = BinaryTreeCreateExe(src);
	
	return cur;
}

BTNode* BinaryTreeCreate(BTDataType* src){
	s_n = 0;
	return BinaryTreeCreateExe(src);
}

//前序遍历(递归)
void BinaryTreePrevOrder(BTNode* root){
	if (root){
		putchar(root->data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
}

//中序遍历(递归)
void BinaryTreeInOrder(BTNode* root){
	if (root){
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
}

//后序遍历(递归)
void BinaryTreePostOrder(BTNode* root){
	if (root){
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->data);
	}
}

//层序遍历,层序遍历需要借助队列(队列由单链表实现)
void BinaryTreeLevelOrder(BTNode* root){
	Queue qu;
	BTNode* cur;
	
	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu)){
		
		cur = QueueTop(&qu);
		
		putchar(cur->data);
		
		if (cur->lchild){
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild){
			QueuePush(&qu, cur->rchild);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
}

//非递归前序遍历,需要借助栈(栈又是由顺序表实现的)
void BinaryTreePrevOrderNonR(BTNode* root){
	Stack st;
	BTNode* cur = root;

	StackInit(&st, 100);
	while (cur){
	
		putchar(cur->data);
		if (cur->rchild){
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild){
			cur = cur->lchild;
		}
		else {
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}

//非递归中序遍历
void BinaryTreeInOrderNonR(BTNode* root){
	
	BTNode* cur = root;

	Stack st;

	StackInit(&st, 100);
#if 0
	while (1){
		for (; cur; cur = cur->lchild){
			StackPush(&st, cur);
		}
		
		cur = StackTop(&st);
		if (!cur){
			break;
		}
		StackPop(&st);
		putchar(cur->data);
		cur = cur->rchild;

	}
#elif 1
	while (cur || !StackIsEmpty(&st)){
		for (; cur; cur = cur->lchild){
			StackPush(&st, cur);
		}

		cur = StackTop(&st);
		
		if (cur){
			putchar(cur->data);
			StackPop(&st);
			cur = cur->rchild;
		}
	}
#endif
	StackDestory(&st);
}

//非递归后序遍历
void BinaryTreePostNonR(BTNode* root){
	char tag[64];
	BTNode* cur = root;

	Stack st;

	StackInit(&st, 100);

	do{
		for (; cur; cur = cur->lchild){
			StackPush(&st, cur);
			tag[st.size - 1] = 0;
		}
		while (!StackIsEmpty(&st) && tag[st.size - 1]){
			cur = StackTop(&st);
			putchar(cur->data);
			StackPop(&st);
		}
		if (!StackIsEmpty(&st)){
			cur = StackTop(&st);
			tag[st.size - 1] = 1;
			cur = cur->rchild;
		}
	} while (!StackIsEmpty(&st));

	StackDestory(&st);
}

//判断一个二叉树是不是完全二叉树(借助层序遍历)
int BinaryTreeComplete(BTNode* root){
	Queue qu;
	BTNode* cur;

	int tag = 0;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu)){

		cur = QueueTop(&qu);

		//putchar(cur->data);

		//有右子树没有左子树则不是完全二叉树
		if (cur->rchild && !cur->lchild){
			return 0;
		}

		if (cur->lchild){
			QueuePush(&qu, cur->lchild);
		}

		if (tag && (cur->lchild || cur->rchild)){
			return 0;
		}

		if (cur->rchild){
			QueuePush(&qu, cur->rchild);
		}
		else {
			//若该节点没有右子树就将该标签置为1
			tag = 1;
		}
		QueuePop(&qu);
	}

	QueueDestory(&qu);
	return 1;
}

//销毁,释放
void BinaryTreeDestory(BTNode* root){
	//后序销毁
	if (root){
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		free(root);
	}
}

//返回二叉树的size
int BinaryTreeSize(BTNode* root){
	int count = 0;
	Stack st;
	BTNode* cur = root;

	StackInit(&st, 100);
	while (cur){
		++count;
		//putchar(cur->data);
		if (cur->rchild){
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild){
			cur = cur->lchild;
		}
		else {
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
	return count;
}

//返回二叉树的叶子节点的个数
int BinaryTreeLeafSize(BTNode* root){
	Queue qu;
	BTNode* cur;
	int count = 0;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu)){

		cur = QueueTop(&qu);

		if (!cur->lchild && !cur->rchild){
			++count;
		}

		if (cur->lchild){
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild){
			QueuePush(&qu, cur->rchild);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);

	return count;
}





