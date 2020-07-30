#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//给你两个数组，arr1 和 arr2，
//arr2 中的元素各不相同
//arr2 中的每个元素都出现在 arr1 中
//对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。
//未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。


int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
	*returnSize = arr1Size;
	if (arr1Size == 1)
		return arr1;
	int* arr = (int*)calloc(sizeof(int), 1001);
	int i = 0;
	int j = 0;
	for (i = 0; i < arr1Size; i++)
	{
		arr[arr1[i]]++;
	}
	for (i = 0; i < arr2Size; i++)
	{
		while (arr[arr2[i]])
		{
			arr1[j++] = arr2[i];
			arr[arr2[i]]--;
		}
	}
	for (i = 0; i < 1001; i++)
	{
		while (arr[i])
		{
			arr1[j++] = i;
			arr[i]--;
		}
	}

	free(arr);
	return arr1;
}

int main()
{
	int arr1[] = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
	int arr2[] = {2, 1, 4, 3, 9, 6};

	int a = 0;
	relativeSortArray(arr1, 11, arr2, 6, &a);
	return 0;
}