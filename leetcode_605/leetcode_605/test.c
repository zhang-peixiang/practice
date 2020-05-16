#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
//假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。
//可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
//
//给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。
//能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

/*
分两种情况讨论：
1.长度小于3的情况
(1)当长度小于3时，只要中间有一个1且n不为0时，返回false，n为0时，返回true
(2)全为0时([0,0,0])，最多只能种一个，所以n小于等于1时，返回true，否则返回false。
2.长度大于等于3的情况
(1)当第一个(i=0)为0和第二个为0的时候，可以在第一个位置上种花。
(2)当最后一个位置上为0并且倒数第二个位置上为0时，可以在最后一个位置上种花
(3)中间位置上，三个连续的0可以种一个花，然后i+2避免重复计算(例如：[1,0,0,0,0,1])
*/
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
	int i = 0;
	int count = 0;
	if (flowerbedSize < 3)//判断长度为3以下的情况
	{
		for (i = 0; i < flowerbedSize; i++)
		{
			if (flowerbed[i] == 1)
			{
				if (n == 0)
				{
					return true;
				}
				return false;
			}
		}
		if (n < 2&& flowerbedSize!=0)
		{
			return true;
		}
		return false;
	}
	for (i = 0; i < flowerbedSize; i++)
	{
		if (i == 0)
		{
			if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)
			{
				count++;
				i += 1;//避免重复计算，i+=2，因为循环结束会加1，所以这里加1  例如[0,0,0,1]
			}
		}
		else if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && i == flowerbedSize - 1)
		{
			count++;
			i += 1;
		}
		else if (i>0 && i <= flowerbedSize - 2)
		{
			if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
			{
				count++;
				i = i + 1;
			}
		}

	}
	if (count >= n)
	{
		return true;
	}
	return false;
}
int main()
{
	int arr[] = { 0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int a = 0;
	scanf("%d", &a);
	int ret = canPlaceFlowers(arr, sz, a);
	printf("%d\n", ret);
	return 0;
}
