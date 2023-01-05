#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

// ��ʼ��
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

// ����Ƿ���Ҫ����
int CheckCapacity(SeqList* s)
{
	assert(s);
	if (s->capacity == s->size)
	{
		// �������ķ�ʽ��������
		int newCapacity = s->capacity * 2;
		s->array = (SDataType*)realloc(s->array, newCapacity*sizeof(SDataType));

		if (NULL == s->array)
			return 0;

		s->capacity = newCapacity;
	}
	return 1;
}


// β��
// 1.����Ҫ����
// 2.����
void SeqLiistPushBack(SeqList* s, SDataType data)
{
	assert(s);
	// �������
	if (!CheckCapacity(s))  // �������ʧ�� ֱ�ӷ���  ��ʾ���ܲ�������
		return;
	
	s->array[s->size] = data;
	s->size++;
}

// βɾ     ��Ҫ�п�
void SeqListPopback(SeqList* s)
{
	if (SeqListEmpty(s))
		return;
	s->size--;
}

// ͷ��
// 1.�ȼ���Ƿ���Ҫ����
// 2.��Ԫ���������
// 3.��ʼλ�ò���data
void SeqListPushFront(SeqList* s, SDataType data)
{
	assert(s);
	// �������
	if (!CheckCapacity(s))
		return;
	for (int i = s->size-1; i >= 0 ; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[0] = data;
	s->size++;
}

//ͷɾ   1. �п� 2.��Ԫ��������ǰ����һ��λ�� 
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

// ����λ�õĲ���
//  1.�жϲ����λ���Ƿ�Ϸ�
//  2.�ж��Ƿ���Ҫ����
//  3.����Ԫ�ؽ��в���
void SeqListInsert(SeqList* s, int pos, SDataType data)
{
	assert(s);
	if (pos < 0 || pos > s->size)
		return;

	if (!CheckCapacity(s))
		return;

	// �����������pos -- size λ�õ�Ԫ��һ��λ��
	for (int i = s->size - 1; i >= pos; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[pos] = data;
	s->size++;

}


// ����λ�õ�ɾ��
// 1.�ж�λ���Ƿ�Ϸ�
// 2.����Ԫ��
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

// ��ȡ˳�������ЧԪ�صĸ���
int SeqListSzie(SeqList* s)
{
	assert(s);
	return s->size;
}

// ��ȡ˳��������
int SeqListCapacity(SeqList* s)
{
	assert(s);
	return s->capacity;
}

// �п�
int SeqListEmpty(SeqList* s) // �ǿյķ���0�����Ƿ���-1
{
	assert(s);
	return 0 == s->size;
}

// ���
void SeqListClear(SeqList *s)
{
	assert(s);
	s->size = 0;
}

// ����ֵΪdata��Ԫ�ز������±꣬���򷵻�-1
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

// ����
void SeqListDestroy(SeqList* s)
{
	assert(s);
	if (s->array)  // ����ռ����
	{
		free(s->array); // �ͷ�����Ķѿռ�
		s->array = NULL;
		s->capacity = 0;
		s->size = 0;
	}
}

// ��ӡ˳���
void SeqListPrintf(SeqList* s)
{
	for (int i = 0; i < s->size; i++)
		printf("%d ", s->array[i]);

	printf("\n");
}


////////////////////////////////
//����

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
