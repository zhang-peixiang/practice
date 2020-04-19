#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//我们把符合下列属性的数组 A 称作山脉：
//A.length >= 3
//存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1]
//给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i - 1] < A[i] > A[i + 1] > ... > A[A.length - 1] 的 i 的值。
int peakIndexInMountainArray(int* A, int ASize)
{
	int i = 0;
	for (i = 0; i < ASize - 1; i++)
	{
		if (*(A + i)>*(A + i + 1))
		{
			return i;
		}
		if (*(A + ASize - 1 - i) < *(A + ASize - 2 - i))
		{
			return *(A + ASize - 2 - i);
		}
	}
	return i + 1;
}
int main()
{
	int arr[] = { 0, 2, 1, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = 0;
	ret = peakIndexInMountainArray(arr, size);
	printf("%d\n", ret);
	return 0;
}