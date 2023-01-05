#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

// ���ֲ���
// 1. ����ұ�
int BinarySearch(int arr[], int size, int data)
{
	int left = 0;
	int right = size - 1; // right�����һ��Ԫ�ص��±�
	while (left <= right)
	{
		int mid = left + ((right-left)>>1);  // mid = (left + right)/2  left+right �п��ܻ����
		if (data == arr[mid])
			return mid;
		else if (data < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

// 2. ����ҿ�
//int BinarySearch(int arr[], int size, int data)
//{
//	int left = 0;
//	int right = size; // right�����һ��Ԫ�ص���һ��λ��
//	while (left < right) // ��������һ��Ԫ�� �Ͳ������
//	{
//		int mid = left + ((right - left) >> 1);
//		if (data == arr[mid])
//			return mid;
//		else if (data < arr[mid])
//			right = mid ;  // ����ҿ� �ұ߲��ܼ�һ
//		else
//			left = mid + 1;
//	}
//	return -1;
//}


// 쳲���������  ʱ�临�Ӷ�O��N��

unsigned long long Fib(int N)
{
	unsigned long long first = 1, second = 1;
	unsigned long long ret = 1;
	for (int i = 2; i < N; i++)
	{
		ret = first + second;
		first = second;
		second = ret;
	}
	return ret;
}


//�������������ݺϲ���һ��

int* MergeData(int arr1[], int size1, int arr2[], int size2)
{
	int index1 = 0, index2 = 0, index = 0;
	int* arr = (int*)malloc((sizeof(arr) / sizeof(arr[0])));
	if (NULL == arr)
		return NULL;

	while (index1 < size1 && index2 < size2)
	{
		if (arr1[index1] <= arr2[index2])
			arr[index++] = arr1[index1++];
		else
			arr[index++] = arr2[index2++];
	}

	while (index1 < size1)  // 1���������û�а���
		arr[index++] = arr1[index1++];
	while (index2 < size2)
		arr[index++] = arr2[index2++];
	
	return arr;
}


int main()
{
	int arr1[] = { 2, 5, 6, 8 };
	int arr2[] = { 1, 3, 5, 7, 8, 9 };
	int* arr = MergeData(arr1, sizeof(arr1) / sizeof(arr1[0]), arr2, sizeof(arr2) / sizeof(arr[0]));
	int size = (sizeof(arr1) / sizeof(arr1[0])) + (sizeof(arr2) / sizeof(arr[0]));
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}