#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// ������Χ [m, n]������ 0 <= m <= n <= 2147483647��
// ���ش˷�Χ���������ֵİ�λ�루���� m, n ���˵㣩��

// ˼·��
//n�Ķ�����λ��m����������ߵ�1��ʱ��&�Ľ����ȻΪ0��
//�����˼�����������������λ��ͬʱ�����1�ᱣ�棬Ȼ��Ƚ���һλ����ͬҲ����...
//����ֻ��Ҫm n ͬʱ���Ƶ����ʱ m n��ֵ����&���ܱ�����λ����Ȼ�����ƻ�����������ֵ��


int rangeBitwiseAnd(int m, int n)
{
	int count = 0;

	while (m != n)
	{
		m >>= 1;
		n >>= 1;
		count++;
	
	}

	return m << count;
}




int main()
{
	int m = 6;
	int n = 7;
	int a = rangeBitwiseAnd(m, n);

	return 0;
}