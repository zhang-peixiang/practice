#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>


// 给定一个正整数，输出它的补数。补数是对该数的二进制表示取反

int findComplement(int num)
{
	int count = 0;
	int tmp = 0;
	while (num)
	{
		int a = num % 2;
		if (a == 1)
		{
			a = 0;
		}
		else
			a = 1;
		count += pow(2, tmp)*a;
		tmp++;
		num /= 2;
	}
	return count;
}


// 简便解法  
// 双百
int findComplement(int num){
	long temp = 1;
	while (num >= temp){
		temp <<= 1;
	}
	return (temp - 1 - num);
}
