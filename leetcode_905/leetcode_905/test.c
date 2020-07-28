#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。


//思路：类比挖坑法
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
	int begin = 0;
	int end = ASize - 1;
	*returnSize = ASize;
	if (ASize == 1)
		return A;
	while (begin < end)
	{
		while (begin < end && A[begin] % 2 == 0)
		{
			begin++;
		}
		while (begin < end && A[end] % 2 == 1)
		{
			end--;
		}
		if (begin < end)
		{
			int tmp = A[begin];
			A[begin++] = A[end];
			A[end--] = tmp;
		}
	}
	return A;
}