#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

int removeElement(int* nums, int numsSize, int val)
{
	assert(nums);
	int i = 0;
	int count = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[count] = nums[i];
			count++;
		}
	}
	return count;
}

int main()
{
	int nums[] = { 3, 2, 2, 3 };
	int n = 3;
	int sz = sizeof(nums) / sizeof(nums[1]);
	int ret = removeElement(nums, sz, n);
	printf("%d\n", ret);
	return 0;
}