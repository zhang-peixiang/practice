#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 在大小为 2N 的数组 A 中有 N + 1 个不同的元素，其中有一个元素重复了 N 次。
// 返回重复了 N 次的那个元素。


int cmp(int* left, int* right)
{
	return *left - *right;
}


int repeatedNTimes(int* A, int ASize)
{
	qsort(A, ASize, sizeof(int), cmp);
	int i = 0;
	int n = 0;
	for (i = 0; i < ASize-1; i++)
	{
		if (A[i] == A[i + 1])
		{
			break;
		}
	}

	return A[i];
}