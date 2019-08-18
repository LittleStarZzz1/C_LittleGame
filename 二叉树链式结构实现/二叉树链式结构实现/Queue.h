#ifndef _Queue_H
#define _Queue_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "BTree.h"

typedef BTNode * QuDataType;

typedef struct QueueNode{
	QuDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue{
	QueueNode* _head;
	QueueNode* _rear;
}Queue;

//��ʼ������
void QueueInit(Queue* plist);

//��Ӧ�ڳ�ʼ����������Ҫ�ͷſ��ٵĶ�̬�ڴ�
void QueueDestory(Queue* plist);

//�����в�������(����ͷ)
void QueuePush(Queue* plist, QuDataType x);
//ɾ�������е�����(����β)
void QueuePop(Queue* plist);

//���ض���ͷ������
QuDataType QueueTop(Queue* plist);

//�ж϶����Ƿ�Ϊ��
int QueueIsEmpty(Queue* plist);

//��ӡ����
void QueuePrint(Queue* plist);


#endif //_Queue_H