#pragma once


// 一般讨论无头结点的单链表

typedef int SLDataType;

typedef struct SListNode // 定义一个节点 
{
	struct SListNode* next; // 指向下一个节点地址的指针
	SLDataType data; // 节点中存放的数据
}SListNode;


// 如果在函数中改变头指针的指向，形参必须为二级指针 例如：插入删除操作
// 不需要改变函数中头指针的指向，只需传递一级指针即可，例如查找操作
void SListPushBack(SListNode** head, SLDataType data);
void SListpPopBack(SListNode** head);
void SListPushFront(SListNode** head, SLDataType data);
void SListPopFront(SListNode** head);

void SListInsertAfter(SListNode* pos, SLDataType data);
void SListEraseAfter(SListNode* pos);

int SListSize(SListNode* head);
int SLiztEmpty(SListNode* head);

void PrintfSList(SListNode* head);

SListNode* SListFind(SListNode* head, SLDataType data);

void SListDestroy(SListNode** head);

/////////////////////////////////
void TestSList();