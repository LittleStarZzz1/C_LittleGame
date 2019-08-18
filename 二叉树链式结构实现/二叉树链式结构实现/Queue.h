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

//初始化函数
void QueueInit(Queue* plist);

//对应于初始化函数，需要释放开辟的动态内存
void QueueDestory(Queue* plist);

//队列中插入数据(队列头)
void QueuePush(Queue* plist, QuDataType x);
//删除队列中的数据(队列尾)
void QueuePop(Queue* plist);

//返回队列头的数据
QuDataType QueueTop(Queue* plist);

//判断队列是否为空
int QueueIsEmpty(Queue* plist);

//打印链表
void QueuePrint(Queue* plist);


#endif //_Queue_H