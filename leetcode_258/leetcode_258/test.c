#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

// 自己思路 --麻烦
int addDigits(int num)
{
	int count = 0;
	int ret = 0;
	while (num)
	{
		count += num % 10;
		num /= 10;
	}
	if (count<9)
	{
		return count;
	}
	else
	{
		while (count)
		{
			ret += count % 10;
			count /= 10;
		}
	}
	return ret;
}

// 题解
int addDigits(int num)
{
	int count = 0;
	while (num/10 !=0)
	{
		count = 0;
		while (num)
		{
			count += num % 10;
			num /= 10;
		}
		num = count;
	}
	return num;
}


//时间复杂度O(1)

int addDigits(int num)
{
	if (num != 0 && num % 9 == 0)
	{
		return 9;
	}
	else
	{
		return num % 9;
	}
}