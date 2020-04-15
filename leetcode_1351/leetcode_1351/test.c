#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。
//请你统计并返回 grid 中 负数 的数目。
int countNegatives(int grid[][4], int gridSize, int* gridColSize)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < gridSize; i++)
	{
		for (j = 0; j < (*gridColSize); j++)
		{
			if (*(*(grid + i) + j)< 0)
				count += 1;
		}
	}
	return count;
}


int main()
{
	int arr[4][4] = { { 4, 3, 2, -1 }, { 3, 2, 1, -1 }, { 1, 1, -1, -2 }, { -1, -1, -2, -3 } };
	int* p[4] = {  arr[0] ,  arr[1] ,  arr[2]  };
	int a = 0;
	int b = 0;
	int count = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	int len1 = sizeof(arr[0]) / sizeof(arr[0][0]);
	count=countNegatives(*p, len, &len1);
	printf("%d\n", count);
	return 0;
}