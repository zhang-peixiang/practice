#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


// ����nums������0��n������������������ȱ��һ����
// ���д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������

// ��0-n��ͣ�Ȼ���ȥ�����е�����ʣ���������ȱʧ����

int missingNumber(int* nums, int numsSize)
{
	int count = 0;
	int i = 0;
	int a = numsSize + 1;
	if (a % 2 == 1)
	{
		count = numsSize*(a / 2) + a / 2;
	}
	else
	{
		count = numsSize*(a / 2);
	}
	for (i = 0; i < numsSize; i++)
	{
		count -= nums[i];
	}
	return count;
}