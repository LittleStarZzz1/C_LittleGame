#ifndef _DEQUEUE_H
#define _DEQUEUE_H
#include <stdio.h>
#include <stdlib.h>

#define QUEUENUM 5
typedef int DataType;

typedef struct{
	DataType _data[QUEUENUM];
	DataType* _head;
	DataType* _tail;
	size_t _size;
}Dequeue;

//��ʼ������
void dequeueInit(Dequeue* qu);

//���ٺ���
void dequeueDestroy(Dequeue* qu);

//�ڶ����в�������,�൱�ڵ��������β��
int dequeuePush(Dequeue* qu, DataType x);

//�൱�ڵ��������ͷɾ
void dequeuePop(Dequeue* qu);

//���ض���ͷ������
DataType dequeueFront(Dequeue* qu);

//���ض���β������
DataType dequeueBack(Dequeue* qu);

//�ж϶����е������Ƿ�Ϊ��
int dequeueIsEmpty(Dequeue* qu);


//���ض��������ݸ���
size_t dequeueSize(Dequeue* qu);


#endif