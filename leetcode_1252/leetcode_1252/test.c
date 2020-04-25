#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//给你一个 n 行 m 列的矩阵，最开始的时候，每个单元格中的值都是 0。
//另有一个索引数组 indices，indices[i] = [ri, ci] 中的 ri 和 ci 分别表示指定的行和列（从 0 开始编号）。
//你需要将每对 [ri, ci] 指定的行和列上的所有单元格的值加 1。
//请你在执行完所有 indices 指定的增量操作后，返回矩阵中 「奇数值单元格」 的数目。

int oddCells(int n, int m, int indices[][2], int indicesSize, int* indicesColSize)
{
	int arr[48][37];
	int i = 0;
	int j = 0;
	int count = 0;
	*indicesColSize = 2;
	for (i = 0; i < n; i++)//初始化
	{
		for (j = 0; j < m; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (i = 0; i < indicesSize; i++)
	{
		int a = indices[i][0];//拿到ri
		int b = indices[i][1];//拿到ci
		for (j = 0; j < m; j++)
		{
			arr[a][j] += 1;//对行赋值
		}
		for (j = 0; j < n; j++)
		{
			arr[j][b] += 1;//对列赋值
		}
	}
	for (i = 0; i < n; i++)//遍历数组，寻找奇数
	{
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] % 2 == 1)
			{
				count++;
			}
		}
	}
	return count;
}


int main()
{
	int n = 48;
	int m = 37;
	int a = 1;
	int b = 1;
	int indices[][2] = { { 40,5 } };
	int ret = oddCells(n, m, indices, a, &b);
	printf("%d\n", ret);
	return 0;
}