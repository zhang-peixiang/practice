#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


// 小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。
//
// 如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。
//
// 请你计算 最多 能喝到多少瓶酒。


int numWaterBottles(int numBottles, int numExchange)
{
	int count = numBottles; // 记录空瓶子
	int a = 0;

	while (count < numExchange)
	{
		a = count%numExchange;
		numBottles += count / numExchange;
		count /= numExchange;
		count += a;
	}
	return numBottles;
}