#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 
//编写一个方法，将 B 合并入 A 并排序。
//初始化 A 和 B 的元素数量分别为 m 和 n。

void merge(int* A, int ASize, int m, int* B, int BSize, int n)
{
	if (BSize == 0)
		return A;
	int i = m-1;
	int j = n - 1;
	int size = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (A[i] > B[j])
			A[size--] = A[i--];
		else
			A[size--] = B[j--];
	}
	while (j>=0)
	{
		A[size--] = B[j--];
	}
	return A;
}