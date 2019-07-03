#include "List.h"

//初始化函数
void ListInit(List* plist){
	assert(plist);
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	memset(&plist->_head->_data, 0, sizeof(LTDataType));
	plist->_head->_next = plist->_head->_prev = plist->_head;
}

//销毁,释放函数
void ListDestroy(List* plist){
	ListNode* tmp = plist->_head->_next;
	while (tmp != plist->_head){
		tmp->_next->_prev = tmp->_prev;
		tmp->_prev->_next = tmp->_next;
		free(tmp);
		tmp = plist->_head->_next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

//尾插
void ListPushBack(List* plist, LTDataType x){
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	plist->_head->_prev->_next = cur;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev = cur;
	cur->_next = plist->_head;
	
}

//尾删
void ListPopBack(List* plist){
	ListNode* tmp = plist->_head->_prev;
	if (tmp != plist->_head){
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

//头插
void ListPushFront(List* plist, LTDataType x){
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	
	plist->_head->_next->_prev = cur;
	cur->_next = plist->_head->_next;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
}

//头删
void ListPopFront(List* plist){
	ListNode* tmp = plist->_head->_next;
	if (tmp != plist->_head){
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

//打印函数
void ListPrint(List* plist){
	ListNode* cur;
	printf("head<-->");
	for (cur = plist->_head->_next; cur; cur = cur->_next){
		printf("%d<-->", cur->_data);
	}
	printf("<-->head\n");
}