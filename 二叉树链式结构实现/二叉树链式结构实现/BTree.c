#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "Queue.h"
#include "stack.h"

//ͨ��ǰ�����������"ABD##GI##J###CE#HK###F##"����������
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

//ǰ�����(�ݹ�)
void BinaryTreePrevOrder(BTNode* root){
	if (root){
		putchar(root->data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
}

//�������(�ݹ�)
void BinaryTreeInOrder(BTNode* root){
	if (root){
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
}

//�������(�ݹ�)
void BinaryTreePostOrder(BTNode* root){
	if (root){
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->data);
	}
}

//�������,���������Ҫ��������(�����ɵ�����ʵ��)
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

//�ǵݹ�ǰ�����,��Ҫ����ջ(ջ������˳���ʵ�ֵ�)
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


//����,�ͷ�
void BinaryTreeDestory(BTNode* root){
	//��������
	if (root){
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		free(root);
	}
}









