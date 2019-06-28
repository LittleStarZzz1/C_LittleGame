#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList {
	SLDataType* array;	// ָ��̬���ٵ�����
	size_t size;		// ��Ч���ݸ���
	size_t capicity;	// �����ռ�Ĵ�С
}SeqList;

// ������ɾ��Ľӿ�
//��ʼ��
void SeqListInit(SeqList* psl, size_t capacity);
//�ͷ�,���ٺ���
void SeqListDestory(SeqList* psl);

//����Ƿ�����
void CheckCapacity(SeqList* psl);
//β��
void SeqListPushBack(SeqList* psl, SLDataType x);
//βɾ
void SeqListPopBack(SeqList* psl);
//ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x);
//ͷɾ
void SeqListPopFront(SeqList* psl);

//���Һ���,�ҵ��󷵻��±�
int SeqListFind(SeqList* psl, SLDataType x);
//���뺯��
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
//ɾ����Ӧλ������
void SeqListErase(SeqList* psl, size_t pos);
//��ն�Ӧλ������
void SeqListRemove(SeqList* psl, SLDataType x);
//�޸Ķ�Ӧλ������
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
//��ӡ����
void SeqListPrint(SeqList* psl);

//ð������
void SeqListBubbleSort(SeqList* psl);
//���ֲ���,�ҵ��󷵻��±�
int SeqListBinaryFind(SeqList* psl, SLDataType x);

#endif //_SEQLIST_H_