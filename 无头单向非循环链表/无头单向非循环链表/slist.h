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

//初始化函数
void SListInit(SList* plist);

//释放开辟的动态内存,销毁函数
void SListDestory(SList* plist);

//头插
void SListPushFront(SList* plist, SLTDataType x);
//头删
void SListPopFront(SList* plist);

//查找对应数据的链表
SListNode* SListFind(SList* plist, SLTDataType x);

//在pos位置后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
//在pos位置后面进行删除
void SListEraseAfter(SListNode* pos);

//打印函数
void SListPrint(SList* plist);

#endif	//_SLIST_H
