#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//�������ֱ����� 4 �� LED ����Сʱ��0 - 11�����ײ��� 6 �� LED ������ӣ�0 - 59����
//ÿ�� LED ����һ�� 0 �� 1�����λ���Ҳࡣ


//�ж�num�ö����Ʊ�ʾ�м���1
int getnum(int num)
{
	int count = 0;
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num /= 2;
	}
	return count;
}

//������
char ** readBinaryWatch(int num, int* returnSize)
{
	int i = 0;//��ʾhour
	int j = 0;//��ʾmin
	int a = 0;//�ƶ����ٿռ��λ��
	int count = 0;
	*returnSize = 0;
	//��*returnSize�Ĵ�С
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 60; j++)
		{
			count = getnum(i) + getnum(j);
			if (count == num)
			{
				(*returnSize)++;
			}
		}
	}
	//���ٶ�ά�ռ�
	char** arr = (char**)malloc((*returnSize)*sizeof(char*));
	for (i = 0; i < *returnSize; i++)
	{
		arr[i] = (char*)malloc(6 * sizeof(char));
	}
	//������ֵ�Ž����ٵĿռ���
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 60; j++)
		{
			count = getnum(i) + getnum(j);
			if (count == num)
			{
				sprintf(arr[a], "%d:%02d", i, j);
				a++;
			}
		}
	}
	return arr;
}

int main()
{
	int a = 0;
	int b = 0;
	readBinaryWatch(a, &b);
	return 0;
}
