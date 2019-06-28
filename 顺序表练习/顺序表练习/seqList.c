#include "seqList.h"

//��ʼ��
void SeqListInit(SeqList* psl, size_t capicity)
{
	assert(psl);

	psl->capicity = capicity;
	psl->array = (SLDataType *)malloc(capicity * sizeof(SLDataType));
	assert(psl->array);

	psl->size = 0;
}

//�ͷ����ٺ���
void SeqListDestory(SeqList* psl)
{
	assert(psl);

	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capicity = 0;
	}
}

//����Ƿ�����
void CheckCapacity(SeqList* psl)
{
	assert(psl);

	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capicity * sizeof(SLDataType));
	}
}

//β��,��������ʱ�ǵü���Ƿ���Ҫ����
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);

	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}

//βɾ
void SeqListPopBack(SeqList* psl)
{
	assert(psl || psl->size);

	psl->size--;
}

//ͷ��,��������ʱ�ǵü���Ƿ���Ҫ����
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);

	CheckCapacity(psl);

	int i;
	for (i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}

//ͷɾ
void SeqListPopFront(SeqList* psl)
{
	assert(psl);

	psl->size--;
	int i;
	for (i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}

//���Һ���,�ҵ��󷵻ض�Ӧ�±�
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int i;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//���뺯��
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos <= psl->size);

	CheckCapacity(psl);

	int i;
	for (i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

//ɾ����Ӧλ������
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl || pos < psl->size);

	psl->size--;
	int i;
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}

//��ն�Ӧ����
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);

	int pos = SeqListFind(psl, x);
	if (pos >= 0)
	{
		SeqListErase(psl, pos);
	}
}

//�޸Ķ�Ӧλ������
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos < psl->size);
	psl->array[pos - 1] = x;
}

//��ӡ����
void SeqListPrint(SeqList* psl)
{
	assert(psl);

	int i;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

//ð������
void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);

	int i, j;
	SLDataType tmp;

	for (i = 0; i < psl->size - 1; i++)
	{
		for (j = 0; j < psl->size - 1 - i; j++)
		{
			if (psl->array[j] > psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}

//���ֲ���,�ҵ��󷵻��±�
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int left = 0;
	int right = psl->size - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (psl->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->array[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

