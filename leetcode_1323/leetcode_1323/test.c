#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

//����һ���������� 6 �� 9 ��ɵ������� num��
//�����ֻ�ܷ�תһλ���֣��� 6 ��� 9�����߰� 9 ��� 6 ��
//�뷵������Եõ���������֡�
int maximum69Number(int num)
{
	int i = 0;
	int count = 0;
	int tmp = 0;
	int a = 0;
	int b = num;//��numֵ����b����ֹnum ���ı�
	int count1 = 0;
	while (b)
	{
		if (b % 10 == 6)//ȡ��ÿһ����������'6'
		{
			count++;//��¼num���м���6
		}
		b /= 10;
	}
	if (count == 0)//���count=0 ��numȫΪ9 ���ؼ�Ϊ���
	{
		return num;
	}
	else
	{
		while (num)
		{
			tmp = num % 10;//ȡ��ÿһ����������'6'���������ֵ
			if (tmp == 6)
			{
				count--;//�����һ��'6'
			}
			if (count == 0)
			{
				tmp = 9;//�����ҵ�������һ��6��Ϊ9��Ϊ���ֵ
			}
			a = a + tmp*pow(10, count1);
			count1++;//10����
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