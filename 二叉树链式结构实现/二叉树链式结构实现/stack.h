#ifndef _Stack_H_
#define _Stack_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BTree.h"


typedef BTNode* StDataType;

typedef struct Stack {
	StDataType* array;	// 指向动态开辟的数组
	size_t size;		// 有效数据个数
	size_t capicity;	// 容量空间的大小
}Stack;

// 基本增删查改接口
//初始化
void StackInit(Stack* psl, size_t capacity);
//释放,销毁函数
void StackDestory(Stack* psl);

//检查是否扩容
void CheckCapacity(Stack* psl);
//尾插
void StackPush(Stack* psl, StDataType x);
//尾删
void StackPop(Stack* psl);

//返回栈顶数据
StDataType StackTop(Stack* psl);

//判断栈是否为空
int StackIsEmpty(Stack* psl);

#endif //_Stack_H_