#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。
//完成所有替换操作后，请你返回这个数组。
int* replaceElements(int* arr, int arrSize, int* returnSize)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < arrSize - 1; i++)
	{
		int a = arr[i+1];//用a来记录两个比较的最大值。
		for (j = i + 1; j < arrSize; j++)//从i后面的一个元素开始循环找最大值
		{
			if (a < arr[j])
			{
				a = arr[j];
			}
		}
		arr[i] = a;
	}
	arr[arrSize - 1] = -1;
	*returnSize = arrSize;
	return arr;
}
int main()
{
	int arr[] = { 17, 18, 5, 4, 6, 1 };
	int sz = sizeof(arr)/sizeof(arr[0]);
	int* ret = replaceElements(arr, sz, &sz);
	return 0;
}