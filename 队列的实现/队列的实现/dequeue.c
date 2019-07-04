#include "dequeue.h"

//��ʼ������
void dequeueInit(Dequeue* qu){
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}

//����,�ͷź���
void dequeueDestroy(Dequeue* qu){
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}

//�ڶ����в�������,�൱�ڵ��������β��
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

//�൱�ڵ��������ͷɾ
void dequeuePop(Dequeue* qu){
	qu->_head++;
	if (qu->_head - qu->_data == QUEUENUM){
		qu->_head = qu->_data;
	}
	qu->_size--;
}


//���ض���ͷ������
DataType dequeueFront(Dequeue* qu){
	return *qu->_head;
}

//���ض���β������
DataType dequeueBack(Dequeue* qu){
	if (qu->_tail == qu->_data){
		return qu->_data[QUEUENUM - 1];
	}
	return qu->_tail[-1];
}

//�ж϶����е������Ƿ�Ϊ��
int dequeueIsEmpty(Dequeue* qu){
	return qu->_head == qu->_tail;
}

//���ض��������ݸ���
size_t dequeueSize(Dequeue* qu){
	return qu->_size;
}

