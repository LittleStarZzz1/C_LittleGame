#include "Queue.h"
#include "BTree.h"

//初始化函数
void QueueInit(Queue* plist){
	assert(plist);
	plist->_head = NULL;
	plist->_rear = NULL;
}

//判断队列是否为空
int QueueIsEmpty(Queue* plist){
	return plist->_head == NULL;
}

//队列中插入数据(队列尾入)
void QueuePush(Queue* plist, QuDataType x){
	QueueNode* cur = (QueueNode*)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	if (QueueIsEmpty(plist)){
		plist->_head = plist->_rear = cur;
	}
	plist->_rear->_next = cur;
	plist->_rear = cur;
}

//删除队列中的数据(队列头出)
void QueuePop(Queue* plist){
	assert(plist);
	QueueNode* tmp;
	if (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

//返回队列头的数据
QuDataType QueueTop(Queue* plist){
	if (QueueIsEmpty(plist)){
		return (QuDataType)0;
	}
	return plist->_head->_data;
}

//对应于初始化函数，需要释放开辟的动态内存
void QueueDestory(Queue* plist){
	assert(plist);
	QueueNode* tmp;
	while (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}


