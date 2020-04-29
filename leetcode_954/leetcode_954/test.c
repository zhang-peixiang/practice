#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//给定一个长度为偶数的整数数组 A，只有对 A 进行重组后可以满足 “对于每个 0 <= i < len(A) / 2，
//都有 A[2 * i + 1] = 2 * A[2 * i]” 时，返回 true；否则，返回 false。

//erro --(1,2,4,8)
//int cmp(const void* e1, const void* e2)
//{
//	return (*(int*)e1 - *(int*)e2);
//}
//int canReorderDoubled(int* A, int ASize)
//{
//	int i = 0;
//	int count = 0;
//	qsort(A, ASize, 4, cmp);
//	int j = 0;
//	for (i = 0; i < ASize; i++)
//	{
//		if (A[i] < 0)
//		{
//			j++;//判断有几个负数
//		}
//		else
//			break;
//	}
//	for (i = 0; i < j/2; i++)//检查负数是否符合题目要求
//	{
//		if (A[i] != 2*A[i + j / 2])
//		{
//			return 0;
//		}
//	}
//	for (i = j; i < ASize/2; i++)//检查正数是否符合题目要求
//	{
//		if (2 * A[i] != A[i + ASize / 2])
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
int cmp(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
int canReorderDoubled(int* A, int ASize)
{
	int i = 0;
	int count = 0;
	qsort(A, ASize, 4, cmp);
	while (i < ASize )
	{
		int j = 0;
		while (j < ASize)
		{
			if (A[i] == 2 * A[j]&& i!=j)
			{
				count++;
				A[i] = 1000000;
				A[j] = 1000000;
				break;
			}
			j++;
		}
		i++;
	}
	if (count == ASize / 2)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int arr[] = { -1, 4, 6, 8, -4, 6, -6, 3, -2, 3, -3, -8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = canReorderDoubled(arr, sz);
	printf("%d", ret);
	return 0;
}

