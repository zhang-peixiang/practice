#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，
//并返回他们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

int cmp(const int* left, const int* right)
{
	return  *left - *right;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i = 0;
	int j = numsSize - 1;
	int* arr = (int*)malloc(sizeof(int)* 2);
	int sum = 0;
	int* arr1 = (int*)malloc(sizeof(int)*numsSize);
	int tmp = 2;
	int a = 0;
	int flag = 0;

	memcpy(arr1, nums, sizeof(int)*numsSize);
	qsort(nums, numsSize, sizeof(int), cmp);
	while (i < j)
	{
		sum = nums[i] + nums[j];
		if (sum == target)
		{
			break;
		}
		else if (nums[i + 1] + nums[j]>target)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	for (a = 0; a < numsSize; a++)
	{
		if (arr1[a] == nums[i] && flag !=1)
		{
			tmp--;
			i = a;
			flag = 1;
		}
		else if (arr1[a] == nums[j] && flag!=2)
		{
			tmp--;
			j = a;
			flag = 2;
		}
		if (tmp == 0)
		{
			break;
		}
	}
	arr[0] = i;
	arr[1] = j;
	*returnSize = 2;
	return arr;
}

int main()
{
	int arr[] = { -3,4,3,90};
	int a = 0;
	int* b = twoSum(arr, 4, 0, &a);

	return 0;
}