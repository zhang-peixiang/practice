#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
//
//如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
//
//请你返回排序后的数组。


int GetNum(int a)
{
	int num = 0;
	while (a)
	{
		if ((a & 1) == 1)
			num++;
		a = a >> 1;
	}
	return num;
}

int cmp(int* a, int* b)
{
	int f1 = GetNum(*a);
	int f2 = GetNum(*b);
	if (f1 == f2)
	{
		return *a - *b;
	}
	return f1 - f2;
}

int* sortByBits(int* arr, int arrSize, int* returnSize)
{
	*returnSize = arrSize;
	if (arrSize == 1)
		return arr;
	qsort(arr, arrSize, sizeof(arr[0]), cmp);

	return arr;
}