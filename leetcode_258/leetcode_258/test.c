#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����

// �Լ�˼· --�鷳
int addDigits(int num)
{
	int count = 0;
	int ret = 0;
	while (num)
	{
		count += num % 10;
		num /= 10;
	}
	if (count<9)
	{
		return count;
	}
	else
	{
		while (count)
		{
			ret += count % 10;
			count /= 10;
		}
	}
	return ret;
}

// ���
int addDigits(int num)
{
	int count = 0;
	while (num/10 !=0)
	{
		count = 0;
		while (num)
		{
			count += num % 10;
			num /= 10;
		}
		num = count;
	}
	return num;
}


//ʱ�临�Ӷ�O(1)

int addDigits(int num)
{
	if (num != 0 && num % 9 == 0)
	{
		return 9;
	}
	else
	{
		return num % 9;
	}
}