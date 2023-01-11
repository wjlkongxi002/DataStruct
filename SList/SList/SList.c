#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// 从堆上创建一个新的节点并初始化
SListNode* BuySListNode(SLDataType data)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == NewNode)  // 新结点创建失败
	{
		assert(0);// 调试宏 参数为0 宏触发  非0 不会触发
		return NULL;
	}

	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

// 尾插 
//1. 如果链表为空，直接插入
//2. 链表非空
void SListPushBack(SListNode** head, SLDataType data)
{
	// 链表为空
	assert(head);
	SListNode* newNode = BuySListNode(data);
	if (NULL == *head)
	{
		*head = newNode;
	}
	else
	{
		// 链表非空 找到最后一个节点  然后插入
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

// 尾删
// 1.空链表
 // 2.非空
void SListpPopBack(SListNode** head)
{
	assert(head);
	if (NULL == *head) // 链表为空
		return;
	else if (NULL == (*head)->next)// 链表只有一个节点
	{
		free(*head);
		*head = NULL;
	}
	else // 链表非空
	{
		SListNode* cur = *head;
		SListNode* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		prev->next = NULL;
	}
}

// 头插  不区分链表是否为空 插入步骤一样
void SListPushFront(SListNode** head, SLDataType data)
{
	assert(head);
	SListNode* newNode = BuySListNode(data);
	newNode->next = *head;
	*head = newNode;
}

// 头删   head中保存的是头指针的地址
void SListPopFront(SListNode** head)
{
	assert(head);
	SListNode* delNode = NULL;
	// 判断是否为空链表 如果是直接返回
	if (*head = NULL)
		return;

	delNode = *head;
	*head = delNode->next;
	free(delNode);
}


// 任意位置的插入
// 考虑为什么在位置之后插入节点  因为只提供了一个位置，找不到位置前面的位置，只能往后面插
void SListInsertAfter(SListNode* pos, SLDataType data)
{
	SListNode* newNode = NULL;
	if (NULL == pos)
		return;

	// 将新节点插入pos位置之后
	newNode = BuySListNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
}

// 删除pos位置之后的节点  但pos不能是最后一个节点
void SListEraseAfter(SListNode* pos)
{
	SListNode* delNode = NULL;
	if (NULL == pos || NULL == pos->next)
		return;

	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}


// 链表的长度
int SListSize(SListNode* head)
{
	int count = 0;
	SListNode* cur = head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}


// 打印链表
void PrintfSList(SListNode* head)
{
	SListNode* cur = head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


// 查找值为data的位置
SListNode* SListFind(SListNode* head, SLDataType data)
{
	SListNode* cur = head;
	while (cur)
	{
		if (cur->data == data)
			return cur;

		cur = cur->next;
	}
	return NULL;
}



// 销毁  采用头删的思想
void SListDestroy(SListNode** head)
{
	assert(head);
	SListNode* cur = *head;
	while (cur)
	{
		*head = cur->next;
		free(cur);
		cur = *head;
	}
}


////////////////////////////////////////
// 测试
void TestSList()
{
	SListNode* listhead = NULL;
	SListPushBack(&listhead, 1);
	SListPushBack(&listhead, 2);
	SListPushBack(&listhead, 3);
	SListPushBack(&listhead, 4);
	SListPushBack(&listhead, 5);

	PrintfSList(listhead);

	//SListpPopBack(&listhead);

	SListInsertAfter(SListFind(listhead, 3), 0);

	PrintfSList(listhead);


	SListDestroy(&listhead);
}