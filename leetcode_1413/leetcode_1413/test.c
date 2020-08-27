#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给你一个整数数组 nums 。你可以选定任意的 正数 startValue 作为初始值。
//你需要从左到右遍历 nums 数组，并将 startValue 依次累加上 nums 数组中的值。
//请你在确保累加和始终大于等于 1 的前提下，选出一个最小的 正数 作为 startValue 。


int minStartValue(int* nums, int numsSize)
{
	int min = 0;
	int i = 0;
	int sum = 0;
	for (i = 0; i < numsSize; i++)
	{
		sum += nums[i];
		min = fmin(sum, min);
	}
	return -(min - 1);
}