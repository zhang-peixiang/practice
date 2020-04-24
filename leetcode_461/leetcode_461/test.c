#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//��������֮��ĺ�������ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��
//������������ x �� y����������֮��ĺ������롣

int hammingDistance(int x, int y)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		int a = 1 & (x >> i);
		int b = 1 & (y >> i);
		if (a != b)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int a = 1;
	int b = 4;
	int ret = hammingDistance(a, b);
	printf("%d\n", ret);
	return 0;
}