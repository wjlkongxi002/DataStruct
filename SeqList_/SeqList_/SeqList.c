#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

// 初始化
void SeqListInit(SeqList* s, int initcapacity)
{
	assert(s);
	initcapacity = initcapacity <= 3 ? 3 : initcapacity;
	s->array = (SDataType*)malloc(sizeof(SDataType)* initcapacity);
	if (NULL == s->array)
		return;

	s->capacity = initcapacity;
	s->size = 0;

}

// 检查是否需要扩容
int CheckCapacity(SeqList* s)
{
	assert(s);
	if (s->capacity == s->size)
	{
		// 按两倍的方式进行扩容
		int newCapacity = s->capacity * 2;
		s->array = (SDataType*)realloc(s->array, newCapacity*sizeof(SDataType));

		if (NULL == s->array)
			return 0;

		s->capacity = newCapacity;
	}
	return 1;
}


// 尾插
// 1.不需要扩容
// 2.扩容
void SeqLiistPushBack(SeqList* s, SDataType data)
{
	assert(s);
	// 检查容量
	if (!CheckCapacity(s))  // 如果扩容失败 直接返回  表示不能插入数据
		return;
	
	s->array[s->size] = data;
	s->size++;
}

// 尾删     需要判空
void SeqListPopback(SeqList* s)
{
	if (SeqListEmpty(s))
		return;
	s->size--;
}

// 头插
// 1.先检测是否需要扩容
// 2.将元素整体搬移
// 3.起始位置插入data
void SeqListPushFront(SeqList* s, SDataType data)
{
	assert(s);
	// 检查容量
	if (!CheckCapacity(s))
		return;
	for (int i = s->size-1; i >= 0 ; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[0] = data;
	s->size++;
}

//头删   1. 判空 2.将元素整体往前搬移一个位置 
void SeqListPopFront(SeqList* s)
{
	if (SeqListEmpty(s))
		return;
	for (int i = 0; i < s->size; i++)
	{
		s->array[i-1] = s->array[i];
	}
	s->size--;
}

// 任意位置的插入
//  1.判断插入的位置是否合法
//  2.判断是否需要扩容
//  3.搬移元素进行插入
void SeqListInsert(SeqList* s, int pos, SDataType data)
{
	assert(s);
	if (pos < 0 || pos > s->size)
		return;

	if (!CheckCapacity(s))
		return;

	// 整体往后搬移pos -- size 位置的元素一个位置
	for (int i = s->size - 1; i >= pos; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[pos] = data;
	s->size++;

}


// 任意位置的删除
// 1.判断位置是否合法
// 2.搬移元素
void SeqListErase(SeqList* s, int pos)
{
	assert(s);
	if (pos < 0 || pos >= s->size)
		return;

	for (int i = pos + 1; i < s->size; i++)
	{
		s->array[i - 1] = s->array[i];
	}
	s->size--;
}

// 获取顺序表中有效元素的个数
int SeqListSzie(SeqList* s)
{
	assert(s);
	return s->size;
}

// 获取顺序表的容量
int SeqListCapacity(SeqList* s)
{
	assert(s);
	return s->capacity;
}

// 判空
int SeqListEmpty(SeqList* s) // 是空的返回0，不是返回-1
{
	assert(s);
	return 0 == s->size;
}

// 清空
void SeqListClear(SeqList *s)
{
	assert(s);
	s->size = 0;
}

// 查找值为data的元素并返回下标，否则返回-1
int SeqListFind(SeqList* s, SDataType data)
{
	assert(s);
	for (int i = 0; i < s->size; i++)
	{
		if (data == s->array[i])
			return i;
	}
	return -1;
}

// 销毁
void SeqListDestroy(SeqList* s)
{
	assert(s);
	if (s->array)  // 如果空间存在
	{
		free(s->array); // 释放申请的堆空间
		s->array = NULL;
		s->capacity = 0;
		s->size = 0;
	}
}

// 打印顺序表
void SeqListPrintf(SeqList* s)
{
	for (int i = 0; i < s->size; i++)
		printf("%d ", s->array[i]);

	printf("\n");
}


////////////////////////////////
//测试

void Test()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqLiistPushBack(&s, 1);
	SeqLiistPushBack(&s, 2);
	SeqLiistPushBack(&s, 3);
	SeqLiistPushBack(&s, 4);
	SeqLiistPushBack(&s, 5);
	//SeqListPopback(&s);
	SeqListPrintf(&s);

	SeqListInsert(&s, 5, 10);
	SeqListPrintf(&s);

	SeqListErase(&s, 2);
	SeqListPrintf(&s);
	printf("%d ",SeqListFind(&s, 5));

	SeqListDestroy(&s);



}
