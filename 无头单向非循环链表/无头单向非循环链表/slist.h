#ifndef _SLIST_H
#define _SLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int SLTDataType;

typedef struct SListNode{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList{
	SListNode* _head;
}SList;

//��ʼ������
void SListInit(SList* plist);

//�ͷſ��ٵĶ�̬�ڴ�,���ٺ���
void SListDestory(SList* plist);

//ͷ��
void SListPushFront(SList* plist, SLTDataType x);
//ͷɾ
void SListPopFront(SList* plist);

//���Ҷ�Ӧ���ݵ�����
SListNode* SListFind(SList* plist, SLTDataType x);

//��posλ�ú�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x);
//��posλ�ú������ɾ��
void SListEraseAfter(SListNode* pos);

//��ӡ����
void SListPrint(SList* plist);

#endif	//_SLIST_H
