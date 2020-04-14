#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//平面上有 n 个点，点的位置用整数坐标表示 points[i] = [xi, yi]。请你计算访问所有这些点需要的最小时间（以秒为单位）。
//你可以按照下面的规则在平面上移动：
//	每一秒沿水平或者竖直方向移动一个单位长度，或者跨过对角线（可以看作在一秒内向水平和竖直方向各移动一个单位长度）。
//	必须按照数组中出现的顺序来访问这些点。

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize)
{
	int i = 0;
	int a = 0;
	int b = 0;
	int count = 0;
	if (pointsSize < 2)
	{
		return 0;
	}
	else
	{
		for (i = 0; i < pointsSize-1; i++)
		{
			a = abs(points[i][0] - points[i + 1][0]);
			b = abs(points[i][1] - points[i + 1][1]);
			if (a>b)
			{
				count += a;
			}
			else
			{
				count += b;
			}
		}
	}
	*pointsColSize = count;
	return count;
}

int main()
{
	int points[3][2] = { { 1, 1 }, { 3, 4 }, { -1, 0 } };
	int sz = sizeof(points) / sizeof(points[0]);
	int *p[3];
	int ret = 0;
	p[0] = points[0];
	p[1] = points[1];
	p[2] = points[2];
	ret=minTimeToVisitAllPoints(p, sz, &ret);
	printf("%d\n", ret);
	return 0;
}
