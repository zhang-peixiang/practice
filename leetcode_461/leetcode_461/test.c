#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
//给出两个整数 x 和 y，计算它们之间的汉明距离。

int hammingDistance(int x, int y)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		int a = 1 & (x >> i);
		int b = 1 & (y >> i);
		if (a != b)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int a = 1;
	int b = 4;
	int ret = hammingDistance(a, b);
	printf("%d\n", ret);
	return 0;
}