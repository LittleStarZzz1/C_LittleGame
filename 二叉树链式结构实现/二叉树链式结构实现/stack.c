#include "stack.h"
#include "BTree.h"

//初始化
void StackInit(Stack* psl, size_t capicity)
{
	assert(psl);

	psl->capicity = capicity;
	psl->array = (StDataType *)malloc(capicity * sizeof(StDataType));
	assert(psl->array);

	psl->size = 0;
}

//释放销毁函数
void StackDestory(Stack* psl)
{
	assert(psl);

	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capicity = 0;
	}
}

//检查是否扩容
void CheckCapacity(Stack* psl)
{
	assert(psl);

	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (StDataType *)realloc(psl->array, psl->capicity * sizeof(StDataType));
	}
}

//尾插,插入数据时记得检查是否需要扩容
void StackPush(Stack* psl, StDataType x)
{
	assert(psl);

	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}

//尾删
void StackPop(Stack* psl)
{
	assert(psl || psl->size);

	psl->size--;
}


//判断栈是否为空
int StackIsEmpty(Stack* psl){
	return psl->size == 0;
}

//返回栈顶数据
StDataType StackTop(Stack* psl){
	if (StackIsEmpty(psl)){
		return (StDataType)0;
	}
	return psl->array[psl->size - 1];
}

