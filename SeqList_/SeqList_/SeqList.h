#pragma once

typedef int SDataType;

// 定义一个结构体变量
typedef struct SeqList
{
	SDataType* array; // 存放元素的数组空间 
	int capacity;  // 空间的容量
	int size; // 有效元素的个数
}SeqList;

// 初始化
void SeqListInit(SeqList* s, int initcapacity);

// 尾插
void SeqLiistPushBack(SeqList* s, SDataType data);

// 尾删
void SeqListPopback(SeqList* s);

// 头插
void SeqListPushFront(SeqList* s, SDataType data);

//头删
void SeqListPopFront(SeqList* s);

// 任意位置的插入
void SeqListInsert(SeqList* s, int pos, SDataType data);


// 任意位置的删除
void SeqListErase(SeqList* s, int pos);

// 获取顺序表中有效元素的个数
int SeqListSzie(SeqList* s);

// 获取顺序表的容量
int SeqListCapacity(SeqList* s);

// 判空
int SeqListEmpty(SeqList* s);

// 清空
void SeqListClear(SeqList *s);

// 查找值为data的元素并返回下标，否则返回-1
int SeqListFind(SeqList* s, SDataType data);

// 销毁
void SeqListDestroy(SeqList* s);
