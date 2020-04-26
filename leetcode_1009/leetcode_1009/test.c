#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//每个非负整数 N 都有其二进制表示。例如， 5 可以被表示为二进制 "101"，11 可以用二进制 "1011" 表示，依此类推。注意，除 N = 0 外，任何二进制表示中都不含前导零。
//二进制的反码表示是将每个 1 改为 0 且每个 0 变为 1。例如，二进制数 "101" 的二进制反码为 "010"。
//给你一个十进制数 N，请你返回其二进制表示的反码所对应的十进制整数。
int bitwiseComplement(int N)
{
	int count = 0;//记录二进制的位数
	int a = 0;
	int i = 0;
	if (N == 0)
	{
		return 1;
	}
	while (N)
	{
		i = N % 2;//余数即为其二进制位上的数
		N /= 2;
		if (i == 0)
		{
			a += pow(2, count);
		}
		count++;//二进制位是从2的0次方开始，所以count应放在最后
	}
	return a;
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	int ret = bitwiseComplement(a);
	printf("%d\n", ret);
	return 0;
}