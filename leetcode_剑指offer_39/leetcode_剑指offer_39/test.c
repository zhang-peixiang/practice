#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。

int cmp(int* left, int* right)
{
	return *left - *right;
}

int majorityElement(int* nums, int numsSize)
{
	int i = 0;
	int count = 1;
	qsort(nums, numsSize, sizeof(int), cmp);
	int tmp = nums[0];
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] == tmp)
		{
			count++;
		}
		else
		{
			count = 1;
			tmp = nums[i];
		}
		if (count > numsSize / 2)
		{
			break;
		}
	}
	return tmp;
}

int main()
{
	int arr[] = { 6,5,5 };
	int a = majorityElement(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}