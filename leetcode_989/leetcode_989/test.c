#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
//例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。
//
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。

/*
1.判断开辟空间的大小，因为两个数相加，所得到的数最多只比最大的数字高一位，所以开辟的空间为tmp+1
2.将数组的最后一位与K的个位相加，然后赋值到开辟的空间最后一位，依次往下，直到把数组的数字处理完
3.当数组的长度小于K的长度时，数组中的数字处理完时，K还没处理完，所以还需要对K进行处理
4.判断开辟的空间大小是否等于returnSize的大小，因为我们放值是从所开辟空间的最后一位开始放，所以需要判断，
  如果开辟空间的大学大于returnSize，则需要进行移位，因为这里开辟的空间最多比returnSize大于1，所以只需要移动一位即可。
*/


int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int count = 0;
	int count1 = 0;
	int tmp = 0;
	int i = 0;
	int a = K;
	while (a)
	{
		count++;
		a /= 10;
	}
	if (ASize > count)
	{
		tmp = ASize;
	}
	else
	{
		tmp = count;
	}
	int* ret = (int*)calloc(tmp + 1, sizeof(int));
	for (i = 0; i < ASize; i++)
	{
		K = A[ASize - 1 - i] + K;
		ret[tmp-i] = K % 10;
		K /= 10;
		count1++;
	}
	while (K)
	{
		ret[tmp-i] = K % 10;
		K /= 10;
		i++;
		count1++;
	}
	*returnSize = count1;
	if (count1 < tmp+1)
	{
		memmove(ret, ret + 1, sizeof(int)*count1);
	}
	return ret;
}

int main()
{
	int A[] = { 0};
	int k = 10000;
	int sz = sizeof(A) / sizeof(A[1]);
	int a = 0;
	addToArrayForm(A, sz, k, &a);
	return 0;
}