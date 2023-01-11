#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// �Ӷ��ϴ���һ���µĽڵ㲢��ʼ��
SListNode* BuySListNode(SLDataType data)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == NewNode)  // �½�㴴��ʧ��
	{
		assert(0);// ���Ժ� ����Ϊ0 �괥��  ��0 ���ᴥ��
		return NULL;
	}

	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

// β�� 
//1. �������Ϊ�գ�ֱ�Ӳ���
//2. ����ǿ�
void SListPushBack(SListNode** head, SLDataType data)
{
	// ����Ϊ��
	assert(head);
	SListNode* newNode = BuySListNode(data);
	if (NULL == *head)
	{
		*head = newNode;
	}
	else
	{
		// ����ǿ� �ҵ����һ���ڵ�  Ȼ�����
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

// βɾ
// 1.������
 // 2.�ǿ�
void SListpPopBack(SListNode** head)
{
	assert(head);
	if (NULL == *head) // ����Ϊ��
		return;
	else if (NULL == (*head)->next)// ����ֻ��һ���ڵ�
	{
		free(*head);
		*head = NULL;
	}
	else // ����ǿ�
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

// ͷ��  �����������Ƿ�Ϊ�� ���벽��һ��
void SListPushFront(SListNode** head, SLDataType data)
{
	assert(head);
	SListNode* newNode = BuySListNode(data);
	newNode->next = *head;
	*head = newNode;
}

// ͷɾ   head�б������ͷָ��ĵ�ַ
void SListPopFront(SListNode** head)
{
	assert(head);
	SListNode* delNode = NULL;
	// �ж��Ƿ�Ϊ������ �����ֱ�ӷ���
	if (*head = NULL)
		return;

	delNode = *head;
	*head = delNode->next;
	free(delNode);
}


// ����λ�õĲ���
// ����Ϊʲô��λ��֮�����ڵ�  ��Ϊֻ�ṩ��һ��λ�ã��Ҳ���λ��ǰ���λ�ã�ֻ���������
void SListInsertAfter(SListNode* pos, SLDataType data)
{
	SListNode* newNode = NULL;
	if (NULL == pos)
		return;

	// ���½ڵ����posλ��֮��
	newNode = BuySListNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
}

// ɾ��posλ��֮��Ľڵ�  ��pos���������һ���ڵ�
void SListEraseAfter(SListNode* pos)
{
	SListNode* delNode = NULL;
	if (NULL == pos || NULL == pos->next)
		return;

	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}


// ����ĳ���
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


// ��ӡ����
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


// ����ֵΪdata��λ��
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



// ����  ����ͷɾ��˼��
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
// ����
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