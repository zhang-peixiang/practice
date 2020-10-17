#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

// 给定两个数组，编写一个函数来计算它们的交集。
int cmp(int* left, int* right)
{
	return *left - *right;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	int i = 0;
	int sz = nums1Size > nums2Size ? nums1Size : nums2Size;
	int* rz = (int*)malloc(sizeof(int)*sz);
	if (nums1 == NULL || nums2 == NULL)
	{
		return 0;
	}
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	int j = 0;
	int tmp = 0;
	for (i = 0; i < nums1Size; i++)
	{
		int max = nums1[i];
		if (tmp != 0 && max != rz[tmp - 1])
		{
			while (j<nums2Size && max >= nums2[j])
			{
				if (max == nums2[j])
				{
					rz[tmp++] = max;
					j++;
					break;
				}
				j++;
			}
		}
		else if (tmp == 0)
		{
			while (j<nums2Size && max >= nums2[j])
			{
				if (max == nums2[j])
				{
					rz[tmp++] = max;
					j++;
					break;
				}
				j++;
			}
		}
	}
	*returnSize = tmp;
	return rz;
}
int main()
{
	int arr1[] = { 1, 2 };
	int arr2[] = { 1, 1 };
	int a = 0;
	int* b = intersection(arr1, 2, arr2, 2, &a);
	return 0;
}