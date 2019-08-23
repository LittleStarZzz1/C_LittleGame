#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define BUFSIZE 10000

void printArray(int* src, int n){
	int i;

	for (i = 0; i < n; ++i){
		//if (src[i + 1] - src[i] < 0){
			printf("%d ", src[i]);
		//}
	}
	putchar('\n');
}

int main(){

#if 1
	//int src[10] = { 3, 1, 6, 7, 9, 2, 4, 8, 10, 5 };
	int src[11] = { 1, 3, 6, 7, 9, 2, 4, 8, 10, 5, 11 };

	//InsertSort(src, 10);

	//shellSort(src, 10);

	//MergeSort(src, 10);

	//heapSort(src, 10);

	//BabbleSort(src, 10);

	QuickSort(src, 11);
	
	printArray(src, 11);

#else
	srand((unsigned int)time(NULL));

	int src[BUFSIZE];
	int i;
	for (i = 0; i < BUFSIZE; ++i){
		src[i] = rand() % 5000 + 1;
	}

	//InsertSort(src, BUFSIZE);

	//shellSort(src, BUFSIZE);

	//MergeSort(src, BUFSIZE);

	//heapSort(src, BUFSIZE);

	//BabbleSort(src, BUFSIZE);

	QuickSort(src, BUFSIZE);
	
	printArray(src, BUFSIZE);
#endif
	system("pause");
	return 0;
}