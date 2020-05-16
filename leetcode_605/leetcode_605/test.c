#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
//假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。
//可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
//
//给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。
//能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
	int i = 0;
	int count = 0;
	if (flowerbedSize < 3)
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
		if (n < 2&&f lowerbedSize!=0)
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
				i += 1;
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
