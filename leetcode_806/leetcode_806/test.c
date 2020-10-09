﻿#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 我们要把给定的字符串 S 从左到右写到每一行上，每一行的最大宽度为100个单位，
// 如果我们在写某个字母的时候会使这行超过了100 个单位，那么我们应该把这个字母写到下一行。
// 我们给定了一个数组 widths ，这个数组 widths[0] 代表 'a' 需要的单位，
// widths[1] 代表 'b' 需要的单位，...， widths[25] 代表 'z' 需要的单位。

// 现在回答两个问题：至少多少行能放下S，以及最后一行使用的宽度是多少个单位？
// 将你的答案作为长度为2的整数列表返回。


int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize)
{
	int sum = 0;
	int i = 0;
	int line = 0;
	int sz = 0;
	int len = strlen(S);
	int* arr = (int*)malloc(sizeof(int)* 2);

	for (i = 0; i < len; i++)
	{
		int num = S[i] - 'a';
		sum += widths[num];
		if (sum>100)
		{
			i--;
			sum = 0;
			line++;
		}
	}
	arr[0] = line+1;
	arr[1] = sum;
	*returnSize = 2;
	return arr;
}