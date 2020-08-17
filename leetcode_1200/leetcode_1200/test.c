#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//给你个整数数组 arr，其中每个元素都 不相同。
//
//请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

int cmp(int* left, int* right)
{
	return *left - *right;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes)
{
	int i = 0;
	int count = 0;
	int a = 0;
	qsort(arr, arrSize, sizeof(int), cmp);
	int low = arr[1] - arr[0];
	//找最小差值
	for (i = 0; i < arrSize - 1; i++)
	{
		if (arr[i + 1] - arr[i] < low)
		{
			low = arr[i + 1] - arr[i];
		}
	}
	//统计最小差值的有几个
	for (i = 0; i < arrSize - 1; i++)
	{
		if (arr[i + 1] - arr[i] == low)
		{
			count++;
		}
	}

	//开辟空间
	int** returnarr = (int**)malloc(sizeof(int*)*count);
	*returnColumnSizes = (int *)malloc(sizeof(int)*count);

	for (i = 0; i < arrSize - 1; i++)
	{
		if (arr[i + 1] - arr[i] == low)
		{
			returnarr[a] = (int*)malloc(sizeof(int)* 2);
			returnarr[a][0] = arr[i];
			returnarr[a][1] = arr[i + 1];
			*(*returnColumnSizes + a) = 2;
			a++;
		}
	}
	*returnSize = count;
	
	return returnarr;
}



int main()
{
	int arr[] = { 4, 2, 1, 3 };
	int a = 0;
	int b = 0;
	int* p = &b;
	int** c= minimumAbsDifference(arr, 4, &a, &p);
	return 0;
}




