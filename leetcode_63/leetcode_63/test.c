#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//¶¯Ì¬¹æ»®
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
	int m = obstacleGridSize;
	int n = *obstacleGridColSize;
	int arr[m + 1][n + 1];
	arr[1][1] = 1;

	int i = 0;
	int j = 0;

	for (i = 0; i < m + 1; i++)
	{
		arr[i][0] = 0;
	}
	for (i = 0; i < n + 1; i++)
	{
		arr[0][i] = 0;
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (obstacleGrid[i][j] == 1)
			{
				arr[i + 1][j + 1] = 0;
			}
			else if (i == 0 && j == 0)
				continue;
			else
			{
				arr[i + 1][j + 1] = arr[i][j + 1] + arr[i + 1][j];
			}
		}
	}
	return arr[i][j];
}

int main()
{
	int arr[3][3] = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
	int a = 3;
	int i = uniquePathsWithObstacles(arr, 3, &a);
	return 0;
}