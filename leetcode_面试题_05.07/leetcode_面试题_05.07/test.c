#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>


// ��Խ�������д���򣬽���ĳ������������λ��ż��λ��
// ����ʹ�ý��ٵ�ָ�Ҳ����˵��λ0��λ1������λ2��λ3�������Դ����ƣ���

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