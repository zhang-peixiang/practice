#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
//int missingNumber(int* nums, int numsSize)//超时
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < numsSize; i++)//冒泡排序，从小到大排序
//	{
//		int ret = 0;
//		for (j = 0; j < numsSize - 1 - i; j++)
//		{
//			if (nums[j]>nums[j + 1])
//			{
//				ret = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = ret;
//			}
//		}
//	}
//	for (i = 0; i < numsSize; i++)
//	{
//		
//		if (nums[i] - i != 0)
//		{
//			return i ;
//		}
//	}
//
//}
//这道题是从0开始的数组，所以位置就等于位置上的数
//方法一：
//int missingNumber(int* nums, int numsSize)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < numsSize; i++)//i表示位置
//	{
//		for (j = 0; j < numsSize; j++)
//		{
//			if (nums[j] == i)//证明这个数字在数组里，跳出循环
//			{
//				break;
//			}
//		}
//		if (j == numsSize)//数组遍历完没找到i，所以缺失i
//		{
//			return i;
//		}
//	}
//	return i;//证明每个数字都不缺少，返回numsSize，比如[0,1] 返回2.
//}
//方法二：求和再做差
int missingNumber(int* nums, int numsSize)
{
	int i = 0;
	int sum1 = 0;
	int sum2 = 0;
	for (i = 0; i < numsSize; i++)
	{
		sum1 += i;
		sum2 += nums[i];
	}
	if (sum2 - sum1 == 0)
	{
		return numsSize;
	}
	else
	{
		int ret = abs(sum1 - sum2);
		return numsSize - ret;
	}
}

int main()
{
	int arr[] = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = missingNumber(arr, sz);
	printf("%d\n", ret);
	return 0;
}