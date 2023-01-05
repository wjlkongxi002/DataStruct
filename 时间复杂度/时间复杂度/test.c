#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

// 二分查找
// 1. 左闭右闭
int BinarySearch(int arr[], int size, int data)
{
	int left = 0;
	int right = size - 1; // right是最后一个元素的下标
	while (left <= right)
	{
		int mid = left + ((right-left)>>1);  // mid = (left + right)/2  left+right 有可能会溢出
		if (data == arr[mid])
			return mid;
		else if (data < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

// 2. 左闭右开
//int BinarySearch(int arr[], int size, int data)
//{
//	int left = 0;
//	int right = size; // right是最后一个元素的下一个位置
//	while (left < right) // 如果是最后一个元素 就不能相等
//	{
//		int mid = left + ((right - left) >> 1);
//		if (data == arr[mid])
//			return mid;
//		else if (data < arr[mid])
//			right = mid ;  // 左闭右开 右边不能减一
//		else
//			left = mid + 1;
//	}
//	return -1;
//}


// 斐波拉契数列  时间复杂度O（N）

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


//将两个有序数据合并成一个

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

	while (index1 < size1)  // 1里面的数据没有搬完
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