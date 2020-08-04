#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize - 1;
	int count = 0;
	if (numsSize == 0)
		return 0;
	if (numsSize == 1)
	{
		if (nums[0] == target)
			return 1;
		else
		{
			return 0;
		}
	}
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid]>target)
		{
			right = mid - 1;
		}
		else
		{
			int tmp = -1;
			if (mid>0)
			{
				tmp = mid - 1;
			}
			while (mid <= right && nums[mid] == target)
			{
				count++;
				mid++;
			}
			while (tmp >= left && nums[tmp] == target)
			{
				count++;
				tmp--;
			}
			break;
		}

	}
	return count;
}

int main()
{
	int arr[] = { 2, 2 };
	int a=search(arr, 2, 2);
	return 0;
}