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

//初始化函数
void dequeueInit(Dequeue* qu);

//销毁函数
void dequeueDestroy(Dequeue* qu);

//在队列中插入数据,相当于单向链表的尾插
int dequeuePush(Dequeue* qu, DataType x);

//相当于单向链表的头删
void dequeuePop(Dequeue* qu);

//返回队列头的数据
DataType dequeueFront(Dequeue* qu);

//返回队列尾的数据
DataType dequeueBack(Dequeue* qu);

//判断队列中的数据是否为空
int dequeueIsEmpty(Dequeue* qu);


//返回队列中数据个数
size_t dequeueSize(Dequeue* qu);


#endif