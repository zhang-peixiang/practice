#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//������������¥�ݡ���Ҫ n ������ܵ���¥����
//ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
/*
����Ϊ��f(n) = f(n-1)+f(n-2)
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