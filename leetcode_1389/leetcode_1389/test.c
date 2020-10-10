#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给你两个整数数组 nums 和 index。你需要按照以下规则创建目标数组：
//
//目标数组 target 最初为空。
//按从左到右的顺序依次读取 nums[i] 和 index[i]，在 target 数组中的下标 index[i] 处插入值 nums[i] 。
//重复上一步，直到在 nums 和 index 中都没有要读取的元素。
//请你返回目标数组。
//
//题目保证数字插入位置总是存在。



int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize)
{
	*returnSize = numsSize;
	int i = 0;
	int* ret = (int*)malloc(sizeof(int)*(numsSize + 1));
	for (i = 0; i < numsSize; i++)
	{
		if (i == index[i])
		{
			ret[i] = nums[i];
		}
		else
		{
			int j = 0;
			for (j = i + 1; j >index[i]; j--)
			{
				ret[j] = ret[j - 1];
			}
			ret[index[i]] = nums[i];
		}
	}
	return ret;
}

int main()
{
	int arr[] = { 0, 1, 2, 3, 4 };
	int index[] = { 0, 1, 2, 2, 1 };
	int a = 0;
	createTargetArray(arr, 5, index, 5, &a);
	return 0;
}





