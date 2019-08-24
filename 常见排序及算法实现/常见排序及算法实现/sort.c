#include "sort.h"

//插入排序
void InsertSort(int* src, int n){
	int i, j;
	int tmp;
	for (i = 1; i < n; ++i){
		tmp = src[i];
		for (j = i; j > 0 && src[j - 1] > tmp; --j){
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}

//希尔排序
void shellSort(int* src, int n){
	int i, j, k;
	int gap;
	int tmp;
	for (gap = n / 2; gap; gap /= 2){
		for (k = 0; k < gap; ++k){
			//插入排序
			for (i = gap + k; i < n; i += gap){
				tmp = src[i];
				for (j = i; j >= gap && src[j - gap] > tmp; j -= gap){
					src[j] = src[j - gap];
				}
				src[j] = tmp;
			}
		}
	}
}

//归并排序
void dealMergeSort(int* src, int* tmp, int start, int end){
	if (start >= end){
		return;
	}

	int mid = (start + end) / 2;
	dealMergeSort(src, tmp, start, mid);
	dealMergeSort(src, tmp, mid + 1, end);

	int a = start;
	int b = mid + 1;
	int c = start;


	while (a <= mid && b <= end){
		if (src[a] > src[b]){
			tmp[c] = src[b];
			++b;
		}
		else {
			tmp[c] = src[a];
			++a;
		}
		++c;
	}
	for (; a <= mid; ++a, ++c){
		tmp[c] = src[a];
	}
	for (; b <= end; ++b, ++c){
		tmp[c] = src[b];
	}
	int i;
	for (i = start; i <= end; ++i){
		src[i] = tmp[i];
	}
}

void MergeSort(int* src, int n){
	
	int* tmp = (int*)malloc(n * sizeof(int));

	dealMergeSort(src, tmp, 0, n - 1);

	free(tmp);
}

//堆排序
//堆排序需要用到向下调整法(将数据调整为堆)
void adjustDown(int* src, int n, int m){
	int cur = m;

	while (cur * 2 + 1 < n){
		if (cur * 2 + 2 >= n){
			m = cur * 2 + 1;
		}
		else {
			if (src[cur * 2 + 1] > src[cur * 2 + 2]){
				m = cur * 2 + 1;
			}
			else {
				m = cur * 2 + 2;
			}
		}
		if (src[cur] < src[m]){
			int tmp = src[cur];
			src[cur] = src[m];
			src[m] = tmp;
			cur = m;
		}
		else {
			break;
		}
	}
}
//堆排序
void swapHeap(int* src, int n){
	if (n == 0){
		return;
	}
	int tmp = src[0];
	src[0] = src[n - 1];
	src[n - 1] = tmp;
	adjustDown(src, n - 1, 0);
}
//对数据进行堆排序
void heapSort(int* src, int n){
	//分两步
	//第一步,将数组中数据调整成堆
	int i;
	for (i = n / 2 - 1; i >= 0; --i){
		adjustDown(src, n, i);
	}
	//第二步,进行堆排序,对数组中的数据进行排序
	for (; n > 1; --n){
		swapHeap(src, n);
	}
}

//冒泡排序
void BabbleSort(int* src, int n){
	int i, j;
	for (i = 0; i < n - 1; ++i){
		for (j = 0; j < n - 1 - i; ++j){
			if (src[j] > src[j + 1]){
				int tmp = src[j];
				src[j] = src[j + 1];
				src[j + 1] = tmp;
			}
		}
	}
}

//快速排序
//双指针法(将数组中第一个元素当做基准)
void swapArgs(int* pa, int* pb){
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
int doublePointerWay1(int* src, int start, int end){
	int a = start, b = end;
	int flag = 0;
	

	while (src[a] < src[b]){
		b--;
	}

	while (a < b){
		swapArgs(src + a, src + b);
		flag = !flag;

		while (a <= end && b >= 0 && src[b] >= src[a]){	//如果此处没有等于号,会变成死循环,两个相同的数一直在不停的交换
			flag ? a++ : b--;
		}
	}
	return flag ? b : a;
}
//双指针的第二种做法,(取数组中的中间元素作为基准)
int doublePointerWay2(int* src, int start, int end){
	int a = start, b = end - 1;
	int mid = (start + end) / 2;

	swapArgs(src + mid, src + end);	//将中间元素保护起来(与末尾元素交换)

	while (a <= b){
		while (a < end && src[a] <= src[end]){
			a++;	//从左边找大于的src[end]的数
		}
		while (b > 0 && src[b] >= src[end]){
			b--;	//从右边找小于src[end]的数
		}
		if (a == b && (a == 0 || a == end)){
			break;
		}
		if (a < b){
			swapArgs(src + a, src + b);
		}
	}
	swapArgs(src + a, src + end);
	return a;
}
//挖坑法
int digWay(int* src, int start, int end){
	int a = start, b = end;
	int flag = 0;
	int tmp = src[start];

	while (1){
		while (src[b] >= tmp){
			b--;
		}
		if (a < b){
			src[a] = src[b];
		}
		else {
			src[a] = tmp;
			return a;
		}
		while (src[a] <= tmp){
			a++;
		}
		if (a < b){
			src[b] = src[a];
		}
		else {
			src[b] = tmp;
			return b;
		}
	}
}
//Hoare法(三数取中法)
int HoareWay(int* src, int start, int end){
	int a = start + 1, b = end - 2;
	int mid = (start + end) / 2;

	if (src[start] > src[mid]){
		swapArgs(src + start, src + mid);
	}
	if (src[mid] > src[end]){
		swapArgs(src + mid, src + end);
	}
	if (src[start] > src[mid]){
		swapArgs(src + start, src + mid);
	}
	if (end - start <= 2){
		return mid;
	}
	swapArgs(src + mid, src + end - 1);

	while (a <= b){
		while (a < end - 1 && src[a] <= src[end - 1]){
			a++;	//从左边找大于的src[end - 1]的数
		}
		while (b > 1 && src[b] >= src[end - 1]){
			b--;	//从右边找小于src[end - 1]的数
		}
		if (a == b && (a == start + 1 || a == end - 2)){
			break;
		}
		if (a < b){
			swapArgs(src + a, src + b);
		}
	}
	swapArgs(src + a, src + end - 1);
	return a;
}
void dealQuickSort(int* src, int start, int end){
	int mid;
	if (start + 8 < end){
		//mid = doublePointerWay2(src, start, end);
		//mid = digWay(src, start, end);
		mid = HoareWay(src, start, end);
		dealQuickSort(src, start, mid - 1);
		dealQuickSort(src, mid + 1, end);
	}
	else {
		InsertSort(src + start, end - start + 1);
	}
}
void QuickSort(int* src, int n){
	dealQuickSort(src, 0, n - 1);
}

//非递归版的快速排序
void QuickSortNonR(int* src, int n){
	
	int start, end;
	int mid;

	Queue qu;

	QueueInit(&qu);

	QueuePush(&qu, 0);
	QueuePush(&qu, n - 1);

	while (!QueueIsEmpty(&qu)){
		start = QueueTop(&qu);
		QueuePop(&qu);
		end = QueueTop(&qu);
		QueuePop(&qu);
		mid = HoareWay(src, start, end);

		if (start < mid - 1){
			QueuePush(&qu, start);
			QueuePush(&qu, mid - 1);
		}
		if (mid + 1 < end){
			QueuePush(&qu, mid + 1);
			QueuePush(&qu, end);
		}
	}
	QueueDestory(&qu);
}



