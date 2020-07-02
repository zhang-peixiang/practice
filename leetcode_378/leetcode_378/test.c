#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
//请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

//方法一：暴力法
//int compare(int* a, int* b)
//{
//	return *a - *b;
//}
//
//int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
//	*matrixColSize = matrixSize;
//	int arr[1000000] = { 0 };
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	for (i = 0; i<matrixSize; i++)
//	{
//		for (j = 0; j<matrixSize; j++)
//		{
//			arr[a] = matrix[i][j];
//			a++;
//		}
//	}
//	qsort(arr, a, sizeof(arr[0]), compare);
//
//	return arr[k - 1];
//}


//方法二：二维数组的二分法
int check(int** matrix, int mid, int row, int col)
{
	int count = 0;
	int i = row - 1;
	int j = 0;
	while (i >= 0 && j < col)
	{
		if (matrix[i][j] <= mid)
		{
			j++;
			count = count + i + 1;
		}
		else
		{
			i--;
		}
	}
	return count;
}


int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
	*matrixColSize = matrixSize;
	int left = matrix[0][0];
	int right = matrix[matrixSize - 1][matrixSize - 1];

	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		int ret = check(matrix, mid, matrixSize, *matrixColSize);
		if (ret< k)
		{
			left = mid + 1;
		}
		else if (ret == k)//可和else合并，写成这样好理解
		{
			right = mid;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

int main()
{
	int arr[][3] = { { 1, 5, 9 },
	{ 10, 11, 13 },
	{ 12, 13, 15 } };

	int a = 3;

	kthSmallest(arr, 3, &a, 8);
	return 0;
}