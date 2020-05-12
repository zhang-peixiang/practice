#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
//写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 - 1。
int search(int* nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		int ret = (left + right) / 2;
		if (nums[ret] > target)
		{
			right = ret - 1;
		}
		else if (nums[ret] < target)
		{
			left = ret + 1;
		}
		else if (nums[ret] == target)
		{
			return ret;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { -1, 0, 3, 5, 9, 12 };
	int b = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	scanf("%d", &b);
	int ret = search(arr, sz, b);
	printf("%d\n", ret);
	return 0;
}