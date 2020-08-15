#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//在整数数组中，如果一个整数的出现频次和它的数值大小相等，我们就称这个整数为「幸运数」。
//
//给你一个整数数组 arr，请你从中找出并返回一个幸运数。
//
//如果数组中存在多个幸运数，只需返回 最大 的那个。
//如果数组中不含幸运数，则返回 - 1 。



int cmp(int* left, int* right)
{
	return *right - *left;
}

int findLucky(int* arr, int arrSize)
{
	int i = 0;
	int count = 1;
	int a = 0;
	if (arrSize == 0)
		return -1;
	if (arrSize == 1 && arr[0] == 1)
		return 1;
	if (arrSize == 1)
		return -1;

	qsort(arr, arrSize, sizeof(arr[0]), cmp);

	for (i = 0; i < arrSize - 1; i++)
	{
		count = 1;
		while (i < arrSize - 1 && arr[i] == arr[i + 1])
		{
			count++;
			i++;
		}
		if (count == arr[i])
		{
			return arr[i];
		}

	}

	if (arr[arrSize - 1] == 1 && arr[arrSize - 2] != 1)
		return 1;
	return -1;
}

int main()
{
	int arr[] = {2,2,2,3,3};
	int a = findLucky(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}