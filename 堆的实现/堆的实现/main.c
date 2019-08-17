#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main1(){
	int data[10] = { 29, 72, 48, 53, 45, 30, 18, 36, 15, 35 };
	Heap hp;

	HeapInit(&hp, data, 10);

	HeapPrint(&hp);

	adjustDown(&hp, 0);
	putchar('\n');
	HeapPrint(&hp);
	
	HeapDestory(&hp);
	system("pause");
	return 0;
}