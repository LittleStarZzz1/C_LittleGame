#ifndef _SORT_H
#define _SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"

//²åÈëÅÅĞò
void InsertSort(int* src, int n);

//Ï£¶ûÅÅĞò
void shellSort(int * src, int n);

//¹é²¢ÅÅĞò
//void dealMergeSort(int* src, int* tmp, int start, int end);
void MergeSort(int* src, int n);

//¶ÑÅÅĞò
//void adjustDown(int* src, int n, int m);
//void swapHeap(int* src, int n);
void heapSort(int* src, int n);

//Ã°ÅİÅÅĞò
void BabbleSort(int* src, int n);

//¿ìËÙÅÅĞò
void QuickSort(int* src, int n);
//·Çµİ¹é°æµÄ¿ìËÙÅÅĞò
void QuickSortNonR(int* src, int n);



#endif //_SORT_H