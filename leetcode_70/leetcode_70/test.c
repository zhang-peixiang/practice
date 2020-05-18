#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
/*
规律为：f(n) = f(n-1)+f(n-2)
*/
int climbStairs(int n)
{
	int i = 0;
	int first = 1;
	int second = 2;
	int ret = 0;
	if (n < 3)
	{
		return n;
	}
	for (i = 3; i <= n; i++)
	{
		ret = first + second;
		first = second;
		second = ret;
	}
	return ret;
}


int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = climbStairs(n);
	printf("%d\n", ret);
	return 0;
}