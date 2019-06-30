#include "slist.h"

//初始化函数
void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

//销毁，释放动态内存
void SListDestory(SList* plist)
{
	SListNode * tmp;
	while (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

//头插
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}

//头删
void SListPopFront(SList* plist)
{
	assert(plist);

	SListNode * tmp;
	if (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

//打印函数
void SListPrint(SList* plist)
{
	assert(plist);

	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}

//查找某个数据对应的节点
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode * cur;

	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}
//前插示范
void SListInsertFront(SList* plist, SLTDataType x, SLTDataType src)
{
	assert(plist);
	SListNode * cur;
	SListNode * newdata = (SListNode *)malloc(sizeof(SListNode));

	if (plist->_head->_data == x)
	{
		SListPushFront(plist, src);
		return;
	}
	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next->_data == x)
		{
			break;
		}
	}
	newdata->_data = src;
	newdata->_next = cur->_next;
	cur->_next = newdata;
}

//在pos位置后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}

//在pos位置后面进行删除
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode * tmp = pos->_next;

	pos->_next = tmp->_next;
	free(tmp);
}

