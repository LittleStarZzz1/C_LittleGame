#ifndef _BTREE_H
#define _BTREE_H

typedef char BTDataType;

typedef struct BinaryTreeNode{
	BTDataType data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;

//ͨ��ǰ�����������"ABD##GI##J###CE#HK###F##"����������
BTNode* BinaryTreeCreate(BTDataType* a);

//ǰ�����(�ݹ�)
void BinaryTreePrevOrder(BTNode* root);
//�������(�ݹ�)
void BinaryTreeInOrder(BTNode* root);
//�������(�ݹ�)
void BinaryTreePostOrder(BTNode* root);

//�������,���������Ҫ��������
void BinaryTreeLevelOrder(BTNode* root);

//�ǵݹ�ǰ�����,��Ҫ����ջ
void BinaryTreePrevOrderNonR(BTNode* root);


#endif	//_BTREE_H