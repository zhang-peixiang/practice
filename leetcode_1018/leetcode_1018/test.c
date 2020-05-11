#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i 个子数组被解释为一个二进制数（从最高有效位到最低有效位）。
//返回布尔值列表 answer，只有当 N_i 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。

//erro--int型会发生截断误差
//bool* prefixesDivBy5(int* A, int ASize, int* returnSize)
//{
//	int i = 0;
//	int j = 0;
//	int b = 0;//用来移动开辟的空间的位置
//	bool* return_arr = (bool*)malloc(ASize*sizeof(int));
//	for (i = 0; i < ASize; i++)
//	{
//		int a = 0;
//		int sum = 0;
//		for (j = i; j >= -1; j--)
//		{
//			if (j<0)
//			{
//				if (i == 0)
//				{
//					sum = A[i];
//					sum = sum % 5;
//				}
//				if (sum == 0)
//				{
//					return_arr[b] = true;
//				}
//				else
//				{
//					return_arr[b] = false;
//				}
//				b++;
//			}
//			else
//			{
//				sum += A[j] * pow(2, a);
//				sum = sum % 5;
//				a++;
//			}
//		}
//	}
//	*returnSize = ASize;
//	return return_arr;
//}


//利用二进制的特点
bool* prefixesDivBy5(int* A, int ASize, int* returnSize)
{
	int i = 0;
	int b = 0;//用来移动开辟的空间的位置
	int sum = 0;
	*returnSize = ASize;
	bool* return_arr = (bool*)malloc(ASize*sizeof(int));
	for (i = 0; i < ASize; i++)
	{
		sum = sum * 2 + A[i];
		if (sum % 5 == 0)
		{
			return_arr[b] = true;
		}
		else
		{
			return_arr[b] = false;
		}
		b++;
		sum = sum % 10;//提前处理，防止超出int范围，产生截断误差
	}
	return return_arr;
}


int main()
{
	int arr[] = {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0,1};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int b = sz;
	bool* ret = prefixesDivBy5(arr, sz, &b);
	//printf("%d\n", ret);
	return 0;
}