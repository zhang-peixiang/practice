#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//给定一个大小为 n 的数组，找到其中的多数元素。
//多数元素是指在数组中出现次数大于 ⌊ n / 2 ⌋ 的元素。
//
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。


int cmp(int* left, int* right)
{
	return *left - *right;
}

int majorityElement(int* nums, int numsSize)
{
	int i = 0;
	int count = 1;
	int ret = numsSize / 2;
	int tmp = 0;
	if (ret == 0)
	{
		return nums[0];
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	for (i = 0; i < numsSize-1; i++)
	{
		if (nums[i] == nums[i + 1])
		{
			count++;
			if (count>ret)
			{
				tmp = nums[i];
			}
		}
		else
		{
			count = 1;
		}
		
	}
	return tmp;
}