#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

//给你一个仅由数字 6 和 9 组成的正整数 num。
//你最多只能翻转一位数字，将 6 变成 9，或者把 9 变成 6 。
//请返回你可以得到的最大数字。
int maximum69Number(int num)
{
	int i = 0;
	int count = 0;
	int tmp = 0;
	int a = 0;
	int b = num;//将num值赋给b，防止num 被改变
	int count1 = 0;
	while (b)
	{
		if (b % 10 == 6)//取到每一个数，拆开找'6'
		{
			count++;//记录num中有几个6
		}
		b /= 10;
	}
	if (count == 0)//如果count=0 即num全为9 返回即为最大
	{
		return num;
	}
	else
	{
		while (num)
		{
			tmp = num % 10;//取到每一个数，拆开找'6'，在组合求值
			if (tmp == 6)
			{
				count--;//找最后一个'6'
			}
			if (count == 0)
			{
				tmp = 9;//将从右到左的最后一个6变为9即为最大值
			}
			a = a + tmp*pow(10, count1);
			count1++;//10的幂
			num /= 10;
		}
	}
	return a;
}


int main()
{
	int a = 0;
	int b = 0;
	scanf("%d", &a);
	int ret = maximum69Number(a);
	printf("%d\n", ret);
	return 0;
}