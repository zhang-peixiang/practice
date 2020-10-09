#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
 
// 给你一个整数数组 nums 。
//
// 如果一组数字(i, j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。
//
// 返回好数对的数目。




#if 0
// 暴力法
int numIdenticalPairs(int* nums, int numsSize)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] == nums[j])
			{
				count++;
			}
		}
	}
	return count;
}
#endif

// 哈希表思想
int numIdenticalPairs(int* nums, int numsSize)
{
	int arr[100] = { 0 };
	int i = 0;
	int tmp = 0;
	int count = 0;
	for (i = 0; i < numsSize; i++)
	{
		arr[nums[i]]++;
	}
	for (i = 0; i < 100; i++)
	{
		tmp = arr[i] - 1;
		int a = 0;
		while (tmp>0)
		{
			a += tmp;
			tmp--;
		}
		count += a;
	}
	return count;
}

int main()
{
	int arr[] = { 1, 2, 3, 1, 1, 3 };
	int a = numIdenticalPairs(arr, 6);
	return 0;
}