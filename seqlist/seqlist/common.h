#ifndef _COMMON_H_
#define _COMMON_H_


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define DataType  int   //�涨��������Ϊ����


void Swap(DataType *a, DataType *b)//���õ�   ��������
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}
#endif