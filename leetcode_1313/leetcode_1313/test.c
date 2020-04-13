#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 解压缩编码列表
//给你一个以行程长度编码压缩的整数列表 nums 。
//考虑每对相邻的两个元素 freq, val] = [nums[2 * i], nums[2 * i + 1]] （其中 i >= 0 ），
//每一对都表示解压后子列表中有 freq 个值为 val 的元素，你需要从左到右连接所有子列表以生成解压后的列表。
//请你返回解压后的列表。

int* decompressRLElist(int* nums, int numsSize, int* returnSize){
	int i = 0;
	int j = 0;
	int sz = 0;
	int k = 0;
	for (i = 0; i < numsSize; i += 2)
	{
		sz += nums[i];
	}
	int* returnlist = (int*)calloc(sz, sizeof(int));
	for (i = 0; i < numsSize; i += 2)
	{
		for (j = 0; j < nums[i]; j++)
		{
			returnlist[k] = nums[i + 1];
			k++;
			//error
			/**returnlist = nums[i + 1];
			returnlist++;*/
		}
	}
	*returnSize = sz;
	return returnlist;
}
int main()
{
	int nums[] = { 1, 2, 3, 4 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int i = 0;
	int a = 0;

	int* arr = decompressRLElist(nums, sz, &a);
	for (i = 0; i < a; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}