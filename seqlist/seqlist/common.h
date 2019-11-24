#ifndef _COMMON_H_
#define _COMMON_H_


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define DataType  int   //规定数据类型为整形


void Swap(DataType *a, DataType *b)//共用的   交换数据
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}
#endif