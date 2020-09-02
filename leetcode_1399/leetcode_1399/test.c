#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 给你一个整数 n 。请你先求出从 1 到 n 的每个整数 10 进制表示下的数位和（每一位上的数字相加），
// 然后把数位和相等的数字放到同一个组中。
//
// 请你统计每个组中的数字数目，并返回数字数目并列最多的组有多少个。




// 注意n的取值范围
// n最大取到10000，9999为数位和的数字，数位和为36。
int countLargestGroup(int n){
	int arr[37] = { 0 };
	int i = 0;
	int sum = 0;
	int a = 0;
	int max = 0;
	for (i = 1; i <= n; i++)
	{
		a = i;
		while (a > 0)
		{
			sum += a % 10;
			a /= 10;
		}
		arr[sum]++;
		sum = 0;
	}
	for (i = 0; i < 37; i++)
	{
		max = fmax(max, arr[i]);
	}
	for (i = 0; i < 37; i++)
	{
		if (arr[i] == max)
		{
			sum++;
		}
	}
	return sum;
}