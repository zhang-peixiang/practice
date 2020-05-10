﻿#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//思路1：不简洁
//int maxProfit(int* prices, int pricesSize)
//{
//	int i = 0;
//	int j = 0;
//	int max = 0;
//	int ret = 0;
//	for (i = 0; i < pricesSize; i++)
//	{
//		int sum = 0;
//		ret = prices[i];
//		for (j = i; j < pricesSize-1; j++)
//		{
//			if (prices[j] < prices[j + 1])
//			{
//				ret = prices[j + 1] - prices[j];
//				sum += ret;
//			}
//			else
//			{
//				ret = prices[j + 1];
//			}
//		}
//		if (max < sum)
//		{
//			max = sum;
//		}
//	}
//	return max;
//}

//思路二：
int maxProfit(int* prices, int pricesSize)
{
	int i = 0;
	int ret = 0;
	int sum = 0;
	for (i = 0; i < pricesSize-1; i++)
	{
		if (prices[i] < prices[i + 1])
		{
			ret = prices[i + 1] - prices[i];
			sum += ret;
		}
	}
	return sum;
}

int main()
{
	int arr[] = { 7, 1, 5, 3, 6, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = maxProfit(arr, sz);
	printf("%d\n", ret);
	return 0;
}