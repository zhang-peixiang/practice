#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
//如果有多对数字的和等于s，则输出任意一对即可。
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int left = 0;
	int right = numsSize - 1;
	int* arr = (int*)malloc(sizeof(int)* 2);
	while (left < right)
	{
		if (nums[left] + nums[right]>target)
		{
			right--;
		}
		else if (nums[left] + nums[right] < target)
		{
			left++;
		}
		else
		{
			arr[0] = nums[left];
			arr[1] = nums[right];
			break;
		}
	}
	*returnSize = 2;
	return arr;
}



int main()
{
	int nums[] = { 14, 15, 16, 22, 53, 60 };
	int a = 0;
	int* b = twoSum(nums, 6, 76, &a);

	return 0;
}