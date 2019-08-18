#include "Queue.h"
#include "BTree.h"

//��ʼ������
void QueueInit(Queue* plist){
	assert(plist);
	plist->_head = NULL;
	plist->_rear = NULL;
}

//�ж϶����Ƿ�Ϊ��
int QueueIsEmpty(Queue* plist){
	return plist->_head == NULL;
}

//�����в�������(����β��)
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

//ɾ�������е�����(����ͷ��)
void QueuePop(Queue* plist){
	assert(plist);
	QueueNode* tmp;
	if (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

//���ض���ͷ������
QuDataType QueueTop(Queue* plist){
	if (QueueIsEmpty(plist)){
		return (QuDataType)0;
	}
	return plist->_head->_data;
}

//��Ӧ�ڳ�ʼ����������Ҫ�ͷſ��ٵĶ�̬�ڴ�
void QueueDestory(Queue* plist){
	assert(plist);
	QueueNode* tmp;
	while (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}


