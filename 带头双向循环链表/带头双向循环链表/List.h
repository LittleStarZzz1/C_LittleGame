#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List{
	ListNode* _head;
}List;

//��ʼ������
void ListInit(List* plist);
//����,�ͷź���
void ListDestroy(List* plist);

//β��
void ListPushBack(List* plist, LTDataType x);
//βɾ
void ListPopBack(List* plist);

//ͷ��
void ListPushFront(List* plist, LTDataType x);
//ͷɾ
void ListPopFront(List* plist);

//���Ҷ�Ӧ���ݵĽڵ�
ListNode* ListFind(List* plist, LTDataType x);

//��posλ�õ�ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);

//ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);

//��ӡ����
void ListPrint(List* plist);


#endif //_LIST_H