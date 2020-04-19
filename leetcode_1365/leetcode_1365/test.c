#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
//换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。
//以数组形式返回答案。
int* smallerNumbersThanCurrent(int* nums, int numsSize)
{
	int i = 0;
	int* returnnums = (int*)calloc(numsSize, sizeof(int));
	for (i = 0; i < numsSize; i++)
	{
		int j = 0;
		int count = 0;
		for (j = 0; j < numsSize; j++)
		{
			if (*(nums + i)>*(nums + j))
			{
				count++;
			}
		}
		returnnums[i] = count;
	}
	return returnnums;
}

int main()
{
	int nums[] = { 8, 1, 2, 2, 3 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int i = 0;
	//int returnnums[5] = { 0 };
	int* returnnums=smallerNumbersThanCurrent(nums, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", returnnums[i]);
	}
	return 0;
}