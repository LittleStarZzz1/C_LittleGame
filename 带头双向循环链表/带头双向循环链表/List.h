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

//初始化函数
void ListInit(List* plist);
//销毁,释放函数
void ListDestroy(List* plist);

//尾插
void ListPushBack(List* plist, LTDataType x);
//尾删
void ListPopBack(List* plist);

//头插
void ListPushFront(List* plist, LTDataType x);
//头删
void ListPopFront(List* plist);

//查找对应数据的节点
ListNode* ListFind(List* plist, LTDataType x);

//在pos位置的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);

//删除pos位置的节点
void ListErase(ListNode* pos);

//打印函数
void ListPrint(List* plist);


#endif //_LIST_H