#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
//注意：你不能在买入股票前卖出股票。
int maxProfit(int* prices, int pricesSize)
{
	int i = 0;
	int j = 0;
	int max = 0;
	int ret = 0;
	for (i = 0; i < pricesSize; i++)
	{
		for (j = i+1; j < pricesSize; j++)
		{
			ret = prices[j] - prices[i];
			if (ret>max)
			{
				max = ret;
			}
		}
	}
	return max;
}

int main()
{
	int arr[] = { 7, 1, 5, 3, 6, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = maxProfit(arr, sz);
	printf("%d\n", ret);
	return 0;
}