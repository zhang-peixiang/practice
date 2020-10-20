#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 给你一个整数数组 A，请你给数组中的每个元素 A[i] 都加上一个任意数字 x （ - K <= x <= K），从而得到一个新数组 B 。

// 返回数组 B 的最大值和最小值之间可能存在的最小差值。

int cmp(int* left, int* right)
{
	return *left - *right;
}
int smallestRangeI(int* A, int ASize, int K)
{
	int i = 0;
	qsort(A, ASize, sizeof(int), cmp);
	int tmp = A[ASize - 1] - A[0];
	if (tmp <= 2 * K)
	{
		return 0;
	}
	
	return tmp - 2 * K;
}


int main()
{
	int arr[] = { 0, 10 };
	int k = 2;
	int a = smallestRangeI(arr, 2, 2);
	return 0;
}