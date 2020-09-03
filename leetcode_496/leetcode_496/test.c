#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
// 找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
//
// nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。
// 如果不存在，对应位置输出 - 1

 
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	*returnSize = nums1Size;
	int i = 0;
	int j = 0;
	int flag = 0;
	int max = 0;
	int* arr = (int*)malloc(sizeof(int)*nums1Size);
	for (i = 0; i < nums1Size; i++)
	{
		j = 0;
		max = 0;
		while (nums2[j] != nums1[i])
		{
			j++;
		}
		while (j < nums2Size)
		{
			if (nums2[j]>nums1[i])
			{
				max = nums2[j];
				arr[i] = max;
				break;
			}
			j++;
		}
		if (max == 0)
		{
			arr[i] = -1;
		}
	}
	return arr;
}