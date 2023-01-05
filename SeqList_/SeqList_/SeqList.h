#pragma once

typedef int SDataType;

// ����һ���ṹ�����
typedef struct SeqList
{
	SDataType* array; // ���Ԫ�ص�����ռ� 
	int capacity;  // �ռ������
	int size; // ��ЧԪ�صĸ���
}SeqList;

// ��ʼ��
void SeqListInit(SeqList* s, int initcapacity);

// β��
void SeqLiistPushBack(SeqList* s, SDataType data);

// βɾ
void SeqListPopback(SeqList* s);

// ͷ��
void SeqListPushFront(SeqList* s, SDataType data);

//ͷɾ
void SeqListPopFront(SeqList* s);

// ����λ�õĲ���
void SeqListInsert(SeqList* s, int pos, SDataType data);


// ����λ�õ�ɾ��
void SeqListErase(SeqList* s, int pos);

// ��ȡ˳�������ЧԪ�صĸ���
int SeqListSzie(SeqList* s);

// ��ȡ˳��������
int SeqListCapacity(SeqList* s);

// �п�
int SeqListEmpty(SeqList* s);

// ���
void SeqListClear(SeqList *s);

// ����ֵΪdata��Ԫ�ز������±꣬���򷵻�-1
int SeqListFind(SeqList* s, SDataType data);

// ����
void SeqListDestroy(SeqList* s);
