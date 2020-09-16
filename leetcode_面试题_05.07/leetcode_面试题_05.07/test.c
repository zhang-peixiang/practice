#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>


// 配对交换。编写程序，交换某个整数的奇数位和偶数位，
// 尽量使用较少的指令（也就是说，位0与位1交换，位2与位3交换，以此类推）。

int exchangeBits(int num)
{
	int i = 0;
	int flag = 0;
	int count = 0;
	int ret = 1;
	while (num)
	{
		if (flag == 0)
		{
			flag = 1;
			count += num % 2 * pow(2, ret);
		}
		else
		{
			flag = 0;
			count += num % 2 * pow(2, ret - 1);
			ret += 2;
		}
		num /= 2;
	}
	if (flag == 1)
	{
		flag = 0;
		count += num % 2 * pow(2, ret - 1);
	}
	return count;
}

int main()
{
	int num = 2;
	int ret = exchangeBits(num);
	return 0;
}