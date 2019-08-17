#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//向下调整法
void adjustDown(Heap* hp, int n){	//n是要执行向下调整的节点
	int	cur = n;
	
	while (cur * 2 + 1 < hp->size){
		if (cur * 2 + 2 >= hp->size){
			n = cur * 2 + 1;
		}
		else {
			if (hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2]){
				n = cur * 2 + 1;
			}
			else {
				n = cur * 2 + 2;
			}
		}
		if (hp->data[cur] < hp->data[n]){
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[n];
			hp->data[n] = tmp;
			cur = n;
		}
		else {
			break;
		}
	}
}

//初始化,也就是建堆
void HeapInit(Heap* hp, HPDataType* a, int n){
	hp->capacity = n * 2;
	hp->size = n;
	hp->data = (HPDataType*)calloc(hp->capacity, sizeof(HPDataType));
	int i;
	for (i = 0; i < n; ++i){
		hp->data[i] = a[i];
	}
	for (i = n / 2 - 1; i >= 0; --i){
		adjustDown(hp, i);	//对每个节点进行向下调整
	}
}

//插入数据(向上调整法)
void HeapPush(Heap* hp, HPDataType x){
	if (hp->size == hp->capacity){
		hp->capacity *= 2;
		hp->data = (HPDataType*)realloc(hp->data, hp->capacity * sizeof(HPDataType));
	}
	hp->data[hp->size] = x;
	hp->size++;

	int cur = hp->size;
	while (cur > 0){
		if (hp->data[cur] > hp->data[(cur - 1) / 2]){	//与父亲节点进行比较
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[(cur - 1) / 2];
			hp->data[(cur - 1) / 2] = tmp;

			cur = (cur - 1) / 2;	//交换完成后更新cur的值
		}
		else {
			break;
		}
	}
}

//删除堆顶的数据
void HeapPop(Heap* hp){
	if (hp->size == 0){
		return;
	}

	hp->size--;
	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];
	hp->data[hp->size] = tmp;	//为了方便后面的堆排序写成这样
	adjustDown(hp, 0);
}

//返回堆顶的数据
HPDataType HeapTop(Heap* hp){
	if (hp->size == 0){
		return (HPDataType)0;
	}
	return hp->data[0];
}

//返回堆的size大小
int HeapSize(Heap* hp){
	return hp->size;
}

//判断堆是否为空
int HeapEmpty(Heap* hp){
	return hp->size == 0;
}

//销毁函数,释放建堆时开辟的动态内存
void HeapDestory(Heap* hp){
	if (hp->data){
		free(hp->data);
	}
	hp->data = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

//堆排序
void HeapSort(Heap* hp){
	int tmp = hp->size;
	while (hp->size > 1){
		HeapPop(hp);
	}
	hp->size = tmp;
}

//打印
void HeapPrint(Heap* hp){
	int i;
	int rn = 0;
	int bin = 2;
	for (i = 0; i < hp->size; ++i){
		printf("%d ", hp->data[i]);
		if (i == rn){
			putchar('\n');
			rn += bin;
			bin = bin * 2;
		}
	}
}