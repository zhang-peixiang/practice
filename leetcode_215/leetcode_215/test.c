#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//方法一：时间长
int compare(int* a, int* b)
{
	return *a - *b;
}

int findKthLargest(int* nums, int numsSize, int k)
{
	int* arr = (int*)malloc(sizeof(int)*k);
	int i = 0;
	int j = 0;
	int ret = nums[0];
	for (i = 0; i < numsSize; i++)
	{
		if (ret <= nums[i])
		{
			arr[j] = nums[i];
			j++;
			qsort(arr, k, sizeof(int), compare);
			if (j = k)
			{
				j = 0;
				ret = arr[0];
			}
		}
	}

	return arr[0];
}

//方法二
int compare(int* a, int* b)
{
	return -(*a - *b);
}

int findKthLargest(int* nums, int numsSize, int k)
{

	qsort(nums, numsSize, sizeof(int), compare);

	return nums[k - 1];
}



int main()
{
	int arr[] = { 3, 2, 1, 5, 6, 4 };

	findKthLargest(arr, 6, 2);
	return 0;
}