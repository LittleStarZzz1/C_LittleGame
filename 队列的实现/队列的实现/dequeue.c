#include "dequeue.h"

//初始化函数
void dequeueInit(Dequeue* qu){
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}

//销毁,释放函数
void dequeueDestroy(Dequeue* qu){
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}

//在队列中插入数据,相当于单向链表的尾插
int dequeuePush(Dequeue* qu, DataType x){
	*qu->_tail = x;
	if (qu->_tail + 1 == qu->_head ||
		(qu->_tail + 1 - qu->_data == QUEUENUM && qu->_head == qu->_data)){
		return -1;
	}
	qu->_tail++;
	if (qu->_tail - qu->_data == QUEUENUM){
		qu->_tail = qu->_head;
	}
	qu->_size++;
	return 0;
}

//相当于单向链表的头删
void dequeuePop(Dequeue* qu){
	qu->_head++;
	if (qu->_head - qu->_data == QUEUENUM){
		qu->_head = qu->_data;
	}
	qu->_size--;
}


//返回队列头的数据
DataType dequeueFront(Dequeue* qu){
	return *qu->_head;
}

//返回队列尾的数据
DataType dequeueBack(Dequeue* qu){
	if (qu->_tail == qu->_data){
		return qu->_data[QUEUENUM - 1];
	}
	return qu->_tail[-1];
}

//判断队列中的数据是否为空
int dequeueIsEmpty(Dequeue* qu){
	return qu->_head == qu->_tail;
}

//返回队列中数据个数
size_t dequeueSize(Dequeue* qu){
	return qu->_size;
}

