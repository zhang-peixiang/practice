#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。


int removeDuplicates(int* nums, int numsSize)
{
	assert(nums);
	if (numsSize < 2)
	{
		return numsSize;
	}
	int i = 0;
	int count = 0;
	for (i = 1; i < numsSize; i++)
	{
		if (nums[count] != nums[i])
		{
			nums[++count] = nums[i];
		}
	}
	return ++count;
}


int main()
{
	int nums[] = { 1, 1, 2 };
	int sz = sizeof(nums) / sizeof(nums[1]);
	int ret = removeDuplicates(nums, sz);
	printf("%d\n", ret);
	return 0;
}