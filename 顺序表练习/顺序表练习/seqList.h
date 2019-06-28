#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList {
	SLDataType* array;	// 指向动态开辟的数组
	size_t size;		// 有效数据个数
	size_t capicity;	// 容量空间的大小
}SeqList;

// 基本增删查改接口
//初始化
void SeqListInit(SeqList* psl, size_t capacity);
//释放,销毁函数
void SeqListDestory(SeqList* psl);

//检查是否扩容
void CheckCapacity(SeqList* psl);
//尾插
void SeqListPushBack(SeqList* psl, SLDataType x);
//尾删
void SeqListPopBack(SeqList* psl);
//头插
void SeqListPushFront(SeqList* psl, SLDataType x);
//头删
void SeqListPopFront(SeqList* psl);

//查找函数,找到后返回下标
int SeqListFind(SeqList* psl, SLDataType x);
//插入函数
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
//删除对应位置数据
void SeqListErase(SeqList* psl, size_t pos);
//清空对应位置数据
void SeqListRemove(SeqList* psl, SLDataType x);
//修改对应位置数据
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
//打印函数
void SeqListPrint(SeqList* psl);

//冒泡排序
void SeqListBubbleSort(SeqList* psl);
//二分查找,找到后返回下标
int SeqListBinaryFind(SeqList* psl, SLDataType x);

#endif //_SEQLIST_H_