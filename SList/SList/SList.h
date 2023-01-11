#pragma once


// һ��������ͷ���ĵ�����

typedef int SLDataType;

typedef struct SListNode // ����һ���ڵ� 
{
	struct SListNode* next; // ָ����һ���ڵ��ַ��ָ��
	SLDataType data; // �ڵ��д�ŵ�����
}SListNode;


// ����ں����иı�ͷָ���ָ���βα���Ϊ����ָ�� ���磺����ɾ������
// ����Ҫ�ı亯����ͷָ���ָ��ֻ�贫��һ��ָ�뼴�ɣ�������Ҳ���
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