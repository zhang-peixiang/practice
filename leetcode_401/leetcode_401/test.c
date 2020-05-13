#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//二进制手表顶部有 4 个 LED 代表小时（0 - 11），底部的 6 个 LED 代表分钟（0 - 59）。
//每个 LED 代表一个 0 或 1，最低位在右侧。


//判断num用二进制表示有几个1
int getnum(int num)
{
	int count = 0;
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num /= 2;
	}
	return count;
}

//暴力法
char ** readBinaryWatch(int num, int* returnSize)
{
	int i = 0;//表示hour
	int j = 0;//表示min
	int a = 0;//移动开辟空间的位置
	int count = 0;
	*returnSize = 0;
	//求*returnSize的大小
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 60; j++)
		{
			count = getnum(i) + getnum(j);
			if (count == num)
			{
				(*returnSize)++;
			}
		}
	}
	//开辟二维空间
	char** arr = (char**)malloc((*returnSize)*sizeof(char*));
	for (i = 0; i < *returnSize; i++)
	{
		arr[i] = (char*)malloc(6 * sizeof(char));
	}
	//将可能值放进开辟的空间中
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 60; j++)
		{
			count = getnum(i) + getnum(j);
			if (count == num)
			{
				sprintf(arr[a], "%d:%02d", i, j);
				a++;
			}
		}
	}
	return arr;
}

int main()
{
	int a = 0;
	int b = 0;
	readBinaryWatch(a, &b);
	return 0;
}
