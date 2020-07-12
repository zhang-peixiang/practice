#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//在一个长度为 n 的数组 nums 里的所有数字都在 0～n - 1 的范围内。
//数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
//请找出数组中任意一个重复的数字。



//超时
//int findRepeatNumber(int* nums, int numsSize)
//{
//	if (numsSize == 0 || numsSize == 1)
//		return NULL;
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	int ret = 0;
//
//	int arr[numsSize];
//	for (i = 0; i < numsSize; i++)
//	{
//		ret = nums[i];
//		arr[count++] = ret;
//		for (j = 0; j < count - 1; j++)
//		{
//			if (ret == arr[j])
//				return ret;
//		}
//	}
//}

//超时
//int findRepeatNumber(int* nums, int numsSize)
//{
//	int i = 0;
//	int j = 0;
//	int ret = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		for (j = 0; j < numsSize - i - 1; j++)
//		{
//			if (nums[j] < nums[j + 1])
//			{
//				ret = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = ret;
//			}
//		}
//	}
//	for (i = 0; i < numsSize-1; i++)
//	{
//		if (nums[i] == nums[i + 1])
//			break;
//	}
//	return nums[i];
//}

//哈希表
int findRepeatNumber(int* nums, int numsSize){
	int arr[numsSize];
	int i = 0;

	for (i = 0; i<numsSize; i++)
	{
		if (arr[nums[i]] == 1)
			return nums[i];
		else
			arr[nums[i]] = 1;
	}
	return -1;
}