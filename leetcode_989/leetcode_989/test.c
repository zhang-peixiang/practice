#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
//例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。
//
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。



int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int count = 0;
	int count1 = 0;
	int tmp = 0;
	int i = 0;
	int* ret = 0;
	while (K)
	{
		count++;
		K /= 10;
	}
	if (ASize > count)
	{
		int* ret = (int*)calloc(ASize+1, sizeof(int));
		for (i = 0; i < ASize; i++)
		{
			K = A[ASize - 1 - i] + K;
			ret[ASize - i] = K % 10;
			K /= 10;
			count1++;
		}
		while (K)
		{
			ret[ASize - i - 1] = K % 10;
			K /= 10;
			count1++;
		}
	}
	else
	{
		int* ret = (int*)calloc(count + 1, sizeof(int));
		count = 0;
		for (i = 0; i < count; i++)
		{
			K = A[ASize - 1 - i] + K;
			ret[ASize - i] = K % 10;
			K /= 10;
			count1++;
		}
		while (K)
		{
			ret[ASize - i - 1] = K % 10;
			K /= 10;
			count1++;
		}
	}
	*returnSize = count1;
	if (count1 < count)
	{
		memmove(ret, ret + 1, sizeof(int)*count1);
	}
	return ret;
}

int main()
{
	int A[] = { 1, 2, 0, 0 };
	int k = 34;
	int sz = sizeof(A) / sizeof(A[1]);
	int a = 0;
	addToArrayForm(A, sz, k, &a);
	return 0;
}