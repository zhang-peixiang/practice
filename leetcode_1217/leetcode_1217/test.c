#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


// 数轴上放置了一些筹码，每个筹码的位置存在数组 chips 当中。

// 你可以对 任何筹码 执行下面两种操作之一（不限操作次数，0 次也可以）：

// 将第 i 个筹码向左或者右移动 2 个单位，代价为 0。
// 将第 i 个筹码向左或者右移动 1 个单位，代价为 1。
// 最开始的时候，同一位置上也可能放着两个或者更多的筹码。

// 返回将所有筹码移动到同一位置（任意位置）上所需要的最小代价。




// erro
//int cmp(const int* left, const int* right)
//{
//	return *left - *right;
//}
//
//
//int minCostToMoveChips(int* position, int positionSize)
//{
//	int i = 0;
//	int count = 0;
//	int ret = 0;
//	int tmp = 0;
//	int max = 0;
//	if (positionSize < 2)
//	{
//		return 0;
//	}
//	qsort(position, positionSize, sizeof(int), cmp);
//	for (i = 0; i < positionSize-1; i++)
//	{
//		ret = 1;
//		while (i < positionSize - 1 && position[i] == position[i + 1])
//		{
//			ret++;
//			i++;
//		}
//		if (ret == positionSize)
//			return 0;
//		if (ret>max)
//		{
//			max = ret;
//			tmp = position[i];
//		}
//	}
//	for (i = 0; i < positionSize; i++)
//	{
//		if (position[i] != tmp)
//		{
//			ret = abs(position[i] - tmp);
//			count += ret % 2;
//		}
//	}
//	return count;
//}

int minCostToMoveChips(int* position, int positionSize)
{
	int count1 = 0;
	int count2 = 0;
	int i = 0;
	for (i = 0; i < positionSize; i++)
	{
		if (position[i] % 2 == 0)
		{
			count1++;
		}
		else
		{
			count2++;
		}
	}
	
	return count1 < count2 ? count1 : count2;
}


int main()
{
	int arr[] = { 2, 2, 2, 3, 3 };
	int ret = minCostToMoveChips(arr, 5);
	return 0;
}