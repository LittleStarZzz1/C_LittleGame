#ifndef _HEAP_H
#define _HEAP_H

typedef int HPDataType;

typedef struct Heap{
	HPDataType* data;
	int size;
	int capacity;
}Heap;

//���µ�����
void adjustDown(Heap* hp, int n);

//��ʼ��,Ҳ���ǽ���
void HeapInit(Heap* hp, HPDataType* a, int n);

//���ٺ���,�ͷŽ���ʱ���ٵĶ�̬�ڴ�
void HeapDestory(Heap* hp);

//��������(���ϵ�����)
void HeapPush(Heap* hp, HPDataType x);

//ɾ���Ѷ�������
void HeapPop(Heap* hp);

//���ضѶ�������
HPDataType HeapTop(Heap* hp);

//���ضѵ�size��С
int HeapSize(Heap* hp);

//�ж϶��Ƿ�Ϊ��
int HeapEmpty(Heap* hp);


//������
void HeapSort(Heap* hp);

//��ӡ
void HeapPrint(Heap* hp);

#endif //_HEAP_H