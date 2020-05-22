#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	assert(nums1 &&nums2);
	int count1 = m-1;
	int count2 = n-1;
	int count = m + n - 1;
	while (count1>=0 && count2>=0)
	{
		if (nums1[count1] > nums2[count2])
		{
			nums1[count] = nums1[count1];
			count--;
			count1--;
		}
		else
		{
			nums1[count] = nums2[count2];
			count--;
			count2--;
		}
	}
	while (count1>=0)
	{
		nums1[count] = nums1[count1];
		count--;
		count1--;
	}
	while (count2>=0)
	{
		nums1[count] = nums2[count2];
		count--;
		count2--;
	}
}

int main()
{
	int nums1[] = { 1, 2, 3, 0, 0, 0 };
	int nums2[] = { 2, 5, 6 };
	merge(nums1, 6, 3, nums2, 3, 3);
	return 0;
}