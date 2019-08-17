#ifndef _HEAP_H
#define _HEAP_H

typedef int HPDataType;

typedef struct Heap{
	HPDataType* data;
	int size;
	int capacity;
}Heap;

//向下调整法
void adjustDown(Heap* hp, int n);

//初始化,也就是建堆
void HeapInit(Heap* hp, HPDataType* a, int n);

//销毁函数,释放建堆时开辟的动态内存
void HeapDestory(Heap* hp);

//插入数据(向上调整法)
void HeapPush(Heap* hp, HPDataType x);

//删除堆顶的数据
void HeapPop(Heap* hp);

//返回堆顶的数据
HPDataType HeapTop(Heap* hp);

//返回堆的size大小
int HeapSize(Heap* hp);

//判断堆是否为空
int HeapEmpty(Heap* hp);


//堆排序
void HeapSort(Heap* hp);

//打印
void HeapPrint(Heap* hp);

#endif //_HEAP_H