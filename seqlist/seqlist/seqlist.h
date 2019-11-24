#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h"

#define SEQLIST_DEFAULT_SIZE 8//定义容量为 8 
#define SEQLIST_INC_SIZE 5//扩容

typedef struct SeqList  //定义一个顺序表
{
	DataType *base;     //定义一个指针，是int型，指到顺序表空间
	size_t   capacity;  //无符号整形
	size_t   size;
}SeqList;

//声明
void SeqListInit(SeqList *psl, int sz);//传递变量进去，*psl表示指向顺序表的指针
bool SeqListPushBack(SeqList *psl, DataType x);
bool SeqListPushFront(SeqList *psl, DataType x);
size_t SeqListLength(SeqList *psl);
size_t SeqListCapacity(SeqList *psl);
bool SeqListModifyByPos(SeqList *psl, int pos, DataType x);
bool SeqListModifyByVal(SeqList *psl, DataType key, DataType x);

bool SeqListPopBack(SeqList *psl);
bool SeqListPopFront(SeqList *psl);
bool SeqListInsertByPos(SeqList *psl, int pos, DataType x);
bool SeqListInsertByVal(SeqList *psl, DataType x);
void SeqListClear(SeqList *psl);
void SeqListDestroy(SeqList *psl);
bool SeqListFindByPos(SeqList *psl, int pos, DataType *ret);
int  SeqListFindByVal(SeqList *psl, DataType key);

bool SeqListDeleteByPos(SeqList *psl, int pos);
bool SeqListDeleteByVal(SeqList *psl, DataType key);


void SeqListSort(SeqList *psl);
void SeqListReverse(SeqList *psl);


bool SeqListIsFull(SeqList *psl)
{
	return psl->size >= psl->capacity;
}
bool SeqListIsEmpty(SeqList *psl)
{
	return psl->size == 0;
}

bool _SeqListInc(SeqList *psl)//扩容
{
	assert(psl != NULL);
	psl->base = realloc(psl->base, sizeof(DataType)*(psl->capacity + SEQLIST_INC_SIZE));
	if (psl->base == NULL)
		return false;
	psl->capacity += SEQLIST_INC_SIZE;//修改容量的前提是，先扩容成功
	return true;
}

//实现
//void SeqListInit(SeqList *psl, int sz)
//{
//	psl->capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
//	psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacity));//空间开辟，将地址给base
//	psl->size = 0;
//}
void SeqListInit(SeqList *psl, int sz)//初始化
{
	psl->capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
	psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacity));
	psl->size = 0;
}


bool SeqListPushBack(SeqList *psl, DataType x)//头插
{
	assert(psl != NULL);
	if (SeqListIsFull(psl) && !_SeqListInc(psl))//???(psl)
	{
		printf("push_back:顺序表已满, %d 不能插入.\n", x);
		return false;
	}
	psl->base[psl->size++] = x;
	return true;
}

bool SeqListPushFront(SeqList *psl, DataType x)
{
	assert(psl != NULL);
	if (SeqListIsFull(psl) && !_SeqListInc(psl))
	{
		printf("push_front:顺序表已满, %d 不能插入.\n", x);
		return false;
	}
	for (int i = psl->size; i>0; --i)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[0] = x;
	psl->size++;
	return true;
}

void SeqListShow(SeqList *psl)//打印元素
{
	for (int i = 0; i<psl->size; ++i)
	{
		printf("%d ", psl->base[i]);
	}
	printf("\n");
}

size_t SeqListLength(SeqList *psl)
{
	assert(psl != NULL);
	return psl->size;
}
size_t SeqListCapacity(SeqList *psl)
{
	assert(psl != NULL);
	return psl->capacity;
}

bool SeqListPopBack(SeqList *psl)//尾删
{
	assert(psl != NULL);
	if (SeqListIsEmpty(psl))
	{
		printf("顺序表已空，不能尾删.\n");
		return false;
	}
	psl->size--;
	return true;
}

bool SeqListPopFront(SeqList *psl)//头删，覆盖
{
	assert(psl != NULL);
	if (SeqListIsEmpty(psl))
	{
		printf("顺序表已空，不能头删.\n");
		return false;
	}

	for (int i = 0; i<psl->size - 1; ++i)
	{
		psl->base[i] = psl->base[i + 1];
	}
	psl->size--;
	return true;
}

bool SeqListInsertByPos(SeqList *psl, int pos, DataType x)//按位置插入
{                                       //函数参数的有效性判断
	assert(psl != NULL);
	if (SeqListIsFull(psl) && !_SeqListInc(psl))
	{
		printf("insert_pos:顺序表已满, %d 不能插入.\n", x);
		return false;
	}
	if (pos<0 || pos>psl->size)
	{
		printf("插入的位置不合法.\n");
		return false;
	}
	for (int i = psl->size; i>pos; --i)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[pos] = x;
	psl->size++;
	return true;
}

bool SeqListInsertByVal(SeqList *psl, DataType x)//按值插入（从后往前，比一次移一次）
{
	assert(psl != NULL);
	if (SeqListIsFull(psl) && !_SeqListInc(psl))
	{
		printf("insert_val:顺序表已满, %d 不能插入.\n", x);
		return false;
	}
	int i;
	for (i = psl->size - 1; i >= 0 && x<psl->base[i]; --i)
	{
		psl->base[i + 1] = psl->base[i];
	}
	psl->base[i + 1] = x;
	psl->size++;
	return true;
}

void SeqListClear(SeqList *psl)//清除，
{
	assert(psl != NULL);
	psl->size = 0;
}
void SeqListDestroy(SeqList *psl)//摧毁，清除数据，数据表也会被摧毁
{
	free(psl->base);
	psl->base = NULL;//预防野指针
	psl->capacity = psl->size = 0;
}

bool SeqListFindByPos(SeqList *psl, int pos, DataType *ret)//按位置查找
{
	assert(psl != NULL);
	if (pos<0 || pos>psl->size - 1)
	{
		printf("要查找的位置不合法.\n");
		return false;
	}
	*ret = psl->base[pos];
	return true;
}

int SeqListFindByVal(SeqList *psl, DataType key)//按值查找
{
	assert(psl != NULL);
	for (int i = 0; i<psl->size; ++i)
	{
		if (psl->base[i] == key)
			return i;
	}
	return -1;
}

bool SeqListModifyByPos(SeqList *psl, int pos, DataType x)//按位置修改
{
	assert(psl != NULL);
	if (pos<0 || pos>psl->size - 1)
	{
		printf("修改的位置不合法.\n");
		return false;
	}
	psl->base[pos] = x;
	return true;
}

bool SeqListModifyByVal(SeqList *psl, DataType key, DataType x)//按值修改
{
	int index = SeqListFindByVal(psl, key);//查找数据
	if (index == -1)
		return false;
	psl->base[index] = x;
	return true;
}

bool SeqListDeleteByPos(SeqList *psl, int pos)//按位置删除
{
	assert(psl != NULL);
	if (pos<0 || pos>psl->size - 1)
	{
		printf("要查找的位置不合法.\n");
		return false;
	}
	for (int i = pos; i<psl->size - 1; ++i)
	{
		psl->base[i] = psl->base[i + 1];
	}
	psl->size--;
	return true;
}
bool SeqListDeleteByVal(SeqList *psl, DataType key)//按值删除
{
	assert(psl != NULL);
	int index = SeqListFindByVal(psl, key);
	if (index == -1)
	{
		printf("要删除的数据不存在.\n");
		return false;
	}
	return SeqListDeleteByPos(psl, index);
}

void SeqListSort(SeqList *psl)//排序
{
	for (int i = 0; i<psl->size - 1; ++i)
	{
		for (int j = 0; j<psl->size - i - 1; ++j)
		{
			if (psl->base[j] > psl->base[j + 1])
			{
				Swap(&(psl->base[j]), &(psl->base[j + 1]));
			}
		}
	}
}

void SeqListReverse(SeqList *psl)//转置
{
	assert(psl != NULL);
	int begin = 0;
	int end = psl->size - 1;
	while (begin < end)
	{
		Swap(&(psl->base[begin]), &(psl->base[end]));
		begin++;
		end--;
	}
}
#endif 