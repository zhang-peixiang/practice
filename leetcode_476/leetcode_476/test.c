#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>


// ����һ����������������Ĳ����������ǶԸ����Ķ����Ʊ�ʾȡ��

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


// ���ⷨ  
// ˫��
int findComplement(int num){
	long temp = 1;
	while (num >= temp){
		temp <<= 1;
	}
	return (temp - 1 - num);
}
