#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "Queue.h"
#include "stack.h"

//通过前序遍历的数组"ABD##GI##J###CE#HK###F##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* src){
	static int s_n = 0;
	if (src[s_n] == '#'){
		s_n++;
		return NULL;
	}
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	s_n++;

	cur->lchild = BinaryTreeCreate(src);
	cur->rchild = BinaryTreeCreate(src);
	
	return cur;
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


//销毁,释放
void BinaryTreeDestory(BTNode* root){
	//后序销毁
	if (root){
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		free(root);
	}
}









