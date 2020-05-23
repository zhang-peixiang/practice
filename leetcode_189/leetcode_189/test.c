#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
/*
1.先判断移动的步数
2.移动k步，就从数组最后的位置开始往前保存k个数，避免移动时被覆盖
3.将数组中的元素向右移动k个位置也就是将numsSize-k个数值往右移动，让numsSize-k-1位置放到最后一个位置，然后依次往前放
4.将开辟的数组中的元素放回nums数组，从0开始依次往后放。
*/
void rotate(int* nums, int numsSize, int k)
{
	if (k >= numsSize) //当k>=numsSize，移动的步数
	{
		k = k - numsSize;
	}
	int i = 0;
	int* arr = (int*)malloc(sizeof(int)*k);
	for (i = 0; i < k; i++)//
	{
		arr[i] = nums[numsSize - k + i];
	}
	//将数组中的元素向右移动k个位置也就是将numsSize-k个数值往右移动，让numsSize-k-1位置放到最后一个位置，然后依次往前放
	for (i = 0; i < numsSize - k; i++)
	{
		nums[numsSize - 1 - i] = nums[numsSize - k - 1 - i];
	}
	//将开辟的数组中的元素放回nums数组，从0开始依次往后放。
	for (i = 0; i < k; i++)
	{
		nums[i] = arr[i];
	}
	free(arr);
	arr = NULL;
}

int main()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	int sz = sizeof(arr) / sizeof(arr[1]);
	rotate(arr, sz, k);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}