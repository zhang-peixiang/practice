#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如(a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

//erro--超时
//int arrayPairSum(int* nums, int numsSize)
//{
//	int i = 0;
//	int j = 0;
//	int max_sum = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		for (j = 0; j < numsSize-1 - i; j++)
//		{
//			int ret = 0;
//			if (nums[j]>nums[j + 1])
//			{
//				ret = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = ret;
//			}
//		}
//	}
//	for (i = 0; i < numsSize; i += 2)
//	{
//		max_sum += nums[i];
//	}
//	return max_sum;
//}


int compare(const void* e1,const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
int arrayPairSum(int* nums, int numsSize)
{
	int sum = 0;
	int i = 0;
	qsort(nums, numsSize, sizeof(nums[0]), compare);
	for (i = 0; i < numsSize; i+=2)
	{
		sum += nums[i];
	}
	return sum;
}

int main()
{
	int arr[] = { 7, 3, 1, 0, 0, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = arrayPairSum(arr, sz);
	printf("%d\n", ret);
	return 0;
}
