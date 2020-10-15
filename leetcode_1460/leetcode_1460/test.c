#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>


// 给你两个长度相同的整数数组 target 和 arr 。
// 每一步中，你可以选择 arr 的任意 非空子数组 并将它翻转。你可以执行此过程任意次。
// 如果你能让 arr 变得与 target 相同，返回 True；否则，返回 False 。

 // 1.哈希表思想
//  2.也可以排序 然后判断
bool canBeEqual(int* target, int targetSize, int* arr, int arrSize)
{
	int arr1[1001] = { 0 };
	int i = 0;
	for (i = 0; i < targetSize; i++)
	{
		arr1[target[i]]++;
		arr1[arr[i]]--;
	}

	for (i = 0; i < 1001; i++)
	{
		if (arr1[i] != 0)
		{
			return false;
		}
	}
	return true;
}