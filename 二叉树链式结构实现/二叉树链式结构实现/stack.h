#ifndef _Stack_H_
#define _Stack_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BTree.h"


typedef BTNode* StDataType;

typedef struct Stack {
	StDataType* array;	// ָ��̬���ٵ�����
	size_t size;		// ��Ч���ݸ���
	size_t capicity;	// �����ռ�Ĵ�С
}Stack;

// ������ɾ��Ľӿ�
//��ʼ��
void StackInit(Stack* psl, size_t capacity);
//�ͷ�,���ٺ���
void StackDestory(Stack* psl);

//����Ƿ�����
void CheckCapacity(Stack* psl);
//β��
void StackPush(Stack* psl, StDataType x);
//βɾ
void StackPop(Stack* psl);

//����ջ������
StDataType StackTop(Stack* psl);

//�ж�ջ�Ƿ�Ϊ��
int StackIsEmpty(Stack* psl);

#endif //_Stack_H_