#ifndef _SORT_H
#define _SORT_H

//��������
void InsertSort(int* src, int n);

//ϣ������
void shellSort(int * src, int n);

//�鲢����
//void dealMergeSort(int* src, int* tmp, int start, int end);
void MergeSort(int* src, int n);

//������
//void adjustDown(int* src, int n, int m);
//void swapHeap(int* src, int n);
void heapSort(int* src, int n);

//ð������
void BabbleSort(int* src, int n);

//��������
void QuickSort(int* src, int n);



#endif //_SORT_H