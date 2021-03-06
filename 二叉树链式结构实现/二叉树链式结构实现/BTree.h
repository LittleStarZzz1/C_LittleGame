#ifndef _BTREE_H
#define _BTREE_H

typedef char BTDataType;

typedef struct BinaryTreeNode{
	BTDataType data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;

//通过前序遍历的数组"ABD##GI##J###CE#HK###F##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a);

//前序遍历(递归)
void BinaryTreePrevOrder(BTNode* root);
//中序遍历(递归)
void BinaryTreeInOrder(BTNode* root);
//后序遍历(递归)
void BinaryTreePostOrder(BTNode* root);

//层序遍历,层序遍历需要借助队列
void BinaryTreeLevelOrder(BTNode* root);

//非递归前序遍历,需要借助栈
void BinaryTreePrevOrderNonR(BTNode* root);
//非递归中序遍历
void BinaryTreeInOrderNonR(BTNode* root);
//非递归后序遍历
void BinaryTreePostNonR(BTNode* root);

//判断一个二叉树是不是完全二叉树
int BinaryTreeComplete(BTNode* root);

//返回二叉树的size
int BinaryTreeSize(BTNode* root);

#endif	//_BTREE_H