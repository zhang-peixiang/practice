#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


// 数组nums包含从0到n的所有整数，但其中缺了一个。
// 请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

// 对0-n求和，然后减去数组中的数，剩余的数就是缺失的数

int missingNumber(int* nums, int numsSize)
{
	int count = 0;
	int i = 0;
	int a = numsSize + 1;
	if (a % 2 == 1)
	{
		count = numsSize*(a / 2) + a / 2;
	}
	else
	{
		count = numsSize*(a / 2);
	}
	for (i = 0; i < numsSize; i++)
	{
		count -= nums[i];
	}
	return count;
}